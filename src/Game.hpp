#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>

#include "Settings.hpp"
#include "GameObject.hpp"
#include "Platform.hpp"
#include "Ball.hpp"
#include "Lives.hpp"
#include "Block.hpp"
#include "Map.hpp"
#include "Bonus.hpp"


class Game {
public:
    /**
     * @throws std::runtime_error if SDL failed to initialise
     */
    Game();

    ~Game() = default;


    int Initialize(const char *title, int xPos, int yPos, int width, int height, bool fullscreen);

    int Play();

    void HandleEvents();

    void Collisions();

    void UpdateAll();

    void RenderAll();

    void CleanAll();

private:
    std::vector<GameObject *> gameObjects;//TODO: remove by using swap and pop_back(https://gamedev.stackexchange.com/questions/33888/what-is-the-most-efficient-container-to-store-dynamic-game-objects-in)
    Platform *platform{};
    Ball *ball{};
    Lives *lives{};
    Map *gameMap{};
    bool isRunning = false;
    Uint32 frameTicks{};
    Uint32 frameDelta{};
    SDL_Window *mainWindow{};
    SDL_Renderer *mainRenderer{};
};
