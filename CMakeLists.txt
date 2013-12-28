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


add_executable(window ${CMAKE_CURRENT_SOURCE_DIR}/examples/window/Main.cpp)
target_link_libraries(window SDLpp)

add_executable(text ${CMAKE_CURRENT_SOURCE_DIR}/examples/text/Main.cpp)
target_link_libraries(text SDLpp)

add_executable(sprite ${CMAKE_CURRENT_SOURCE_DIR}/examples/sprite/Main.cpp)
target_link_libraries(sprite SDLpp)

add_executable(offscreen_drawing ${CMAKE_CURRENT_SOURCE_DIR}/examples/offscreen_drawing/Main.cpp)
target_link_libraries(offscreen_drawing SDLpp)
