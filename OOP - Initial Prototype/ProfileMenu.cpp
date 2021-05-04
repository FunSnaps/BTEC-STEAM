#include "ProfileMenu.h"

ProfileMenu::ProfileMenu(const std::string& title, Application* app)
	: Menu(title, app)
{
	Paint(); // required in constructor
}

void ProfileMenu::OutputOptions( )
{
	for (int i = 0; i < 1; i++)
	{
		// adding 1 so the display is nicer for the user
		//Option(i + 1, "Account holder: " + app->GetAccount()->users.
		Option(i + 2, "Username: " + app->GetCurrentAccount()->users[i]->GetUsername());
		Line();
		Option(i + 3, "Password");
	}
}


bool ProfileMenu::HandleChoice(char choice)
{
	// since we are using numbers here we shift the char down by '1'
	// this puts '1' as 0, '2' as 1, '3' as 2, '4' as 3, etc.
	// this reverses the + 1 above and lets us do the range check below
	int index = choice - '1';

	if (index >= 0 && index < 1)
	{
		BlockingMessage("Not implemented, press return to continue");
		// go to game detail page
	}

	return false;
}