#include "GameObject.hpp"

#include "TextureLoader.hpp"


GameObject::GameObject(const char *ID, const char *textureDest, SDL_Renderer *renderer, int xPosition, int yPosition) {
    this->ID = ID;
    destR.x = xPosition;
    destR.y = yPosition;
    objRenderer = renderer;
    objTexture = CTextureLoader::LoadTexture(textureDest, renderer);
}

GameObject::~GameObject() {}

void GameObject::Render() {
    SDL_RenderCopy(objRenderer, objTexture, nullptr, &destR);
    //TODO in block class override to use only part of the image instead of the whole image
}

Direction GameObject::CollisionDetection(GameObject *object) const {
    /* int objX = object->destR.x;
     int objY = object->destR.y;
     int objOtherX = object->destR.x + object->destR.w;
     int objOtherY = object->destR.y + object->destR.h;
     return AABB(objX, objY, objOtherX, objOtherY);
 */
    int x = object->destR.x;
    int y = object->destR.y;
    int otherX = object->destR.x + object->destR.w;
    int otherY = object->destR.y + object->destR.h;
    //TODO: use comparison with a constant bcs of multiple triggers per tick
    /**Vertical collision*/
    if (destR.x >= x && destR.x + destR.w <= otherX) {
        if (destR.y + destR.h >= y && destR.y < y) {
            std::cout << "YES1" << std::endl;
            return TOP;
        } else if (destR.y <= otherY && destR.y + destR.h > otherY) {
            std::cout << "YES2" << std::endl;
            return BOT;
        }
        /**Horizontal collision*/
    } else if (destR.y <= otherY && destR.y + destR.h >= y) {
        if (destR.x + destR.w >= x && destR.x <= x) {
            std::cout << "YES3" << std::endl;
            return LEFT;
        } else if (destR.x + destR.w >= otherX && destR.x <= otherX) {
            std::cout << "YES4" << std::endl;
            return RIGHT;
        }
    }
    return NONE;

}
/*
Direction GameObject::AABB(int x, int y, int otherX, int otherY) {
    //todo: overload for block check for collision only bcs we don't care abt direction and make it faster
//    if (destR.x >= x &&
//        destR.x + destR.w <= otherX &&
//        destR.y + destR.h >= y &&
//        destR.y + destR.h <= otherY) {
//        std::cout << "YES1" << std::endl;
//        return TOP;
//    } else if (destR.x >= x &&
//               destR.x + destR.w <= otherX &&
//               destR.y >= y &&
//               destR.y <= otherY) {
//        std::cout << "YES2" << std::endl;
//        return BOT;
//    } else if (destR.x + destR.w >= x &&
//               destR.x + destR.w <= otherX &&
//               destR.y >= y &&
//               destR.y + destR.h <= otherY) {
//        std::cout << "YES3" << std::endl;
//        return LEFT;
//    } else if (destR.x >= x &&
//               destR.x <= otherX &&
//               destR.y >= y &&
//               destR.y + destR.h <= otherY) {
//        std::cout << "YES4" << std::endl;
//        return RIGHT;
//    }
    if (destR.x >= x && destR.x + destR.w <= otherX) {
        if (destR.y + destR.h >= y && destR.y < y) {
            std::cout << "YES1" << std::endl;
            return TOP;
        } else if (destR.y <= otherY && destR.y + destR.h > otherY) {
            std::cout << "YES2" << std::endl;
            return BOT;
        }
    } else if (destR.y <= otherY && destR.y + destR.h >= y) {
        if (destR.x + destR.w >= x && destR.x <= x) {
            std::cout << "YES3" << std::endl;
            return LEFT;
        } else if (destR.x + destR.w >= otherX && destR.x <= otherX) {
            std::cout << "YES4" << std::endl;
            return RIGHT;
        }
    }
    return NONE;
}
*/