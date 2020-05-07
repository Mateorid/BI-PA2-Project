#include "TextureLoader.hpp"

SDL_Texture *CTextureLoader::LoadTexture(const char *dest, SDL_Renderer *rnd) { //TODO fail switch for non existent file
    SDL_Surface *tmp = IMG_Load(dest);
    SDL_Texture *imgTexture = SDL_CreateTextureFromSurface(rnd, tmp);
    SDL_FreeSurface(tmp);
    return imgTexture;
}
