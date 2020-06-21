#include "ExitState.hpp"

void ExitState::Initialize(Application &app) {
    if (app.score != nullptr)
        delete app.score;
    if (app.mainWindow != nullptr)
        SDL_DestroyRenderer(app.mainRenderer);
    if (app.mainWindow != nullptr)
        SDL_DestroyWindow(app.mainWindow);
    if (app.font != nullptr)
        TTF_CloseFont(app.font);
    IMG_Quit();
    TTF_Quit();
    SDL_Quit();
    app.Exit();
    exit(0);
}
