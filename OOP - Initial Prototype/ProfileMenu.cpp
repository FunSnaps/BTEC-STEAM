#include "ProfileMenu.h"

ProfileMenu::ProfileMenu(const std::string& title, Application* app)
	: Menu(title, app)
{
	Paint(); // required in constructor
}

void ProfileMenu::OutputOptions( )
{
		
		// adding 1 so the display is nicer for the user
		Line( "Account holder: " + app->GetCurrentAccount()->users[0]->GetUsername());
		Line();
		Line("Username: " + app->GetCurrentUser()->GetUsername());
		Line();
		Line("Owned Games");
		for (iter = 0; iter != app->GetCurrentUser()->getLibraryItems().size(); iter++) {
			Option(iter + 1, app->GetCurrentUser()->getLibraryItems().operator[](iter)->getGame().GetName());
		}

		if (app->GetCurrentUser()->GetUserStatus()) {
			Line();
			Option(iter + 1, "Add new user");
			Option(iter + 2, "Remove user");
		}
}

bool ProfileMenu::HandleChoice(char choice)
{
	// since we are using numbers here we shift the char down by '1'
	// this puts '1' as 0, '2' as 1, '3' as 2, '4' as 3, etc.
	// this reverses the + 1 above and lets us do the range check below
	int index = choice - '1';

	if (index >= 0 && index < 10)
	{
		for (int i = 0; i < iter; i++) {
			if (i == index) {
				BlockingMessage(app->GetCurrentUser()->getLibraryItems().operator[](i)->getGame().GetName());
			}
		}

		if (index == (iter)) {
			BlockingMessage("ADD");
		}
		/*else if (index == iter + 1) {
			std::string temp = Question("Who would you like to remove?");
			for (int j = 0; j < app->GetCurrentAccount()->users.length(); j++) {
				if (temp == app->GetCurrentAccount()->users.operator[](j)->GetUsername()) {
					std::string username = app->GetCurrentAccount()->users.operator[](j)->GetUsername();
					std::string password = app->GetCurrentAccount()->users.operator[](j)->GetPassword;
					Date* date = app->GetCurrentAccount()->users.operator[](j).GetCreated();
					int credit = app->GetCurrentAccount()->users.operator[](j)->getCredit();
					bool status = app->GetCurrentAccount()->users.operator[](j)->GetUserStatus();
					app->GetCurrentAccount()->users.deleteOne(new Player(username, password, date, credit, status));
				}
			}
		}*/
	}

	return false;
}