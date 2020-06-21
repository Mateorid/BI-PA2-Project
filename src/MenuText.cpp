#include "MenuText.hpp"

MenuText::MenuText(Application &app, int y, const char *txt, bool title) : yPos(y), isTitle(title) {
    texture = app.textPrinter.CreateTextTexture(txt, rect);
    type = TEXT;
    this->app = &app;
}

MenuText::MenuText(Application &app, int y, int lvl, bool active) : yPos(y) {
    texture = app.textPrinter.CreateLevelTexture(lvl, rect, active);
    type = LVL_SELECT;
    this->app = &app;
}

MenuText::MenuText(Application &app, int y, int score) : yPos(y) {
    texture = app.textPrinter.CreateTotalScoreTexture(score, rect);
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
    SDL_RenderCopy(app->mainRenderer, texture, &rect, &tmp);
}

void MenuText::Update(int lvl, bool active) {
    if (type == LVL_SELECT)
        texture = app->textPrinter.CreateLevelTexture(lvl, rect, active);
    Render();
}

void MenuText::Selected() {
    SDL_SetRenderDrawColor(app->mainRenderer, 255, 255, 255, 255);//Setting white colour for underline
    SDL_Rect tmpR = {(APP_WIDTH - rect.w) / 2, yPos + 45, rect.w, 5};  //todo set height & gap on res?
    SDL_RenderFillRect(app->mainRenderer, &tmpR);
    SDL_SetRenderDrawColor(app->mainRenderer, 0, 0, 0, 0);   //Back to black
}
