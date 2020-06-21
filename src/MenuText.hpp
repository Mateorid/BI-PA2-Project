#pragma once

#include <SDL2/SDL.h>
#include "Application.hpp"


enum TextType {
    TEXT,
    SCORE,
    LVL_SELECT
};

class MenuText {
public:
    MenuText(Application &, int y, const char *txt, bool title);

    MenuText(Application &, int y, int lvl, bool active);

    MenuText(Application &, int y, int score);

    ~MenuText();

    void Update(int lvl, bool active);

    void Selected();

private:

    void Render();

    Application *app;
    TextType type;
    int yPos;
    bool isTitle = false;
    SDL_Rect rect{};
    SDL_Texture *texture;

    const char *TEXT_ERROR = "Failed to create text texture.";
};




