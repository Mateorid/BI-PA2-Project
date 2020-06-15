#pragma once


#include "GameObject.hpp"
#include "Settings.hpp"
#include "ScoreManager.hpp"
#include "Ball.hpp"


/**Destination of bonus source image*/
static const char *const BONUS_SRC = "examples/textures/bonus.png";
/**Bonus falling speed*/
static const int BONUS_SPEED = 3;
/**Number of bonuses*/
static const int BONUS_TYPES = 7;
/**Amount of score for EXTRA_SCORE bonus*/
static const int SCORE_BONUS = 1000;

class Bonus : public GameObject {
public:
    Bonus(SDL_Renderer *renderer, Ball &b1, Ball &b2, GameObject &plat, ScoreManager &score);

    void Update() override;

    void SpawnBonus(int x, int y);

    void Collided(bool activate) override;

    void Render() override;

    bool ToDelete() const override { return toDelete; };

private:

    void Init(int x, int y);

    void SetBonusType(int x);

    void ApplyBonus();

    void SecondBall();

    bool toDelete = false;
    BonusType bonusType{};
    Ball *ball1{};
    Ball *ball2{};
    GameObject *platform{};
    ScoreManager *score{};
};




