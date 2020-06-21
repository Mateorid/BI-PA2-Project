#pragma once

#include <SDL2/SDL.h>

#include "Application.hpp"


class Application;

class State {
public:
    virtual void Initialize(Application &) {};

    virtual void HandleEvents(Application &) {};

    virtual void Update(Application &) {};

    virtual void Render(Application &) {};

    virtual void Clean(Application &) {};
protected:
};




