#pragma once


#include "MenuState.hpp"

static const int LVL_COUNT = 3;

class MainMenu : public MenuState {
public:

    void Initialize(Application &) override;

    void HandleEvents(Application &) override;

private:
};


