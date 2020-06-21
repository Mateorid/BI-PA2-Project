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

/**Game title*/
static const char *const GAME_NAME = "Arkanoid 2020";
/**Game window height*/
static const int APP_HEIGHT = 800;  //currently fixed on 800
/**Game window width*/
static const int APP_WIDTH = (3 * APP_HEIGHT) / 4; //todo try multiples of 12?
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

/**
 * Class inspired Jan Matoušek's snake game series, refactored & edited for my application
 * @author Jan Matoušek <jan.matousek@fit.cvut.cz> (https://www.youtube.com/playlist?list=PLuOBL1HCzT4fxwtSEvk30_k3kwVfuqTNh)
 */
class Application {
public:
//todo delete copy
    ~Application();

    void AddState(StateName, State *);

    void ChangeState(StateName);

    void Run();

    void Exit();

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




