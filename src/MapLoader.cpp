#include "MapLoader.hpp"

MapLoader::MapLoader(const string &filename, SDL_Renderer *renderer) {
    this->renderer = renderer;
    if (BLOCK_HEIGHT == 0 || BLOCK_WIDTH == 0)
        throw invalid_argument("ERROR! Block cannot have 0 size.");
    maxBlocksLine = GAME_WIDTH / BLOCK_WIDTH;
    cout << "Max blocks on line is: " << maxBlocksLine << endl; //todo delete
    LoadBlocks(filename);
}

void MapLoader::LoadBlocks(const string &filename) {
    ifstream inputFile(filename, ios::in);

    while (!inputFile.eof()) {
        if (!inputFile.is_open()) {                         //Error while loading file
            inputFile.close();
            throw runtime_error("ERROR! Map file loading error.");
        }

        inputFile >> blockLvl;
        if (inputFile.eof()) {                              //EOF check
            if (blocksInLine != maxBlocksLine || rows == MAP_MAX_ROWS) {       //Line not fully filled or too many rows
                inputFile.close();
                throw invalid_argument("ERROR! Invalid map content.");
            }
            break;
        }
        if (!inputFile.good()) {                            //Invalid levels in map
            inputFile.close();
            throw invalid_argument("ERROR! Invalid map content.");
        }
        if (blocksInLine == maxBlocksLine) {
            rows++;
            blocksInLine = 0;
        }
        InsertBlock(blockLvl);
    }
    inputFile.close();
}

void MapLoader::InsertBlock(int lvl) {
    if (lvl == 0) {
        blocksInLine++;
        return;
    }
    auto *tmpBlock = new Block(renderer, lvl, blocksInLine * BLOCK_WIDTH, rows * BLOCK_HEIGHT);
    blocks.push_back(tmpBlock);
    blocksInLine++;

}
