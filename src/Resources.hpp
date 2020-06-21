#pragma once

#include <SDL2/SDL.h>
#include <SDL_ttf.h>
#include <vector>

#include "ScoreManager.hpp"
#include "TextPrinter.hpp"
#include "GameObject.hpp"
#include "Platform.hpp"
#include "Ball.hpp"
#include "Bonus.hpp"

class Platform;

class Ball;

class Bonus;


class Resources {
public:
    TextPrinter textPrinter{};
    ScoreManager *score{};
    Platform *platform{};
    Ball *ball1{};
    Ball *ball2{};
    Bonus *bonus{};
    std::vector<GameObject *> gameObjects;
    SDL_Renderer *mainRenderer{};
    SDL_Window *mainWindow{};
    TTF_Font *font{};
    bool won = false;

};




