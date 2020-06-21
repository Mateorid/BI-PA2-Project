#include "StateManager.hpp"


StateManager::~StateManager() {
    if (activeState != nullptr)
        activeState->Clean(*this);
}

void StateManager::AddState(StateName stateName, State *state) {
    states[stateName] = std::shared_ptr<State>(state);
}

void StateManager::ChangeState(StateName stateName) {
    if (activeState != nullptr)
        activeState->Clean(*this);
    activeState = states[stateName];
    activeState->Initialize(*this);
}

void StateManager::Run() {
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

void StateManager::Exit() {
//    ResetObjects();
    if (activeState != nullptr)
        activeState->Clean(*this);
    activeState = nullptr;
}

void StateManager::ResetObjects() {
    for (auto &gameObject : gameObjects) {
        delete gameObject;
    }
    gameObjects.clear();
}
