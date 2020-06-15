#include "Bonus.hpp"

Bonus::Bonus(SDL_Renderer *renderer, Ball &b1, Ball &b2, GameObject &plat, ScoreManager &score) {
    type = BONUS;
    objRenderer = renderer;
    ball1 = &b1;
    ball2 = &b2;
    platform = &plat;
    this->score = &score;
    LoadTexture(BONUS_SRC);
    speed = BONUS_SPEED;
}

void Bonus::SpawnBonus(int x, int y) {
    bool tmp1 = (rand() & 1);   //25% chance of spawning a bonus
    bool tmp2 = (rand() & 1);
    if (tmp1 & tmp2)
        Init(x, y);
}

void Bonus::Init(int x, int y) {
    if (!active) {
        srand(time(nullptr));//Set's a random bonus
        int tmp = std::rand() % BONUS_TYPES;
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
            score->AddLife();
            break;
        case SECOND_BALL:
            SecondBall();
            break;
        case SLOW_PLAT:
            platform->SlowDown();
            break;
        case SLOW_BALL:
            ball1->SlowDown();
            ball2->SlowDown();
            break;
        case FAST_PLAT:
            platform->SpeedUP();
            break;
        case FAST_BALL:
            ball1->SpeedUP();
            ball2->SpeedUP();
            break;
    }
}

void Bonus::Render() {
    SDL_RenderCopy(objRenderer, objTexture, &srcR, &destR);
}

void Bonus::SecondBall() {
    if (!ball1->IsActive())
        ball1->Init(platform->GetX());
    else if (!ball2->IsActive())
        ball2->Init(platform->GetX());
}
