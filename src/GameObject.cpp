#include "GameObject.hpp"
#include "TextureLoader.hpp"


GameObject::GameObject(const char *textureDest, SDL_Renderer *renderer, int xPosition, int yPosition) {
    xPos = xPosition;
    yPos = yPosition;
    objRenderer = renderer;
    objTexture = CTextureLoader::LoadTexture(textureDest, renderer);
}

GameObject::~GameObject() {
    //TODO?
}

void GameObject::Update() {
    destR.x = xPos;
    destR.y = yPos;
}

void GameObject::Render() {
    SDL_RenderCopy(objRenderer, objTexture, nullptr, &destR);
    //TODO in block class override to use only part of the image instead of the whole image
}
