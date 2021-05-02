#pragma once

#include "Menu.h"
#include <string>
#include <vector>

class StoreMenu : public Menu
{
public:
    StoreMenu(const std::string& title, Application* app);
    void OutputOptions() final;
    bool HandleChoice(char choice) final;
private:
    //needs to be loaded from file later on 
    std::vector<std::string> games = { "The Witness", "Braid", "Factorio", "LIMBO","INSIDE","Portal 2","Half Life 3","NUVAVULT","Path" };
};