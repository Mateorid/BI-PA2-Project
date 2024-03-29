#include "ScoreManager.hpp"

ScoreManager::ScoreManager(SDL_Renderer *ren) {
    renderer = ren;
}

void ScoreManager::Init(GameObject &plat, GameObject &b1, GameObject &b2, TextPrinter &txt) {
    lives = START_LIVES;
    score = 0;
    platform = &plat;
    ball1 = &b1;
    ball2 = &b2;
    textPrinter = &txt;
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
    scoreTexture = textPrinter->CreateTextTexture(oss, srcR);
    if (scoreTexture == nullptr)
        throw std::runtime_error("Score texture creation failed.");
}

void ScoreManager::Render() {
    destR = srcR;
    destR.x = (APP_WIDTH - destR.w) / 2;
    destR.y = APP_HEIGHT - destR.h;
    if (SDL_RenderCopy(renderer, scoreTexture, &srcR, &destR) < 0)
        throw std::runtime_error(SDL_GetError());
}
