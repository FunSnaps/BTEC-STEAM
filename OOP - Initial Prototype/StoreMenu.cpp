#include "Menu.h"
#include "StoreMenu.h"
#include "GameInfoMenu.h"
#include <string>

StoreMenu::StoreMenu(const std::string& title, Application* app) : Menu(title, app)
{
    Paint(); // required in constructor
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
    // since we are using numbers here we shift the char down by '1'
    // this puts '1' as 0, '2' as 1, '3' as 2, '4' as 3, etc.
    // this reverses the + 1 above and lets us do the range check below
    int index = choice - '1';

    if (index >= 0 && index < app->GetStore().GetGames().length() / 2 + 1)
    {
        std::string temp = app->GetStore().getIndex(index).GetName();
        GameInfoMenu(temp, app, index);
    }

    switch (choice) {
    case 'N':
    {   
        GameInfoMenu("STORE", app, 6);
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

