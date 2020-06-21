#pragma once

#include <map>
#include <memory>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <vector>


#include "State.hpp"
#include "Resources.hpp"

/**Game title*/
static const char *const GAME_NAME = "Arkanoid 2020";
/**Game window height*/
static const int APP_HEIGHT = 800;                  //currently fixed on 800
/**Game window width*/
static const int APP_WIDTH = (3 * APP_HEIGHT) / 4;  //dropped res changing
/**FPS limit*/
static const int MAX_FPS = 100;
/**Frame delay*/
static const int FRAME_DELAY = 1000 / MAX_FPS;

class State;

class Resources;

/**State IDs*/
enum class StateName {
    START,
    MAIN_MENU,
    LOAD_MAP,
    GAME,
    RESULT,
    EXIT,
};

/**
 * 
 * Class is inspired by Jan Matoušek snake game series, refactored & edited for my application
 * @author Jan Matoušek <jan.matousek@fit.cvut.cz> (https://www.youtube.com/playlist?list=PLuOBL1HCzT4fxwtSEvk30_k3kwVfuqTNh)
 */
class Application {
public:
    explicit Application(Resources &);

    ~Application();

    /** Copy-cons is deleted, because copy of application is not applicable. */
    Application(const Application &) = delete;

    Application &operator=(const Application &) = delete;

    void AddState(StateName, State *);

    void ChangeState(StateName);

    void Run();

    void Exit();

    int GetLevel() const { return selectedLevel; }

    void SetLevel(int x) { selectedLevel = x; }

    Resources &res;
private:
    int selectedLevel = 0;
    std::shared_ptr<State> activeState;
    std::map<StateName, std::shared_ptr<State>> states;
    Uint32 frameTicks{};
    Uint32 frameDelta{};
};
