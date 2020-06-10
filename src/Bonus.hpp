#pragma once


#include "GameObject.hpp"
#include "Settings.hpp"
#include "Ball.hpp"
#include "Platform.hpp"


/**Destination of bonus source image*/
static const char *const BONUS_SRC = "examples/textures/bonus.png";
/**Bonus falling speed*/
static const int BONUS_SPEED = 3;


class Bonus : public GameObject {
public:
    Bonus(SDL_Renderer *renderer, Ball &b1, Platform &plat, Lives &hp);

    void Update() override;

    void Init(int x, int y);

    void Collided(bool activate) override;

    void Render() override;

    bool ToDelete() const override { return toDelete; };

private:
    void SetBonusType(int x);

    void ApplyBonus();

    bool toDelete = false;
    BonusType bonusType{};
    Ball *ball1{};
//    Ball *ball2{};//TODO 2nd ball check
    Platform *platform{};
    Lives *lives{};
};




