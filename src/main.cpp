//#include "Application.hpp"
#include "StateManager.hpp"
#include "StartupState.hpp"
#include "MenuState.hpp"
#include "ExitState.hpp"


int main(int argc, char *argv[]) {
    StateManager stateManager;
    stateManager.AddState(StateName::START, new StartupState());
    stateManager.AddState(StateName::MAIN_MENU, new MenuState());
    stateManager.AddState(StateName::EXIT, new ExitState());
    stateManager.Run();

    return 0;

//    try {
//        auto *app = new Application();
//        int tmp = app->Start();
//        delete app;
//        return tmp;
//    }
//    catch (std::runtime_error &err) {
//        std::cout << err.what() << std::endl;
//        return 69;
//    }
}