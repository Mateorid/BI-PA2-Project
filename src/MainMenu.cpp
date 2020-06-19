#include "MainMenu.hpp"

void MainMenu::Initialize(StateManager &manager) {
    positions.push_back(20);//title pos     //todo set these by resolution
    positions.push_back(400);//lvl select pos
    positions.push_back(600);//exit pos
    texts.push_back(std::make_unique<MenuText>(manager, positions[0], GAME_NAME, 1)); //game title
    texts.push_back(std::make_unique<MenuText>(manager, positions[1], selectedLvl, 1)); //lvl select
    texts.push_back(std::make_unique<MenuText>(manager, positions[2], "EXIT", 0)); //exit text
    SDL_SetRenderDrawColor(manager.mainRenderer, 0, 0, 0, 0);            //Setting black background
    menuSelections = 2;
    changedText = true;
}

void MainMenu::HandleEvents(StateManager &manager) {
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
