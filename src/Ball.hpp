#pragma once


#include <iostream>
#include <ctime>

#include "GameObject.hpp"
#include "Settings.hpp"
#include "Lives.hpp"


/**Destination of ball source image*/
static const char *const BALL_SRC = "examples/textures/ball.png";


class Ball : public GameObject {
public:
    Ball(SDL_Renderer *renderer, Lives *lives);

    void Init(SDL_Renderer *renderer, int platformX);

    void Update() override;

    void SlowDown() override { horSpeed = verSpeed = 3; }//TODO?

    void SpeedUP() override { horSpeed = verSpeed = 7; }

    void Collided(Direction dir) override;

    bool ToDelete() const override { return toDelete; }; //TODO Override destroy bcs of this?

private:
    bool toDelete = false;
    Lives *lives;
    int dirX = 0;
    int dirY = -1;
};
