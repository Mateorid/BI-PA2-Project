#include "Block.hpp"

Block::Block(const char *ID, SDL_Renderer *renderer, int lvl, int x, int y) {
    this->ID = ID;
    level = lvl;
    type = BLOCK;
    objRenderer = renderer;
    objTexture = CTextureLoader::LoadTexture(BLOCK_SRC, renderer);
    destR.x = x;
    destR.y = y;
    destR.h = BLOCK_H;
    destR.w = BLOCK_W;
    UpdateTexture(level);
    active = true;
}

void Block::Hit() {
    //todo
    level--;
    if (level == 0) {
//        GameObject::Destroy();
        active = false;
    }
    UpdateTexture(level);
}

void Block::UpdateTexture(int lvl) {
    srcR.y = 0;
    srcR.x = lvl == 1 ? 0 : 0 + ((lvl - 1) * BLOCK_W); //Set the starting point of the texture according to the lvl
    srcR.h = BLOCK_H;
    srcR.w = BLOCK_W;

}

void Block::Render() {
    SDL_RenderCopy(objRenderer, objTexture, &srcR, &destR);
}

void Block::Collided(Direction dir) {
    if (dir == NONE)
        return;
    else
        Hit();
    std::cout << "HIT" << std::endl;
}
