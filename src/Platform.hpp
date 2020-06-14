#pragma once


#include "GameObject.hpp"
#include "Settings.hpp"


/**Destination of platform source image*/
static const char *const PLATFORM_SRC = "examples/textures/paddle.png";
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
