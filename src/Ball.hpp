#pragma once


#include "GameObject.hpp"
#include "ScoreManager.hpp"
#include "Platform.hpp"


/**Destination of ball source image*/
static const char *const BALL_SRC = "examples/textures/ball.png";
/**Ball speeds*/
static const int BALL_SPEED = 5;
static const int BALL_SLOW = 3;
static const int BALL_FAST = 7;
/**Game object sizes*/
static const int BALL_SIZE = 20;


class ScoreManager;

/**Ball class*/
class Ball : public GameObject {
public:
    /**
     * Constructor
     * @param renderer
     * @param score ScoreManger pointer
     */
    Ball(SDL_Renderer *renderer, ScoreManager *score);

    /**
     * Launches ball from platform at X position
     * @param platformX
     */
    void Init(int platformX);

    /**Moves ball*/
    void Update() override;

    /**Bonus action*/
    void SlowDown() override { speed = BALL_SLOW; }

    /**Bonus action*/
    void SpeedUP() override { speed = BALL_FAST; }

    /**Resets speed*/
    void ResetSpeed() override { speed = BALL_SPEED; }

    bool CollisionDetection(GameObject *object) override;

private:
    bool collision = false;
    ScoreManager *score;
    /**Movement directions*/
    int dirX = 1;
    int dirY = -1;
};
