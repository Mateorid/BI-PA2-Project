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
        activeState->HandleEvents(*this);
        if (activeState) activeState->Update(*this);
        if (activeState) activeState->Render(*this);
    }
}

void StateManager::Exit() {
    if (activeState != nullptr)
        activeState->Clean(*this);
    activeState = nullptr;
}
