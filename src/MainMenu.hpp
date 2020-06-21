#pragma once


#include "MenuState.hpp"


class MainMenu : public MenuState {
public:

    void Initialize(Application &) override;

    void HandleEvents(Application &) override;

private:
    /**Number of available levels*/
    static const int LVL_COUNT = 5;
};


