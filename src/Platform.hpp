#pragma once


#include "GameObject.hpp"
//#include "Application.hpp"
#include "State.hpp"


/**Destination of platform source image*/
static const char *const PLATFORM_SRC = "examples/textures/paddle.png";
/**Platform settings*/
static const int PLATFORM_H = 20;
static const int PLATFORM_W = 90;
static const int PLATFORM_SPEED = 8;

class Platform : public GameObject {
public:
    explicit Platform(SDL_Renderer *renderer);

    void Init() override;

    void MoveLeft();

    void MoveRight();

    void SlowDown() override { speed = 5; }//TODO const?

    void SpeedUP() override { speed = 11; }

    void ResetSpeed() override { speed = PLATFORM_SPEED; }


private:
};
