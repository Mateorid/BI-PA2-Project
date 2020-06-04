#pragma once


#include "GameObject.hpp"
#include "Lives.hpp"
#include "Settings.hpp"

class Platform : public GameObject {
public:
    Platform(SDL_Renderer *renderer, Lives *lives);

    void Init() override;

//    void Update() override;

    void MoveLeft() override;    //todo: make moving slower/faster when bonus is active (depending on int)

    void MoveRight() override;

    bool Collided(Direction dir) override;

    int getPlatX() { return destR.x; };

    int getPlatY() { return destR.y; };

private:
    Lives *lives;
};
