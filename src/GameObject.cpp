#include "GameObject.hpp"

GameObject::GameObject(const char *textureDest, SDL_Renderer *renderer, int x, int y)
        : xPos(x), yPos(y) { //TODO works?
    objRenderer = renderer;
    objTexture = CTextureLoader::LoadTexture(textureDest, renderer);
}

GameObject::~GameObject() {

}

void GameObject::update() {
//    srcR.h = 779;
//    srcR.w = 379;
//    srcR.x = 0;
//    srcR.y = 0;
    xPos++;
    yPos++;

    destR.h = 182;
    destR.w = 88;
    destR.x = xPos;
    destR.y = yPos;
}

void GameObject::render() {
    SDL_RenderCopy(objRenderer, objTexture, NULL, &destR);

}