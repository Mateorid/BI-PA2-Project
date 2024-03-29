#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <sstream>
#include <iomanip>

#include "GameObject.hpp"
#include "State.hpp"
#include "TextPrinter.hpp"

/**How many lives you start with*/
static const int START_LIVES = 3;
/**Score added after hitting a block*/
static const int SCORE_ADD = 100;
/**Score deducted after losing a life*/
static const int SCORE_DEDUCT = 300;

/**In-game score managin class*/
class ScoreManager {
public:

    explicit ScoreManager(SDL_Renderer *);

    ~ScoreManager() = default;

    ScoreManager(const ScoreManager &) = delete;

    ScoreManager &operator=(const ScoreManager &) = delete;

    void Init(GameObject &, GameObject &, GameObject &, TextPrinter &);

    void UpdateScore();

    void Render();

    void PlusScore();

    void PlusScore(int);

    void MinusScore();

    void AddLife();

    void LoseLife();

    void AddScores() { totalScore += score; };

    void ResetScore() { totalScore = 0; };

    int GetScore() const { return totalScore; }

    int GetLives() const { return lives; }

private:
    int lives = 0;
    int score = 0;
    int totalScore = 0;
    GameObject *platform{};
    GameObject *ball1{};
    GameObject *ball2{};
    TextPrinter *textPrinter{};
    SDL_Renderer *renderer{};
    SDL_Texture *scoreTexture{};
    SDL_Rect srcR{};
    SDL_Rect destR{};
};




