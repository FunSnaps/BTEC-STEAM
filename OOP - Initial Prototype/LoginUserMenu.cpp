#include "LoginUserMenu.h"

LoginUserMenu::LoginUserMenu(const std::string& title, Application* app) : Menu(title, app)
{
    Paint();
}


void LoginUserMenu::OutputOptions()
{
    for (int i = 0; i < 3; i++)
    {
        // adding 1 so the display is nicer for the user
        Option(i + 1, app->GetCurrentAccount()->users[i]->GetUsername());
    }
}

bool LoginUserMenu::HandleChoice(char choice)
{
    int index = choice - '1';

    if (index >= 0 && index < 3)
    {
        switch (choice)
        {
        case '1': {
            
            int index = choice - '1';
            
            if (index >= 0 && index < 3) // TODO: Hardcoded numbers, change when using List<T>
            {
                std::string username = app->GetCurrentAccount()->users[index]->GetUsername();

                std::cout << "  Enter password for " << username << ": ";
                if (app->LoginUser(username, Utils::getLineFromUser()))
                {
                    return true;
                }
            }	
        }
        case '2': {
            int index = choice - '1';

            if (index >= 0 && index < 3) // TODO: Hardcoded numbers, change when using List<T>
            {
                std::string username = app->GetCurrentAccount()->users[index]->GetUsername();

                std::cout << "  Enter password for " << username << ": ";
                if (app->LoginUser(username, Utils::getLineFromUser()))
                {
                    return true;
                }
            }
        }
        case '3': {
            int index = choice - '1';

            if (index >= 0 && index < 3) // TODO: Hardcoded numbers, change when using List<T>
            {
                std::string username = app->GetCurrentAccount()->users[index]->GetUsername();

                std::cout << "  Enter password for " << username << ": ";
                if (app->LoginUser(username, Utils::getLineFromUser()))
                {
                    return true;
                }
            }
        }
        default:
            break;
        }
        return false;
    }
}

