#include "GameState.hpp"

void GameState::Initialize(StateManager &manager) {
    font = TTF_OpenFont(FONT_SRC, 50);
    if (font == nullptr)
        throw std::invalid_argument("ERROR! Failed to load font!");
    toWin = manager.bricks.size();         //Assign number of blocks to win

    gameObjects = std::move(manager.bricks);

    score = new ScoreManager(manager.mainRenderer, START_LIVES, font);

    platform = new Platform(manager.mainRenderer);
    gameObjects.push_back(platform);

    ball1 = new Ball(manager.mainRenderer, score);
    gameObjects.push_back(ball1);

    ball2 = new Ball(manager.mainRenderer, score);
    gameObjects.push_back(ball2);

    bonus = new Bonus(manager.mainRenderer, *ball1, *ball2, *platform, *score);
    gameObjects.push_back(bonus);

    score->Init(*platform, *ball1, *ball2);

    SDL_SetRenderDrawColor(manager.mainRenderer, 100, 100, 100, 0);//Setting a gray background
    manager.Run();
}

void GameState::HandleEvents(StateManager &manager) {
    SDL_Event events;
//    while (SDL_PollEvent(&events)) {
    SDL_PollEvent(&events);
        if (events.type == SDL_QUIT)                                            //Clean signal
            manager.ChangeState(StateName::EXIT);
        if (events.type == SDL_KEYDOWN) {                                       //Keypress handling
            switch (events.key.keysym.sym) {
                case SDLK_SPACE:
                    ball1->Init(platform->GetX());
                    break;
                case SDLK_LEFT:
                    if (!isPaused)
                        platform->MoveLeft();
                    break;
                case SDLK_RIGHT:
                    if (!isPaused)
                        platform->MoveRight();
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
        }
    }
//}

void GameState::Update(StateManager &manager) {
    int tmpIt = 0;
    for (auto it:gameObjects) {
        if (it->IsActive())
            it->Update();
        else if (it->GetType() == BLOCK) {
            bonus->SpawnBonus(it->GetX(), it->GetY());
            toWin--;
            delete gameObjects[tmpIt];
            gameObjects.erase(gameObjects.begin() + tmpIt);
        }
        if (toWin == 0) {
            manager.ChangeState(StateName::EXIT);//todo change to result
            return;
        }
        tmpIt++;
    }
    if (score->GetLives() == 0) {
        manager.ChangeState(StateName::EXIT);//todo change to result
        return;
    }
    Collisions(manager);
}

void GameState::Render(StateManager &manager) {
    SDL_RenderClear(manager.mainRenderer);
    for (auto it:gameObjects) {
        if (it->IsActive())
            it->Render();
    }
    score->Render();
    SDL_RenderPresent(manager.mainRenderer);
}

void GameState::Collisions(StateManager &manager) {
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

void GameState::Clean(StateManager &manager) {
    delete score;
    for (auto it:gameObjects) {
        delete it;
    }

    TTF_CloseFont(font);
}
