#include "Platform.hpp"
#include "TextureLoader.hpp"

Platform::Platform(const char *textureDest, SDL_Renderer *renderer) {
    xPos = (GAME_WIDTH / 2) - (PLATFORM_W / 2);
    yPos = GAME_HEIGHT - 50;
    objRenderer = renderer;
    objTexture = CTextureLoader::LoadTexture(textureDest, renderer);
    destR.h = PLATFORM_H;
    destR.w = PLATFORM_W;
    destR.x = xPos;
    destR.y = yPos;
}

//void Platform::Update() {}

void Platform::MoveLeft() {
    xPos -= 5;
}

void Platform::MoveRight() {
    xPos += 5;
}

