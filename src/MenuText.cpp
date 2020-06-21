#include "MenuText.hpp"

MenuText::MenuText(Application &app, int y, const char *txt, bool title) : yPos(y), isTitle(title) {
    texture = app.res.textPrinter.CreateTextTexture(txt, rect);
    if (texture == nullptr)
        throw std::runtime_error(TEXT_ERROR);
    type = TEXT;
    this->app = &app;
}

MenuText::MenuText(Application &app, int y, int lvl, bool active) : yPos(y) {
    texture = app.res.textPrinter.CreateLevelTexture(lvl, rect, active);
    if (texture == nullptr)
        throw std::runtime_error(TEXT_ERROR);
    type = LVL_SELECT;
    this->app = &app;
}

MenuText::MenuText(Application &app, int y, int score) : yPos(y) {
    texture = app.res.textPrinter.CreateTotalScoreTexture(score, rect);
    if (texture == nullptr)
        throw std::runtime_error(TEXT_ERROR);
    type = SCORE;
    this->app = &app;
}

MenuText::~MenuText() {
    SDL_DestroyTexture(texture);
}

void MenuText::Render() {
    SDL_Rect tmp = rect;
    if (isTitle) {
        tmp.h *= 2;
        tmp.w *= 2;
    }
    tmp.x = (APP_WIDTH - tmp.w) / 2; //center position
    tmp.y = yPos;
    if (SDL_RenderCopy(app->res.mainRenderer, texture, &rect, &tmp) < 0)
        throw std::runtime_error(SDL_GetError());
}

void MenuText::Update(int lvl, bool active) {
    if (type == LVL_SELECT)
        texture = app->res.textPrinter.CreateLevelTexture(lvl, rect, active);
    Render();
}

void MenuText::Selected() {
    if (SDL_SetRenderDrawColor(app->res.mainRenderer, 255, 255, 255, 255) < 0)//Setting white colour for underline
        throw std::runtime_error(SDL_GetError());
    SDL_Rect tmpR = {(APP_WIDTH - rect.w) / 2, yPos + 45, rect.w, 5};  //todo set height & gap on res?
    if (SDL_RenderFillRect(app->res.mainRenderer, &tmpR) < 0)
        throw std::runtime_error(SDL_GetError());
    if (SDL_SetRenderDrawColor(app->res.mainRenderer, 0, 0, 0, 0) < 0)  //Back to black
        throw std::runtime_error(SDL_GetError());
}
