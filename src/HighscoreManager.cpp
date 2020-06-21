#include <iostream>
#include "HighscoreManager.hpp"

void HighscoreManager::GetScores(int score) {
    LoadScores();
    InsertScore(score);
    Clean();
}

void HighscoreManager::LoadScores() {
    int i = 0;
    int tmp = 0;
    std::ifstream file(HIGHSCORES_SRC, std::ios::in);
    while (file >> tmp) {
        highscores.push_back(tmp);
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

void HighscoreManager::InsertScore(int score) {
    auto it = std::lower_bound(highscores.rbegin(), highscores.rend(), score);
    if (highscores.size() >= 10 && it == highscores.rbegin())
        return;
    highscores.insert(it.base(), score);
    if (highscores.size() > 10)
        highscores.pop_back();
    PrintScore();
}

void HighscoreManager::PrintScore() {
    std::ofstream file(HIGHSCORES_SRC, std::ios::out);
    for (auto &it : highscores) {
        if (!file.is_open() || !file.good()) {
            file.close();
            throw std::runtime_error("ERROR! Highscores file writing error.");
        }
        file << it << std::endl;
    }
    file.close();
}

void HighscoreManager::Clean() {
    highscores.clear();
    std::vector<int>().swap(highscores);
}
