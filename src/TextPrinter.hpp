#pragma once

#include <SDL2/SDL_ttf.h>
#include <sstream>


class TextPrinter {
public:

    void Init(SDL_Renderer *, TTF_Font *);

    SDL_Texture *CreateLevelTexture(int, SDL_Rect &, bool);

    SDL_Texture *CreateTotalScoreTexture(int, SDL_Rect &);

    SDL_Texture *CreateTextTexture(std::ostringstream &, SDL_Rect &);

    SDL_Texture *CreateTextTexture(const char *, SDL_Rect &);

private:
    TTF_Font *font{};
    SDL_Renderer *renderer{};
    SDL_Surface *surface{};
    SDL_Texture *texture{};
};
