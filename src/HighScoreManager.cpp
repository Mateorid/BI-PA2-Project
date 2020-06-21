#include <iostream>
#include "HighScoreManager.hpp"

void HighScoreManager::GetScores(int score) {
    LoadScores();
    InsertScore(score);
    Clean();
}

void HighScoreManager::LoadScores() {
    int i = 0;
    int tmp = 0;
    std::ifstream file(HIGH_SCORES_SRC, std::ios::in);
    while (file >> tmp) {
        highScores.push_back(tmp);
        i++;
        if (i == 10)
            break;
        if (file.eof())
            break;
        if (!file.is_open() || !file.good()) {                         //Error while loading file
            file.close();
            throw std::runtime_error("ERROR! Highscores file loading error.");
        }
    }
    file.close();
}

void HighScoreManager::InsertScore(int score) {
    auto it = std::lower_bound(highScores.rbegin(), highScores.rend(), score);
    if (highScores.size() >= 10 && it == highScores.rbegin())
        return;
    highScores.insert(it.base(), score);
    if (highScores.size() > 10)
        highScores.pop_back();
    PrintScore();
}

void HighScoreManager::PrintScore() {
    std::ofstream file(HIGH_SCORES_SRC, std::ios::out);
    for (auto &it : highScores) {
        if (!file.is_open() || !file.good()) {
            file.close();
            throw std::runtime_error("ERROR! Highscores file writing error.");
        }
        file << it << std::endl;
    }
    file.close();
}

void HighScoreManager::Clean() {
    highScores.clear();
    std::vector<int>().swap(highScores);
}
