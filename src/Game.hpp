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


/**Game FPS limit*/
static const int MAX_FPS = 100;
/**Frame delay*/
static const int FRAME_DELAY = 1000 / MAX_FPS;
/**How many lives you start with*/
static const int START_LIVES = 3;


class Game {
public:
    /**
     * @throws std::runtime_error if SDL fails to initialise
     */
    Game() = default;

    explicit Game(std::vector<GameObject *> obj, SDL_Renderer *renderer);

    ~Game() = default;


    void Initialize();

    int Play();

    void HandleEvents();

    void Collisions();

    void UpdateAll();

    void SpawnBonus(int x, int y);

    void RenderAll();

    void CleanAll();

private:
    std::vector<GameObject *> gameObjects;
    Platform *platform{};
    Ball *ball{};
    Lives *lives{};
    Bonus *bonus{};
    bool isRunning = false;
    int toWin = 0;
    Uint32 frameTicks{};
    Uint32 frameDelta{};
    SDL_Renderer *mainRenderer{};
};
