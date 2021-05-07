#pragma once

#include "Menu.h"
#include "Utils.h"
#include "Date.h"
#include <iostream>

class PurchaseSuccessMenu : public Menu
{
public:
    PurchaseSuccessMenu(const std::string& title, Application* app, const int& index);
    void OutputOptions() final;
    bool HandleChoice(char choice) final;
private:
    const int& index;
    Utils utils;
    Date* d;
};
