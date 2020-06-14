#include "Application.hpp"

Application::Application() {
    Initialize(GAME_NAME, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
               GAME_WIDTH, GAME_HEIGHT, START_FULLSCREEN);
}

void Application::Initialize(const char *title, int xPos, int yPos, int width, int height, bool fullscreen) {
    int initFullscreen = fullscreen ? SDL_WINDOW_FULLSCREEN : 0; //TODO remove fullscreen option?

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
        throw std::runtime_error("ERROR! SDL_INIT_EVERYTHING failed to initialize!");

    if (IMG_Init(IMG_INIT_PNG) == 0)
        throw std::runtime_error("ERROR! IMG_Init failed to initialize!");

    if (TTF_Init() == -1)
        throw std::runtime_error("ERROR! TTF_Init failed to initialize!");

    mainWindow = SDL_CreateWindow(title, xPos, yPos, width, height, initFullscreen);
    if (mainWindow == nullptr)
        throw std::runtime_error("ERROR! SDL_CreateWindow failed to initialize!");

    mainRenderer = SDL_CreateRenderer(mainWindow, -1, SDL_RENDERER_ACCELERATED);
    if (mainRenderer == nullptr) {
        throw std::runtime_error("ERROR! SDL_CreateRenderer failed to initialize!");
    }
    SDL_SetRenderDrawColor(mainRenderer, 100, 100, 100, 255);               //Setting the background colour
}

int Application::Start() {
    try {
        LoadMap();
    } catch (exception &exception) {
        std::cout << exception.what() << std::endl;
        return 69;
    }
    game = new Game(gameObjects, mainRenderer);
    game->Play();
    CleanAll();
    return 0;
}

void Application::LoadMap() {
    mapLoader = new MapLoader(MAP_SRC, mainRenderer); //todo convert to MapLoader
    gameObjects = std::move(mapLoader->getBlocks()); //todo does move work like this? (removed const const from map.hpp)
}

void Application::CleanAll() {
//todo?
    for (auto it:gameObjects)
        it->Destroy();
    gameObjects.clear();
    SDL_DestroyRenderer(mainRenderer);
    SDL_DestroyWindow(mainWindow);
    SDL_Quit();
    IMG_Quit();
    TTF_Quit();
    std::cout << "Everything cleaned" << std::endl;
}
