#include "Application.hpp"


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
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "ERROR", err.what(), mainWindow);
        Exit();
    }
}

//todo catch stuff here?
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
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "ERROR", err.what(), mainWindow);
        Exit();
    }
}

void Application::Exit() {
    try {
        if (activeState != nullptr)
            activeState->Clean(*this);
        activeState = nullptr;
    } catch (std::exception &err) {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "ERROR", err.what(), mainWindow);
        return;
    }
}
