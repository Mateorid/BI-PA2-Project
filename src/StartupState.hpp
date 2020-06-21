#pragma once

#include <SDL2/SDL_ttf.h>
#include <iostream>


#include "State.hpp"


class StartupState : public State {
public:

    explicit StartupState(Application &app) : State(app) {}

    void Initialize() override;

    void Update() override;

private:
    /**Font destination*/
    const char *FONT_SRC = "examples/Gamer.ttf";
};





