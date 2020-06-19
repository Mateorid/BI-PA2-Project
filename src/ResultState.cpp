#include "ResultState.hpp"

void ResultState::Initialize(StateManager &manager) {
    /**1st must be a non selectable one, followed by all selectable ones*/
    positions.push_back(20);//result pos     //todo set these by resolution
    positions.push_back(400);//retry/next pos
    positions.push_back(600);//menu pos
    positions.push_back(200);//score pos
    if (manager.won) {
        texts.push_back(std::make_unique<MenuText>(manager, positions[0], "VICTORY", 1)); //result text
        texts.push_back(std::make_unique<MenuText>(manager, positions[1], "PLAY NEXT", 0)); //next text
    } else {
        texts.push_back(std::make_unique<MenuText>(manager, positions[0], "DEFEAT", 1)); //result text
        texts.push_back(std::make_unique<MenuText>(manager, positions[1], "RETRY", 0)); //retry text
    }
    texts.push_back(std::make_unique<MenuText>(manager, positions[2], "MENU", 0)); //menu text
    texts.push_back(std::make_unique<MenuText>(manager, positions[3], manager.score->GetScore())); //score text

    SDL_SetRenderDrawColor(manager.mainRenderer, 0, 0, 0, 0); //black background
    menuSelections = 2;
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
                menuPos == 1 ? menuPos = menuSelections : menuPos--;
                changedText = true;
                break;
            case SDLK_DOWN:
                menuPos == menuSelections ? menuPos = 1 : menuPos++;
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
                    else
                        manager.score->ResetScore();
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
