#include "ExitState.hpp"

void ExitState::Initialize() {
    if (app.res.mainWindow != nullptr)
        SDL_DestroyRenderer(app.res.mainRenderer);
    if (app.res.mainWindow != nullptr)
        SDL_DestroyWindow(app.res.mainWindow);
    if (app.res.font != nullptr)
        TTF_CloseFont(app.res.font);
    delete app.res.score;
    IMG_Quit();
    TTF_Quit();
    SDL_Quit();
    app.Exit();
    exit(0);
}
