#include "Menu.h"
#include "StoreMenu.h"
#include "GameInfoMenu.h"
#include <string>

StoreMenu::StoreMenu(const std::string& title, Application* app) : Menu(title, app)
{
    Paint(); 
}

void StoreMenu::OutputOptions()
{
    for (int i = 0; i < app->GetStore().GetGames().length() / 2 + 1; i++)
    {
        Option(i + 1, app->GetStore().getIndex(i).GetName());
    }

    Line();
    Option('S', "Search");
    Option('N', "Next Page");
}


bool StoreMenu::HandleChoice(char choice)
{
    int index = choice - '1';

    if (index >= 0 && index < app->GetStore().GetGames().length() / 2 + 1)
    {
        std::string temp = app->GetStore().getIndex(index).GetName();
        GameInfoMenu(utils.ToUpper(temp), app, index);
    }

    switch (choice) {
    case 'N':
    {   
        GameInfoMenu("STORE", app, 'N');
    } break;
    case 'S':
    {
        BlockingMessage("SEARCH PAGE");
    }
    default:
        break;
    }

    return false;
}

