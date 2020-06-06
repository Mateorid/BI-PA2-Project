#include <vector>
#include "Map.hpp"


Map::Map(const std::string &filename, SDL_Renderer *renderer) {
    ifstream inputFile(filename, ios::in);
    char blockLevel;
    while (inputFile.get(blockLevel).good()) {
        if (!inputFile.is_open()) {
            inputFile.close();
            throw runtime_error("Map file loading error.");
        }
        if (inputFile.eof())
            return;
//        if (blockLevel < 0 || blockLevel > BLOCK_MAX_LVL) //todo fix
//            throw invalid_argument("Wrong Block level in map.");
        int level = 0;
        level = GetLevel(blockLevel);
        if (level == 0)
            posX++;
        else
            InsertBlock(level, renderer);

    }
    inputFile.close();
}

void Map::InsertBlock(int lvl, SDL_Renderer *renderer) {
    auto *tmpBlock = new Block(renderer, lvl, posX * BLOCK_WIDTH, posY * BLOCK_HEIGHT); //todo fix
    blocks.push_back(tmpBlock);
    posX++;
}

int Map::GetLevel(const char level) {
    if (level == '0')
        return 0;
    else if (level == '1')
        return 1;
    else if (level == '2')
        return 2;
    else if (level == '3')
        return 3;
    else if (level == '/n')
        return -1;
    else
//        throw invalid_argument("Invalid block level in map. Must be 0-3");
        cout << "XD: " << posX << endl;
    cout << x << endl;
}
