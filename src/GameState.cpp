#include "GameState.hpp"

void GameState::Initialize(StateManager &manager) {
    font = TTF_OpenFont(FONT_SRC, 50);
    if (font == nullptr)
        throw std::invalid_argument("ERROR! Failed to load font!");


    toWin = manager.gameObjects.size();         //Assign number of blocks to win
    score = new ScoreManager(manager.mainRenderer, START_LIVES, font);

    manager.platform = new Platform(manager.mainRenderer);
    manager.gameObjects.push_back(manager.platform);

    manager.ball1 = new Ball(manager.mainRenderer, score);
    manager.gameObjects.push_back(manager.ball1);

    manager.ball2 = new Ball(manager.mainRenderer, score);
    manager.gameObjects.push_back(manager.ball2);

    manager.bonus = new Bonus(manager.mainRenderer, *manager.ball1, *manager.ball2, *manager.platform, *score); //todo valgrind ???
    manager.gameObjects.push_back(manager.bonus);

    score->Init(*manager.platform, *manager.ball1, *manager.ball2);

    SDL_SetRenderDrawColor(manager.mainRenderer, 100, 100, 100, 0);//Setting a gray background
    manager.Run();
}

void GameState::HandleEvents(StateManager &manager) {
    SDL_Event events{};
    while (SDL_PollEvent(&events)) {
        switch (events.type) {
            case SDL_QUIT:                                      //Clean signal
                manager.ChangeState(StateName::EXIT);
            case SDL_KEYDOWN: //Key down handling
                switch (events.key.keysym.sym) {
                    case SDLK_SPACE:
                        if (!manager.ball2->IsActive())
                            manager.ball1->Init(manager.platform->GetX());
                        break;
                    case SDLK_LEFT:
                        if (!isPaused)
                            manager.platform->MoveLeft();
                        break;
                    case SDLK_RIGHT:
                        if (!isPaused)
                            manager.platform->MoveRight();
                        break;
                    case SDLK_p:
                        isPaused = !isPaused;
                        break;
                    case SDLK_ESCAPE:
                        manager.ChangeState(StateName::EXIT);
                        break;
                    default:
                        break;
                }
                break;
            case SDL_KEYUP: //Key release handling
                switch (events.key.keysym.sym) {
                    case SDLK_LEFT:
                    case SDLK_RIGHT:
                        if (!isPaused) {
                            manager.platform->Stop();
                        }
                    default:
                        break;
                }
            default:
                break;
        }
    }
}


void GameState::Update(StateManager &manager) {
    if (isPaused)
        return;
    int tmpIt = 0;
    for (auto it:manager.gameObjects) {
        if (it->IsActive())
            it->Update();
        else if (it->GetType() == BLOCK) {
            manager.bonus->SpawnBonus(it->GetX(), it->GetY());
            toWin--;
            delete manager.gameObjects[tmpIt];
            manager.gameObjects.erase(manager.gameObjects.begin() + tmpIt);
        }
        if (toWin == 0) {
            manager.totalScore += score->GetScore();//todo
            manager.ChangeState(StateName::VICTORY);
            return;
        }
        tmpIt++;
    }
    if (score->GetLives() == 0) {
        manager.totalScore += score->GetScore();//todo
        manager.ChangeState(StateName::VICTORY);//todo defeat
        return;
    }
    Collisions(manager);
}

void GameState::Render(StateManager &manager) {
    if (isPaused)
        return;
    SDL_RenderClear(manager.mainRenderer);
    for (auto it:manager.gameObjects) {
        if (it->IsActive())
            it->Render();
    }
    score->Render();
    SDL_RenderPresent(manager.mainRenderer);
}

void GameState::Collisions(StateManager &manager) {
    for (auto it:manager.gameObjects) {
        if (!it->IsActive())//Skips all non-active Game objects
            continue;

        if (it->GetType() == BLOCK) {//Ball-Block collision
            if (manager.ball1->CollisionDetection(it) || manager.ball2->CollisionDetection(it)) {
                it->Collided(true);
                score->PlusScore();
            }
        } else if (it->GetType() == PLATFORM) {//Ball-Platform collision
            manager.ball1->CollisionDetection(it);
            manager.ball2->CollisionDetection(it);
        } else if (it->GetType() == BONUS) {//Bonus-Platform collision
            it->Collided(it->CollisionDetection(manager.platform));
        }
    }
}

void GameState::Clean(StateManager &manager) {
    delete score;
    TTF_CloseFont(font);
}
