#include "MenuState.hpp"

void MenuState::Initialize(StateManager &manager) {
    renderer = manager.mainRenderer;
    titleTexture = manager.textPrinter.CreateTextTexture(GAME_NAME, titleR);
    lvlSelectTexture = manager.textPrinter.CreateLevelTexture(selectedLvl, lvlSelectR, menuPos == 1);
    exitTexture = manager.textPrinter.CreateTextTexture("EXIT", exitR);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);            //Setting black background
    changedText = true;
}

void MenuState::HandleEvents(StateManager &manager) {
    SDL_Event events{};
    SDL_PollEvent(&events);
    if (events.type == SDL_QUIT)                                            //Exit signal
        manager.ChangeState(StateName::EXIT);
    if (events.type == SDL_KEYDOWN) {                                       //Keypress handling
        switch (events.key.keysym.sym) {
            case SDLK_LEFT:
                if (menuPos == 1) {
                    selectedLvl--;
                    if (selectedLvl <= 0) selectedLvl = LVL_COUNT;
                    changedText = true;
                }
                break;
            case SDLK_RIGHT:
                if (menuPos == 1) {
                    selectedLvl++;
                    if (selectedLvl > LVL_COUNT) selectedLvl = 1;
                    changedText = true;
                }
                break;
            case SDLK_UP:
                menuPos == 1 ? menuPos = 2 : menuPos = 1;
                changedText = true;
                break;
            case SDLK_DOWN:
                menuPos == 2 ? menuPos = 1 : menuPos = 2;
                changedText = true;
                break;
            case SDLK_ESCAPE:
                manager.ChangeState(StateName::EXIT);
                break;
            case SDLK_RETURN:
            case SDLK_SPACE:
                if (menuPos == 1) {
                    manager.SetLevel(selectedLvl);
                    manager.ChangeState(StateName::LOAD_MAP);
                } else
                    manager.ChangeState(StateName::EXIT);
                break;
            default:
                break;
        }
    }
}

void MenuState::Render(StateManager &manager) {
    if (changedText) { //when there's no update we don't need to re-render
        SDL_RenderClear(renderer);

        lvlSelectTexture = manager.textPrinter.CreateLevelTexture(selectedLvl, lvlSelectR, menuPos == 1);

        RenderText(titleTexture, titleR, positions[0], true);
        RenderText(lvlSelectTexture, lvlSelectR, positions[1], false);
        RenderText(exitTexture, exitR, positions[2], false);
        RenderSelected();

        SDL_RenderPresent(renderer);
        changedText = false;
    }
}

void MenuState::RenderText(SDL_Texture *texture, SDL_Rect rect, int y, bool bigger) {
    renderR = rect;
    if (bigger) {
        renderR.h *= 2;
        renderR.w *= 2;
    }
    renderR.x = (APP_WIDTH - renderR.w) / 2;
    renderR.y = y;
    SDL_RenderCopy(renderer, texture, &rect, &renderR);
}

void MenuState::RenderSelected() {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);            //Setting white colour for underline
    SDL_Rect tmpR = {0, 0, 200, 5};//todo set these
    tmpR.x = (APP_WIDTH - tmpR.w) / 2;
    tmpR.y = positions[menuPos] + 45; //todo?
    SDL_RenderFillRect(renderer, &tmpR);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);   //Back to black
}

void MenuState::Clean(StateManager &) {
    SDL_DestroyTexture(titleTexture);
    SDL_DestroyTexture(lvlSelectTexture);
    SDL_DestroyTexture(exitTexture);
}
