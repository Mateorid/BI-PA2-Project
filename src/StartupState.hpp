#pragma once

#include <SDL2/SDL_ttf.h>
#include <iostream>


#include "State.hpp"


class StartupState : public State {
public:
    /**
     * Constructor - uses parent class constructor
     * @param app reference to Application gets stored for later use
     */
    explicit StartupState(Application &app) : State(app) {}

    /**
     * Initialize phase
     * Initializes everything needed for working with SDL, creates mainWindow & mainRenderer
     * Initializes TextPrinter
     * Assigns new ScoreManger
     * Lastly switches to MainMenu state
     * @throws runtime_error when initialization failed
     * @throws invalid_argument when font failed to open or when game window is too small
     */
    void Initialize() override;

private:
    /**Font destination*/
    const char *FONT_SRC = "examples/Gamer.ttf";
};





