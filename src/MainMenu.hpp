#pragma once


#include "MenuState.hpp"


class MainMenu : public MenuState {
public:
    /**
     * Constructor - uses parent class constructor
     * @param app reference to Application gets stored for later use
     */
    explicit MainMenu(Application &app) : MenuState(app) {}

    /**
     * Initializes all menu text
     * Displays error message box if text initialization failed
     */
    void Initialize() override;

    /**Handles user keyboard & quit inputs*/
    void HandleEvents() override;

private:
    /**Number of available levels*/
    static const int LVL_COUNT = 5;
};


