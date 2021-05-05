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

		Line();
		Option(iter + 3, "Sort by game name");
		Option(iter + 4, "Sort by date");
}

bool ProfileMenu::HandleChoice(char choice)
{
	int index = choice - '1';

	if (index >= 0 && index < 10)
	{
		for (int i = 0; i < iter; i++) {
			if (i == index) {
				BlockingMessage(app->GetCurrentUser()->getLibraryItems().operator[](i)->getGame().GetName());
			}
		}

		if (index == (iter)) {
			std::string newUsername = Question("Enter username");
			std::string newPassword = Question("Enter Password");
			Date* date = d->CurrentDate();
			Player* player = new Player(newUsername, newPassword, date, 0, false);
			app->GetCurrentAccount()->users.addAtEnd(player);
		}
		else if (index == iter + 1) {
			std::string temp = Question("Who would you like to remove?");
			for (int j = 0; j < app->GetCurrentAccount()->users.length(); j++) {
				if (temp == app->GetCurrentAccount()->users.operator[](j)->GetUsername()) {
					app->GetCurrentAccount()->users.deleteOne(app->GetCurrentAccount()->users.operator[](j));
					BlockingMessage("Deleted");
				}
			}
		}

	}

	return false;
}


