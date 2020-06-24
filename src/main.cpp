#include <SDL2/SDL.h>

#include "Application.hpp"


int main() {
    try {
        Resources resources;
        Application app(resources);
        app.Run();
        return 0;
    }
    catch (std::exception &err) {//this shouldn't trigger
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "ERROR", err.what(), nullptr);
        return 69;
    }
}