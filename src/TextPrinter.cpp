#include "TextPrinter.hpp"

SDL_Texture *
TextPrinter::CreateTextTexture(std::ostringstream &oss, SDL_Renderer *renderer, SDL_Rect &rect, TTF_Font *font) {
    surface = TTF_RenderUTF8_Blended(font, oss.str().c_str(), {255, 255, 255, 0});
    rect = {0, 0, surface->w, surface->h};
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}
