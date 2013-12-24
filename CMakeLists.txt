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

# add_library(SDLpp STATIC ${headers} ${sources})
add_library(SDLpp SHARED ${headers} ${sources})

if(APPLE)
    find_library(SDL2 SDL2)
    find_library(SDL2_ttf SDL2_ttf)
    find_library(SDL2_image SDL2_image)
    target_link_libraries(SDLpp ${SDL2} ${SDL2_ttf} ${SDL2_image} std++)
elseif(UNIX)
    target_link_libraries(SDLpp SDL2 SDL2_ttf SDL2_image)
endif(APPLE)
