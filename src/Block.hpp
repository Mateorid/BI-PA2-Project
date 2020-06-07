#pragma once

#include "GameObject.hpp"
#include "Settings.hpp"


/**Destination of block source image*/
static const char *const BLOCK_SRC = "examples/textures/block.png";


class Block : public GameObject {
public:
    Block(SDL_Renderer *renderer, int lvl, int x, int y); //todo will had to add bonus pointer so I can init it here if bonus should be spawned

    void Destroy() override ;

    void Collided(Direction dir) override;

    void Hit();

    void UpdateTexture(int lvl);

    void Render() override;

private:
    int level;
};




