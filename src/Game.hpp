#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <iostream>
#include <vector>

#include "GameObject.hpp"
#include "Platform.hpp"
#include "Ball.hpp"
#include "Block.hpp"
#include "Bonus.hpp"
#include "ScoreManager.hpp"


/**Game FPS limit*/
static const int MAX_FPS = 100;
/**Frame delay*/
static const int FRAME_DELAY = 1000 / MAX_FPS;
/**How many score you start with*/
static const int START_LIVES = 3;

class Platform;

class Ball;

class Block;

class Bonus;

class Game {
public:
    /**
     * @throws std::runtime_error if SDL fails to initialise
     */
    Game() = default;

    explicit Game(std::vector<GameObject *> obj, SDL_Renderer *renderer);

    ~Game();


    int Play();


private:
    void Initialize();

    void HandleEvents();

    void Collisions();

    void UpdateAll();

    void RenderAll();

    void Victory();

    void Defeat();

    std::vector<GameObject *> gameObjects;
    Platform *platform{};
    Ball *ball1{};
    Ball *ball2{};
    Bonus *bonus{};
    ScoreManager *score{};
    bool isRunning = false;
    bool isPaused = false;
    int toWin = 0;
    Uint32 frameTicks{};
    Uint32 frameDelta{};
    SDL_Renderer *mainRenderer{};
};
