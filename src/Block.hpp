#pragma once

#include "GameObject.hpp"
#include "Settings.hpp"


class Block : public GameObject {
public:
    Block(const char *ID, SDL_Renderer *renderer, int lvl, int x, int y);

    void Collided(Direction dir) override;

    void Hit();

    void UpdateTexture(int lvl);

    void Render() override;

private:
    int level;
};




