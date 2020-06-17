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

    std::vector<std::shared_ptr<GameObject>> gameObjects;
    std::shared_ptr<Platform> platform;
    std::shared_ptr<Ball> ball1;
    std::shared_ptr<Ball> ball2;
    std::shared_ptr<Bonus> bonus;
    ScoreManager *score{};
    int toWin = 0;
    bool isPaused = false;
};




