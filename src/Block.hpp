#pragma once

#include "GameObject.hpp"


/**Destination of block source image*/
static const char *const BLOCK_SRC = "examples/textures/block.png";
/**Block settings*/
static const int BLOCK_HEIGHT = 22;
static const int BLOCK_WIDTH = 50;


class Block : public GameObject {
public:
    Block(SDL_Renderer *renderer, int lvl, int x, int y);

    ~Block() override;

    void Collided(bool activate) override;

    bool Used() override;

    void Render() override;

private:
    void UpdateTexture(int lvl);

    void SetLevel(int lvl);

    int level = 0;
    bool used = false;
};




