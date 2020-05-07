#pragma once

#include "Settings.hpp"

class Lives {
public:
    explicit Lives(int x) : lives(x) {};

    void AddLife() { lives++; }

    void LoseLife() { lives--; }

    int GetLives() const { return lives; }

private:
    int lives;
};