#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class CTextureLoader {
public:
    //creates and return a SDL_Texture from image in dest, using a tmp surface
    static SDL_Texture *LoadTexture(const char *dest, SDL_Renderer *rnd);
};