#include "Application.hpp"

Application::Application() {
    try {
        Initialize(GAME_NAME, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                   GAME_WIDTH, GAME_HEIGHT, START_FULLSCREEN);
    } catch (std::runtime_error &err) {
        std::cout << &err << std::endl;
    }
}

void Application::Initialize(const char *title, int xPos, int yPos, int width, int height, bool fullscreen) {
    int initFullscreen = fullscreen ? SDL_WINDOW_FULLSCREEN : 0; //TODO remove fullscreen option?

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
        throw std::runtime_error("SDL_INIT_EVERYTHING failed to initialize!");

    if (IMG_Init(IMG_INIT_PNG) == 0)
        throw std::runtime_error("IMG_Init failed to initialize!");

    mainWindow = SDL_CreateWindow(title, xPos, yPos, width, height, initFullscreen);
    if (mainWindow == nullptr)
        throw std::runtime_error("SDL_CreateWindow failed to initialize!");

    mainRenderer = SDL_CreateRenderer(mainWindow, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(mainRenderer, 100, 100, 100, 255);
    if (mainRenderer == nullptr)
        throw std::runtime_error("SDL_CreateRenderer failed to initialize!");
}

int Application::Start() {
//    LoadMap();
    game = new Game(gameObjects, mainRenderer);
    game->Play();
    CleanAll();
    return 0;
}

void Application::LoadMap() {
    gameMap = new Map(MAP_SRC, mainRenderer); //todo convert to MapLoader
    gameObjects = std::move(gameMap->getBlocks()); //todo does move work like this? (removed const const from map.hpp)
}

void Application::CleanAll() {
//todo?
    for (auto it:gameObjects)
        it->Destroy();
    gameObjects.clear();
    SDL_DestroyRenderer(mainRenderer);
    SDL_DestroyWindow(mainWindow);
    IMG_Quit();
    SDL_Quit();
    std::cout << "Everything cleaned" << std::endl;
}
