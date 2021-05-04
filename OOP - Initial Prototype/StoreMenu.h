#pragma once

#include "Menu.h"

#include <iostream>

class StoreMenu : public Menu
{
public:
    StoreMenu(const std::string& title, Application* app);
    void OutputOptions() final;
    bool HandleChoice(char choice) final;
private:
    List<std::string> games;
    //std::vector<std::string> games;
};