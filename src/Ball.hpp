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

    void Init(int platformX);

    void Update() override;

    void SlowDown() override { speed = 3; }//TODO?

    void SpeedUP() override { speed = 7; }

    bool CollisionDetection(GameObject *object) override;

    bool ToDelete() const override { return toDelete; }; //TODO Override destroy bcs of this?

private:
    bool toDelete = false;
    Lives *lives;
    int dirX = 1;
    int dirY = -1;
};
