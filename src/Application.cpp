#include "Application.hpp"
#include "StartupState.hpp"
#include "MainMenu.hpp"
#include "LoadState.hpp"
#include "GameState.hpp"
#include "ResultState.hpp"
#include "ExitState.hpp"


Application::Application(Resources &resources) : res(resources) {
    AddState(StateName::START, new StartupState());
    AddState(StateName::MAIN_MENU, new MainMenu());
    AddState(StateName::LOAD_MAP, new LoadState());
    AddState(StateName::GAME, new GameState());
    AddState(StateName::RESULT, new ResultState());
    AddState(StateName::EXIT, new ExitState());
}

Application::~Application() {
    Exit();
}

void Application::AddState(StateName stateName, State *state) {
    states[stateName] = std::shared_ptr<State>(state);
}

void Application::ChangeState(StateName stateName) {
    try {
        if (activeState != nullptr)
            activeState->Clean(*this);
        activeState = states[stateName];
        activeState->Initialize(*this);
    } catch (std::exception &err) {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "ERROR", err.what(), res.mainWindow);
        Exit();
    }
}

void Application::Run() {
    try {
        if (activeState == nullptr)
            ChangeState(StateName::START);
        while (activeState) {
            frameTicks = SDL_GetTicks();

            activeState->HandleEvents(*this);
            if (activeState)
                activeState->Update(*this);
            if (activeState)
                activeState->Render(*this);

            frameDelta = SDL_GetTicks() - frameTicks;                           //FPS handling
            if (FRAME_DELAY > frameDelta) {
                SDL_Delay(FRAME_DELAY - frameDelta);
            }
        }
    } catch (std::exception &err) {//shouldn't happen
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "ERROR", err.what(), res.mainWindow);
        Exit();
    }
}

void Application::Exit() {
    try {
        if (activeState != nullptr)
            activeState->Clean(*this);
        activeState = nullptr;
    } catch (std::exception &err) {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "ERROR", err.what(), res.mainWindow);
        return;
    }
}
