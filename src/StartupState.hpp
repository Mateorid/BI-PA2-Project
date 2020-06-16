#pragma once

#include <SDL2/SDL_ttf.h>
#include <iostream>


#include "State.hpp"


/**Destination of map source*/
static const char *const MAP_SRC = "examples/map.map";

class StartupState : public State {
public:
    StartupState() = default;

    void Initialize(StateManager &) override;

    void HandleEvents(StateManager &) override {};

    void Update(StateManager &) override;

    void Render(StateManager &) override {};

    void Clean(StateManager &) override {}; //todo delete those with {}
};





