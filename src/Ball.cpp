#include "Ball.hpp"

Ball::Ball(SDL_Renderer *renderer, Lives *lives) {
    this->lives = lives;
    type = BALL;
    objTexture = IMG_LoadTexture(renderer, BALL_SRC);
    speed = BALL_SPEED;
    destR.x = destR.y = 1;
    active = false;
    objRenderer = renderer;
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
            lives->LoseLife();
            active = false;
        }
    }
}

/**
bool Ball::CollisionDetection(GameObject *object) {
    if (bouncingRectX + bouncingRectWidth + bouncingRectSpeedX > centerRectX &&
        bouncingRectX + bouncingRectSpeedX < centerRectX + centerRectWidth &&
        bouncingRectY + bouncingRectHeight > centerRectY &&
        bouncingRectY < centerRectY + centerRectHeight) {
        bouncingRectSpeedX *= -1;
    }
        //bounce off left and right edges of screen
    else if(bouncingRectX < 0 || bouncingRectX + bouncingRectWidth > width){
        bouncingRectSpeedX *= -1;
    }

    //if I keep moving in my current Y direction, will I collide with the center rectangle?
    if (bouncingRectX + bouncingRectWidth > centerRectX &&
        bouncingRectX < centerRectX + centerRectWidth &&
        bouncingRectY + bouncingRectHeight + bouncingRectSpeedY > centerRectY &&
        bouncingRectY + bouncingRectSpeedY < centerRectY + centerRectHeight) {
        bouncingRectSpeedY *= -1;
    }
}*/



bool Ball::CollisionDetection(GameObject *object) {
    collision = false;
    int x = object->GetX();
    int y = object->GetY();
    int otherX = object->GetX() + object->GetW();
    int otherY = object->GetY() + object->GetH();
    /**Vertical collision*/
    if (destR.x >= x && destR.x + destR.w <= otherX) {
        if (destR.y + destR.h >= y && destR.y < y) {
            destR.y = y - destR.h - 1;
            dirY *= -1;
            collision = true;
        } else if (destR.y <= otherY && destR.y + destR.h > otherY) {
            destR.y = otherY + 1;
            dirY *= -1;
            collision = true;
        }
        /**Horizontal collision*/
    }
    if (destR.y <= otherY && destR.y + destR.h >= y) {
        if (destR.x + destR.w >= x && destR.x <= x) {
            destR.x = x - destR.w - 1;
            dirX *= -1;
            collision = true;
        } else if (destR.x + destR.w >= otherX && destR.x <= otherX) {
            destR.x = otherX + 1;
            dirX *= -1;
            collision = true;
        }
    }
    return collision;
}

