#include "GameObject.hpp"


bool GameObject::CollisionDetection(GameObject *object) {
    return SDL_HasIntersection(&destR, &object->destR);
}

void GameObject::LoadTexture(const char *destination) {
    objTexture = IMG_LoadTexture(objRenderer, destination);
    if (objTexture == nullptr)
        throw std::invalid_argument("ERROR! Wrong path or missing texture file.");
}

void GameObject::Render() {
    if (SDL_RenderCopy(objRenderer, objTexture, nullptr, &destR) < 0)
        throw std::runtime_error(SDL_GetError());
}

GameObject::~GameObject() {
    SDL_DestroyTexture(objTexture);
}
