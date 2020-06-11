#pragma once

#include "Settings.hpp"
#include "GameObject.hpp"

class Lives {
public:
    explicit Lives(int x);

    void Init(GameObject &plat, GameObject &b1);

    void AddLife();

    void LoseLife();

    int GetLives() const { return lives; }

private:
    int lives;
    GameObject * platform{};
    GameObject* ball{};
//    GameObject* ball2; //TODO
};