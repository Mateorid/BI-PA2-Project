#pragma once


#include "State.hpp"
#include "MapLoader.hpp"


class LoadState : public State {
public:
    /**
     * Constructor - uses parent class constructor
     * @param app reference to Application gets stored for later use
     */
    explicit LoadState(Application &app) : State(app) {}

    /**
     * Creates an instance of MapLoader depending on selected level
     * If selected level is not within range sets it to the 1st one and starts MapLoader
     */
    void Initialize() override;

private:
    /**Maps destinations*/
    const char *MAP1_SRC = "examples/map1.map";
    const char *MAP2_SRC = "examples/map2.map";
    const char *MAP3_SRC = "examples/map3.map";
    const char *MAP4_SRC = "examples/map4.map";
    const char *MAP5_SRC = "examples/map5.map";
};




