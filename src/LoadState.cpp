#include "LoadState.hpp"

void LoadState::Initialize(StateManager &manager) {
//    manager.ResetObjects();
    switch (manager.GetLevel()) {
        case 1:
            mapLoader = new MapLoader(MAP1_SRC, manager);
            break;
        case 2:
            mapLoader = new MapLoader(MAP2_SRC, manager);
            break;
        case 3:
            mapLoader = new MapLoader(MAP3_SRC, manager);
            break;
        default:
            mapLoader = new MapLoader(MAP1_SRC, manager);
            break;
    }
    manager.ChangeState(StateName::GAME);
}

void LoadState::Clean(StateManager &) {
    delete mapLoader;
}
