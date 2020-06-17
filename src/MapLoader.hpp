#pragma once

#include <SDL2/SDL.h>
#include <string>
#include <vector>
#include <fstream>

#include "Block.hpp"
#include "State.hpp"
//#include "Application.hpp"


static const int MAP_MAX_ROWS = 20;

using namespace std;

class State;

class MapLoader {
public:
    /**
     * @throws overflow_error when (block size + spacing) == 0 (dividing by zero would occur)
     */

    MapLoader(const string &filename, SDL_Renderer *renderer);

    vector<GameObject *> &getBlocks() { return blocks; };

private:
    /**
     * @throws runtime_error when there's been a problem with loading the map file
     * @throws invalid_argument when there are non-numeric characters in the map file (excluding whitespaces & newlines)
     * @throws invalid_argument when the line of blocks isn't filled all the way or there are more rows than MAP_MAX_ROWS
     * @param filename destination of the map file
     */
    void LoadBlocks(const string &filename);

    void InsertBlock(int lvl);

    vector<GameObject *> blocks;
    SDL_Renderer *renderer{};
    int blocksInLine = 0;
    int rows = 0;
    int blockLvl = 0;
    int maxBlocksLine = 0;
//    int spacedWidth = BLOCK_SPACING + BLOCK_WIDTH;
//    int spaceHeight = BLOCK_SPACING + BLOCK_HEIGHT;
};




