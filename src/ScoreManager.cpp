#include "ScoreManager.hpp"

ScoreManager::ScoreManager(SDL_Renderer *ren, int x) {
    renderer = ren;
    lives = x;
    gameFont = TTF_OpenFont(FONT_SRC, 50);
}

void ScoreManager::Init(GameObject &plat, GameObject &b1) {
    platform = &plat;
    ball = &b1;
    UpdateScore();
}

void ScoreManager::PlusScore() {
    score += SCORE_ADD;
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
    lives--;
    UpdateScore();
    MinusScore();
    platform->ResetSpeed();
    ball->ResetSpeed();
    //todo 2nd ball
}

void ScoreManager::UpdateScore() {
    std::ostringstream oss;
    oss << "Score: " << std::setw(6) << std::setfill('0') << score << "  Lives: " << lives;
    scoreSurface = TTF_RenderUTF8_Blended(gameFont, oss.str().c_str(), {255, 255, 255, 0});
    srcR = {0, 0, scoreSurface->w, scoreSurface->h};
    scoreTexture = SDL_CreateTextureFromSurface(renderer, scoreSurface);
}

void ScoreManager::Render() {
    destR = srcR;
    destR.x = (GAME_WIDTH - destR.w) / 2;
    destR.y = GAME_HEIGHT - destR.h;
    SDL_RenderCopy(renderer, scoreTexture, &srcR, &destR);
}
