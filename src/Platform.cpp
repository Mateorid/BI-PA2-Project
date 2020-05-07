#include "Platform.hpp"
#include "TextureLoader.hpp"

Platform::Platform(const char *ID, const char *textureDest, SDL_Renderer *renderer, Lives *lives) {
    this->ID = ID;
    this->lives = lives;
    objRenderer = renderer;
    objTexture = CTextureLoader::LoadTexture(textureDest, renderer);
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
