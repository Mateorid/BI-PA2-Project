#pragma once

#include <SDL2/SDL.h>
#include <string>
#include <iostream>
#include <SDL2/SDL_image.h>

#include "Settings.hpp"

enum Direction {
    NONE, TOP, BOT, LEFT, RIGHT
}; //TODO corners?

class GameObject {
public:
    GameObject() = default;

    GameObject(const char *textureDest, SDL_Renderer *renderer, int xPosition, int yPosition);

    ~GameObject();

    virtual void Init() {};

    virtual void Update() {};

    virtual void MoveLeft() {};

    virtual void MoveRight() {};

    virtual void SpeedUP() {};

    virtual void SlowDown() {};

    virtual void Destroy() { SDL_DestroyTexture(objTexture); }

    Direction CollisionDetection(GameObject *object);

    virtual void Collided(Direction dir) {};

    bool IsActive() const { return active; }

    virtual bool ToDelete() const { return !active; }

    GOType GetType() const { return type; }

    int GetX() const { return destR.x; }

    int GetY() const { return destR.y; }

    virtual void Render();

    SDL_Rect srcR{}, destR{}; //TODO: delete srdR add only in block & bonus class + move to private?
protected:
    bool isColliding = false;
    bool active = false;
    int verSpeed = 0; //TODO to int if not using speed up over time
    int horSpeed = 0;
    GOType type;
    SDL_Texture *objTexture{};
    SDL_Renderer *objRenderer{};
};