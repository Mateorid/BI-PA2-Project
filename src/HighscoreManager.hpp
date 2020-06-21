#pragma once

#include <algorithm>
#include <fstream>
#include <vector>

static const char *HIGHSCORES_SRC = "examples/highscores.txt";


class HighscoreManager {
public:
    void GetScores(int);

private:

    void LoadScores();

    void InsertScore(int);

    void PrintScore();

    void Clean();

    std::vector<int> highscores;
};




