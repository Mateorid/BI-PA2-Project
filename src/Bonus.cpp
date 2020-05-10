#include "Bonus.hpp"

Bonus::Bonus(SDL_Renderer *renderer, int x, int y) {
    type = BONUS;
    objRenderer = renderer;
    objTexture = IMG_LoadTexture(renderer, BLOCK_SRC); //todo create textures for bonus
    verSpeed = 2;
    Init(x, y);
    active = true;
}

void Bonus::Init(int x, int y) {
    /**Random bonus type*/
    srand(time(nullptr));
    int tmp = std::rand() % 6;
    switch (tmp) {
        case 0:
            bonusType = PLUS_LIFE;
            break;
        case 1:
            bonusType = SECOND_BALL;
            break;
        case 2:
            bonusType = SLOW_PLAT;
            break;
        case 3:
            bonusType = SLOW_BALL;
            break;
        case 4:
            bonusType = FAST_PLAT;
            break;
        case 5:
            bonusType = FAST_BALL;
            break;
        default:
            break;
    }
    destR.x = x;
    destR.y = y;
    destR.h = 25; //TODO: tmp solution
    destR.w = 25;
    //TODO set srcR according to bonusType
}

void Bonus::Update() {
    if (destR.y < GAME_HEIGHT - 5) {
        destR.y += verSpeed;
        return;
    }
    active = false;
}
