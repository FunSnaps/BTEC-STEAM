#include "LoginUserMenu.h"

LoginUserMenu::LoginUserMenu(const std::string& title, Application* app) : Menu(title, app)
{
    Paint();
}


void LoginUserMenu::OutputOptions()
{
    for (int i = 0; i < users.size(); i++)
    {
        // adding 1 so the display is nicer for the user
        Option(i + 1, users[i]);
    }
}

bool LoginUserMenu::HandleChoice(char choice)
{
    int index = choice - '1';

    if (index >= 0 && index < users.size())
    {
        switch (choice)
        {
        case '1': {
            
            BlockingMessage("TEST");
        }
        case '2': {
            
        }
        default:
            break;
        }
        return false;
    }
}

