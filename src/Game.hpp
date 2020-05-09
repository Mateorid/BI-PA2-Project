#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>

#include "Game.hpp"
#include "Settings.hpp"
#include "GameObject.hpp"
#include "Platform.hpp"
#include "Ball.hpp"
#include "Lives.hpp"
#include "Block.hpp"


class Game {
public:
    Game();

    ~Game() = default;


    int initialize(const char *title, int xPos, int yPos, int width, int height, bool fullscreen);

    int play();

    void handleEvents();

    void Collisions();

    void updateAll();

    void renderAll();

    void cleanAll();

private:
    std::vector<GameObject *> gameObjects;//TODO: remove by using swap and pop_back(https://gamedev.stackexchange.com/questions/33888/what-is-the-most-efficient-container-to-store-dynamic-game-objects-in)
    Platform *platform{};
    Ball *ball{};
    Lives *lives{};
    Block *block{};
    Block *block2{};
    Block *block3{};
    const Uint32 frameDelay = 1000 / MAX_FPS;
    Uint32 frameTicks{};
    Uint32 frameDelta{};
    bool isRunning{};
    SDL_Window *MainWindow{};
    SDL_Renderer *MainRenderer{};
};
