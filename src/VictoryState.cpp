#include "VictoryState.hpp"

void VictoryState::Initialize(StateManager &manager) {
    font = TTF_OpenFont(FONT_SRC, 50);
    if (font == nullptr)
        throw std::invalid_argument("ERROR! Failed to load font!");

    std::ostringstream oss; //todo use the better text class

    oss << "VICTORY!";
    resultTexture = manager.textPrinter.CreateTextTexture(oss, manager.mainRenderer, resultR, font);
    std::ostringstream().swap(oss);

    oss << "TOTAL SCORE: " << manager.totalScore;
    scoreTexture = manager.textPrinter.CreateTextTexture(oss, manager.mainRenderer, scoreR, font);
    std::ostringstream().swap(oss);

    oss << "PLAY NEXT";
    nextTexture = manager.textPrinter.CreateTextTexture(oss, manager.mainRenderer, nextR, font);
    std::ostringstream().swap(oss);

    oss << "MENU";
    menuTexture = manager.textPrinter.CreateTextTexture(oss, manager.mainRenderer, menuR, font);
    std::ostringstream().swap(oss);

    SDL_SetRenderDrawColor(manager.mainRenderer, 0, 0, 0, 0);
    changedText = true;
}

void VictoryState::HandleEvents(StateManager &manager) {
    SDL_Event events{};
    SDL_PollEvent(&events);
    if (events.type == SDL_QUIT)                                            //Exit signal
        manager.ChangeState(StateName::EXIT);
    if (events.type == SDL_KEYDOWN) {                                       //Keypress handling
        switch (events.key.keysym.sym) {
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
                    manager.SetLevel(manager.GetLevel() + 1); //todo must check if not last lvl
                    manager.ChangeState(StateName::LOAD_MAP);
                } else {
                    manager.totalScore = 0; //todo
                    manager.ChangeState(StateName::MAIN_MENU);
                }
                break;
            default:
                break;
        }
    }
}

void VictoryState::Render(StateManager &manager) {
    if (changedText) {
        SDL_RenderClear(manager.mainRenderer);

        RenderText(manager.mainRenderer, resultTexture, resultR, positions[0], true);
        RenderText(manager.mainRenderer, scoreTexture, scoreR, positions[1], false);
        RenderText(manager.mainRenderer, nextTexture, nextR, positions[2], false);
        RenderText(manager.mainRenderer, menuTexture, menuR, positions[3], false);
        RenderSelected(manager.mainRenderer);

        SDL_RenderPresent(manager.mainRenderer);
        changedText = false;
    }
}

void VictoryState::RenderText(SDL_Renderer *renderer, SDL_Texture *texture, SDL_Rect rect, int y, bool title) {
    renderR = rect;
    if (title) {
        renderR.h *= 2;
        renderR.w *= 2;
    }
    renderR.x = (APP_WIDTH - renderR.w) / 2;
    renderR.y = y;
    SDL_RenderCopy(renderer, texture, &rect, &renderR);
}

void VictoryState::RenderSelected(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);            //Setting white colour for underline
    SDL_Rect tmpR = {0, 0, 200, 5};//todo set these
    tmpR.x = (APP_WIDTH - tmpR.w) / 2;
    tmpR.y = positions[menuPos + 1] + 45; //todo?
    SDL_RenderFillRect(renderer, &tmpR);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);   //Back to black
}

void VictoryState::Clean(StateManager &) {
    SDL_DestroyTexture(resultTexture);
    SDL_DestroyTexture(scoreTexture);
    SDL_DestroyTexture(nextTexture);
    SDL_DestroyTexture(menuTexture);
    TTF_CloseFont(font);
}