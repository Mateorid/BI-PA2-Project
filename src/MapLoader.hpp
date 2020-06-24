#pragma once

#include <SDL2/SDL.h>
#include <string>
#include <vector>
#include <fstream>

#include "Block.hpp"
#include "State.hpp"

/**Map settings*/
static const int MAP_ROWS = 20;
static const int MAP_COLUMNS = 12;

using namespace std;

class State;

/**Class for loading blocks from files*/
class MapLoader {
public:
    /**
     * Constructor - calls LoadBlocks
     * @param mapSrc map file destination
     * @param app Application reference
     */
    MapLoader(const char *mapSrc, Application &app);

    /**
     * @throws runtime_error when there's been a problem with loading the map file
     * @throws invalid_argument when there are non-numeric characters in the map file (excluding whitespaces & newlines)
     * @throws invalid_argument when the line of blocks isn't filled all the way or there are more rows than MAP_ROWS
     * @param filename destination of the map file
     */
    void LoadBlocks(const char *filename, Application &app);

private:

    void InsertBlock(int lvl, Application &);

    int blocksInLine = 0;
    int rows = 0;
    int blockLvl = 0;
};




