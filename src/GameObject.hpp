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

    virtual void Destroy() { SDL_DestroyTexture(objTexture); } //todo

    virtual bool CollisionDetection(GameObject *object);

    virtual void Collided(bool activate) {};

    virtual bool ToDelete() const { return !active; }

    void LoadTexture(const char * destination);

    virtual void Render();

    bool IsActive() const { return active; }

    GOType GetType() const { return type; }

    int GetX() const { return destR.x; }

    int GetY() const { return destR.y; }

    int GetH() const { return destR.h; }

    int GetW() const { return destR.w; }

protected:
    SDL_Rect srcR{}, destR{}; //TODO: delete srdR add only in block & bonus class + move to private?
    bool active = false;
    int speed = 0;
    GOType type{};
    SDL_Texture *objTexture{};
    SDL_Renderer *objRenderer{};
};