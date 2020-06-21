#pragma once


#include "State.hpp"
#include "MapLoader.hpp"


class LoadState : public State {
public:
    void Initialize(Application &) override;

    void Clean(Application &) override;

private:
    MapLoader *mapLoader{};
};




