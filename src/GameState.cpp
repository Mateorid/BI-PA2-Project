#include "GameState.hpp"

void GameState::Initialize() {
    toWin = app.res.gameObjects.size();         //Assign number of blocks to win
    app.res.won = false;

    try {
        CreateObjects();
        app.res.score->Init(*app.res.platform, *app.res.ball1, *app.res.ball2, app.res.textPrinter);
        if (SDL_SetRenderDrawColor(app.res.mainRenderer, 100, 100, 100, 0) < 0)//Setting a gray background
            throw std::runtime_error(SDL_GetError());
    } catch (std::exception &err) {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "ERROR", err.what(), app.res.mainWindow);
        app.ChangeState(StateType::EXIT);
    }
    app.Run();
}

void GameState::CreateObjects() {//todo static?
    app.res.platform = new Platform(app.res.mainRenderer);
    app.res.gameObjects.push_back(app.res.platform);

    app.res.ball1 = new Ball(app.res.mainRenderer, app.res.score);
    app.res.gameObjects.push_back(app.res.ball1);

    app.res.ball2 = new Ball(app.res.mainRenderer, app.res.score);
    app.res.gameObjects.push_back(app.res.ball2);

    app.res.bonus = new Bonus(app.res.mainRenderer, *app.res.ball1, *app.res.ball2, *app.res.platform,
                              *app.res.score);
    app.res.gameObjects.push_back(app.res.bonus);
}


void GameState::HandleEvents() {
    SDL_Event events{};
    while (SDL_PollEvent(&events)) {
        switch (events.type) {
            case SDL_QUIT:                                      //Clean signal
                app.ChangeState(StateType::EXIT);
            case SDL_KEYDOWN: //Key down handling
                switch (events.key.keysym.sym) {
                    case SDLK_SPACE:
                        if (!app.res.ball2->IsActive())
                            app.res.ball1->Init(app.res.platform->GetX());
                        break;
                    case SDLK_LEFT:
                        if (!isPaused)
                            app.res.platform->MoveLeft();
                        break;
                    case SDLK_RIGHT:
                        if (!isPaused)
                            app.res.platform->MoveRight();
                        break;
                    case SDLK_p:
                        isPaused = !isPaused;
                        break;
                    case SDLK_ESCAPE:
                        app.res.score->AddScores();
                        app.ChangeState(StateType::RESULT);
                        break;
                    default:
                        break;
                }
                break;
            case SDL_KEYUP: //Key release handling
                switch (events.key.keysym.sym) {
                    case SDLK_LEFT:
                    case SDLK_RIGHT:
                        if (!isPaused)
                            app.res.platform->Stop();
                        break;
                    default:
                        break;
                }
            default:
                break;
        }
    }
}

void GameState::Update() {
    if (isPaused)
        return;
    int tmpIt = 0;
    try {
        for (auto it:app.res.gameObjects) {
            if (it->IsActive())
                it->Update();
            else if (it->GetType() == BLOCK) {
                app.res.bonus->SpawnBonus(it->GetX(), it->GetY());
                toWin--;
                delete app.res.gameObjects[tmpIt];
                app.res.gameObjects.erase(app.res.gameObjects.begin() + tmpIt);
            }
            if (toWin == 0) {
                app.res.won = true;
                app.res.score->AddScores();
                app.ChangeState(StateType::RESULT);
                return;
            }
            tmpIt++;
        }
        if (app.res.score->GetLives() == 0) {
            app.res.won = false;
            app.res.score->AddScores();
            app.ChangeState(StateType::RESULT);
            return;
        }
        Collisions();
    } catch (std::exception &err) { //this shouldn't trigger
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "UNEXPECTED ERROR", err.what(), app.res.mainWindow);
        app.ChangeState(StateType::EXIT);
    }
}

void GameState::Render() {
    try {
        if (isPaused) {
            return;
        }
        if (SDL_RenderClear(app.res.mainRenderer) < 0)
            throw std::runtime_error(SDL_GetError());
        for (auto it:app.res.gameObjects) {
            if (it->IsActive())
                it->Render();
        }
        app.res.score->Render();
        SDL_RenderPresent(app.res.mainRenderer);
    } catch (std::exception &err) {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "UNEXPECTED ERROR", err.what(), app.res.mainWindow);
        app.ChangeState(StateType::EXIT);
    }
}

void GameState::Collisions() {//todo make this more polymorphic commit before tho xdd
    for (auto it:app.res.gameObjects) {
        if (!it->IsActive())//Skips all non-active Game objects
            continue;

        if (it->GetType() == BLOCK) {//Ball-Block collision
            if (app.res.ball1->CollisionDetection(it) || app.res.ball2->CollisionDetection(it)) {
                it->Collided(true);
                app.res.score->PlusScore();
            }
        } else if (it->GetType() == PLATFORM) {//Ball-Platform collision
            app.res.ball1->CollisionDetection(it);
            app.res.ball2->CollisionDetection(it);
        } else if (it->GetType() == BONUS) {//Bonus-Platform collision
            it->Collided(it->CollisionDetection(app.res.platform));
        }
    }
}

void GameState::Clean() {
    for (auto &gameObject : app.res.gameObjects) {
        delete gameObject;
    }
    app.res.gameObjects.clear();
}
