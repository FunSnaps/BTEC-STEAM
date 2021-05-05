#pragma once

#include "Menu.h"
#include <iostream>

class GameBuyMenu : public Menu
{
public:
    GameBuyMenu(const std::string& title, Application* app, const int& index);
    void OutputOptions() final;
    bool HandleChoice(char choice) final;
private:
    Date* d;
    const int& index;
};
