#include <iostream>     //todo
#include "ExitState.hpp"

void ExitState::Initialize(StateManager &manager) {
    SDL_DestroyRenderer(manager.mainRenderer);
    SDL_DestroyWindow(manager.mainWindow);
    SDL_Quit();
    IMG_Quit();
    TTF_Quit();
    std::cout << "EXIT finished" << std::endl; //todo
//    manager.textPrinter.Exit();
    manager.Exit();
}
