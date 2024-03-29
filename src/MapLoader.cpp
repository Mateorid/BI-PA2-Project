#include "MapLoader.hpp"

MapLoader::MapLoader(const char *mapSrc, Application &app) {
    LoadBlocks(mapSrc, app);
}


void MapLoader::LoadBlocks(const char *filename, Application &app) {
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
    app.res.gameObjects.push_back(
            new Block(app.res.mainRenderer, lvl, blocksInLine * BLOCK_WIDTH, rows * BLOCK_HEIGHT));
    blocksInLine++;

}
