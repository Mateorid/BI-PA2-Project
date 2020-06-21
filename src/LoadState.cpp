#include "LoadState.hpp"

void LoadState::Initialize(Application &app) {
    switch (app.GetLevel()) {
        case 1:
            mapLoader = new MapLoader(MAP1_SRC, app);
            break;
        case 2:
            mapLoader = new MapLoader(MAP2_SRC, app);
            break;
        case 3:
            mapLoader = new MapLoader(MAP3_SRC, app);
            break;
        default:
            mapLoader = new MapLoader(MAP1_SRC, app);
            break;
    }
    app.ChangeState(StateName::GAME);
}

void LoadState::Clean(Application &) {
    delete mapLoader;
}
