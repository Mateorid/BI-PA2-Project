#include <SDL2/SDL.h>

#include "Application.hpp"
#include "StartupState.hpp"
#include "MainMenu.hpp"
#include "LoadState.hpp"
#include "GameState.hpp"
#include "ResultState.hpp"
#include "ExitState.hpp"


int main() {
    try {
        Application app;
        app.AddState(StateName::START, new StartupState());//todo move to const/init?
        app.AddState(StateName::MAIN_MENU, new MainMenu());
        app.AddState(StateName::LOAD_MAP, new LoadState());
        app.AddState(StateName::GAME, new GameState());
        app.AddState(StateName::RESULT, new ResultState());
        app.AddState(StateName::EXIT, new ExitState());
        app.Run();
        return 0;
    }
    catch (std::exception &err) {//this shouldn't trigger
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "ERROR", err.what(), nullptr);
        return 69;
    }
}