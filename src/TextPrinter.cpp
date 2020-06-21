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
    try {
        surface = TTF_RenderUTF8_Blended(font, text, {255, 255, 255, 0});
        if (surface == nullptr)
            throw std::runtime_error("Text render failed.");
        rect = {0, 0, surface->w, surface->h};
        texture = SDL_CreateTextureFromSurface(renderer, surface);
        if (texture == nullptr)
            throw std::runtime_error(SDL_GetError());
        SDL_FreeSurface(surface);
        return texture;
    }
    catch (std::runtime_error &err) {
        std::cerr << err.what() << std::endl;
        return nullptr;
    }
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
