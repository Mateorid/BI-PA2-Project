#pragma once

#include <SDL2/SDL.h>
#include <string>
#include <iostream>
#include <SDL2/SDL_image.h>

#include "Settings.hpp"

class GameObject {
public:
    GameObject() = default;

    ~GameObject() = default; //todo?

    virtual void Init() {};

    virtual void Update() {};

    virtual void SpeedUP() {};

    virtual void SlowDown() {};

    virtual void ResetSpeed() {};

    virtual void Destroy() { SDL_DestroyTexture(objTexture); }

    virtual bool CollisionDetection(GameObject *object);

    virtual void Collided(bool activate) {};

    bool IsActive() const { return active; }

    virtual bool ToDelete() const { return !active; }

    GOType GetType() const { return type; }

    int GetX() const { return destR.x; }

    int GetY() const { return destR.y; }

    int GetH() const { return destR.h; }

    int GetW() const { return destR.w; }

    virtual void Render();

protected:
    SDL_Rect srcR{}, destR{}; //TODO: delete srdR add only in block & bonus class + move to private?
    bool isColliding = false; //todo delete?
    bool active = false;
    int speed = 0;
    GOType type{};
    SDL_Texture *objTexture{};
    SDL_Renderer *objRenderer{};
};