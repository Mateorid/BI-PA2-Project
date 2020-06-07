#pragma once


#include "GameObject.hpp"
#include "Lives.hpp"
#include "Settings.hpp"


/**Destination of platform source image*/
static const char *const PLATFORM_SRC = "examples/textures/paddle.png";


class Platform : public GameObject {
public:
    Platform(SDL_Renderer *renderer);

    void Init() override;

    void MoveLeft() override;    //todo: make moving slower/faster when bonus is active (depending on int)

    void MoveRight() override;

    void SlowDown() override { verSpeed = 5; }//TODO const?

    void SpeedUP() override { verSpeed = 11; }

private:
};
