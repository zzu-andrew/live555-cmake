# `Live555`分析



## 引言

`live555`作为入门级的音视频开发源码，怎样安装就不说了，可以官方下载，也可以使用我这里这个`cmake`管理的项目，目前写的`cmake`只在`linux`上验证过。

为什么`live555`叫入门级，因为相对`gstream`， `FFMpeg` ，`WebRTC`来说`live555`真的是太简单了

主要的目录和功能如下：

`UsageEnvironment`目录中生命了一些虚类

`BasicUsageEnvironment`主要是对目录`UsageEnvironment`中定义的虚类的实现

`groupsock`主要实现了对`socket`封装，在`liveMedia`目录中涉及网络的部分会使用

`liveMedia`目录是整个`live555`开发库的核心部分



## 从示例程序的`main`函数开始

首先建立两个环境对象，整个程序运行过程中都会用到，如下：

```cpp
// Begin by setting up our usage environment:
TaskScheduler* scheduler = BasicTaskScheduler::createNew();
UsageEnvironment* env = BasicUsageEnvironment::createNew(*scheduler);
```

`TaskScheduler`类的继承关系如下：

![image-20201118230923184](image/image-20201118230923184.png)

`UsageEnvironment`的继承关系如下：

![image-20201118231253772](image/image-20201118231253772.png)

从继承关系上来开，`live555`继承管理还是比较好的，基本上只有两次继承。

其中`UsageEnvironment`和`TaskScheduler`使用了设计模式中的桥接模式关系，`UsageEnvironment`引用了`TaskScheduler`，并对其功能进行了扩展。

如果需要认证，就实现下：

```cpp
UserAuthenticationDatabase* authDB = NULL;
```

默认没有实现，就不在这里介绍了，在下面小结会专门介绍认证的过程。

接下来就是创建`RTSP server`的过程

会首先尝试使用554端口创建，创建失败了会再次使用8554端口创建`RTSP server`

```cpp
RTSPServer* rtspServer;
portNumBits rtspServerPortNum = 554;
rtspServer = DynamicRTSPServer::createNew(*env, rtspServerPortNum, authDB);
if (rtspServer == NULL) {
    rtspServerPortNum = 8554;
    rtspServer = DynamicRTSPServer::createNew(*env, rtspServerPortNum, authDB);
}
if (rtspServer == NULL) {
    *env << "Failed to create RTSP server: " << env->getResultMsg() << "\n";
    exit(1);
}
```

`portNumBits`定义的事`u_int16_t`类型，将其传入`createNew`之后会使用这个值，对`Port`进行初始化。

```cpp
typedef u_int16_t portNumBits;
```

首次使用554端口进行绑定的时候会失败，失败之后会进行8554端口绑定，代码在`GroupsockHelper.cpp:306`行，后期库更新位置可能会变，调用的函数为`setupStreamSocket`。

```cpp
MAKE_SOCKADDR_IN(name, ReceivingInterfaceAddr, port.num());
if (bind(newSocket, (struct sockaddr*)&name, sizeof name) != 0) {// 端口为554的时候， 这里进行bind会失败
    char tmpBuffer[100];
    sprintf(tmpBuffer, "bind() error (port number: %d): ",
            ntohs(port.num()));
    socketErr(env, tmpBuffer);
    closeSocket(newSocket);
    return -1;
}
```

然后使用`*env`进行打印提示：

```cpp
*env << "LIVE555 Media Server\n";
*env << "\tversion " << MEDIA_SERVER_VERSION_STRING
    << " (LIVE555 Streaming Media library version "
    << LIVEMEDIA_LIBRARY_VERSION_STRING << ").\n";

char* urlPrefix = rtspServer->rtspURLPrefix();
*env << "Play streams from this server using the URL\n\t"
    << urlPrefix << "<filename>\nwhere <filename> is a file present in the current directory.\n";
*env << "Each file's type is inferred from its name suffix:\n";
*env << "\t\".264\" => a H.264 Video Elementary Stream file\n";
*env << "\t\".265\" => a H.265 Video Elementary Stream file\n";
*env << "\t\".aac\" => an AAC Audio (ADTS format) file\n";
*env << "\t\".ac3\" => an AC-3 Audio file\n";
*env << "\t\".amr\" => an AMR Audio file\n";
*env << "\t\".dv\" => a DV Video file\n";
*env << "\t\".m4e\" => a MPEG-4 Video Elementary Stream file\n";
*env << "\t\".mkv\" => a Matroska audio+video+(optional)subtitles file\n";
*env << "\t\".mp3\" => a MPEG-1 or 2 Audio file\n";
*env << "\t\".mpg\" => a MPEG-1 or 2 Program Stream (audio+video) file\n";
*env << "\t\".ogg\" or \".ogv\" or \".opus\" => an Ogg audio and/or video file\n";
*env << "\t\".ts\" => a MPEG Transport Stream file\n";
*env << "\t\t(a \".tsx\" index file - if present - provides server 'trick play' support)\n";
*env << "\t\".vob\" => a VOB (MPEG-2 video with AC-3 audio) file\n";
*env << "\t\".wav\" => a WAV Audio file\n";
*env << "\t\".webm\" => a WebM audio(Vorbis)+video(VP8) file\n";
*env << "See http://www.live555.com/mediaServer/ for additional documentation.\n";
```

可以看到`*env`能调用`<<`操作符，是因为在`UsageEnvironment`类中进行了操作符重载

```cpp
// 'console' output:
virtual UsageEnvironment& operator<<(char const* str) = 0;
virtual UsageEnvironment& operator<<(int i) = 0;
virtual UsageEnvironment& operator<<(unsigned u) = 0;
virtual UsageEnvironment& operator<<(double d) = 0;
virtual UsageEnvironment& operator<<(void* p) = 0;
```





















0