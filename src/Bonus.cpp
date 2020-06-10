#include "Bonus.hpp"

Bonus::Bonus(SDL_Renderer *renderer, Ball &b1, Platform &plat, Lives &hp) { //todo remove  x & y from here
    type = BONUS;
    objRenderer = renderer;
    ball1 = &b1;
    platform = &plat;
    lives = &hp;
    objTexture = IMG_LoadTexture(renderer, BONUS_SRC);
    speed = BONUS_SPEED;
}

void Bonus::Init(int x, int y) {
    if (!active) {
        /**Random bonus type*/
        srand(time(nullptr));
        int tmp = std::rand() % 6;
        SetBonusType(tmp);
        destR.x = x;
        destR.y = y;
        destR.h = destR.w = BONUS_SIZE;
        srcR.w = srcR.h = 100;
        srcR.y = 0;
        active = true;
    }
}

void Bonus::SetBonusType(int x) {
    switch (x) {
        case 0:
            bonusType = PLUS_LIFE;
            srcR.x = 100;
            break;
        case 1:
            bonusType = SECOND_BALL;
            srcR.x = 0;
            break;
        case 2:
            bonusType = SLOW_PLAT;
            srcR.x = 400;
            break;
        case 3:
            bonusType = SLOW_BALL;
            srcR.x = 300;
            break;
        case 4:
            bonusType = FAST_PLAT;
            srcR.x = 200;
            break;
        case 5:
            bonusType = FAST_BALL;
            srcR.x = 500;
            break;
        default:
            break;
    }
}

void Bonus::Update() {
    if (destR.y < GAME_HEIGHT) {
        destR.y += speed;
        return;
    }
    active = false;
}

void Bonus::Collided(bool activate) {
    if (activate) {
        ApplyBonus();
        active = false;
    }
}

void Bonus::ApplyBonus() {
    switch (bonusType) {
        case PLUS_LIFE:
            lives->AddLife();
            break;
        case SECOND_BALL:
            //todo
            break;
        case SLOW_PLAT:
            platform->SlowDown();
            break;
        case SLOW_BALL:
            ball1->SlowDown();
            break;
        case FAST_PLAT:
            platform->SpeedUP();
            break;
        case FAST_BALL:
            ball1->SpeedUP();
            break;
    }
}

void Bonus::Render() {
    SDL_RenderCopy(objRenderer, objTexture, &srcR, &destR);
}
