#pragma once


#include <iostream>
#include <ctime>

#include "GameObject.hpp"
#include "ScoreManager.hpp"
#include "Platform.hpp"


/**Destination of ball source image*/
static const char *const BALL_SRC = "examples/textures/ball.png";
/**Ball settings*/
static const int BALL_SPEED = 5;
static const int BALL_SIZE = 20;

class ScoreManager;

class Ball : public GameObject {
public:
    Ball(SDL_Renderer *renderer, ScoreManager *score);

    void Init(int platformX);

    void Update() override;

    void SlowDown() override { speed = 3; }

    void SpeedUP() override { speed = 7; }

    void ResetSpeed() override { speed = BALL_SPEED; }

    bool CollisionDetection(GameObject *object) override;

private:
    bool collision = false;
    ScoreManager *score;
    int dirX = 1;
    int dirY = -1;
};
