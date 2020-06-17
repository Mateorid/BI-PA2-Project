#pragma once


#include "GameObject.hpp"
#include "ScoreManager.hpp"
#include "Ball.hpp"


/**Destination of bonus source image*/
static const char *const BONUS_SRC = "examples/textures/bonus.png";
/**Bonus settings*/
static const int BONUS_SPEED = 3;
static const int BONUS_SIZE = 25;
/**Number of bonuses*/
static const int BONUS_TYPES = 7;
/**Amount of score for EXTRA_SCORE bonus*/
static const int SCORE_BONUS = 1000;
/**Bonus types*/
enum BonusType {
    PLUS_LIFE, SECOND_BALL, SLOW_PLAT, SLOW_BALL, FAST_PLAT, FAST_BALL, EXTRA_SCORE
};


class Ball;

class ScoreManager;


class Bonus : public GameObject {
public:
    Bonus(SDL_Renderer *renderer, Ball &b1, Ball &b2, GameObject &plat, ScoreManager &score);

    ~Bonus() override;

    void Update() override;

    void SpawnBonus(int x, int y);

    void Collided(bool activate) override;

    void Render() override;

private:

    void Init(int x, int y);

    void SetBonusType(int x);

    void ApplyBonus();

    void SecondBall();

    BonusType bonusType{};
    Ball *ball1{};
    Ball *ball2{};
    GameObject *platform{};
    ScoreManager *score{};
};




