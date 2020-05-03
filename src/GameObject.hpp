#pragma once

#include "Game.hpp"
#include "TextureLoader.hpp"

class GameObject {
public:
    GameObject(const char *textureDest, SDL_Renderer *renderer, int x, int y);

    ~GameObject();

    void update();

    void render();

private:
    int xPos;
    int yPos;
    SDL_Texture *objTexture;
    SDL_Renderer *objRenderer;
    SDL_Rect srcR, destR;
};