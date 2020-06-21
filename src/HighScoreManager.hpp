#pragma once

#include <algorithm>
#include <fstream>
#include <vector>


class HighScoreManager {
public:
    void GetScores(int);

private:

    void LoadScores();

    void InsertScore(int);

    void PrintScore();

    void Clean();

    std::vector<int> highScores;

    /**HighScores file destination*/
    const char *HIGH_SCORES_SRC = "examples/highscores.txt";
};




