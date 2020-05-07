#include "GameObject.hpp"

#include "TextureLoader.hpp"


GameObject::GameObject(const char *ID, const char *textureDest, SDL_Renderer *renderer, int xPosition, int yPosition) {
    this->ID = ID;
    destR.x = xPosition;
    destR.y = yPosition;
    objRenderer = renderer;
    objTexture = CTextureLoader::LoadTexture(textureDest, renderer);
    collider = new CollisionModel(xPosition, yPosition, 0, 0);
}

GameObject::~GameObject() {
    delete collider;
}

void GameObject::Render() {
    SDL_RenderCopy(objRenderer, objTexture, nullptr, &destR);
    //TODO in block class override to use only part of the image instead of the whole image
}
