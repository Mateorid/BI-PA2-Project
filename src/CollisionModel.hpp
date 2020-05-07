#pragma once

#include "SDL2/SDL.h"

class CollisionModel {
public:
    CollisionModel(int x, int y, int h, int w) {
        boundaries.x = x;
        boundaries.y = y;
        boundaries.h = h;
        boundaries.w = w;
    };

    ~CollisionModel() = default;

    int GetX() const { return boundaries.x; };

    int GetY() const { return boundaries.y; };

    int GetOtherX() const { return boundaries.x + boundaries.w; };

    int GetOtherY() const { return boundaries.y + boundaries.h; };

private:
    SDL_Rect boundaries{};
};




