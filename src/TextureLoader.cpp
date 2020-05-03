#include "TextureLoader.hpp"

SDL_Texture *CTextureLoader::LoadTexture(const char *dest, SDL_Renderer *rnd) { //TODO what if destination fails?
    SDL_Surface *tmp = IMG_Load(dest);
    SDL_Texture *imgTexture = SDL_CreateTextureFromSurface(rnd, tmp);
    SDL_FreeSurface(tmp);
    return imgTexture;
}
