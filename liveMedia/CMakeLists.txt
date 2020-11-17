#This should be the first line of the CMakeLists.txt
cmake_minimum_required(VERSION 3.2)

# Poor practice, but very common
project(live555 VERSION 4.7.2)


file(GLOB USER_LIBS_FILE ./*.cpp)
file(GLOB USER_LIBS_C_FILE ./*.c)

add_library(liveMedia 
        STATIC
        ${USER_LIBS_FILE}
        ${USER_LIBS_C_FILE})

add_definitions("-Wall -g")
add_definitions("-std=c++11 -O -DSOCKLEN_T=socklen_t -g -D_LARGEFILE_SOURCE=1 -D_FILE_OFFSET_BITS=64 -Wall -DBSD=1")
#add_compile_options(-std=c++11 -O -DSOCKLEN_T=socklen_t -g -D_LARGEFILE_SOURCE=1 -D_FILE_OFFSET_BITS=64 -Wall -DBSD=1)

target_link_libraries(liveMedia
        PUBLIC ssl
        PUBLIC crypto
      )
target_include_directories(liveMedia 
        PUBLIC .
        PUBLIC include
        PUBLIC ../UsageEnvironment/include
        PUBLIC ../groupsock/include)
