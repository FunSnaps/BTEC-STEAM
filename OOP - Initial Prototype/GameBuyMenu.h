#pragma once

#include "Menu.h"

#include "SearchMenu.h"
#include "PurchaseSuccessMenu.h"
#include "Utils.h"

#include <iostream>

class GameBuyMenu : public Menu
{
public:
    GameBuyMenu(const std::string& title, Application* app, const int& index);
    void OutputOptions() final;
    bool HandleChoice(char choice) final;
private:
    Date* d;

    const int& gameIndex;
    Utils utils;
    bool line = false;
};
