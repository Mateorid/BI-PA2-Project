#pragma once

#include "GameObject.hpp"


/**Destination of block source image*/
static const char *const BLOCK_SRC = "examples/textures/block.png";
/**Block settings*/
static const int BLOCK_HEIGHT = 22;//move to private and set on runtime? + add getter for maploader needs
static const int BLOCK_WIDTH = 50;

/**Block class*/
class Block : public GameObject {
public:
    /**
     * Constructor
     * @param renderer
     * @param lvl block lvl
     * @param x x position
     * @param y y position
     */
    Block(SDL_Renderer *renderer, int lvl, int x, int y);

    /**Collision handler*/
    void Collided(bool activate) override;

    /**Updates texture according to lvl*/
    void UpdateTexture(int lvl);

    /**Renders block*/
    void Render() override;

private:
    void SetLevel(int lvl);

    int level = 0;
};




