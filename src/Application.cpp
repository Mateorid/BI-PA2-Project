#include "Application.hpp"
#include "StartupState.hpp"
#include "MainMenu.hpp"
#include "LoadState.hpp"
#include "GameState.hpp"
#include "ResultState.hpp"
#include "ExitState.hpp"


Application::Application(Resources &resources) : res(resources) {
    AddState(StateType::START, new StartupState());
    AddState(StateType::MAIN_MENU, new MainMenu());
    AddState(StateType::LOAD_MAP, new LoadState());
    AddState(StateType::GAME, new GameState());
    AddState(StateType::RESULT, new ResultState());
    AddState(StateType::EXIT, new ExitState());
}

Application::~Application() {
    Exit();
}

void Application::AddState(StateType stateType, State *state) {
    states[stateType] = std::shared_ptr<State>(state);
}

void Application::ChangeState(StateType stateType) {
    try {
        if (activeState != nullptr)
            activeState->Clean(*this);
        activeState = states[stateType];
        activeState->Initialize(*this);
    } catch (std::exception &err) {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "ERROR", err.what(), res.mainWindow);
        Exit();
    }
}

void Application::Run() {
    try {
        if (activeState == nullptr)
            ChangeState(StateType::START);
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
