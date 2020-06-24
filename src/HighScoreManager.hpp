#pragma once

#include <algorithm>
#include <fstream>
#include <vector>

/**HighScore managing class*/
class HighScoreManager {
public:
    /**uses other methods to check if new top 10 score*/
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




