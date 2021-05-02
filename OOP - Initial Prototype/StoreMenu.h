#pragma once

#include "Menu.h"

#include <iostream>
#include <vector>

class StoreMenu : public Menu
{
public:
    StoreMenu(const std::string& title, Application* app);
    void OutputOptions() final;
    bool HandleChoice(char choice) final;
private:
    std::vector<std::string> games;
};