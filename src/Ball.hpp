#pragma once


#include "GameObject.hpp"
#include "Settings.hpp"

class Ball : public GameObject {
public:
    Ball(const char *textureDest, SDL_Renderer *renderer);

    void Update() override;
//todo: add spacebar activation
};




