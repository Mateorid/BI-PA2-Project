#include "Game.hpp"

#include <utility>

Game::Game(std::vector<GameObject *> obj, SDL_Renderer *renderer) {
    toWin = obj.size();         //Assign number of blocks
    gameObjects = std::move(obj); //todo is the old one empty now? Can I still clean it with loop in app?
    mainRenderer = renderer;
    Initialize();
}

void Game::Initialize() {
    /**Creating and inserting the platform and ball1 objects*/
    score = new ScoreManager(mainRenderer, START_LIVES);
    platform = new Platform(mainRenderer);
    gameObjects.push_back(platform);
    ball1 = new Ball(mainRenderer, score);
    gameObjects.push_back(ball1);
    ball2 = new Ball(mainRenderer, score);
    gameObjects.push_back(ball2);
    bonus = new Bonus(mainRenderer, *ball1, *ball2, *platform, *score);
    gameObjects.push_back(bonus);
    score->Init(*platform, *ball1, *ball2);
    isRunning = true;
}

int Game::Play() {
    while (isRunning) {
        frameTicks = SDL_GetTicks();

        HandleEvents();
        UpdateAll();
        Collisions();
        RenderAll();

        frameDelta = SDL_GetTicks() - frameTicks;                           //FPS handling
        if (FRAME_DELAY > frameDelta) {
            SDL_Delay(FRAME_DELAY - frameDelta);
        }
    }
//todo win/defeat check
    if (toWin == 0)
        Victory();
    else
        Defeat();
//    CleanAll();
    return 0;
}

void Game::HandleEvents() {
    SDL_Event events;
    SDL_PollEvent(&events);
    if (events.type == SDL_QUIT)                                            //Exit signal
        isRunning = false;
    if (events.type == SDL_KEYDOWN) {                                       //Keypress handling
        switch (events.key.keysym.sym) {
            case SDLK_SPACE:
                ball1->Init(platform->GetX());
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
        if (!it->IsActive())//Skips all non-active Game objects
            continue;

        if (it->GetType() == BLOCK) {//Ball-Block collision
            if (ball1->CollisionDetection(it) || ball2->CollisionDetection(it)) {
                it->Collided(true);
                score->PlusScore();
            }
        } else if (it->GetType() == PLATFORM) {//Ball-Platform collision
            ball1->CollisionDetection(it);
            ball2->CollisionDetection(it);
        } else if (it->GetType() == BONUS) {//Bonus-Platform collision
            it->Collided(it->CollisionDetection(platform));
        }
    }
}

void Game::UpdateAll() {
    int tmpIt = 0;
    for (auto it:gameObjects) {
        if (it->IsActive())
            it->Update();
        else if (it->ToDelete()) {
            if (it->GetType() == BLOCK) {
                bonus->SpawnBonus(it->GetX(), it->GetY());
                toWin--;
            }
            gameObjects.erase(gameObjects.begin() + tmpIt);
            std::cout << "DELETED SOMETHING" << std::endl;
            if (toWin == 0) {
                isRunning = false;
                return;
            }
        }
        tmpIt++;
    }
    if (score->GetLives() == 0) {
        isRunning = false;
        return;
    }
}

void Game::RenderAll() {
    SDL_RenderClear(mainRenderer);
    for (auto it:gameObjects) {
        if (it->IsActive())
            it->Render();
    }
    score->Render();
    SDL_RenderPresent(mainRenderer);        //Draws stuff in window
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

void Game::Victory() {
    std::cout << "YOU WON" << std::endl;
}

void Game::Defeat() {
    std::cout << "YOU LOST" << std::endl;
}
