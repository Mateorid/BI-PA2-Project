#include "MenuText.hpp"

MenuText::MenuText(StateManager &manager, int y, const char *txt, bool title) : yPos(y), isTitle(title) {
    texture = manager.textPrinter.CreateTextTexture(txt, rect);
    type = TEXT;
    this->manager = &manager;
}

MenuText::MenuText(StateManager &manager, int y, int lvl, bool active) : yPos(y) {
    texture = manager.textPrinter.CreateLevelTexture(lvl, rect, active);
    type = LVL_SELECT;
    this->manager = &manager;
}

MenuText::MenuText(StateManager &manager, int y, int score) : yPos(y) {
    texture = manager.textPrinter.CreateTotalScoreTexture(score, rect);
    type = SCORE;
    this->manager = &manager;
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
    SDL_RenderCopy(manager->mainRenderer, texture, &rect, &tmp);
}

void MenuText::Update(int lvl, bool active) {
    if (type == LVL_SELECT)
        texture = manager->textPrinter.CreateLevelTexture(lvl, rect, active);
    Render();
}

void MenuText::Selected() {
    SDL_SetRenderDrawColor(manager->mainRenderer, 255, 255, 255, 255);//Setting white colour for underline
    SDL_Rect tmpR = {(APP_WIDTH - rect.w) / 2, yPos + 45, rect.w, 5};  //todo set height & gap on res?
//    tmpR.x = (APP_WIDTH - tmpR.w) / 2;
//    tmpR.y = positions[menuPos + 1] + 45; //todo delete
    SDL_RenderFillRect(manager->mainRenderer, &tmpR);
    SDL_SetRenderDrawColor(manager->mainRenderer, 0, 0, 0, 0);   //Back to black
}
