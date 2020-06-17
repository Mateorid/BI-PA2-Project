#include "GameObject.hpp"


bool GameObject::CollisionDetection(std::shared_ptr<GameObject> object) {
    return SDL_HasIntersection(&destR, &object->destR);
}

void GameObject::LoadTexture(const char *destination) {
    objTexture = IMG_LoadTexture(objRenderer, destination);
    if (objTexture == nullptr)
        throw std::invalid_argument("ERROR! Wrong path or missing texture file.");
}

void GameObject::Render() {
    SDL_RenderCopy(objRenderer, objTexture, nullptr, &destR);
}

GameObject::~GameObject() {
    std::cout << "GO del" << std::endl;
    SDL_DestroyTexture(objTexture);
}

GameObject::GameObject() {
    std::cout << "make GO" << std::endl;
}
