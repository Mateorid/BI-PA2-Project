#pragma once

#include <SDL2/SDL.h>

#include "Application.hpp"

/**Game title*/
static const char *const GAME_NAME = "Arkanoid 2020";
/**Game window height*/
static const int APP_HEIGHT = 800;  //currently fixed on 800
/**Game window width*/
static const int APP_WIDTH = (3 * APP_HEIGHT) / 4;
/**Files destination*/
static const char *FONT_SRC = "examples/Gamer.ttf";
static const char *MAP1_SRC = "examples/map1.map";
static const char *MAP2_SRC = "examples/map2.map";
static const char *MAP3_SRC = "examples/map3.map";
/**How many lives you start with*/
static const int START_LIVES = 1;


class Application;

class State {
public:
    virtual void Initialize(Application &) {};

    virtual void HandleEvents(Application &) {};

    virtual void Update(Application &) {};

    virtual void Render(Application &) {};

    virtual void Clean(Application &) {};
protected:
};




