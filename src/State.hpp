#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "StateManager.hpp"

/**Title of the game*/
static const char *const GAME_NAME = "Arkanoid 2020";
/**Game window width*/
static const int APP_WIDTH = 600;
/**Game window height*/
static const int APP_HEIGHT = 800;

class StateManager;

class State {
public:
    virtual void Initialize(StateManager &) {};

    virtual void HandleEvents(StateManager &) {};

    virtual void Update(StateManager &) {};

    virtual void Render(StateManager &) {};

    virtual void Clean(StateManager &) {};
protected:
    bool isRunning = false; //todo use this in the loop? + init it where its needed (menu & game)
};




