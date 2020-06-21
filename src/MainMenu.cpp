#include "MainMenu.hpp"

void MainMenu::Initialize(Application &app) {
    positions.push_back(20);//title pos     //todo set these by resolution
    positions.push_back(400);//lvl select pos
    positions.push_back(600);//exit pos
    try {
        texts.push_back(std::make_unique<MenuText>(app, positions[0], GAME_NAME, 1)); //game title
        texts.push_back(std::make_unique<MenuText>(app, positions[1], selectedLvl, 1)); //lvl select
        texts.push_back(std::make_unique<MenuText>(app, positions[2], "EXIT", 0)); //exit text
        if (SDL_SetRenderDrawColor(app.res.mainRenderer, 0, 0, 0, 0) < 0)            //Setting black background
            throw std::runtime_error(SDL_GetError());
    }
    catch (std::runtime_error &err) {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "ERROR", err.what(), app.res.mainWindow);
        app.ChangeState(StateType::EXIT);
    }
    menuSelections = 2;
    changedText = true;
}

void MainMenu::HandleEvents(Application &app) {
    SDL_Event events{};
    SDL_PollEvent(&events);
    if (events.type == SDL_QUIT)                                            //Exit signal
        app.ChangeState(StateType::EXIT);
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
                app.ChangeState(StateType::EXIT);
                break;
            case SDLK_RETURN:
            case SDLK_SPACE:
                if (menuPos == 1) {
                    app.res.currentLevel = selectedLvl;
                    app.ChangeState(StateType::LOAD_MAP);
                } else
                    app.ChangeState(StateType::EXIT);
                break;
            default:
                break;
        }
    }
}
