#include "Application.hpp"


Application::~Application() {
    if (activeState != nullptr)
        activeState->Clean(*this);
}

void Application::AddState(StateName stateName, State *state) {
    states[stateName] = std::shared_ptr<State>(state);
}

void Application::ChangeState(StateName stateName) {
    if (activeState != nullptr)
        activeState->Clean(*this);
    activeState = states[stateName];
    activeState->Initialize(*this);
}

void Application::Run() {
    if (activeState == nullptr)
        ChangeState(StateName::START);
    while (activeState) {
        frameTicks = SDL_GetTicks();
        activeState->HandleEvents(*this);
        if (activeState) activeState->Update(*this);
        if (activeState) activeState->Render(*this);
        frameDelta = SDL_GetTicks() - frameTicks;                           //FPS handling
        if (FRAME_DELAY > frameDelta) {
            SDL_Delay(FRAME_DELAY - frameDelta);
        }
    }
}

void Application::Exit() {
    if (activeState != nullptr)
        activeState->Clean(*this);
    activeState = nullptr;
}

void Application::ResetObjects() {
    for (auto &gameObject : gameObjects) {
        delete gameObject;
    }
    gameObjects.clear();
}
