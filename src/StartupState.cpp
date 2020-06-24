#include "StartupState.hpp"


void StartupState::Initialize() {
    if (APP_HEIGHT < 720 || APP_WIDTH < 540) {
        throw std::invalid_argument("Game size must be at least 720x540");
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
        throw std::runtime_error(SDL_GetError());

    if (IMG_Init(IMG_INIT_PNG) == 0)
        throw std::runtime_error("ERROR! IMG_Init failed to initialize!");

    if (TTF_Init() == -1)
        throw std::runtime_error(SDL_GetError());

    app.res.mainWindow = SDL_CreateWindow(GAME_NAME, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                          APP_WIDTH, APP_HEIGHT, false);
    if (app.res.mainWindow == nullptr)
        throw std::runtime_error(SDL_GetError());

    app.res.mainRenderer = SDL_CreateRenderer(app.res.mainWindow, -1, SDL_RENDERER_ACCELERATED);
    if (app.res.mainRenderer == nullptr)
        throw std::runtime_error(SDL_GetError());

    app.res.font = TTF_OpenFont(FONT_SRC, 50);
    if (app.res.font == nullptr)
        throw std::invalid_argument(SDL_GetError());

    app.res.textPrinter.Init(app.res.mainRenderer, app.res.font);
    app.res.score = new ScoreManager(app.res.mainRenderer);

    app.ChangeState(StateType::MAIN_MENU);
}
