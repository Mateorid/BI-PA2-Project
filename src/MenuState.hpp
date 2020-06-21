#pragma once

#include <sstream>


#include "State.hpp"
#include "MenuText.hpp"

class MenuState : public State {
public:
    explicit MenuState(Application &app) : State(app) {}

    void Initialize() override {};

    void HandleEvents() override {};

    void Render() override;

    void Clean() override;

protected:
    bool changedText = true;
    int menuPos = 1;
    int selectedLvl = 1;
    int menuSelections = 0;
    std::vector<std::unique_ptr<MenuText>> texts;
    std::vector<int> positions;
};


