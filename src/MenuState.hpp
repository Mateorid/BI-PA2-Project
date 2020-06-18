#pragma once

#include <sstream>


#include "State.hpp"

static const int LVL_COUNT = 3;

class MenuState : public State {
public:
    MenuState() = default;

    void Initialize(StateManager &) override;

    void HandleEvents(StateManager &) override;

    void Render(StateManager &) override;

    void Clean(StateManager &) override;

private:
    void RenderText(SDL_Texture *, SDL_Rect, int, bool);

    void RenderSelected();

    bool changedText = true;
    int selectedLvl = 1;
    int menuPos = 1;
    int positions[3] = {20, 400, 600};
    SDL_Renderer *renderer{};
    SDL_Texture *titleTexture{};
    SDL_Texture *lvlSelectTexture{};
    SDL_Texture *exitTexture{};
    SDL_Rect titleR{};
    SDL_Rect lvlSelectR{};
    SDL_Rect exitR{};
    SDL_Rect renderR{};
};


