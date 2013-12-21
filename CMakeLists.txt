cmake_minimum_required(VERSION 2.8.12)
project(SDLpp)

if(APPLE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
endif(APPLE)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -Wall")

include_directories(include)
file(GLOB sources RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
     src/*.cpp)
file(GLOB headers RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
     include/*.h)

add_library(SDLpp STATIC ${headers} ${sources})

if(APPLE)
    find_library(SDL2 SDL2)
    target_link_libraries(SDLpp ${SDL2} std++)
elseif(UNIX)
    target_link_libraries(SDLpp SDL2)
endif(APPLE)
