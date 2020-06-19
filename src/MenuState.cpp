#include "MenuState.hpp"

void MenuState::Render(StateManager &manager) {
    if (changedText) { //when there's no update we don't need to re-render
        SDL_RenderClear(manager.mainRenderer);

        for (auto &it :texts)
            it->Update(selectedLvl, menuPos == 1);
        texts[menuPos]->Selected();//render underline

        SDL_RenderPresent(manager.mainRenderer);
        changedText = false;
    }
}

void MenuState::Clean(StateManager &) {
    positions.clear();
    std::vector<int>().swap(positions);
    texts.clear();
    std::vector<std::unique_ptr<MenuText>>().swap(texts);
}
