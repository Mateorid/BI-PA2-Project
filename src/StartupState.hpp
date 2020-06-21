#pragma once

#include <SDL2/SDL_ttf.h>
#include <iostream>


#include "State.hpp"


class StartupState : public State {
public:
    StartupState() = default;

    void Initialize(Application &) override;

    void Update(Application &) override;

};





