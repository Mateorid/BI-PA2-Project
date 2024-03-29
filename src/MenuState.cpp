#include "MenuState.hpp"

void MenuState::Render() {
    if (changedText) { //when there's no update we don't need to re-render
        if (SDL_RenderClear(app.res.mainRenderer) < 0)
            throw std::runtime_error(SDL_GetError());

        for (auto &it :texts)
            it->Update(selectedLvl, menuPos == 1);
        texts[menuPos]->Selected();//render underline

        SDL_RenderPresent(app.res.mainRenderer);
        changedText = false;
    }
}

void MenuState::Clean() {
    positions.clear();
    std::vector<int>().swap(positions);
    texts.clear();
    std::vector<std::unique_ptr<MenuText>>().swap(texts);
}
