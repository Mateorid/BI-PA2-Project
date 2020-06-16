#pragma once

#include <map>
#include <memory>
#include <SDL2/SDL.h>


#include "State.hpp"
#include "TextPrinter.hpp"

class State;

enum class StateName {
    START,
    MAIN_MENU,
    GAME,
    RESULTS,
    EXIT,
};

//Inspired by J. Matousek(https://www.youtube.com/watch?v=EFCHth2vR24&list=PLuOBL1HCzT4fxwtSEvk30_k3kwVfuqTNh&index=3&t=5114s)
class StateManager {
public:

    ~StateManager();

    void AddState(StateName, State *);

    void ChangeState(StateName);

    void Run();

    void Exit();


    SDL_Renderer *mainRenderer{};
    SDL_Window *mainWindow{};
    TextPrinter textPrinter{};
private: // todo create font here maybe? & clear it here as well? nope?
    std::shared_ptr<State> activeState;
    std::map<StateName, std::shared_ptr<State>> states;
};




