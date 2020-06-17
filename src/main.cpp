#include "StateManager.hpp"
#include "StartupState.hpp"
#include "MenuState.hpp"
#include "LoadState.hpp"
#include "GameState.hpp"
#include "VictoryState.hpp"
#include "ExitState.hpp"


int main(int argc, char *argv[]) {
    try {
        StateManager stateManager;
        stateManager.AddState(StateName::START, new StartupState());
        stateManager.AddState(StateName::MAIN_MENU, new MenuState());
        stateManager.AddState(StateName::LOAD_MAP, new LoadState());
        stateManager.AddState(StateName::GAME, new GameState());
        stateManager.AddState(StateName::VICTORY, new VictoryState());
        stateManager.AddState(StateName::EXIT, new ExitState());
        stateManager.Run();
        return 0;
    }
    catch (std::runtime_error &err) {
        std::cout << err.what() << std::endl;
        return 69;
    }
}