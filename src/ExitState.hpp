#pragma once


#include "State.hpp"

class ExitState : public State {
public:
    explicit ExitState(Application &app) : State(app) {}

    void Initialize() override;
};




