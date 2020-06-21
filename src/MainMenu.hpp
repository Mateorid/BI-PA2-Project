#pragma once


#include "MenuState.hpp"


class MainMenu : public MenuState {
public:
    explicit MainMenu(Application &app) : MenuState(app) {}

    void Initialize() override;

    void HandleEvents() override;

private:
    /**Number of available levels*/
    static const int LVL_COUNT = 5;
};


