#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>

#include "Game.hpp"
#include "MapLoader.hpp"
#include "GameObject.hpp"


/**Title of the game*/
static const char *const GAME_NAME = "Arkanoid 2.0";
///**Game window width*/
//static const int GAME_WIDTH = 600;
///**Game window height*/
//static const int GAME_HEIGHT = 800;
/**Start game in fullscreen*/
static const bool START_FULLSCREEN = false;
/**Destination of map source*/
static const char *const MAP_SRC = "examples/map";


class Application {
public:

    Application();

    ~Application() = default;

    void Initialize(const char *title, int xPos, int yPos, int width, int height, bool fullscreen);

    int Start();

private:
    void LoadMap();

    void CleanAll();

    SDL_Window *mainWindow{};
    SDL_Renderer *mainRenderer{};
    std::vector<GameObject *> gameObjects;
    Game *game{};
    MapLoader *mapLoader{};

};




