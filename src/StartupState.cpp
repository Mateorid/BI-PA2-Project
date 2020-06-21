#include "StartupState.hpp"

void StartupState::Initialize(Application &app) {

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
        throw std::runtime_error("ERROR! SDL_INIT_EVERYTHING failed to initialize!");

    if (IMG_Init(IMG_INIT_PNG) == 0)
        throw std::runtime_error("ERROR! IMG_Init failed to initialize!");

    if (TTF_Init() == -1)
        throw std::runtime_error("ERROR! TTF_Init failed to initialize!");

    app.mainWindow = SDL_CreateWindow(GAME_NAME, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                          APP_WIDTH, APP_HEIGHT, false);
    if (app.mainWindow == nullptr)
        throw std::runtime_error("ERROR! SDL_CreateWindow failed!");

    app.mainRenderer = SDL_CreateRenderer(app.mainWindow, -1, SDL_RENDERER_ACCELERATED);
    if (app.mainRenderer == nullptr)
        throw std::runtime_error("ERROR! SDL_CreateRenderer failed!");

    app.font = TTF_OpenFont(FONT_SRC, 50);
    if (app.font == nullptr)
        throw std::invalid_argument("ERROR! Failed to load font!");

    app.textPrinter.Init(app.mainRenderer, app.font);
    app.score = new ScoreManager(app.mainRenderer);
}

void StartupState::Update(Application &stateManager) {
    stateManager.ChangeState(StateName::MAIN_MENU);
}
