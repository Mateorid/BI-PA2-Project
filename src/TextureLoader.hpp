#pragma once

#include "Game.hpp"

class CTextureLoader {
public:
    //creates and return a SDL_Texture from image in dest, using a tmp surface
    static SDL_Texture *LoadTexture(const char *dest, SDL_Renderer *rnd);
};