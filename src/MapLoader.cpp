#include "MapLoader.hpp"

MapLoader::MapLoader(const string &filename, StateManager &manager) {
    if (BLOCK_HEIGHT == 0 || BLOCK_WIDTH == 0)
        throw invalid_argument("ERROR! Block cannot have 0 size.");
    maxBlocksLine = APP_WIDTH / BLOCK_WIDTH;
    cout << "Max blocks on line is: " << maxBlocksLine << endl; //todo delete
    LoadBlocks(filename, manager);
}

void MapLoader::LoadBlocks(const string &filename, StateManager &manager) { //todo toto nechytam??
    ifstream inputFile(filename, ios::in);
    while (inputFile.is_open()) {
        inputFile >> blockLvl;
        if (inputFile.eof()) {                              //EOF check
            if (blocksInLine != maxBlocksLine || rows >= MAP_MAX_ROWS) {       //Line not fully filled or too many rows
                inputFile.close();
                throw invalid_argument("ERROR! Wrong map size.");
            } else {
                inputFile.close(); //good map content
                return;
            }
        }
        if (!inputFile.good()) {                            //Invalid levels in map
            inputFile.close();
            throw invalid_argument("ERROR! Invalid map content.");
        }
        if (blocksInLine == maxBlocksLine) {
            rows++;
            blocksInLine = 0;
        }
        InsertBlock(blockLvl, manager);
    }
    inputFile.close();
    throw runtime_error("ERROR! Map file loading error.");
}

void MapLoader::InsertBlock(int lvl, StateManager &man) {
    if (lvl == 0) {
        blocksInLine++;
        return;
    }
    man.gameObjects.push_back(new Block(man.mainRenderer, lvl, blocksInLine * BLOCK_WIDTH, rows * BLOCK_HEIGHT));
    blocksInLine++;

}
