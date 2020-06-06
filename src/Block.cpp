#include "Block.hpp"

Block::Block(SDL_Renderer *renderer, int lvl, int x, int y) {
    level = lvl;
    type = BLOCK;
    objRenderer = renderer;
    objTexture = IMG_LoadTexture(renderer, BLOCK_SRC);
    destR.x = x;
    destR.y = y;
    destR.h = BLOCK_HEIGHT;
    destR.w = BLOCK_WIDTH;
    UpdateTexture(level);
    active = true;
}

void Block::Destroy() {
    active = false;
    SDL_DestroyTexture(objTexture);
}

void Block::Collided(Direction dir) {
    if (dir == NONE)
        return;
    Hit();
    std::cout << "HIT" << std::endl; //todo delete
}

void Block::Hit() {
    //todo
    level--;
    if (level == 0) {
        Destroy();
        return;
    }
    UpdateTexture(level);
}

void Block::UpdateTexture(int lvl) {
    srcR.y = 0;
    srcR.x = lvl == 1 ? 0 : 0 + ((lvl - 1) * BLOCK_WIDTH); //Sets the texture according to the lvl
    srcR.h = BLOCK_HEIGHT;
    srcR.w = BLOCK_WIDTH;
}

void Block::Render() {
    SDL_RenderCopy(objRenderer, objTexture, &srcR, &destR);
}
