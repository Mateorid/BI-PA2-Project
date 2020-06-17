#include "Platform.hpp"

Platform::Platform(SDL_Renderer *renderer) {
    type = PLATFORM;
    objRenderer = renderer;
    speed = PLATFORM_SPEED;
    LoadTexture(PLATFORM_SRC);
    Init();
    active = true;
}

void Platform::Init() {
    destR.x = (APP_WIDTH / 2) - (PLATFORM_W / 2);
    destR.y = APP_HEIGHT - 50;
    destR.h = PLATFORM_H;
    destR.w = PLATFORM_W;
}

void Platform::Update() {
    if ((dir == 1 && (destR.x + PLATFORM_W) <= APP_WIDTH) ||    //Right wall collision check
        (dir == -1 && destR.x > 0))                             //Left wall collision check
        destR.x += dir * speed;
}
