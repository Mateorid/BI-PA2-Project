#include "ExitState.hpp"

void ExitState::Initialize(Application &app) {
    delete app.score;
    SDL_DestroyRenderer(app.mainRenderer);
    SDL_DestroyWindow(app.mainWindow);
    TTF_CloseFont(app.font);
    SDL_Quit();
    IMG_Quit();
    TTF_Quit();
    app.Exit();
}
