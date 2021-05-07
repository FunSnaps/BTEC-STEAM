#pragma once

#include "Menu.h"
#include "User.h"
#include <iostream>

class SearchMenu : public Menu
{
public:
    SearchMenu(const std::string& title, Application* app);
    void OutputOptions() final;
    bool HandleChoice(char choice) final;
private:
    List<std::string> games;
    Utils utils;
};