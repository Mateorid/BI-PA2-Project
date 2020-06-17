#include "GameState.hpp"

void GameState::Initialize(StateManager &manager) {
    font = TTF_OpenFont(FONT_SRC, 50);
    if (font == nullptr)
        throw std::invalid_argument("ERROR! Failed to load font!");
    toWin = manager.bricks.size();         //Assign number of blocks to win

    gameObjects = std::move(manager.bricks);

    score = new ScoreManager(manager.mainRenderer, START_LIVES, font);

    platform.reset(new Platform(manager.mainRenderer));
//    platform = std::make_shared<Platform>(manager.mainRenderer);
    gameObjects.emplace_back(platform);
//    gameObjects.push_back(platform);

    ball1.reset(new Ball(manager.mainRenderer, score));
//    ball1 = std::make_shared<Ball>(manager.mainRenderer, score);
    gameObjects.emplace_back(ball1);
//    gameObjects.push_back(ball1);

    ball2.reset(new Ball(manager.mainRenderer, score));
//    ball2 = std::make_shared<Ball>(manager.mainRenderer, score);
    gameObjects.emplace_back(ball2);
//    gameObjects.push_back(ball2);

    bonus.reset(new Bonus(manager.mainRenderer, *ball1, *ball2, *platform, *score));
//    bonus = std::make_shared<Bonus>(manager.mainRenderer, *ball1, *ball2, *platform, *score);
    gameObjects.emplace_back(bonus);
//    gameObjects.push_back(bonus);

    score->Init(*platform, *ball1, *ball2);

    SDL_SetRenderDrawColor(manager.mainRenderer, 100, 100, 100, 0);//Setting a gray background

    manager.Run();
}

void GameState::HandleEvents(StateManager &manager) {
    SDL_Event events{};
    while (SDL_PollEvent(&events)) {
        switch (events.type) {
            case SDL_QUIT:                                      //Clean signal
                manager.ChangeState(StateName::EXIT);
            case SDL_KEYDOWN:                                   //Key down handling
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
                break;
            case SDL_KEYUP:                                     //Key release handling
                switch (events.key.keysym.sym) {
                    case SDLK_LEFT:
                    case SDLK_RIGHT:
                        if (!isPaused) {
                            platform->Stop();
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
    for (const auto &it:gameObjects) {
        if (it->IsActive())
            it->Update();
        else if (it->GetType() == BLOCK && !it->Used()) {   //Block that hasn't been given the change to spawn bonus
            bonus->SpawnBonus(it->GetX(), it->GetY());
            toWin--;
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
    if (isPaused)
        return;

    SDL_RenderClear(manager.mainRenderer);
    for (const auto &it:gameObjects) {
        if (it->IsActive())
            it->Render();
    }
    score->Render();
    SDL_RenderPresent(manager.mainRenderer);
}

void GameState::Collisions(StateManager &manager) {
    for (const auto &it:gameObjects) {
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
//    std::cout << "gameObject loop" << std::endl;
//    while (!gameObjects.empty()) {
//        gameObjects.pop_back();    }
//    std::cout << "Stuff reset" << std::endl;
//    platform.reset();
//    ball1.reset();
//    ball2.reset();
//    bonus.reset();
//    std::cout << "gameObject.clear()" << std::endl;
//    gameObjects.clear();
    TTF_CloseFont(font);
}
