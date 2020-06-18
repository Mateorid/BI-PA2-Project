#pragma once


#include "State.hpp"

class GameState : public State {
public:
    void Initialize(StateManager &) override;

    void HandleEvents(StateManager &) override;

    void Update(StateManager &) override;

    void Render(StateManager &) override;

    void Clean(StateManager &) override;

private:
    void Collisions(StateManager &);

//    ScoreManager *score{};
    int toWin = 0;
    bool isPaused = false;
};


