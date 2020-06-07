#include "Game.hpp"

#include <utility>

Game::Game(std::vector<GameObject *> obj, SDL_Renderer *renderer) {
    toWin = obj.size();         //Assign number of blocks
    gameObjects = std::move(obj); //todo is the old one empty now? Can I still clean it with loop in app?
    mainRenderer = renderer;
    Initialize();
}

void Game::Initialize() {
    /**Creating and inserting the platform and ball objects*/
    lives = new Lives(START_LIVES);
    platform = new Platform(mainRenderer);
    gameObjects.push_back(platform);
    ball = new Ball(mainRenderer, lives);
    gameObjects.push_back(ball);

    /**Tmp solution before I implement MapLoader*/
    bonus = new Bonus(mainRenderer, 200, 20, *ball, *platform, *lives);
    gameObjects.push_back(bonus);
    auto *block = new Block(mainRenderer, 1, 300, 10);
    gameObjects.push_back(block);
    auto *block2 = new Block(mainRenderer, 1, 300, 100);
    gameObjects.push_back(block2);
    auto *block3 = new Block(mainRenderer, 1, 300, 160);
    gameObjects.push_back(block3);

    isRunning = true;
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
//    CleanAll();
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
                ball->Init(mainRenderer, platform->GetX());
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
        if (!it->IsActive())
            continue;
        if (it->GetType() == BONUS) {
            it->Collided(it->CollisionDetection(platform));
            continue;
        } else if (it->GetType() != BALL)
            ball->Collided(ball->CollisionDetection(it));
        if (it->GetType() == BLOCK) {
            it->Collided(it->CollisionDetection(ball));
        }
    }
}

void Game::UpdateAll() {
    int tmpIt = 0;
    for (auto it:gameObjects) {
        if (it->IsActive())
            it->Update();
        else if (it->ToDelete()) {
//            TODO: Add blocks left till win counter, (if BLOCK then toWin--)
            if (it->GetType() == BLOCK) {
                SpawnBonus(it->GetX(), it->GetY());
                toWin--;
            }
            gameObjects.erase(gameObjects.begin() + tmpIt);
            std::cout << "DELETED SOMETHING" << std::endl;
            //todo Add toWin win check here
        }
        tmpIt++;
    }
}

void Game::RenderAll() {
    SDL_RenderClear(mainRenderer);
    for (auto it:gameObjects) {
        if (it->IsActive())
            it->Render();
    }
    SDL_RenderPresent(mainRenderer);        //Draws stuff in window
}

void Game::SpawnBonus(int x, int y) {
//    srand(time(nullptr));
    bool tmp1 = (rand() & 1);   //25% chance of spawning a bonus
    bool tmp2 = (rand() & 1);
    if (tmp1) std::cout<< "1 true"<<std::endl;
    if (tmp2) std::cout<< "2 true"<<std::endl;
    if (tmp1 & tmp2)
        bonus->Init(x, y);
}

void Game::CleanAll() {
//    for (auto it:gameObjects) {
//        it->Destroy();
//    }
//    gameObjects.clear();
//    SDL_DestroyRenderer(mainRenderer);
//    SDL_DestroyWindow(mainWindow);
//    IMG_Quit();
//    SDL_Quit();
//    std::cout << "Everything cleaned" << std::endl;
}
