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
    VICTORY,
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

    void ResetObjects();

    int GetLevel() const { return selectedLevel; }

    void SetLevel(int x) { selectedLevel = x; }

    SDL_Renderer *mainRenderer{};
    SDL_Window *mainWindow{};
    TextPrinter textPrinter{};
    std::vector<GameObject *> gameObjects;
    Platform *platform{};
    Ball *ball1{};
    Ball *ball2{};
    Bonus *bonus{};
    int totalScore = 0;//todo += in gamestate
private: // todo create font here maybe? & clear it here as well? nope?
    int selectedLevel = 0;
    std::shared_ptr<State> activeState;
    std::map<StateName, std::shared_ptr<State>> states;
    Uint32 frameTicks{};
    Uint32 frameDelta{};
};




