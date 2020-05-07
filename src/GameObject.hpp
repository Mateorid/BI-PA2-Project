#pragma once

#include <SDL2/SDL.h>
#include <string>
#include "CollisionModel.hpp"


class GameObject {
public:
    GameObject() = default;

    GameObject(const char *ID, const char *textureDest, SDL_Renderer *renderer, int xPosition, int yPosition);

    ~GameObject();

    virtual void Init() {};

    virtual void Update() {};

    virtual void MoveLeft() {};

    virtual void MoveRight() {};

    std::string GetID() const { return ID; }

    void Render();

protected:
    std::string ID{};
    bool active{};
    float verSpeed = 0.0;
    float horSpeed = 0.0;
    CollisionModel *collider{};
    SDL_Texture *objTexture{};
    SDL_Renderer *objRenderer{};
    SDL_Rect srcR{}, destR{}; //TODO: delete srdR add only in block class
};