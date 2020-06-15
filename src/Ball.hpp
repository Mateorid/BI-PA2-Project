#pragma once


#include <iostream>
#include <ctime>

#include "GameObject.hpp"
#include "Settings.hpp"
#include "ScoreManager.hpp"


/**Destination of ball1 source image*/
static const char *const BALL_SRC = "examples/textures/ball.png";
static const int BALL_SPEED = 5;


class Ball : public GameObject {
public:
    Ball(SDL_Renderer *renderer, ScoreManager *score);

    void Init(int platformX);

    void Update() override;

    void SlowDown() override { speed = 3; }

    void SpeedUP() override { speed = 7; }

    void ResetSpeed() override { speed = BALL_SPEED; }

    bool CollisionDetection(GameObject *object) override;

    bool ToDelete() const override { return toDelete; }; //TODO Override destroy bcs of this?

private:
    bool toDelete = false;
    bool collision = false;
    ScoreManager *score;
    int dirX = 1;
    int dirY = -1;
};
