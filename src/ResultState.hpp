#pragma once

#include "MenuState.hpp"

class ResultState : public MenuState {
public:
    void Initialize(StateManager &) override;

    void HandleEvents(StateManager &) override;

private:
};
