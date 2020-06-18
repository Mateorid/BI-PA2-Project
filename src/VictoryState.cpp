#include "VictoryState.hpp"

void VictoryState::Initialize(StateManager &manager) {
    renderer = manager.mainRenderer;

    resultTexture = manager.textPrinter.CreateTextTexture("VICTORY", resultR);

    scoreTexture = manager.textPrinter.CreateTotalScoreTexture(manager.score->GetScore(), scoreR);

    nextTexture = manager.textPrinter.CreateTextTexture("PLAY NEXT", nextR);

    menuTexture = manager.textPrinter.CreateTextTexture("MENU", menuR);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0); //black background
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
                    manager.score->ResetScore();
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

void VictoryState::RenderText(SDL_Texture *texture, SDL_Rect rect, int y, bool bigger) {
    renderR = rect;
    if (bigger) {
        renderR.h *= 2;
        renderR.w *= 2;
    }
    renderR.x = (APP_WIDTH - renderR.w) / 2;
    renderR.y = y;
    SDL_RenderCopy(renderer, texture, &rect, &renderR);
}

void VictoryState::RenderSelected() {
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
}
