#pragma once

#include "MenuState.hpp"
#include "HighscoreManager.hpp"

class ResultState : public MenuState {
public:
    void Initialize(StateManager &) override;

    void HandleEvents(StateManager &) override;

private:

    void Highscore(StateManager &);

    HighscoreManager highscore{};
};
