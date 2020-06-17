#include "MenuState.hpp"

void MenuState::Initialize(StateManager &manager) {
    font = TTF_OpenFont(FONT_SRC, 50);
    if (font == nullptr)
        throw std::invalid_argument("ERROR! Failed to load font!");

    std::ostringstream oss;
    oss << GAME_NAME;
    titleTexture = manager.textPrinter.CreateTextTexture(oss, manager.mainRenderer, titleR, font);
    std::ostringstream().swap(oss);
    LevelText(manager);
    oss << "EXIT";
    exitTexture = manager.textPrinter.CreateTextTexture(oss, manager.mainRenderer, exitR, font);
    SDL_SetRenderDrawColor(manager.mainRenderer, 0, 0, 0, 0);            //Setting black background
}

void MenuState::HandleEvents(StateManager &manager) {
    SDL_Event events{};
    SDL_PollEvent(&events);
    if (events.type == SDL_QUIT)                                            //Exit signal
        manager.ChangeState(StateName::EXIT);
    if (events.type == SDL_KEYDOWN) {                                       //Keypress handling
        switch (events.key.keysym.sym) {
            case SDLK_LEFT:
                selectedLvl--;
                if (selectedLvl <= 0) selectedLvl = LVL_COUNT;
                changedText = true;
                break;
            case SDLK_RIGHT:
                selectedLvl++;
                if (selectedLvl > LVL_COUNT) selectedLvl = 1;
                changedText = true;
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
                    std::cout << "SELECTED GAME LVL: " << manager.GetLevel() << std::endl;
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
    if (changedText) {
        SDL_RenderClear(manager.mainRenderer);

        LevelText(manager);
        RenderText(manager.mainRenderer, titleTexture, titleR, positions[0], true);
        RenderText(manager.mainRenderer, lvlSelectTexture, lvlSelectR, positions[1], false);
        RenderText(manager.mainRenderer, exitTexture, exitR, positions[2], false);
        RenderSelected(manager.mainRenderer);

        SDL_RenderPresent(manager.mainRenderer);
        changedText = false;
    }
}

void MenuState::LevelText(StateManager &manager) {
    std::ostringstream oss;
    oss << "PLAY LVL " << selectedLvl;
    lvlSelectTexture = manager.textPrinter.CreateTextTexture(oss, manager.mainRenderer, lvlSelectR, font);
    std::ostringstream().swap(oss);
}

void MenuState::RenderText(SDL_Renderer *renderer, SDL_Texture *texture, SDL_Rect rect, int y, bool title) {
    renderR = rect;
    if (title) {
        renderR.h *= 2;
        renderR.w *= 2;
    }
    renderR.x = (APP_WIDTH - renderR.w) / 2;
    renderR.y = y;
    SDL_RenderCopy(renderer, texture, &rect, &renderR);
}

void MenuState::RenderSelected(SDL_Renderer *renderer) {
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
    TTF_CloseFont(font);
}
