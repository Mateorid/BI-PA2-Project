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
    Bonus(SDL_Renderer *renderer, int x, int y);

    void Update() override;

    void Init(int x, int y);

    void Collided(Direction dir) override;

    void Render() override;

    BonusType GetBonusType() const { return bonusType; } //todo un-override?

private:
    void SetBonusType(int x);

    BonusType bonusType;
    Ball *ball1{};
//    Ball *ball2{};//TODO 2nd ball check
    Platform *platform{};
    Lives *lives{};
};




