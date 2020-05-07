#include "Platform.hpp"
#include "TextureLoader.hpp"

Platform::Platform(const char *ID, const char *textureDest, SDL_Renderer *renderer) {
    this->ID = ID;
    objRenderer = renderer;
    objTexture = CTextureLoader::LoadTexture(textureDest, renderer);
    verSpeed = 10.0;
    Init();
    active = true;
}

void Platform::Init() {
    destR.x = (GAME_WIDTH / 2) - (PLATFORM_W / 2);
    destR.y = GAME_HEIGHT - 50;
    destR.h = PLATFORM_H;
    destR.w = PLATFORM_W;
    collider = new CollisionModel(destR.x, destR.y, destR.h, destR.w);
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

