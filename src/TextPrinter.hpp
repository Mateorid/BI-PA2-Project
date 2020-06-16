#pragma once

#include <SDL2/SDL_ttf.h>
#include <sstream>


static const char *const FONT_SRC = "examples/Gamer.ttf";

class TextPrinter {
public:
    TextPrinter();

    ~TextPrinter();

    bool Init();

    void Exit();

    SDL_Texture *CreateTextTexture(std::ostringstream &, SDL_Renderer *, SDL_Rect &);

private:
    SDL_Surface *surface{};
    SDL_Texture *texture{};
    TTF_Font *font{};
};




