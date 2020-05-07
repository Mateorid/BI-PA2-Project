#include "Game.hpp"

Game::Game() {
    if (initialize(GAME_NAME, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                   GAME_WIDTH, GAME_HEIGHT, START_FULLSCREEN) != 0) {
        isRunning = false;
        throw std::runtime_error("SDL library failed to initialized");
    }
}

int Game::initialize(const char *title, int xPos, int yPos, int width, int height, bool fullscreen) {
    int initFullscreen = fullscreen ? SDL_WINDOW_FULLSCREEN : 0;

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        std::cerr << "SDL_INIT_EVERYTHING failed" << std::endl;
        return 1;
    }

    IMG_Init(IMG_INIT_PNG);

    MainWindow = SDL_CreateWindow(title, xPos, yPos, width, height, initFullscreen);
    if (MainWindow == nullptr) {
        std::cerr << "SDL_CreateWindow failed" << std::endl;
        return 2;
    }

    MainRenderer = SDL_CreateRenderer(MainWindow, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(MainRenderer, 100, 100, 100, 255);
    if (MainRenderer == nullptr) {
        std::cerr << "SDL_CreateRenderer failed" << std::endl;
        return 3;
    }
    /**Creating and inserting the platform and ball objects*/
    lives = new Lives(1); //todo
    platform = new Platform("Platform", PLATFORM_SRC, MainRenderer, lives);
    gameObjects.push_back(platform);
    ball = new Ball("Ball1", BALL_SRC, MainRenderer, lives);
    gameObjects.push_back(ball);


    isRunning = true;
    return 0;
}

int Game::play() {
    while (isRunning) {
        frameTicks = SDL_GetTicks();
        if (lives->GetLives() == 0) {
            std::cout << "GAME OVER" << std::endl;
            isRunning = false;
        }
        handleEvents();
        updateAll();
        Collisions();
        renderAll();

        frameDelta = SDL_GetTicks() - frameTicks;
        if (frameDelay > frameDelta) {
            SDL_Delay(frameDelay - frameDelta);
        }
    }

    cleanAll();
    return 0;
}

void Game::handleEvents() {
    SDL_Event events;
    SDL_PollEvent(&events);
    if (events.type == SDL_QUIT)            //Exit signal
        isRunning = false;
    if (events.type == SDL_KEYDOWN) {       //Keypress handling
        switch (events.key.keysym.sym) {
            case SDLK_SPACE:
                ball->Init(MainRenderer, platform->getPlatX());
                break;
            case SDLK_LEFT:
                platform->MoveLeft();
                break;
            case SDLK_RIGHT:
                platform->MoveRight();
                break;
            case SDLK_ESCAPE:
                isRunning = false;
                break;
            default:
                break;
        }
    }
}

void Game::Collisions() {
    for (auto it:gameObjects) {
        if (it->GetType() == BONUS) //TODO if we want to implement speed over time
            platform->Collided(platform->CollisionDetection(it));
        else if (it->GetType() != BALL)
            ball->Collided(ball->CollisionDetection(it));
        if (it->GetType() == BLOCK) {
            it->Collided(it->CollisionDetection(ball));
        }
    }
}

void Game::updateAll() {

    for (auto it:gameObjects) {
        it->Update();
    }
}

void Game::renderAll() {
    SDL_RenderClear(MainRenderer);
    for (auto it:gameObjects) {
        it->Render();
    }
    SDL_RenderPresent(MainRenderer);        //Draws stuff in window
}

void Game::cleanAll() {
    for (auto it:gameObjects) {
        it->Destroy();
    }
    SDL_DestroyRenderer(MainRenderer);
    SDL_DestroyWindow(MainWindow);
    IMG_Quit();
    SDL_Quit();
    std::cout << "Everything cleaned" << std::endl;
}
