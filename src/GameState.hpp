#pragma once


#include "State.hpp"

class GameState : public State {
public:
    explicit GameState(Application &app) : State(app) {}

    void Initialize() override;

    void HandleEvents() override;

    void Update() override;

    void Render() override;

    void Clean() override;

private:
    void Collisions();

    void CreateObjects();

    int toWin = 0;
    bool isPaused = false;
};


