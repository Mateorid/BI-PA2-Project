#include "TextPrinter.hpp"

TextPrinter::TextPrinter() {
    font = TTF_OpenFont(FONT_SRC, 50);
}

TextPrinter::~TextPrinter() {
//    TTF_CloseFont(font);
}

void TextPrinter::Init() {
    font = TTF_OpenFont(FONT_SRC, 50);
}

void TextPrinter::Exit() {
    TTF_CloseFont(font);
}

SDL_Texture *TextPrinter::CreateTextTexture(std::ostringstream &oss, SDL_Renderer *renderer, SDL_Rect &rect) {
    if (font == nullptr)
        Init();
    surface = TTF_RenderUTF8_Blended(font, oss.str().c_str(), {255, 255, 255, 0});
    rect = {0, 0, surface->w, surface->h};
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}
