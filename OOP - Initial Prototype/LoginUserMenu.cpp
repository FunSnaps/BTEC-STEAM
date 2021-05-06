#include "LoginUserMenu.h"

LoginUserMenu::LoginUserMenu(const std::string& title, Application* app) : Menu(title, app)
{
    Paint();
}


void LoginUserMenu::OutputOptions()
{
    for (int i = 0; i < app->GetCurrentAccount()->users.length(); i++)
    {
        // adding 1 so the display is nicer for the user
        Option(i + 1, app->GetCurrentAccount()->users.operator[](i)->GetUsername());
    }
}

bool LoginUserMenu::HandleChoice(char choice)
{
    int index = choice - '1';

    if (index >= 0 && index < app->GetCurrentAccount()->users.length())
    {

        std::string username = app->GetCurrentAccount()->users.operator[](index)->GetUsername();

        std::cout << "  Enter password for " << username << ": ";
        if (app->LoginUser(username, Utils::getLineFromUser(), index))
        {
            return true;
        }
        else {
            BlockingMessage("Incorrect Password. Try Again ");
            return false;
        }
    }
    return false;
}

