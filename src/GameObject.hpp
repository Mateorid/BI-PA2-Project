#pragma once

#include <SDL2/SDL.h>


class GameObject {
public:
    GameObject() = default;

    GameObject(const char *textureDest, SDL_Renderer *renderer, int xPosition, int yPosition);

    ~GameObject();

    virtual void Update();

    void Render();

protected:
    //TODO add velocity
    int ID = 0; //todo
    bool active{};
    int xPos{};
    int yPos{};
    SDL_Texture *objTexture{};
    SDL_Renderer *objRenderer{};
    SDL_Rect srcR{}, destR{};
};