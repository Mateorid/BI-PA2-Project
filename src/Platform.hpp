#pragma once


#include "GameObject.hpp"
#include "Settings.hpp"

class Platform : public GameObject {
public:
    Platform(const char *textureDest, SDL_Renderer *renderer);

//    void Update() override;

    void MoveLeft();    //todo: make moving slower/faster when bonus is active (depending on int)

    void MoveRight();

private:

};




