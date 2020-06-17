#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "StateManager.hpp"

/**Title of the game*/
static const char *const GAME_NAME = "Arkanoid 2020";
/**Game window width*/
static const int APP_WIDTH = 600;
/**Game window height*/
static const int APP_HEIGHT = 800;
/**Files destination*/
static const char *const FONT_SRC = "examples/Gamer.ttf";
static const char *const MAP1_SRC = "examples/map1.map";
static const char *const MAP2_SRC = "examples/map2.map";
static const char *const MAP3_SRC = "examples/map3.map";
/**Game FPS limit*/
static const int MAX_FPS = 100;
/**Frame delay*/
static const int FRAME_DELAY = 1000 / MAX_FPS;
/**How many lives you start with*/
static const int START_LIVES = 1;


class StateManager;

class State {
public:
    virtual void Initialize(StateManager &) {};

    virtual void HandleEvents(StateManager &) {};

    virtual void Update(StateManager &) {};

    virtual void Render(StateManager &) {};

    virtual void Clean(StateManager &) {};
protected:
    TTF_Font *font{};
//    bool isRunning = false; //todo use this in the loop? + init it where its needed (menu & game)
};




