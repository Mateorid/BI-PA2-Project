#include "LoadState.hpp"

void LoadState::Initialize(StateManager &manager) {
    switch (manager.GetLevel()) {
        case 1:
            mapLoader = new MapLoader(MAP1_SRC, manager.mainRenderer);
            break;
        case 2:
            mapLoader = new MapLoader(MAP2_SRC, manager.mainRenderer);
            break;
        case 3:
            mapLoader = new MapLoader(MAP3_SRC, manager.mainRenderer);
            break;
        default:
            mapLoader = new MapLoader(MAP1_SRC, manager.mainRenderer);
            break;
    }
    manager.gameObjects = std::move(mapLoader->getBlocks());
    manager.ChangeState(StateName::GAME);
}

void LoadState::Clean(StateManager &) {
    delete mapLoader;
}
