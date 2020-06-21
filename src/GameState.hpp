#pragma once


#include "State.hpp"

class GameState : public State {
public:
    void Initialize(Application &) override;

    void HandleEvents(Application &) override;

    void Update(Application &) override;

    void Render(Application &) override;

    void Clean(Application &) override;

private:
    void Collisions(Application &);

    int toWin = 0;
    bool isPaused = false;
};


