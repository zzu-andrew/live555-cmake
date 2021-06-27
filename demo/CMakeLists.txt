#This should be the first line of the CMakeLists.txt
cmake_minimum_required(VERSION 3.2)

# Poor practice, but very common
project(live555 VERSION 4.7.2)


add_executable(MPEG2TransportStreamIndexer1
        MPEG2TransportStreamIndexer/MPEG2TransportStreamIndexer.cpp)
target_link_libraries(MPEG2TransportStreamIndexer1
        PUBLIC ssl
        PUBLIC crypto
        PRIVATE liveMedia
        PRIVATE groupsock
        PRIVATE BasicUsageEnvironment
        PRIVATE UsageEnvironment
        )
target_include_directories(MPEG2TransportStreamIndexer1
        PUBLIC .
        PUBLIC include
        PUBLIC ${PROJECT_SOURCE_DIR}/../UsageEnvironment/include
        PUBLIC ${PROJECT_SOURCE_DIR}/../groupsock/include
        PUBLIC ${PROJECT_SOURCE_DIR}/../liveMedia/include
        PUBLIC ${PROJECT_SOURCE_DIR}/../BasicUsageEnvironment/include)


add_executable(typeid_test basic/typeid_test.cpp)