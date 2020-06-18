#include "ExitState.hpp"

void ExitState::Initialize(StateManager &manager) {
    SDL_DestroyRenderer(manager.mainRenderer);
    SDL_DestroyWindow(manager.mainWindow);
    TTF_CloseFont(manager.font);
    SDL_Quit();
    IMG_Quit();
    TTF_Quit();
    manager.Exit();
}
