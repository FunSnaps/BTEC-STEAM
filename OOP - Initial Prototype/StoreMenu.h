#pragma once

#include "Menu.h"

#include "GameInfoMenu.h"
#include "GameBuyMenu.h"
#include "SearchMenu.h"

#include <iostream>

class StoreMenu : public Menu
{
public:
    StoreMenu(const std::string& title, Application* app);
    void OutputOptions() final;
    bool HandleChoice(char choice) final;
private:
    List<std::string> games;
    Utils utils;
};