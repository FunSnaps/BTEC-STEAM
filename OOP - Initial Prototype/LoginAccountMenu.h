#pragma once
#include "Menu.h"
#include "MainMenu.h"
#include "ListT.h"
#include <iostream>

class LoginAccountMenu :
    public Menu
{
public:
    LoginAccountMenu(const std::string& title, Application* app);
    void OutputOptions() final;
    bool HandleChoice(char choice) final;
private:
    int i;
};

