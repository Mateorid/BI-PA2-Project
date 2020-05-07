#include "Ball.hpp"
#include "TextureLoader.hpp"

Ball::Ball(const char *ID, const char *textureDest, SDL_Renderer *renderer) {
    this->ID = ID;
    objTexture = CTextureLoader::LoadTexture(textureDest, renderer);
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
        destR.y = GAME_HEIGHT - PLATFORM_H - 50;
        destR.h = destR.w = BALL_SIZE;
        /**Random direction*/
        srand(time(nullptr));
        dirX = (std::rand() % 2) ? -1 : 1;
        collider = new CollisionModel(destR.x, destR.y, destR.h, destR.w);
        active = true;
    }
}

void Ball::Update() {
    if (active) {
        destR.x += (dirX * (int) verSpeed);
        destR.y += (dirY * (int) horSpeed);
        if (destR.x <= 0)
            dirX *= -1;
        if (destR.x >= GAME_WIDTH - BALL_SIZE)
            dirX *= -1;
        if (destR.y <= 0)
            dirY *= -1;
    }
}

void Ball::CollisionDetector() {

}
