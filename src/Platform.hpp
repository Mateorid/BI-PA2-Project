#pragma once


#include "GameObject.hpp"
#include "State.hpp"


/**Destination of platform source image*/
static const char *const PLATFORM_SRC = "examples/textures/paddle.png";
/**Platform settings*/
static const int PLATFORM_H = 20;
static const int PLATFORM_W = 90;
static const int PLATFORM_SPEED = 8;
static const int PLATFORM_FAST = 11;
static const int PLATFORM_SLOW = 5;

class Platform : public GameObject {
public:
    explicit Platform(SDL_Renderer *renderer);

    ~Platform() override;

    void Init() override;

    void Update() override;

    void MoveLeft() { dir = -1; }

    void MoveRight() { dir = 1; }

    void Stop() { dir = 0; };

    void SlowDown() override { speed = PLATFORM_SLOW; }

    void SpeedUP() override { speed = PLATFORM_FAST; }

    void ResetSpeed() override { speed = PLATFORM_SPEED; }

private:
    int dir = 0;
};
