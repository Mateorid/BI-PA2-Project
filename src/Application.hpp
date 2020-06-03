#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>


class Application {
public:

    Application();

    ~Application() = default;

    void Initialise();

private:
    void LoadMap();

    void CleanAll();
};




