#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

class Game {
public:
    Game() = default;

    ~Game() = default;

    void initialize(const char *title, int xPos, int yPos, int width, int height, bool fullscreen);

    void handleEvents();

    void updateAll();

    void renderAll();

    void cleanAll();

    bool running() { return isRunning; }

private:
    bool isRunning;
    SDL_Window *MainWindow;
    SDL_Renderer *MainRenderer;

};
