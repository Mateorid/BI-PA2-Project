cmake_minimum_required(VERSION 3.16)
project(WoT)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
#find_package(SDL2_image REQUIRED)
#find_package(SDL2_mixer REQUIRED)
#find_package(SDL2_net REQUIRED)
#find_package(SDL2_ttf REQUIRED)
#find_package(SDL2_gfx REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
#include_directories(${SDL2_IMAGE_INCLUDE_DIRS})
#include_directories(${SDL2_MIXER_INCLUDE_DIRS})
#include_directories(${SDL2_NET_INCLUDE_DIRS})
#include_directories(${SDL2_TTF_INCLUDE_DIRS})
#include_directories(${SDL2_GFX_INCLUDE_DIRS})

add_executable(WoT src/main.cpp src/Game.cpp src/Game.hpp src/TextureLoader.hpp src/TextureLoader.cpp src/Settings.hpp src/GameObject.hpp src/GameObject.cpp)

#target_link_libraries(WoT ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} ${SDL2_MIXER_LIBRARIES} ${SDL2_NET_LIBRARIES} ${SDL2_TTF_LIBRARIES})


target_link_libraries(WoT ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})