#pragma once

#include "MenuState.hpp"
#include "HighScoreManager.hpp"

/**Menu type state with result screen*/
class ResultState : public MenuState {
public:
    /**
     * Constructor - uses parent class constructor
     * @param app reference to Application gets stored for later use
     */
    explicit ResultState(Application &app) : MenuState(app) {}

    /**Initializes all menu texts & background*/
    void Initialize() override;

    /**Handles user input*/
    void HandleEvents() override;

private:

    /**Calls HighScoreManger class*/
    void HighScore();

    /**HighScoreManager instance*/
    HighScoreManager highScore{};
};
