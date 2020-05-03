#include "Game.hpp"
#include "TextureLoader.hpp"
#include "GameObject.hpp"

SDL_Rect srcR, destR;
GameObject *playerTank;

void Game::initialize(const char *title, int xPos, int yPos, int width, int height, bool fullscreen) {
    int initFullscreen = fullscreen ? SDL_WINDOW_FULLSCREEN : 0;

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        std::cout << "SDL initialized successfully" << std::endl;

        IMG_Init(IMG_INIT_PNG);


        MainWindow = SDL_CreateWindow(title, xPos, yPos, width, height, initFullscreen);
        if (MainWindow == nullptr) {
            std::cout << "MainWindow failed to initialize" << std::endl;
            isRunning = false;
        }

        MainRenderer = SDL_CreateRenderer(MainWindow, -1, SDL_RENDERER_ACCELERATED);
//        SDL_SetRenderDrawColor(MainRenderer,100,255,100,255);
        if (MainRenderer == nullptr) {
            std::cout << "MainRenderer failed to initialize" << std::endl;
            isRunning = false;
        }

        isRunning = true;
    } else {
        std::cout << "SDL failed to initialize" << std::endl;
        isRunning = false;
    }
    playerTank = new GameObject("src/textures/playerTank.png", MainRenderer, 50, 50);
}

void Game::handleEvents() {
    SDL_Event events;
    SDL_PollEvent(&events);
    if (events.type == SDL_QUIT)            //Exit signal
        isRunning = false;
    if (events.type == SDL_KEYDOWN) {       //Keypress handling
        switch (events.key.keysym.sym) {

//        case SDLK_UP:            //"w" pressed move half a tank forward
//            StartPos.y -= 90;
//            break;
//        case SDLK_DOWN:
//            StartPos.y += 90;
//            break;
//        case SDLK_LEFT:
//            StartPos.x -= 60;
//            break;
//        case SDLK_RIGHT:
//            StartPos.x += 60;
//            break;
            case SDLK_ESCAPE:
                isRunning = false;
                break;
            default:
                break;

        }
    }
}

int cnt = 0;

void Game::updateAll() {
    cnt++;
    std::cout << cnt << std::endl;
    playerTank->update();

}

void Game::renderAll() {
    SDL_RenderClear(MainRenderer);
    playerTank->render();
    SDL_RenderPresent(MainRenderer);        //Draws stuff in window
}


void Game::cleanAll() {
    SDL_DestroyRenderer(MainRenderer);
    SDL_DestroyWindow(MainWindow);
    IMG_Quit();
    SDL_Quit();
    std::cout << "Everything cleaned" << std::endl;
}
