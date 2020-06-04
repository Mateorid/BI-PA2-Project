#include "Ball.hpp"

Ball::Ball(SDL_Renderer *renderer, Lives *lives) {
    this->lives = lives;
    objTexture = IMG_LoadTexture(renderer, BALL_SRC);
    verSpeed = 5;
    horSpeed = 5;
    destR.x = 1;
    destR.y = 1;
    active = false;
}

void Ball::Init(SDL_Renderer *renderer, int platformX) {
    if (!active) {
        objRenderer = renderer;
        /**Sets destination*/
        destR.x = (platformX + (PLATFORM_W / 2) - (BALL_SIZE / 2));
        destR.y = GAME_HEIGHT - PLATFORM_H - 50 - 1;
        destR.h = destR.w = BALL_SIZE;
        /**Random direction*/
        srand(time(nullptr));
        dirX = (std::rand() % 2) ? -1 : 1;

        active = true;
    }
}

void Ball::Update() {
    /**Border control*/
    if (active) {
        destR.x += (dirX * verSpeed);
        destR.y += (dirY * horSpeed);
        if (destR.x <= 0)
            dirX *= -1;
        if (destR.x >= GAME_WIDTH - BALL_SIZE)
            dirX *= -1;
        if (destR.y <= 0)
            dirY *= -1;
        if (destR.y >= GAME_HEIGHT - BALL_SIZE) {
            std::cout << "Lost life" << std::endl;    //todo
            lives->LoseLife();
            active = false;
        }
    }
}

bool Ball::Collided(Direction dir) {
    if (dir == NONE)
        return false;
    if (dir == TOP || dir == BOT) {
        dirY *= -1;
        return true;
    } else {
        dirX *= -1;
        return true;
    }
}
