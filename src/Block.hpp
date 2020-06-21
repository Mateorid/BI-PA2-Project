#pragma once

#include "GameObject.hpp"


/**Destination of block source image*/
static const char *const BLOCK_SRC = "examples/textures/block.png";
/**Block settings*/
static const int BLOCK_HEIGHT = 22;//move to private and set on runtime? + add getter for maploader needs
static const int BLOCK_WIDTH = 50;


class Block : public GameObject {
public:
    Block(SDL_Renderer *renderer, int lvl, int x, int y);

    void Collided(bool activate) override;

    void UpdateTexture(int lvl);

    void Render() override;

private:
    void SetLevel(int lvl);

    int level = 0;
};




