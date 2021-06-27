//
// Created by andrew on 2021/6/17.
//
#include <iostream>
#include <liveMedia.hh>
#include <BasicUsageEnvironment.hh>
#include <cstring>


void afterPlaying(void* /*clientData*/) {
    std::cout << "done" << std::endl;
    exit(0);
}

class MPEG2TransportStreamIndex {
public:
    MPEG2TransportStreamIndex() = default;
    ~MPEG2TransportStreamIndex() = default;

    int32_t Init(const char* pProgramName, const char* pSzInputFilename, size_t filenameLen) {
        // 设置用户环境变量
        if (filenameLen < 4 || strcmp(&pSzInputFilename[filenameLen - 3], ".ts") != 0) {
            *m_pEnv << "ERROR : input file name " << pSzInputFilename;

            return -1;
        }

        TaskScheduler* pScheduler = BasicTaskScheduler::createNew();
        m_pEnv = BasicUsageEnvironment::createNew(*pScheduler);
        m_pProgramName = pProgramName;
        m_pInputFilename = pSzInputFilename;
        m_fileNameLen = filenameLen;
        return 0;
    }

    int32_t OpenInputFile() {
        m_pInput = ByteStreamFileSource::createNew(*m_pEnv, m_pInputFilename, TRANSPORT_PACKET_SIZE);
        if (nullptr == m_pInput) {
            *m_pEnv << "open input file failed .";
            return -1;
        }

        return 0;
    }

    int32_t CreatTransportStreamFilter() {
        m_pIndexer = MPEG2IFrameIndexFromTransportStream::createNew(*m_pEnv, m_pInput);
        if (nullptr == m_pIndexer) {
            return -1;
        }
        return 0;
    }

    int32_t OpenOutputFile() {
        char *pSzOutputFilename = new char[m_fileNameLen + 2];
        sprintf(pSzOutputFilename, "%sx", m_pInputFilename);

        m_pOutput = FileSink::createNew(*m_pEnv, pSzOutputFilename);
        if (nullptr == m_pOutput) {
            return -1;
        }

        return 0;
    }

    void StartPlaying() {
        *m_pEnv << "Start Writing index file " ;
        m_pOutput->startPlaying(*m_pIndexer, afterPlaying, nullptr);
        m_pEnv->taskScheduler().doEventLoop();
    }

private:
    UsageEnvironment *m_pEnv{};
    const char *m_pProgramName{};
    // 输入文件名和文件长度
    const char *m_pInputFilename{};
    int m_fileNameLen{};
    FramedSource* m_pInput{};
    FramedSource * m_pIndexer{};
    MediaSink* m_pOutput{};
};



int main(int argc, char* argv[]) {

    if (argc != 2) {
        std::cout << "argc < 2" << std::endl;
        return -1;
    }

    // 定义一个Mpeg解析类
    MPEG2TransportStreamIndex mpeg2TransportStreamIndex;
    int32_t ret = mpeg2TransportStreamIndex.Init(argv[0], argv[1], strlen(argv[1]));
    if (0 != ret) {
        std::cerr << "mpeg2TransportStreamIndex.Init failed." << std::endl;
        return ret;
    }

//    打开输入文件
    ret = mpeg2TransportStreamIndex.OpenInputFile();
    if (0 != ret) {
        std::cerr << "mpeg2TransportStreamIndex.OpenInputFile failed." << std::endl;
        return ret;
    }
    // 创建文件流
    ret = mpeg2TransportStreamIndex.CreatTransportStreamFilter();
    if (0 != ret) {
        std::cerr << "mpeg2TransportStreamIndex.CreatTransportStreamFilter failed." << std::endl;
        return ret;
    }
    // 打开输出文件
    ret = mpeg2TransportStreamIndex.OpenOutputFile();
    if (0 != ret) {
        std::cerr << "mpeg2TransportStreamIndex.OpenOutputFile failed." << std::endl;
        return ret;
    }
    // 开始执行事件循环
    mpeg2TransportStreamIndex.StartPlaying();

    return 0;
}




