#include "ScoreManager.hpp"

ScoreManager::ScoreManager(SDL_Renderer *ren, int x) {
    renderer = ren;
    lives = x;
    gameFont = TTF_OpenFont(FONT_SRC, 50);
}

ScoreManager::~ScoreManager() {
    TTF_CloseFont(gameFont);
}

void ScoreManager::Init(GameObject &plat, GameObject &b1, GameObject &b2) {
    platform = &plat;
    ball1 = &b1;
    ball2 = &b2;
    UpdateScore();
}

void ScoreManager::PlusScore() {
    score += SCORE_ADD;
    UpdateScore();
}

void ScoreManager::PlusScore(int x) {
    score += x;
    UpdateScore();
}

void ScoreManager::MinusScore() {
    score -= SCORE_DEDUCT;
    UpdateScore();
}

void ScoreManager::AddLife() {
    lives++;
    UpdateScore();
}

void ScoreManager::LoseLife() {
    if (!ball1->IsActive() && !ball2->IsActive()) {
        lives--;
        UpdateScore();
        MinusScore();
        platform->ResetSpeed();
        ball1->ResetSpeed();
        ball2->ResetSpeed();
    }
}

void ScoreManager::UpdateScore() {
    std::ostringstream oss;
    oss << "Score: " << std::setw(3) << std::setfill('0') << score << "  Lives: " << lives;
    scoreSurface = TTF_RenderUTF8_Blended(gameFont, oss.str().c_str(), {255, 255, 255, 0});
    srcR = {0, 0, scoreSurface->w, scoreSurface->h};
    scoreTexture = SDL_CreateTextureFromSurface(renderer, scoreSurface);
    SDL_FreeSurface(scoreSurface);
}

void ScoreManager::Render() {
    destR = srcR;
    destR.x = (APP_WIDTH - destR.w) / 2;
    destR.y = APP_HEIGHT - destR.h;
    SDL_RenderCopy(renderer, scoreTexture, &srcR, &destR);
}
