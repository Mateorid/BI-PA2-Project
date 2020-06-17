#pragma once

#include "State.hpp"

class VictoryState : public State {
public:
    void Initialize(StateManager &) override;

    void HandleEvents(StateManager &) override;

    void Render(StateManager &) override;

    void Clean(StateManager &) override;

private:
    void RenderText(SDL_Renderer *, SDL_Texture *, SDL_Rect, int, bool); //todo move thes to State class?

    void RenderSelected(SDL_Renderer *renderer);

    bool changedText = true;
    int menuPos = 1;
    int positions[4] = {20, 200, 400, 600,};
    SDL_Texture *resultTexture{};
    SDL_Texture *scoreTexture{};
    SDL_Texture *nextTexture{};
    SDL_Texture *menuTexture{};
    SDL_Rect resultR{};
    SDL_Rect scoreR{};
    SDL_Rect nextR{};
    SDL_Rect menuR{};
    SDL_Rect renderR{};
};
