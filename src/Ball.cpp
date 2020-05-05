#include "Ball.hpp"
#include "TextureLoader.hpp"

Ball::Ball(const char *textureDest, SDL_Renderer *renderer) {
    xPos = (GAME_WIDTH / 2) - (BALL_SIZE / 2);
    yPos = GAME_HEIGHT - 50;
    objRenderer = renderer;
    objTexture = CTextureLoader::LoadTexture(textureDest, renderer);
    destR.h = destR.w = BALL_SIZE;
    destR.x = xPos;
    destR.y = yPos;
}

void Ball::Update() {
    //TODO
    destR.y--;
}
