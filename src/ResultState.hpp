#pragma once

#include "MenuState.hpp"
#include "HighscoreManager.hpp"

class ResultState : public MenuState {
public:
    void Initialize(Application &) override;

    void HandleEvents(Application &) override;

private:

    void HighScore(Application &);

    HighscoreManager highScore{};
};
