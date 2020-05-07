#pragma once


#include "GameObject.hpp"
#include "Settings.hpp"
#include "iostream"
#include <ctime>

class Ball : public GameObject {
public:
    Ball(const char * ID, const char *textureDest, SDL_Renderer *renderer);

    void Init(SDL_Renderer *renderer, int platformX);

    void Update() override;

    void CollisionDetector();

private:
    int dirX = 0;
    int dirY = -1;
};




