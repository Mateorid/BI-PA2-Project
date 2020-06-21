#include "GameState.hpp"

void GameState::Initialize(Application &app) {
    toWin = app.gameObjects.size();         //Assign number of blocks to win

    app.platform = new Platform(app.mainRenderer);
    app.gameObjects.push_back(app.platform);

    app.ball1 = new Ball(app.mainRenderer, app.score);
    app.gameObjects.push_back(app.ball1);

    app.ball2 = new Ball(app.mainRenderer, app.score);
    app.gameObjects.push_back(app.ball2);

    app.bonus = new Bonus(app.mainRenderer, *app.ball1, *app.ball2, *app.platform,
                          *app.score);
    app.gameObjects.push_back(app.bonus);

    app.score->Init(*app.platform, *app.ball1, *app.ball2,
                    app.textPrinter);

    SDL_SetRenderDrawColor(app.mainRenderer, 100, 100, 100, 0);//Setting a gray background
    app.Run();
}

void GameState::HandleEvents(Application &app) {
    SDL_Event events{};
    while (SDL_PollEvent(&events)) {
        switch (events.type) {
            case SDL_QUIT:                                      //Clean signal
                app.ChangeState(StateName::EXIT);
            case SDL_KEYDOWN: //Key down handling
                switch (events.key.keysym.sym) {
                    case SDLK_SPACE:
                        if (!app.ball2->IsActive())
                            app.ball1->Init(app.platform->GetX());
                        break;
                    case SDLK_LEFT:
                        if (!isPaused)
                            app.platform->MoveLeft();
                        break;
                    case SDLK_RIGHT:
                        if (!isPaused)
                            app.platform->MoveRight();
                        break;
                    case SDLK_p:
                        isPaused = !isPaused;
                        break;
                    case SDLK_ESCAPE:
                        app.ChangeState(StateName::MAIN_MENU);
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
                            app.platform->Stop();
                        }
                    default:
                        break;
                }
            default:
                break;
        }
    }
}


void GameState::Update(Application &app) {
    if (isPaused)
        return;
    int tmpIt = 0;
    for (auto it:app.gameObjects) {
        if (it->IsActive())
            it->Update();
        else if (it->GetType() == BLOCK) {
            app.bonus->SpawnBonus(it->GetX(), it->GetY());
            toWin--;
            delete app.gameObjects[tmpIt];
            app.gameObjects.erase(app.gameObjects.begin() + tmpIt);
        }
        if (toWin == 0) {
            app.won = true;
            app.score->AddScores();
            app.ChangeState(StateName::RESULT);
            return;
        }
        tmpIt++;
    }
    if (app.score->GetLives() == 0) {
        app.won = false;
        app.score->AddScores();
        app.ChangeState(StateName::RESULT);
        return;
    }
    Collisions(app);
}

void GameState::Render(Application &app) {
    if (isPaused)
        return;
    SDL_RenderClear(app.mainRenderer);
    for (auto it:app.gameObjects) {
        if (it->IsActive())
            it->Render();
    }
    app.score->Render();
    SDL_RenderPresent(app.mainRenderer);
}

void GameState::Collisions(Application &app) {
    for (auto it:app.gameObjects) {
        if (!it->IsActive())//Skips all non-active Game objects
            continue;

        if (it->GetType() == BLOCK) {//Ball-Block collision
            if (app.ball1->CollisionDetection(it) || app.ball2->CollisionDetection(it)) {
                it->Collided(true);
                app.score->PlusScore();
            }
        } else if (it->GetType() == PLATFORM) {//Ball-Platform collision
            app.ball1->CollisionDetection(it);
            app.ball2->CollisionDetection(it);
        } else if (it->GetType() == BONUS) {//Bonus-Platform collision
            it->Collided(it->CollisionDetection(app.platform));
        }
    }
}

void GameState::Clean(Application &app) {
    app.ResetObjects();
}
