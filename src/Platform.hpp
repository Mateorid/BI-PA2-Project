#pragma once


#include "GameObject.hpp"
#include "Settings.hpp"

class Platform : public GameObject {
public:
    Platform(const char * ID, const char *textureDest, SDL_Renderer *renderer);

    void Init() override;

//    void Update() override;

    void MoveLeft() override;    //todo: make moving slower/faster when bonus is active (depending on int)

    void MoveRight() override;

    int getPlatX() { return destR.x; };

    int getPlatY() { return destR.y; };

private:
};



