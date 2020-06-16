#include "StartupState.hpp"

void StartupState::Initialize(StateManager &manager) {

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
        throw std::runtime_error("ERROR! SDL_INIT_EVERYTHING failed to initialize!");

    if (IMG_Init(IMG_INIT_PNG) == 0)
        throw std::runtime_error("ERROR! IMG_Init failed to initialize!");

    if (TTF_Init() == -1)
        throw std::runtime_error("ERROR! TTF_Init failed to initialize!");

    manager.mainWindow = SDL_CreateWindow(GAME_NAME, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                          APP_WIDTH, APP_HEIGHT, false);
    if (manager.mainWindow == nullptr)
        throw std::runtime_error("ERROR! SDL_CreateWindow failed!");

    manager.mainRenderer = SDL_CreateRenderer(manager.mainWindow, -1, SDL_RENDERER_ACCELERATED);
    if (manager.mainRenderer == nullptr)
        throw std::runtime_error("ERROR! SDL_CreateRenderer failed!");

//    if (manager.textPrinter.Init())
//        throw std::invalid_argument("ERROR! Failed to load font!");
//    SDL_SetRenderDrawColor(manager.mainRenderer, 100, 100, 100, 255);   //todo            //Setting gray background colour
}

void StartupState::Update(StateManager &stateManager) {
    stateManager.ChangeState(StateName::MAIN_MENU);
}