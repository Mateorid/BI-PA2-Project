#include "Game.hpp"
#include "Application.hpp"

int main(int argc, char *argv[]) {
    Game *game = new Game();
    return game->Play();
}