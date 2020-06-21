#pragma once


#include "State.hpp"
#include "MapLoader.hpp"


class LoadState : public State {
public:
    void Initialize(Application &) override;

private:
    /**Maps destination*/
    const char *MAP1_SRC = "examples/map1.map";
    const char *MAP2_SRC = "examples/map2.map";
    const char *MAP3_SRC = "examples/map3.map";
    const char *MAP4_SRC = "examples/map4.map";
    const char *MAP5_SRC = "examples/map5.map";
};




