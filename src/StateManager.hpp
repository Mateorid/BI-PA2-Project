#pragma once

#include <map>
#include <memory>
#include <SDL2/SDL.h>
#include <vector>


#include "State.hpp"
#include "TextPrinter.hpp"
#include "GameObject.hpp"
#include "Platform.hpp"
#include "Ball.hpp"
#include "Bonus.hpp"

class State;

class Block;

class Platform;

class Bonus;

enum class StateName {
    START,
    MAIN_MENU,
    LOAD_MAP,
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

    int GetLevel() const { return selectedLevel; }

    void SetLevel(int x) { selectedLevel = x; }

    SDL_Renderer *mainRenderer{};
    SDL_Window *mainWindow{};
    TextPrinter textPrinter{};
    std::vector<GameObject *> bricks;
private: // todo create font here maybe? & clear it here as well? nope?
    std::shared_ptr<State> activeState;
    std::map<StateName, std::shared_ptr<State>> states;
    int selectedLevel = 0;
    Uint32 frameTicks{};
    Uint32 frameDelta{};
};




