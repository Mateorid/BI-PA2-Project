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

/**State types*/
enum class StateType {
    START,
    MAIN_MENU,
    LOAD_MAP,
    GAME,
    RESULT,
    EXIT,
};

/**
 * Handles transitions between game state states
 * Class is inspired by Jan Matoušek snake game series, refactored & edited for my application
 * @author Jan Matoušek <jan.matousek@fit.cvut.cz> (https://www.youtube.com/playlist?list=PLuOBL1HCzT4fxwtSEvk30_k3kwVfuqTNh)
 */
class Application {
public:
    /**
     * Constructor - Adds 6 states to states map
     * @param resources Reference to resource class
     */
    explicit Application(Resources &resources);

    /** Destructor*/
    ~Application();

    /** Copy-cons is deleted, because we only want 1 instance of Application. */
    Application(const Application &) = delete;

    /** = operator is deleted, because we only want 1 instance of Application. */
    Application &operator=(const Application &) = delete;


    /**
     * Changes the activeState pointer to selected one
     * @param stateType desired state type
     */
    void ChangeState(StateType stateType);

    /**
     *"Runs" currently active state by looping through its
     * HandleEvents-Update-Render methods
     */
    void Run();

    /**Clears currently active state*/
    void Exit();

    /** Reference to a "wrapping" Resource class that holds all the important stuff*/
    Resources &res;
private:
    /**
     * Adds new state to our states map
    * @param stateType enum class of the state type
    * @param state new State class
    */
    void AddState(StateType stateType, State *state);

    /** Shared_ptr that points to currently active state*/
    std::shared_ptr<State> activeState;
    /**
     * std::Map of all states in Application
     * ->First is the state type
     * ->Second is the shared_ptr to it
     */
    std::map<StateType, std::shared_ptr<State>> states;
    /**
     * Used for limiting Application render speed
     */
    Uint32 frameTicks{};
    Uint32 frameDelta{};
};
