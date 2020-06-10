#include "GameObject.hpp"


void GameObject::Render() {
    SDL_RenderCopy(objRenderer, objTexture, nullptr, &destR);
}

bool GameObject::CollisionDetection(GameObject *object) {
    return SDL_HasIntersection(&destR, &object->destR);
}