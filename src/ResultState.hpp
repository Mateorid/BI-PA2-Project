#pragma once

#include "MenuState.hpp"
#include "HighScoreManager.hpp"

class ResultState : public MenuState {
public:
    explicit ResultState(Application &app) : MenuState(app) {}

    void Initialize() override;

    void HandleEvents() override;

private:

    void HighScore();

    HighScoreManager highScore{};
};
