#include "Platform.hpp"

Platform::Platform(const char *ID, SDL_Renderer *renderer, Lives *lives) {
    this->ID = ID;
    this->lives = lives;
    type = PLATFORM;
    objRenderer = renderer;
    objTexture = IMG_LoadTexture(renderer, PLATFORM_SRC);
    verSpeed = 8;
    Init();
    active = true;
}

void Platform::Init() {
    destR.x = (GAME_WIDTH / 2) - (PLATFORM_W / 2);
    destR.y = GAME_HEIGHT - 50;
    destR.h = PLATFORM_H;
    destR.w = PLATFORM_W;
}

//void Platform::Update() {}

void Platform::MoveLeft() {
    if (destR.x > 0)
        destR.x -= (int) verSpeed;
}

void Platform::MoveRight() {
    if ((destR.x + PLATFORM_W) <= GAME_WIDTH)
        destR.x += (int) verSpeed;
}

void Platform::Collided(Direction dir) {
    if (dir == NONE)
        return;
    std::cout << "BONUS PICKUP" << std::endl;
}
