#include "Game.hpp"
#include "Settings.hpp"


int main(int argc, char *argv[]) {
    Game *game = nullptr;
    const int frameDelay = 1000 / MAX_FPS;
    Uint32 frameTicks;
    int frameDelta;

    game = new Game();
    game->initialize(GAME_NAME, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                     GAME_WIDTH, GAME_HEIGHT, START_FULLSCREEN);

    while (game->running()) {
        frameTicks = SDL_GetTicks();

        game->handleEvents();
        game->updateAll();
        game->renderAll();
        frameDelta = SDL_GetTicks() - frameTicks;
        if (frameDelay > frameDelta) {
            SDL_Delay(frameDelay - frameDelta);
        }
    }
    game->cleanAll();
//    delete game;
    return 0;
}