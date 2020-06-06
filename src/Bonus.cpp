#include "Bonus.hpp"

Bonus::Bonus(SDL_Renderer *renderer, int x, int y) {
    type = BONUS;
    objRenderer = renderer;
    objTexture = IMG_LoadTexture(renderer, BONUS_SRC);
    verSpeed = BONUS_SPEED;
    Init(x, y);
    active = true;
}

void Bonus::Init(int x, int y) {
    /**Random bonus type*/
    srand(time(nullptr));
    int tmp = std::rand() % 6;
    SetBonusType(tmp);
    destR.x = x;
    destR.y = y;
    destR.h = destR.w = BONUS_SIZE;
    srcR.w = srcR.h = 100;
    srcR.y = 0;
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
        destR.y += verSpeed;
        return;
    }
    active = false;
}

void Bonus::Collided(Direction dir) {
    if (dir == NONE)
        return;
    std::cout << "BONUS PICKUP!" << std::endl;
    //todo here
}

void Bonus::Render() {
    SDL_RenderCopy(objRenderer, objTexture, &srcR, &destR);
}
