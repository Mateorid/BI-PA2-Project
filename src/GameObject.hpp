#pragma once

#include <SDL2/SDL.h>
#include <string>
#include <iostream>
#include <SDL2/SDL_image.h>

/**Game object types*/
enum GOType {
    PLATFORM, BALL, BLOCK, BONUS
};

class GameObject {
public:
    GameObject() = default;

    virtual ~GameObject();

    virtual void Init() {};

    virtual void Update() {};

    virtual void SpeedUP() {};

    virtual void SlowDown() {};

    virtual void ResetSpeed() {};

    virtual bool CollisionDetection(GameObject *object);

    virtual void Collided(bool activate) {};

    virtual void Render();

    void LoadTexture(const char *destination);

    bool IsActive() const { return active; }

    GOType GetType() const { return type; }

    int GetX() const { return destR.x; }

    int GetY() const { return destR.y; }

    int GetH() const { return destR.h; }

    int GetW() const { return destR.w; }

protected:
    SDL_Rect srcR{}, destR{};
    bool active = false;
    int speed = 0;
    GOType type{};
    SDL_Texture *objTexture{};
    SDL_Renderer *objRenderer{};
};