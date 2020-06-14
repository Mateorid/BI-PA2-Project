#include "Ball.hpp"

Ball::Ball(SDL_Renderer *renderer, ScoreManager *score) {
    this->score = score;
    type = BALL;
    objRenderer = renderer;
    speed = BALL_SPEED;
    destR.x = destR.y = 1000;
    LoadTexture(BALL_SRC);
    active = false;
}

void Ball::Init(int platformX) {
    if (!active) {
        /**Sets destination*/
        destR.x = (platformX + (PLATFORM_W / 2) - (BALL_SIZE / 2));
        destR.y = GAME_HEIGHT - PLATFORM_H - 50 - 1;
        destR.h = destR.w = BALL_SIZE;
        /**Random direction*/
        srand(time(nullptr));
        dirX = (std::rand() % 2) ? -1 : 1;

        dirY = -1;
        active = true;
    }
}

void Ball::Update() {
    /**Border control*/
    if (active) {
        destR.x += (dirX * speed);
        destR.y += (dirY * speed);
        if (destR.x <= 0)
            dirX *= -1;
        if (destR.x >= GAME_WIDTH - BALL_SIZE)
            dirX *= -1;
        if (destR.y <= 0)
            dirY *= -1;
        if (destR.y >= GAME_HEIGHT - BALL_SIZE) {
            std::cout << "Lost life" << std::endl;    //todo Add second ball check
            score->LoseLife();
            active = false;
        }
    }
}

bool Ball::CollisionDetection(GameObject *object) {
    //Inspired by this article: https://happycoding.io/tutorials/processing/collision-detection
    collision = false;
    int x = object->GetX();
    int y = object->GetY();
    int otherX = object->GetX() + object->GetW();
    int otherY = object->GetY() + object->GetH();
    /**Horizontal collision*/
    if (destR.x + destR.w + (dirX * speed) > x &&
        destR.x + (dirX * speed) < otherX &&
        destR.y + destR.h > y &&
        destR.y < otherY) {
        dirX *= -1;
        collision = true;
    }
    /**Vertical collision*/
    if (destR.x + destR.w > x &&
        destR.x < otherX &&
        destR.y + destR.h + (dirY * speed) > y &&
        destR.y + (dirY * speed) < otherY) {
        dirY *= -1;
        collision = true;
    }
    return collision;
}
