#pragma once


#include "State.hpp"

/**Game state*/
class GameState : public State {
public:
    /**
     * Constructor - uses parent class constructor
     * @param app reference to Application gets stored for later use
     */
    explicit GameState(Application &app) : State(app) {}

    /**Initializes the class and game objects*/
    void Initialize() override;

    /**Handles user input*/
    void HandleEvents() override;

    /**Updates active game objects*/
    void Update() override;

    /**Renders active game objects*/
    void Render() override;

    /**Clears game objects vector*/
    void Clean() override;

private:
    /**Checks for collisions of game objects using their Collision method*/
    void Collisions();

    /**Creates game obects that aren't bricks*/
    void CreateObjects();

    /**Bricks left to win*/
    int toWin = 0;
    /**Indicates if game is paused*/
    bool isPaused = false;
};


