#include "Menu.h"
#include "StoreMenu.h"

#include <string>

StoreMenu::StoreMenu(const std::string& title, Application* app) : Menu(title, app)
{
    Paint(); // required in constructor
}

void StoreMenu::OutputOptions()
{
    /*for (int i = 0; i < games.size() - 4; i++)
    {
        Option(i + 1, games[i]);
    }*/

    for (int i = 0; i < games.size(); i++)
    {
        Option(i + 1, games[i]);
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

    if (index >= 0 && index < games.size())
    {
        BlockingMessage("TO BE DONE AFTER DATA LOADING ");
        // go to game detail page
    }

    switch (choice) {
    case 'N':
    {
        system("CLS");
        for (int i = 5; i < games.size(); i++)
        {
            Option(i + 1, games[i]);
        }
        Utils::getCharFromUser();

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

