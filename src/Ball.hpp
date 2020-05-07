#pragma once


#include "GameObject.hpp"
#include "Settings.hpp"
#include "Lives.hpp"
#include <iostream>
#include <ctime>

class Ball : public GameObject {
public:
    Ball(const char *ID, const char *textureDest, SDL_Renderer *renderer, Lives *lives);

    void Init(SDL_Renderer *renderer, int platformX);

    void Update() override;

    void Collided(Direction dir) override;

private:
    Lives *lives;
    int dirX = 0;
    int dirY = -1;
};
