#include "MainMenu.h"

MainMenu::MainMenu(const std::string& title, Application* app) 
	: Menu(title, app)
{
	Paint(); // required in constructor
}

void MainMenu::OutputOptions()
{
	Option('S', "Browse Store");
	if (app->IsAccountLoggedIn() && !app->IsUserLoggedIn()) {

		Option('L', "User Login");
		Option('A', "Logout");
	}
	else if (app->IsUserLoggedIn())
	{
		Option('P', "View Profile");
		Option('L', "Logout");
	}
	else
	{
		Option('A', "Account Login");
	}
}

bool MainMenu::HandleChoice(char choice)
{
	switch (choice)
	{
	case 'S':
	{
		StoreMenu("STORE", app);
	} break;
	case 'L':
	{
		if (app->IsUserLoggedIn())
		{
			std::string answer = Question("Are you sure?");
			if (answer == "y" || answer == "Y")
			{
				app->LogoutUser();
			}
		}
		else
		{
			
			LoginUserMenu("Login Menu", app);
		}
	} break;
	case 'P':
	{
		if (app->IsUserLoggedIn())
		{
			ProfileMenu("PROFILE MENU", app);
		}
	} break;
	case 'A':
	{
		if (app->IsAccountLoggedIn()) {
			std::string answer = Question("Are you sure?");
			if (answer == "y" || answer == "Y")
			{
				app->LogoutAccount();
			}
		}
		else {
			LoginAccountMenu("ACCOUNT LOGIN", app);
		}
	}
	}

	return false;
}

