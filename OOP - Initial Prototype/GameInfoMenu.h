#pragma once

#include "Menu.h"
#include "Utils.h"
#include <iostream>

class GameInfoMenu : public Menu
{
public:
    GameInfoMenu(const std::string& title, Application* app, const int& index);
    void OutputOptions() final;
    bool HandleChoice(char choice) final;
private:

    const int& gameIndex;
    Utils utils;
};
