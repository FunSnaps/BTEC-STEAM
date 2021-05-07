#include "Menu.h"
#include "SearchMenu.h"
#include "SearchResultsMenu.h"
#include "GameInfoMenu.h"
#include "GameBuyMenu.h"
#include <string>

SearchMenu::SearchMenu(const std::string& title, Application* app) : Menu(title, app)
{
    Paint();
}

void SearchMenu::OutputOptions()
{
    std::cout << "  Loading " << app->GetStore().GetGames().length() << " Games";
    Line();
    Option('S', "Search by name");
    Option('P', "Search by price");
}


bool SearchMenu::HandleChoice(char choice)
{


    switch (choice) {
    case 'S':
    {
        std::string temp = Utils::toLower(Question("Game Name"));
        SearchResultsMenu("SEARCH RESULT", app, temp, "gamename");
    } break;
    case 'P':
    {
        std::string temp = Utils::toLower(Question("Game Price (value1-value2)"));
        SearchResultsMenu("SEARCH RESULT", app, temp, "gameprice");
    }
    default:
        break;
    }

    return false;
}

