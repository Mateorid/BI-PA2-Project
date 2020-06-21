#include "Application.hpp"
#include "StartupState.hpp"
#include "MainMenu.hpp"
#include "LoadState.hpp"
#include "GameState.hpp"
#include "ResultState.hpp"
#include "ExitState.hpp"


int main(int argc, char *argv[]) {
    try {
        Application app;
        app.AddState(StateName::START, new StartupState());
        app.AddState(StateName::MAIN_MENU, new MainMenu());
        app.AddState(StateName::LOAD_MAP, new LoadState());
        app.AddState(StateName::GAME, new GameState());
        app.AddState(StateName::RESULT, new ResultState());
        app.AddState(StateName::EXIT, new ExitState());
        app.Run();
        return 0;
    }
    catch (std::runtime_error &err) {
        std::cout << err.what() << std::endl;
        return 69;
    }
}