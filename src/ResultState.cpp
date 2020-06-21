#include "ResultState.hpp"

void ResultState::Initialize(Application &app) {
    /**1st must be a non selectable one, followed by all selectable ones*/
    positions.push_back(20);//result pos     //todo set these by resolution
    positions.push_back(400);//retry/next pos
    positions.push_back(600);//menu pos
    positions.push_back(200);//score pos
    if (app.res.won) {
        texts.push_back(std::make_unique<MenuText>(app, positions[0], "VICTORY", 1)); //result text
        texts.push_back(std::make_unique<MenuText>(app, positions[1], "PLAY NEXT", 0)); //next text
    } else {
        texts.push_back(std::make_unique<MenuText>(app, positions[0], "DEFEAT", 1)); //result text
        texts.push_back(std::make_unique<MenuText>(app, positions[1], "RETRY", 0)); //retry text
        HighScore(app);
    }
    texts.push_back(std::make_unique<MenuText>(app, positions[2], "MENU", 0)); //menu text
    texts.push_back(std::make_unique<MenuText>(app, positions[3], app.res.score->GetScore())); //score text

    SDL_SetRenderDrawColor(app.res.mainRenderer, 0, 0, 0, 0); //black background
    menuSelections = 2;
    menuPos = 1;
    changedText = true;
}

void ResultState::HandleEvents(Application &app) {
    SDL_Event events{};
    SDL_PollEvent(&events);
    if (events.type == SDL_QUIT)                                            //Exit signal
        app.ChangeState(StateType::EXIT);
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
                app.ChangeState(StateType::EXIT);
                break;
            case SDLK_RETURN:
            case SDLK_SPACE:
                if (menuPos == 1) {
                    if (app.res.won)
                        app.res.currentLevel++;
                    else
                        app.res.score->ResetScore();
                    app.ChangeState(StateType::LOAD_MAP);
                } else {
                    app.res.score->ResetScore();
                    app.ChangeState(StateType::MAIN_MENU);
                }
                break;
            default:
                break;
        }
    }
}

void ResultState::HighScore(Application &app) {
    highScore.GetScores(app.res.score->GetScore());
}
