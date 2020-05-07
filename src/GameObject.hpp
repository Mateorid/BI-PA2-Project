#pragma once

#include <SDL2/SDL.h>
#include <string>
#include <iostream>
#include "CollisionModel.hpp"
#include "Settings.hpp"

enum Direction {
    NONE, TOP, BOT, LEFT, RIGHT
}; //TODO corners?

class GameObject {
public:
    GameObject() = default;

    GameObject(const char *ID, const char *textureDest, SDL_Renderer *renderer, int xPosition, int yPosition);

    ~GameObject();

    virtual void Init() {};

    virtual void Update() {};

    virtual void MoveLeft() {};

    virtual void MoveRight() {};

    void Destroy() { SDL_DestroyTexture(objTexture); }

    Direction CollisionDetection(GameObject *object) const;

    virtual void Collided(Direction dir) {};

//    Direction AABB(int x, int y, int otherX, int otherY);

    std::string GetID() const { return ID; }

    GOType GetType() const { return type; }

    void Render();

    SDL_Rect srcR{}, destR{}; //TODO: delete srdR add only in block class
protected:
    std::string ID{};
    bool active{};
    int verSpeed = 0.0; //TODO to int if not using speed up over time
    int horSpeed = 0.0;
    GOType type;
    SDL_Texture *objTexture{};
    SDL_Renderer *objRenderer{};
};