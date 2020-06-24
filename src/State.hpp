#pragma once

#include <SDL2/SDL.h>

#include "Application.hpp"


class Application;

/** Virtual State class*/
class State {
public:
    /**
     * Constructor
     * @param app reference to Application gets stored for later use
     */
    explicit State(Application &app) : app(app) {};

    virtual void Initialize() {};

    virtual void HandleEvents() {};

    virtual void Update() {};

    virtual void Render() {};

    virtual void Clean() {};
protected:
    /**Referemce to Application*/
    Application &app;
};




