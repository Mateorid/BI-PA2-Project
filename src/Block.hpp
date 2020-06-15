#pragma once

#include "GameObject.hpp"
#include "Settings.hpp"


/**Destination of block source image*/
static const char *const BLOCK_SRC = "examples/textures/block.png";


class Block : public GameObject {
public:
    Block(SDL_Renderer *renderer, int lvl, int x, int y);

    ~Block();

    void Destroy() override;

    void Collided(bool activate) override;

    void UpdateTexture(int lvl);

    void Render() override;

private:
    void SetLevel(int lvl);

    int level = 0;
};




