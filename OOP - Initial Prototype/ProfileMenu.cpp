#include "ProfileMenu.h"

ProfileMenu::ProfileMenu(const std::string& title, Application* app)
	: Menu(title, app)
{
	Paint(); // required in constructor
}

void ProfileMenu::OutputOptions( )
{
	
	
		// adding 1 so the display is nicer for the user
		Option(1, "Account holder: " + app->accounts.first()->users[0]->GetUsername());
		Line();
		Option(2, "Username: " + app->GetCurrentAccount()->users[0]->GetUsername());
		Line();
		Option(3, "Password");
	
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