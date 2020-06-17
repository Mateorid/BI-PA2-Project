cmake_minimum_required(VERSION 3.16)
project(Arkanoid)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
#find_package(SDL2_mixer REQUIRED)
#find_package(SDL2_net REQUIRED)
find_package(SDL2_ttf REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS})
include_directories(${SDL2_IMAGE_INCLUDE_DIRS})
include_directories(${SDL2_MIXER_INCLUDE_DIRS})
include_directories(${SDL2_NET_INCLUDE_DIRS})
include_directories(${SDL2_TTF_INCLUDE_DIRS})

include_directories(src)
include_directories(examples)

add_executable(Arkanoid
        src/Ball.cpp                src/Ball.hpp
        src/Block.cpp               src/Block.hpp
        src/Bonus.cpp               src/Bonus.hpp
        src/GameObject.cpp          src/GameObject.hpp
        src/main.cpp
        src/MapLoader.cpp           src/MapLoader.hpp
        src/Platform.cpp            src/Platform.hpp
        src/ScoreManager.cpp        src/ScoreManager.hpp
        src/TextPrinter.cpp         src/TextPrinter.hpp
        src/State.cpp               src/State.hpp
        src/StateManager.cpp        src/StateManager.hpp
        src/StartupState.cpp        src/StartupState.hpp
        src/MenuState.cpp           src/MenuState.hpp
        src/ExitState.cpp           src/ExitState.hpp
        src/GameState.cpp           src/GameState.hpp
        src/LoadState.cpp           src/LoadState.hpp
        src/VictoryState.cpp        src/VictoryState.hpp)
target_link_libraries(Arkanoid ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES} ${SDL2_TTF_LIBRARIES})