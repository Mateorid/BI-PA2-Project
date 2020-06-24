#pragma once


#include "State.hpp"

/**Exit state class*/
class ExitState : public State {
public:
    /**
     * Constructor - uses parent class constructor
     * @param app reference to Application gets stored for later use
     */
    explicit ExitState(Application &app) : State(app) {}

    /**Closes, clears and deletes everything that's left*/
    void Initialize() override;
};




