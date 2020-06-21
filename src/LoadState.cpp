#include "LoadState.hpp"

void LoadState::Initialize(Application &app) {
    try {
        switch (app.GetLevel()) {
            case 1:
                MapLoader(MAP1_SRC, app);
                break;
            case 2:
                MapLoader(MAP2_SRC, app);
                break;
            case 3:
                MapLoader(MAP3_SRC, app);
                break;
            case 4:
                MapLoader(MAP4_SRC, app);
                break;
            case 5:
                MapLoader(MAP5_SRC, app);
                break;
            default:
                MapLoader(MAP1_SRC, app);
                break;
        }
    } catch (std::exception &err) {
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "ERROR", err.what(), app.res.mainWindow);
        app.ChangeState(StateName::EXIT);
    }
    app.ChangeState(StateName::GAME);
}
