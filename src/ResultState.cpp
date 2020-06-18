#include "ResultState.hpp"

void ResultState::Initialize(StateManager &manager) {
    renderer = manager.mainRenderer;
    if (manager.won) {
        resultTexture = manager.textPrinter.CreateTextTexture("VICTORY", resultR);
        nextTexture = manager.textPrinter.CreateTextTexture("PLAY NEXT", nextR);
    } else {
        resultTexture = manager.textPrinter.CreateTextTexture("DEFEAT", resultR);
        nextTexture = manager.textPrinter.CreateTextTexture("RETRY LEVEL", nextR);
    }
    scoreTexture = manager.textPrinter.CreateTotalScoreTexture(manager.score->GetScore(), scoreR);
    menuTexture = manager.textPrinter.CreateTextTexture("MENU", menuR);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0); //black background //todo set this to red/green based on won
    changedText = true;
}

void ResultState::HandleEvents(StateManager &manager) {
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
                    if (manager.won)
                        manager.SetLevel(manager.GetLevel() + 1); //todo must check if not last lvl
                    manager.ChangeState(StateName::LOAD_MAP);
                } else {
                    manager.score->ResetScore();
                    manager.ChangeState(StateName::MAIN_MENU);
                }
                break;
            default:
                break;
        }
    }
}

void ResultState::Render(StateManager &manager) {
    if (changedText) {
        SDL_RenderClear(renderer);

        RenderText(resultTexture, resultR, positions[0], true);
        RenderText(scoreTexture, scoreR, positions[1], false);
        RenderText(nextTexture, nextR, positions[2], false);
        RenderText(menuTexture, menuR, positions[3], false);
        RenderSelected();

        SDL_RenderPresent(renderer);
        changedText = false;
    }
}

void ResultState::RenderText(SDL_Texture *texture, SDL_Rect rect, int y, bool bigger) {
    renderR = rect;
    if (bigger) {
        renderR.h *= 2;
        renderR.w *= 2;
    }
    renderR.x = (APP_WIDTH - renderR.w) / 2;
    renderR.y = y;
    SDL_RenderCopy(renderer, texture, &rect, &renderR);
}

void ResultState::RenderSelected() {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);            //Setting white colour for underline
    SDL_Rect tmpR = {0, 0, 200, 5};//todo set these
    tmpR.x = (APP_WIDTH - tmpR.w) / 2;
    tmpR.y = positions[menuPos + 1] + 45; //todo?
    SDL_RenderFillRect(renderer, &tmpR);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);   //Back to black
}

void ResultState::Clean(StateManager &) {
    SDL_DestroyTexture(resultTexture);
    SDL_DestroyTexture(scoreTexture);
    SDL_DestroyTexture(nextTexture);
    SDL_DestroyTexture(menuTexture);
}
