#include "Game.hpp"

Game::Game() {
    if (Initialize(GAME_NAME, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                   GAME_WIDTH, GAME_HEIGHT, START_FULLSCREEN) != 0) {
        isRunning = false;
        throw std::runtime_error("SDL library failed to initialized");
    }
}

int Game::Initialize(const char *title, int xPos, int yPos, int width, int height, bool fullscreen) {
    int initFullscreen = fullscreen ? SDL_WINDOW_FULLSCREEN : 0;

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        std::cerr << "SDL_INIT_EVERYTHING failed" << std::endl;
        return 1;
    }

    IMG_Init(IMG_INIT_PNG);

    mainWindow = SDL_CreateWindow(title, xPos, yPos, width, height, initFullscreen);
    if (mainWindow == nullptr) {
        std::cerr << "SDL_CreateWindow failed" << std::endl;
        return 2;
    }

    mainRenderer = SDL_CreateRenderer(mainWindow, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(mainRenderer, 100, 100, 100, 255);
    if (mainRenderer == nullptr) {
        std::cerr << "SDL_CreateRenderer failed" << std::endl;
        return 3;
    }
    /**Creating and inserting the platform and ball objects*/
    lives = new Lives(1); //todo
    platform = new Platform("Platform", mainRenderer, lives);
    gameObjects.push_back(platform);
    ball = new Ball("Ball1", mainRenderer, lives);
    gameObjects.push_back(ball);
    /**Tmp solution before I implement MapLoader*/
    auto *block = new Block("tmpBlock1", mainRenderer, 1, 300, 10);
    gameObjects.push_back(block);
    auto *block2 = new Block("tmpBlock2", mainRenderer, 2, 300, 100);
    gameObjects.push_back(block2);
    auto *block3 = new Block("tmpBlock3", mainRenderer, 3, 300, 160);
    gameObjects.push_back(block3);
    auto *bonus = new Bonus(mainRenderer, 200, 20);
    gameObjects.push_back(bonus);


    isRunning = true;
    return 0;
}

int Game::Play() {
    while (isRunning) {
        frameTicks = SDL_GetTicks();
        if (lives->GetLives() == 0) {
            std::cout << "GAME OVER" << std::endl;
            isRunning = false;
        }
        HandleEvents();
        UpdateAll();
        Collisions();
        RenderAll();

        frameDelta = SDL_GetTicks() - frameTicks;
        if (FRAME_DELAY > frameDelta) {
            SDL_Delay(FRAME_DELAY - frameDelta);
        }
    }

    CleanAll();
    return 0;
}

void Game::HandleEvents() {
    SDL_Event events;
    SDL_PollEvent(&events);
    if (events.type == SDL_QUIT)            //Exit signal
        isRunning = false;
    if (events.type == SDL_KEYDOWN) {       //Keypress handling
        switch (events.key.keysym.sym) {
            case SDLK_SPACE:
                ball->Init(mainRenderer, platform->getPlatX());
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

void Game::UpdateAll() {
    for (auto it:gameObjects) {
        if (it->GetActive())
            it->Update();
    }
    //todo update returning bool if its still active => delete if not (using the method in .h)
}

void Game::RenderAll() {
    SDL_RenderClear(mainRenderer);
    for (auto it:gameObjects) {
        if (it->GetActive())
            it->Render();
    }
    SDL_RenderPresent(mainRenderer);        //Draws stuff in window
}

void Game::CleanAll() {
    for (auto it:gameObjects) {
        it->Destroy();
    }
    SDL_DestroyRenderer(mainRenderer);
    SDL_DestroyWindow(mainWindow);
    IMG_Quit();
    SDL_Quit();
    std::cout << "Everything cleaned" << std::endl;
}
