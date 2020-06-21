#include "StartupState.hpp"

void StartupState::Initialize(Application &app) {
    if (APP_HEIGHT < 720 || APP_WIDTH < 540) {//todo delete?
        throw std::invalid_argument("Game size must be at least 720x540");
    }
    //todo other GO sizes?

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
        throw std::runtime_error(SDL_GetError());

    if (IMG_Init(IMG_INIT_PNG) == 0)
        throw std::runtime_error("ERROR! IMG_Init failed to initialize!");

    if (TTF_Init() == -1)
        throw std::runtime_error(SDL_GetError());

    app.mainWindow = SDL_CreateWindow(GAME_NAME, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                      APP_WIDTH, APP_HEIGHT, false);
    if (app.mainWindow == nullptr)
        throw std::runtime_error(SDL_GetError());

    app.mainRenderer = SDL_CreateRenderer(app.mainWindow, -1, SDL_RENDERER_ACCELERATED);
    if (app.mainRenderer == nullptr)
        throw std::runtime_error(SDL_GetError());

    app.font = TTF_OpenFont(FONT_SRC, 50);
    if (app.font == nullptr)
        throw std::invalid_argument(SDL_GetError());

    app.textPrinter.Init(app.mainRenderer, app.font);
    app.score = new ScoreManager(app.mainRenderer);
}

void StartupState::Update(Application &stateManager) {
    stateManager.ChangeState(StateName::MAIN_MENU);
}
