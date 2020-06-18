#include "TextPrinter.hpp"

void TextPrinter::Init(SDL_Renderer *ren, TTF_Font *fnt) {
    renderer = ren;
    font = fnt;
}

SDL_Texture *
TextPrinter::CreateTextTexture(std::ostringstream &oss, SDL_Rect &rect) {
    return CreateTextTexture(oss.str().c_str(), rect);
}

SDL_Texture *TextPrinter::CreateTextTexture(const char *text, SDL_Rect &rect) {
    surface = TTF_RenderUTF8_Blended(font, text, {255, 255, 255, 0});
    rect = {0, 0, surface->w, surface->h};
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}

SDL_Texture *TextPrinter::CreateLevelTexture(int lvl, SDL_Rect &rect, bool selected) {
    std::ostringstream oss;
    if (selected)
        oss << "<< PLAY LVL " << lvl << " >>";
    else
        oss << "PLAY LVL " << lvl;
    return CreateTextTexture(oss, rect);
}

SDL_Texture *TextPrinter::CreateTotalScoreTexture(int score, SDL_Rect &rect) {
    std::ostringstream oss;
    oss << "TOTAL SCORE: " << score;
    return CreateTextTexture(oss, rect);
}
