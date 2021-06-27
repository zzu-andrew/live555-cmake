#This should be the first line of the CMakeLists.txt
cmake_minimum_required(VERSION 3.2)

# Poor practice, but very common
project(live555 VERSION 4.7.2)

#
add_subdirectory(liveMedia)
add_subdirectory(groupsock)
add_subdirectory(BasicUsageEnvironment)
add_subdirectory(UsageEnvironment)
add_subdirectory(demo)

file(GLOB USER_LIBS_FILE ./mediaServer/*.cpp)
add_executable(live555MediaServer
        ${USER_LIBS_FILE})   

add_definitions("-std=c++11 -O0 -DSOCKLEN_T=socklen_t -g -D_LARGEFILE_SOURCE=1 -D_FILE_OFFSET_BITS=64 -Wall -DBSD=1")
#add_compile_options(-std=c++11 -O -DSOCKLEN_T=socklen_t -g -D_LARGEFILE_SOURCE=1 -D_FILE_OFFSET_BITS=64 -Wall -DBSD=1)

target_link_libraries(live555MediaServer
        PRIVATE liveMedia
        PRIVATE groupsock
        PRIVATE BasicUsageEnvironment
        PRIVATE UsageEnvironment
      )

target_include_directories(live555MediaServer 
        PUBLIC .
        PUBLIC include
        PUBLIC UsageEnvironment/include
        PUBLIC groupsock/include
        PUBLIC liveMedia/include
        PUBLIC BasicUsageEnvironment/include)

# proxy live555
add_executable(live555ProxyServer proxyServer/live555ProxyServer.cpp)  
target_link_libraries(live555ProxyServer
        PRIVATE liveMedia
        PRIVATE groupsock
        PRIVATE BasicUsageEnvironment
        PRIVATE UsageEnvironment
      )
target_include_directories(live555ProxyServer 
        PUBLIC .
        PUBLIC include
        PUBLIC UsageEnvironment/include
        PUBLIC groupsock/include
        PUBLIC liveMedia/include
        PUBLIC BasicUsageEnvironment/include)
# hls live555
add_executable(live555HLSProxy hlsProxy/live555HLSProxy.cpp)  
target_link_libraries(live555HLSProxy
        PRIVATE liveMedia
        PRIVATE groupsock
        PRIVATE BasicUsageEnvironment
        PRIVATE UsageEnvironment
      )
target_include_directories(live555HLSProxy 
        PUBLIC .
        PUBLIC include
        PUBLIC UsageEnvironment/include
        PUBLIC groupsock/include
        PUBLIC liveMedia/include
        PUBLIC BasicUsageEnvironment/include)

# test programe
add_executable(testMP3Streamer testProgs/testMP3Streamer.cpp)  
target_link_libraries(testMP3Streamer
        PUBLIC ssl
        PUBLIC crypto
        PRIVATE liveMedia
        PRIVATE groupsock
        PRIVATE BasicUsageEnvironment
        PRIVATE UsageEnvironment
      )
target_include_directories(testMP3Streamer 
        PUBLIC .
        PUBLIC include
        PUBLIC UsageEnvironment/include
        PUBLIC groupsock/include
        PUBLIC liveMedia/include
        PUBLIC BasicUsageEnvironment/include)

#
add_executable(testMPEG1or2VideoStreamer testProgs/testMPEG1or2VideoStreamer.cpp)  
target_link_libraries(testMPEG1or2VideoStreamer
        PUBLIC ssl
        PUBLIC crypto
        PRIVATE liveMedia
        PRIVATE groupsock
        PRIVATE BasicUsageEnvironment
        PRIVATE UsageEnvironment
        )
target_include_directories(testMPEG1or2VideoStreamer 
        PUBLIC .
        PUBLIC include
        PUBLIC UsageEnvironment/include
        PUBLIC groupsock/include
        PUBLIC liveMedia/include
        PUBLIC BasicUsageEnvironment/include)

add_executable(testMPEG1or2AudioVideoStreamer testProgs/testMPEG1or2AudioVideoStreamer.cpp)  
target_link_libraries(testMPEG1or2AudioVideoStreamer
        PUBLIC ssl
        PUBLIC crypto
        PRIVATE liveMedia
        PRIVATE groupsock
        PRIVATE BasicUsageEnvironment
        PRIVATE UsageEnvironment
        )
target_include_directories(testMPEG1or2AudioVideoStreamer 
        PUBLIC .
        PUBLIC include
        PUBLIC UsageEnvironment/include
        PUBLIC groupsock/include
        PUBLIC liveMedia/include
        PUBLIC BasicUsageEnvironment/include)


add_executable(testMPEG2TransportStreamer testProgs/testMPEG2TransportStreamer.cpp)  
target_link_libraries(testMPEG2TransportStreamer
        PUBLIC ssl
        PUBLIC crypto
        PRIVATE liveMedia
        PRIVATE groupsock
        PRIVATE BasicUsageEnvironment
        PRIVATE UsageEnvironment
        )
target_include_directories(testMPEG2TransportStreamer 
        PUBLIC .
        PUBLIC include
        PUBLIC UsageEnvironment/include
        PUBLIC groupsock/include
        PUBLIC liveMedia/include
        PUBLIC BasicUsageEnvironment/include)
##########################################################
add_executable(testH264VideoStreamer testProgs/testH264VideoStreamer.cpp)  
target_link_libraries(testH264VideoStreamer
        PUBLIC ssl
        PUBLIC crypto
        PRIVATE liveMedia
        PRIVATE groupsock
        PRIVATE BasicUsageEnvironment
        PRIVATE UsageEnvironment
        )
target_include_directories(testH264VideoStreamer 
        PUBLIC .
        PUBLIC include
        PUBLIC UsageEnvironment/include
        PUBLIC groupsock/include
        PUBLIC liveMedia/include
        PUBLIC BasicUsageEnvironment/include)

add_executable(testH265VideoStreamer testProgs/testH265VideoStreamer.cpp)  
target_link_libraries(testH265VideoStreamer
        PUBLIC ssl
        PUBLIC crypto
        PRIVATE liveMedia
        PRIVATE groupsock
        PRIVATE BasicUsageEnvironment
        PRIVATE UsageEnvironment
        )
target_include_directories(testH265VideoStreamer 
        PUBLIC .
        PUBLIC include
        PUBLIC UsageEnvironment/include
        PUBLIC groupsock/include
        PUBLIC liveMedia/include
        PUBLIC BasicUsageEnvironment/include)

add_executable(testDVVideoStreamer testProgs/testDVVideoStreamer.cpp)  
target_link_libraries(testDVVideoStreamer
        PUBLIC ssl
        PUBLIC crypto
        PRIVATE liveMedia
        PRIVATE groupsock
        PRIVATE BasicUsageEnvironment
        PRIVATE UsageEnvironment
        )
target_include_directories(testDVVideoStreamer 
        PUBLIC .
        PUBLIC include
        PUBLIC UsageEnvironment/include
        PUBLIC groupsock/include
        PUBLIC liveMedia/include
        PUBLIC BasicUsageEnvironment/include)



add_executable(testWAVAudioStreamer testProgs/testWAVAudioStreamer.cpp)  
target_link_libraries(testWAVAudioStreamer
        PUBLIC ssl
        PUBLIC crypto
        PRIVATE liveMedia
        PRIVATE groupsock
        PRIVATE BasicUsageEnvironment
        PRIVATE UsageEnvironment
        )

target_include_directories(testWAVAudioStreamer 
        PUBLIC .
        PUBLIC include
        PUBLIC UsageEnvironment/include
        PUBLIC groupsock/include
        PUBLIC liveMedia/include
        PUBLIC BasicUsageEnvironment/include)

add_executable(testAMRAudioStreamer testProgs/testAMRAudioStreamer.cpp)  
target_link_libraries(testAMRAudioStreamer
        PUBLIC ssl
        PUBLIC crypto
        PRIVATE liveMedia
        PRIVATE groupsock
        PRIVATE BasicUsageEnvironment
        PRIVATE UsageEnvironment
        )
target_include_directories(testAMRAudioStreamer 
        PUBLIC .
        PUBLIC include
        PUBLIC UsageEnvironment/include
        PUBLIC groupsock/include
        PUBLIC liveMedia/include
        PUBLIC BasicUsageEnvironment/include)

add_executable(testMKVStreamer testProgs/testMKVStreamer.cpp)  
target_link_libraries(testMKVStreamer
        PUBLIC ssl
        PUBLIC crypto
        PRIVATE liveMedia
        PRIVATE groupsock
        PRIVATE BasicUsageEnvironment
        PRIVATE UsageEnvironment
        )
target_include_directories(testMKVStreamer 
        PUBLIC .
        PUBLIC include
        PUBLIC UsageEnvironment/include
        PUBLIC groupsock/include
        PUBLIC liveMedia/include
        PUBLIC BasicUsageEnvironment/include)

add_executable(testOggStreamer testProgs/testOggStreamer.cpp)  
target_link_libraries(testOggStreamer
        PUBLIC ssl
        PUBLIC crypto
        PRIVATE liveMedia
        PRIVATE groupsock
        PRIVATE BasicUsageEnvironment
        PRIVATE UsageEnvironment
        )
target_include_directories(testOggStreamer 
        PUBLIC .
        PUBLIC include
        PUBLIC UsageEnvironment/include
        PUBLIC groupsock/include
        PUBLIC liveMedia/include
        PUBLIC BasicUsageEnvironment/include)


add_executable(vobStreamer testProgs/vobStreamer.cpp)  
target_link_libraries(vobStreamer
        PUBLIC ssl
        PUBLIC crypto
        PRIVATE liveMedia
        PRIVATE groupsock
        PRIVATE BasicUsageEnvironment
        PRIVATE UsageEnvironment
        )
target_include_directories(vobStreamer 
        PUBLIC .
        PUBLIC include
        PUBLIC UsageEnvironment/include
        PUBLIC groupsock/include
        PUBLIC liveMedia/include
        PUBLIC BasicUsageEnvironment/include)

add_executable(testMP3Receiver testProgs/testMP3Receiver.cpp)  
target_link_libraries(testMP3Receiver
        PUBLIC ssl
        PUBLIC crypto
        PRIVATE liveMedia
        PRIVATE groupsock
        PRIVATE BasicUsageEnvironment
        PRIVATE UsageEnvironment
        )
target_include_directories(testMP3Receiver 
        PUBLIC .
        PUBLIC include
        PUBLIC UsageEnvironment/include
        PUBLIC groupsock/include
        PUBLIC liveMedia/include
        PUBLIC BasicUsageEnvironment/include)


add_executable(testMPEG2TransportReceiver testProgs/testMPEG2TransportReceiver.cpp)  
target_link_libraries(testMPEG2TransportReceiver
        PUBLIC ssl
        PUBLIC crypto
        PRIVATE liveMedia
        PRIVATE groupsock
        PRIVATE BasicUsageEnvironment
        PRIVATE UsageEnvironment
        )
target_include_directories(testMPEG2TransportReceiver 
        PUBLIC .
        PUBLIC include
        PUBLIC UsageEnvironment/include
        PUBLIC groupsock/include
        PUBLIC liveMedia/include
        PUBLIC BasicUsageEnvironment/include)

add_executable(sapWatch testProgs/sapWatch.cpp)  
target_link_libraries(sapWatch
        PUBLIC ssl
        PUBLIC crypto
        PRIVATE liveMedia
        PRIVATE groupsock
        PRIVATE BasicUsageEnvironment
        PRIVATE UsageEnvironment
        )
target_include_directories(sapWatch 
        PUBLIC .
        PUBLIC include
        PUBLIC UsageEnvironment/include
        PUBLIC groupsock/include
        PUBLIC liveMedia/include
        PUBLIC BasicUsageEnvironment/include)

##################################
add_executable(testRelay testProgs/testRelay.cpp)  
target_link_libraries(testRelay
        PUBLIC ssl
        PUBLIC crypto
        PRIVATE liveMedia
        PRIVATE groupsock
        PRIVATE BasicUsageEnvironment
        PRIVATE UsageEnvironment
        )
target_include_directories(testRelay 
        PUBLIC .
        PUBLIC include
        PUBLIC UsageEnvironment/include
        PUBLIC groupsock/include
        PUBLIC liveMedia/include
        PUBLIC BasicUsageEnvironment/include)
add_executable(testReplicator testProgs/testReplicator.cpp)  
target_link_libraries(testReplicator
        PUBLIC ssl
        PUBLIC crypto
        PRIVATE liveMedia
        PRIVATE groupsock
        PRIVATE BasicUsageEnvironment
        PRIVATE UsageEnvironment
        )
target_include_directories(testReplicator 
        PUBLIC .
        PUBLIC include
        PUBLIC UsageEnvironment/include
        PUBLIC groupsock/include
        PUBLIC liveMedia/include
        PUBLIC BasicUsageEnvironment/include)

add_executable(testOnDemandRTSPServer testProgs/testOnDemandRTSPServer.cpp)  
target_link_libraries(testOnDemandRTSPServer
        PUBLIC ssl
        PUBLIC crypto
        PRIVATE liveMedia
        PRIVATE groupsock
        PRIVATE BasicUsageEnvironment
        PRIVATE UsageEnvironment
        )
target_include_directories(testOnDemandRTSPServer 
        PUBLIC .
        PUBLIC include
        PUBLIC UsageEnvironment/include
        PUBLIC groupsock/include
        PUBLIC liveMedia/include
        PUBLIC BasicUsageEnvironment/include)

add_executable(testRTSPClient testProgs/testRTSPClient.cpp)  
target_link_libraries(testRTSPClient
        PUBLIC ssl
        PUBLIC crypto
        PRIVATE liveMedia
        PRIVATE groupsock
        PRIVATE BasicUsageEnvironment
        PRIVATE UsageEnvironment
        )
target_include_directories(testRTSPClient 
        PUBLIC .
        PUBLIC include
        PUBLIC UsageEnvironment/include
        PUBLIC groupsock/include
        PUBLIC liveMedia/include
        PUBLIC BasicUsageEnvironment/include)

add_executable(openRTSP 
        testProgs/openRTSP.cpp
        testProgs/playCommon.cpp)  
target_link_libraries(openRTSP
        PUBLIC ssl
        PUBLIC crypto
        PRIVATE liveMedia
        PRIVATE groupsock
        PRIVATE BasicUsageEnvironment
        PRIVATE UsageEnvironment
        )
target_include_directories(openRTSP 
        PUBLIC .
        PUBLIC include
        PUBLIC UsageEnvironment/include
        PUBLIC groupsock/include
        PUBLIC liveMedia/include
        PUBLIC BasicUsageEnvironment/include)
        
add_executable(playSIP 
        testProgs/playSIP.cpp
        testProgs/playCommon.cpp)  
target_link_libraries(playSIP
        PUBLIC ssl
        PUBLIC crypto
        PRIVATE liveMedia
        PRIVATE groupsock
        PRIVATE BasicUsageEnvironment
        PRIVATE UsageEnvironment
        )
target_include_directories(playSIP 
        PUBLIC .
        PUBLIC include
        PUBLIC UsageEnvironment/include
        PUBLIC groupsock/include
        PUBLIC liveMedia/include
        PUBLIC BasicUsageEnvironment/include)

add_executable(testH264VideoToHLSSegments 
        testProgs/testH264VideoToHLSSegments.cpp)  
target_link_libraries(testH264VideoToHLSSegments
        PUBLIC ssl
        PUBLIC crypto
        PRIVATE liveMedia
        PRIVATE groupsock
        PRIVATE BasicUsageEnvironment
        PRIVATE UsageEnvironment
        )
target_include_directories(testH264VideoToHLSSegments 
        PUBLIC .
        PUBLIC include
        PUBLIC UsageEnvironment/include
        PUBLIC groupsock/include
        PUBLIC liveMedia/include
        PUBLIC BasicUsageEnvironment/include)

add_executable(testMPEG1or2Splitter 
        testProgs/testMPEG1or2Splitter.cpp)  
target_link_libraries(testMPEG1or2Splitter
        PUBLIC ssl
        PUBLIC crypto
        PRIVATE liveMedia
        PRIVATE groupsock
        PRIVATE BasicUsageEnvironment
        PRIVATE UsageEnvironment
        )
target_include_directories(testMPEG1or2Splitter 
        PUBLIC .
        PUBLIC include
        PUBLIC UsageEnvironment/include
        PUBLIC groupsock/include
        PUBLIC liveMedia/include
        PUBLIC BasicUsageEnvironment/include)

add_executable(testMPEG1or2ProgramToTransportStream 
        testProgs/testMPEG1or2ProgramToTransportStream.cpp)  
target_link_libraries(testMPEG1or2ProgramToTransportStream
        PUBLIC ssl
        PUBLIC crypto
        PRIVATE liveMedia
        PRIVATE groupsock
        PRIVATE BasicUsageEnvironment
        PRIVATE UsageEnvironment
        )
target_include_directories(testMPEG1or2ProgramToTransportStream 
        PUBLIC .
        PUBLIC include
        PUBLIC UsageEnvironment/include
        PUBLIC groupsock/include
        PUBLIC liveMedia/include
        PUBLIC BasicUsageEnvironment/include)

add_executable(testH264VideoToTransportStream 
        testProgs/testH264VideoToTransportStream.cpp)  
target_link_libraries(testH264VideoToTransportStream
        PUBLIC ssl
        PUBLIC crypto
        PRIVATE liveMedia
        PRIVATE groupsock
        PRIVATE BasicUsageEnvironment
        PRIVATE UsageEnvironment
        )
target_include_directories(testH264VideoToTransportStream 
        PUBLIC .
        PUBLIC include
        PUBLIC UsageEnvironment/include
        PUBLIC groupsock/include
        PUBLIC liveMedia/include
        PUBLIC BasicUsageEnvironment/include)

add_executable(testH265VideoToTransportStream 
        testProgs/testH265VideoToTransportStream.cpp)  
target_link_libraries(testH265VideoToTransportStream
        PUBLIC ssl
        PUBLIC crypto
        PRIVATE liveMedia
        PRIVATE groupsock
        PRIVATE BasicUsageEnvironment
        PRIVATE UsageEnvironment
        )
target_include_directories(testH265VideoToTransportStream 
        PUBLIC .
        PUBLIC include
        PUBLIC UsageEnvironment/include
        PUBLIC groupsock/include
        PUBLIC liveMedia/include
        PUBLIC BasicUsageEnvironment/include)

add_executable(MPEG2TransportStreamIndexer 
        testProgs/MPEG2TransportStreamIndexer.cpp)  
target_link_libraries(MPEG2TransportStreamIndexer
        PUBLIC ssl
        PUBLIC crypto
        PRIVATE liveMedia
        PRIVATE groupsock
        PRIVATE BasicUsageEnvironment
        PRIVATE UsageEnvironment
        )
target_include_directories(MPEG2TransportStreamIndexer 
        PUBLIC .
        PUBLIC include
        PUBLIC UsageEnvironment/include
        PUBLIC groupsock/include
        PUBLIC liveMedia/include
        PUBLIC BasicUsageEnvironment/include)

add_executable(testMPEG2TransportStreamTrickPlay 
        testProgs/testMPEG2TransportStreamTrickPlay.cpp)  
target_link_libraries(testMPEG2TransportStreamTrickPlay
        PUBLIC ssl
        PUBLIC crypto
        PRIVATE liveMedia
        PRIVATE groupsock
        PRIVATE BasicUsageEnvironment
        PRIVATE UsageEnvironment
        )
target_include_directories(testMPEG2TransportStreamTrickPlay 
        PUBLIC .
        PUBLIC include
        PUBLIC UsageEnvironment/include
        PUBLIC groupsock/include
        PUBLIC liveMedia/include
        PUBLIC BasicUsageEnvironment/include)

add_executable(registerRTSPStream 
        testProgs/registerRTSPStream.cpp)  
target_link_libraries(registerRTSPStream
        PUBLIC ssl
        PUBLIC crypto
        PRIVATE liveMedia
        PRIVATE groupsock
        PRIVATE BasicUsageEnvironment
        PRIVATE UsageEnvironment
        )
target_include_directories(registerRTSPStream 
        PUBLIC .
        PUBLIC include
        PUBLIC UsageEnvironment/include
        PUBLIC groupsock/include
        PUBLIC liveMedia/include
        PUBLIC BasicUsageEnvironment/include)

add_executable(testMKVSplitter 
        testProgs/testMKVSplitter.cpp)  
target_link_libraries(testMKVSplitter
        PUBLIC ssl
        PUBLIC crypto
        PRIVATE liveMedia
        PRIVATE groupsock
        PRIVATE BasicUsageEnvironment
        PRIVATE UsageEnvironment
        )
target_include_directories(testMKVSplitter 
        PUBLIC .
        PUBLIC include
        PUBLIC UsageEnvironment/include
        PUBLIC groupsock/include
        PUBLIC liveMedia/include
        PUBLIC BasicUsageEnvironment/include)

add_executable(testMPEG2TransportStreamSplitter 
        testProgs/testMPEG2TransportStreamSplitter.cpp)  
target_link_libraries(testMPEG2TransportStreamSplitter
        PUBLIC ssl
        PUBLIC crypto
        PRIVATE liveMedia
        PRIVATE groupsock
        PRIVATE BasicUsageEnvironment
        PRIVATE UsageEnvironment
        )
target_include_directories(testMPEG2TransportStreamSplitter 
        PUBLIC .
        PUBLIC include
        PUBLIC UsageEnvironment/include
        PUBLIC groupsock/include
        PUBLIC liveMedia/include
        PUBLIC BasicUsageEnvironment/include)

add_executable(mikeyParse 
        testProgs/mikeyParse.cpp)  
target_link_libraries(mikeyParse
        PUBLIC ssl
        PUBLIC crypto
        PRIVATE liveMedia
        PRIVATE groupsock
        PRIVATE BasicUsageEnvironment
        PRIVATE UsageEnvironment
        )
target_include_directories(mikeyParse 
        PUBLIC .
        PUBLIC include
        PUBLIC UsageEnvironment/include
        PUBLIC groupsock/include
        PUBLIC liveMedia/include
        PUBLIC BasicUsageEnvironment/include)
