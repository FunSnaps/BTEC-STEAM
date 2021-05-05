#pragma once
#include "Menu.h"
#include<iostream>

class ProfileMenu :
    public Menu
{

public:
    ProfileMenu(const std::string& title, Application* app);
    void OutputOptions();
    bool HandleChoice(char choice);

private:
    int iter = 0;
};

