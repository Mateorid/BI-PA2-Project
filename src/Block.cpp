#include "Block.hpp"

Block::Block(SDL_Renderer *renderer, int lvl, int x, int y) {
    SetLevel(lvl);
    type = BLOCK;
    objRenderer = renderer;
    destR.x = x;
    destR.y = y;
    destR.h = BLOCK_HEIGHT;
    destR.w = BLOCK_WIDTH;
    LoadTexture(BLOCK_SRC);
    UpdateTexture(level);
    active = true;
}

void Block::Collided(bool activate) {
    if (!activate)
        return;
    level--;
    if (level == 0) {
        active = false;
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

void Block::SetLevel(int lvl) {
    if (lvl <= 1) level = 1;
    else if (lvl >= 3) level = 3;
    else level = 2;
}
