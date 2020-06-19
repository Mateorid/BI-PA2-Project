#pragma once

#include <sstream>


#include "MenuState.hpp"

static const int LVL_COUNT = 3;

class MainMenu : public MenuState {
public:

    void Initialize(StateManager &) override;

    void HandleEvents(StateManager &) override;

private:
};


