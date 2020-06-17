#pragma once


#include "State.hpp"
#include "MapLoader.hpp"


class LoadState : public State {
public:
    void Initialize(StateManager &) override;

    void Clean(StateManager &) override;

private:
    MapLoader *mapLoader{};
};




