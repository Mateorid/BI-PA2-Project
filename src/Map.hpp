#pragma once

#include <SDL2/SDL.h>
#include <string>
#include <stdexcept>
#include <fstream>

#include "Block.hpp"


using namespace std;

class Map {
public:
    static const int MAP_MIN_HEIGHT = 5;
    static const int MAP_MAX_HEIGHT = 20;
    static const int MAP_MIN_WIDTH = 5;
    static const int MAP_MAX_WIDTH = 20; //TODO Set these correctly
    static const int MAP_MIN_BLOCKS = 1;
    static const int BLOCK_MAX_LVL = 3;

    Map() = default;

    ~Map() = default;

    explicit Map(const std::string &filename, SDL_Renderer *renderer);

    vector<GameObject *> &getBlocks() { return blocks; };

private:

    void InsertBlock(int lvl, SDL_Renderer *renderer);

    int GetLevel(char level);

    int posX = 0;
    int posY = 0;
//    int test[posX][posY] ; //todo remove
    vector<GameObject *> blocks;
    size_t x = string::npos;
};




