#pragma once

#include <map>
#include <memory>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <vector>


#include "State.hpp"
#include "TextPrinter.hpp"
#include "ScoreManager.hpp"
#include "GameObject.hpp"
#include "Platform.hpp"
#include "Ball.hpp"
#include "Bonus.hpp"

/**FPS limit*/
static const int MAX_FPS = 100;
/**Frame delay*/
static const int FRAME_DELAY = 1000 / MAX_FPS;

class State;

class Block;

class Platform;

class Bonus;

enum class StateName {
    START,
    MAIN_MENU,
    LOAD_MAP,
    GAME,
    RESULT,
    EXIT,
};

//Inspired by J. Matousek(https://www.youtube.com/watch?v=EFCHth2vR24&list=PLuOBL1HCzT4fxwtSEvk30_k3kwVfuqTNh&index=3&t=5114s)
class Application {
public:

    ~Application();

    void AddState(StateName, State *);

    void ChangeState(StateName);

    void Run();

    void Exit();

    void ResetObjects();

    int GetLevel() const { return selectedLevel; }

    void SetLevel(int x) { selectedLevel = x; }

    TextPrinter textPrinter{};
    ScoreManager *score{};
    Platform *platform{};
    Ball *ball1{};
    Ball *ball2{};
    Bonus *bonus{};
    std::vector<GameObject *> gameObjects;
    SDL_Renderer *mainRenderer{};
    SDL_Window *mainWindow{};
    TTF_Font *font{};
    bool won = false;
private:
    int selectedLevel = 0;
    std::shared_ptr<State> activeState;
    std::map<StateName, std::shared_ptr<State>> states;
    Uint32 frameTicks{};
    Uint32 frameDelta{};
};




