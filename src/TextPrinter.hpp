#pragma once

#include <SDL2/SDL_ttf.h>
#include <sstream>


class TextPrinter {
public:
    SDL_Texture *CreateTextTexture(std::ostringstream &, SDL_Renderer *, SDL_Rect &, TTF_Font *);

private:
    SDL_Surface *surface{};
    SDL_Texture *texture{};
};




