#pragma once


#include "GameObject.hpp"
#include "Settings.hpp"
#include "ScoreManager.hpp"


/**Destination of bonus source image*/
static const char *const BONUS_SRC = "examples/textures/bonus.png";
/**Bonus falling speed*/
static const int BONUS_SPEED = 3;


class Bonus : public GameObject {
public:
    Bonus(SDL_Renderer *renderer, GameObject &b1, GameObject &plat, ScoreManager &score);

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
    GameObject *ball1{};
//    GameObject *ball2{};//TODO 2nd ball check
    GameObject *platform{};
    ScoreManager *score{};
};




