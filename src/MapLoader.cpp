#include "MapLoader.hpp"

MapLoader::MapLoader(const string &filename, Application &app) {
    if (BLOCK_HEIGHT == 0 || BLOCK_WIDTH == 0)
        throw invalid_argument("ERROR! Block cannot have 0 size.");
    LoadBlocks(filename, app);
}

void MapLoader::LoadBlocks(const string &filename, Application &app) { //todo toto nechytam??
    ifstream inputFile(filename, ios::in);
    while (inputFile.is_open()) {
        inputFile >> blockLvl;
        if (inputFile.eof()) {                              //EOF check
            if (blocksInLine != MAP_COLUMNS || rows >= MAP_ROWS) {       //Line not fully filled or too many rows
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
        if (blocksInLine == MAP_COLUMNS) {
            rows++;
            blocksInLine = 0;
        }
        InsertBlock(blockLvl, app);
    }
    inputFile.close();
    throw runtime_error("ERROR! Map file loading error.");
}

void MapLoader::InsertBlock(int lvl, Application &app) {
    if (lvl == 0) {
        blocksInLine++;
        return;
    }
    app.gameObjects.push_back(new Block(app.mainRenderer, lvl, blocksInLine * BLOCK_WIDTH, rows * BLOCK_HEIGHT));
    blocksInLine++;

}
