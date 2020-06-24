#pragma once

#include <sstream>


#include "State.hpp"
#include "MenuText.hpp"

/** Menu parent class*/
class MenuState : public State {
public:
    /**
     * Constructor - uses parent class constructor
     * @param app reference to Application gets stored for later use
     */
    explicit MenuState(Application &app) : State(app) {}

    /**Virtual method*/
    void Initialize() override {};

    /**Virtual method*/
    void HandleEvents() override {};

    /**Renders all texts stored in texts vector and underlines currently selected one*/
    void Render() override;

    /**Empties texts & positions vectors*/
    void Clean() override;

protected:
    /**Indicates if we need to re-render text*/
    bool changedText = true;
    /**Currently selected menu position*/
    int menuPos = 1;
    /**Currently selected level*/
    int selectedLvl = 1;
    /**Number of selectable texts*/
    int menuSelections = 0;
    /**Vector of unique_ptr of MenuTexts*/
    std::vector<std::unique_ptr<MenuText>> texts;
    /**vector of all text positions*/
    std::vector<int> positions;
};


