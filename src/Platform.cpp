#include "Platform.hpp"

Platform::Platform(SDL_Renderer *renderer) {
    type = PLATFORM;
    objRenderer = renderer;
    objTexture = IMG_LoadTexture(renderer, PLATFORM_SRC);
    verSpeed = 8; //todo const?
    Init();
    active = true;
}

void Platform::Init() {
    destR.x = (GAME_WIDTH / 2) - (PLATFORM_W / 2);
    destR.y = GAME_HEIGHT - 50;
    destR.h = PLATFORM_H;
    destR.w = PLATFORM_W;
}

void Platform::MoveLeft() {
    if (destR.x > 0)
        destR.x -= verSpeed;
}

void Platform::MoveRight() {
    if ((destR.x + PLATFORM_W) <= GAME_WIDTH)
        destR.x += verSpeed;
}
