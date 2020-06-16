#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <sstream>
#include <iomanip>

#include "GameObject.hpp"
#include "Application.hpp"
#include "TextPrinter.hpp"

/**Score added after hitting a block*/
static const int SCORE_ADD = 100;
/**Score deducted after losing a life*/
static const int SCORE_DEDUCT = 500;


class ScoreManager {
public:
    ScoreManager(SDL_Renderer *ren, int x);

    ~ScoreManager() = default;

    void Init(GameObject &plat, GameObject &b1, GameObject &b2);

    void UpdateScore();

    void Render();

    void PlusScore();

    void PlusScore(int x);

    void MinusScore();

    void AddLife();

    void LoseLife();

    int GetScore() const { return score; }

    int GetLives() const { return lives; }

private:
    int lives = 0;
    int score = 0;
    GameObject *platform{};
    GameObject *ball1{};
    GameObject *ball2{};
    TextPrinter textPrinter{};
    SDL_Renderer *renderer{};
    SDL_Texture *scoreTexture{};
    SDL_Rect srcR{};
    SDL_Rect destR{};
};




