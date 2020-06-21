#pragma once

#include <sstream>


#include "State.hpp"
#include "MenuText.hpp"

class MenuState : public State {
public:
    MenuState() = default;

    void Initialize(Application &) override {};

    void HandleEvents(Application &) override {};

    void Render(Application &) override;

    void Clean(Application &) override;

protected:
    bool changedText = true;
    int menuPos = 1;
    int selectedLvl = 1;
    int menuSelections = 0;
    std::vector<std::unique_ptr<MenuText>> texts;
    std::vector<int> positions;
};


