#pragma once

#include <SDL2/SDL.h>
#include "StateManager.hpp"

enum TextType {
    TEXT,
    SCORE,
    LVL_SELECT
};

class MenuText {
public:
    MenuText(StateManager &manager, int y, const char *txt, bool title);

    MenuText(StateManager &manager, int y, int lvl, bool active);

    MenuText(StateManager &manager, int y, int score);

    ~MenuText();

    void Update(int lvl, bool active);

    void Selected();

private:

    void Render();

    StateManager *manager;
    TextType type;
    int yPos;
    bool isTitle = false;
    SDL_Rect rect{};
    SDL_Texture *texture;
};




