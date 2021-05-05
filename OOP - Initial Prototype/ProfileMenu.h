#pragma once
#include "Menu.h"
#include "Date.h"
#include<iostream>
#include <algorithm>

class ProfileMenu :
    public Menu
{

public:
    ProfileMenu(const std::string& title, Application* app);
    void OutputOptions();
    bool HandleChoice(char choice);

private:
    Date* d;
    int iter;
    void sortResults();
    bool sort() const;
};

