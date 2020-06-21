#pragma once

#include <SDL2/SDL.h>

#include "Application.hpp"


class Application;

/**
 * Virtual class
 */
class State {
public:
    explicit State(Application &app) : app(app) {};

    virtual void Initialize() {};

    virtual void HandleEvents() {};

    virtual void Update() {};

    virtual void Render() {};

    virtual void Clean() {};
protected:
    Application &app;
};




