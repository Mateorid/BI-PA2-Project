#pragma once


#include "GameObject.hpp"
#include "Settings.hpp"

class Bonus : public GameObject {
public:
    Bonus(SDL_Renderer *renderer, int x, int y);

    void Update() override;

    void Init(int x, int y);

    BonusType GetBonusType() const override { return bonusType; }

    void Render() override;

private:
    BonusType bonusType;
};




