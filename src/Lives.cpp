#include "Lives.hpp"

Lives::Lives(int x) {
    lives = x;
}

void Lives::Init(GameObject &plat, GameObject &b1) {
    platform = &plat;
    ball = &b1;
}

void Lives::AddLife() { lives++; }

void Lives::LoseLife() {
    lives--;
    platform->ResetSpeed();
    ball->ResetSpeed();
}
