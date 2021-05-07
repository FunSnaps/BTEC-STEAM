#pragma once

#include "Menu.h"
#include "User.h"
#include <iostream>

class SearchResultsMenu : public Menu
{
public:
    SearchResultsMenu(const std::string& title, Application* app, std::string answer, std::string type);
    void OutputOptions() final;
    bool HandleChoice(char choice) final;
private:
    List<std::string> games;
    Utils utils;
    std::string answer;
    std::string type;
    List<Game*> foundGames;
    int first, second;
};