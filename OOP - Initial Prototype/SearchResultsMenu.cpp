#include "Menu.h"
#include "SearchResultsMenu.h"
#include "GameInfoMenu.h"
#include "GameBuyMenu.h"
#include <string>
#include "SearchMenu.h"

SearchResultsMenu::SearchResultsMenu(const std::string& title, Application* app, std::string answer, std::string type)
    : Menu(title, app), answer(answer), type(type)
{
    Paint();
}

void SearchResultsMenu::OutputOptions()
{
    if (type == "gamename") {
        for (int i = 0; i < app->GetStore().GetGames().length(); i++)
        {
            std::string temp = Utils::toLower(app->GetStore().getIndex(i).GetName());
            if (!Utils::startsWith(temp, answer)) {
                Option(i + 1, app->GetStore().getIndex(i).GetName());
            }
        }
    }
    else {
        std::vector<std::string> v = Utils::split(answer, "-");
        int first = std::stoi(v[0]) * 100;
        int second = std::stoi(v[1]) * 100;
        for (int i = 0; i < app->GetStore().GetGames().length(); i++)
        {
            int temp = app->GetStore().getIndex(i).GetCost();
            if (temp >= first && temp <= second) {
                Option(i + 1, app->GetStore().getIndex(i).GetName());
            }
        }
    }
    Line();
    Option('S', "Search");
}


bool SearchResultsMenu::HandleChoice(char choice)
{
    int index = choice - '1';

    if (index >= 0 && index < app->GetStore().GetGames().length())
    {
        int temp = app->GetStore().getIndex(index).GetCost();
        if (!Utils::startsWith(Utils::toLower(app->GetStore().getIndex(index).GetName()), answer)) {
            std::string temp = app->GetStore().getIndex(index).GetName();
            if (app->IsUserLoggedIn()) {
                GameBuyMenu(utils.ToUpper(temp), app, index);
            }
            else {
                GameInfoMenu(utils.ToUpper(temp), app, index);
            }
        }
        else if (temp >= first && temp <= second) {
            std::string temp = app->GetStore().getIndex(index).GetName();
            if (app->IsUserLoggedIn()) {
                GameBuyMenu(utils.ToUpper(temp), app, index);
            }
            else {
                GameInfoMenu(utils.ToUpper(temp), app, index);
            }
        }
    }

    switch (choice) {
    case 'S':
    {
        SearchMenu("SEARCH", app);
    } break;
    }
    return false;
}

