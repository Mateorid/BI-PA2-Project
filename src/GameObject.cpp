#include "GameObject.hpp"


GameObject::GameObject(const char *textureDest, SDL_Renderer *renderer, int xPosition, int yPosition) {
    destR.x = xPosition;
    destR.y = yPosition;
    objRenderer = renderer;
    objTexture = IMG_LoadTexture(renderer, textureDest);
    active = true;
}

GameObject::~GameObject() {}

void GameObject::Render() {
    SDL_RenderCopy(objRenderer, objTexture, nullptr, &destR);
    //TODO in block class override to use only part of the image instead of the whole image
}

Direction GameObject::CollisionDetection(GameObject *object) {
    int x = object->destR.x;
    int y = object->destR.y;
    int otherX = object->destR.x + object->destR.w;
    int otherY = object->destR.y + object->destR.h;
    //TODO this is still shit
    if (!isColliding) {
        /**Vertical collision*/
        if (destR.x >= x && destR.x + destR.w <= otherX) {
            if (destR.y + destR.h >= y && destR.y < y) {
                std::cout << "YES1" << std::endl;
                isColliding = true;
                return TOP;
            } else if (destR.y <= otherY && destR.y + destR.h > otherY) {
                std::cout << "YES2" << std::endl;
                isColliding = true;
                return BOT;
            }
            /**Horizontal collision*/
        } else if (destR.y <= otherY && destR.y + destR.h >= y) {
            if (destR.x + destR.w >= x && destR.x <= x) {
                std::cout << "YES3" << std::endl;
                isColliding = true;
                return LEFT;
            } else if (destR.x + destR.w >= otherX && destR.x <= otherX) {
                std::cout << "YES4" << std::endl;
                isColliding = true;
                return RIGHT;
            }
        }
    }
    isColliding = false;
    return NONE;
}