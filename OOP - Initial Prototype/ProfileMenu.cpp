#include "ProfileMenu.h"

ProfileMenu::ProfileMenu(const std::string& title, Application* app)
	: Menu(title, app)
{
	Paint();
}

void ProfileMenu::OutputOptions()
{
	Line("Account holder: " + app->GetCurrentAccount()->users[0]->GetUsername());
	Line();
	Line("Username: " + app->GetCurrentUser()->GetUsername());
	Line();
	Line("Current Credit - ");
	OptionCost(app->GetCurrentUser()->getCredit());
	Line();
	Line("I) Purchase 10 Credits");
	Line("O) Purchase 100 Credits");
	Line("P) Purchase 1000 Credits");
	Line();
	Line("Owned Games");
	for (iter = 0; iter != app->GetCurrentUser()->getLibraryItems().size(); iter++) {
		Option(iter + 1, Utils::formatTime(app->GetCurrentUser()->getLibraryItems().operator[](iter)->getHours(), app->GetCurrentUser()->getLibraryItems().operator[](iter)->getGame().GetName()));
	}

	Line();
	Option(iter + 1, "Sort by game name");
	Option(iter + 2, "Sort by date");


	if (app->GetCurrentUser()->GetUserStatus()) {
		Line();
		Option(iter + 3, "Add new user");
		Option(iter + 4, "Remove user");
	}

	if (app->IsUserLoggedIn()) {
		Line();
		Option('L', "Like");
		Option('D', "Dislike");
	}
}

bool ProfileMenu::HandleChoice(char choice)
{
	int index = choice - '1';

	if (index >= 0 && index < 10)
	{
		for (int i = 0; i < iter; i++) {
			if (i == index) {
				app->GetCurrentUser()->getLibraryItems().operator[](i)->setHours();

			}
		}

		if (index == (iter)) {
			app->GetCurrentUser()->sortGameName();
		}
		else if (index == iter + 1) {
			app->GetCurrentUser()->sortReleaseDate();
		}
		else if (index == (iter + 2)) {
			std::string newUsername = Question("Enter username");
			std::string newPassword = Question("Enter Password");
			Date* date = d->CurrentDate();
			Player* player = new Player(newUsername, newPassword, date, 0, false);
			app->GetCurrentAccount()->users.addAtEnd(player);
			BlockingMessage("Created");
		}
		else if (index == iter + 3) {
			std::string temp = Question("Who would you like to remove?");
			for (int j = 0; j < app->GetCurrentAccount()->users.length(); j++) {
				if (temp == app->GetCurrentAccount()->users.operator[](j)->GetUsername()) {
					app->GetCurrentAccount()->users.deleteOne(app->GetCurrentAccount()->users.operator[](j));
					BlockingMessage("Deleted");
				}
			}
		}
	}
	switch (choice) {
	case 'I':
	{
		system("CLS");
		app->GetCurrentUser()->addCredit(10);
		Line();
		Line("You have purchased 10 credits!");
		Line();
		Line("Your credit is now - ");
		printInt(app->GetCurrentUser()->getCredit());
		Line();
		Option("B) Back");
		Utils::getCharFromUser();

	switch (choice) {
	case 'I':
	{
		system("CLS");
		app->GetCurrentUser()->addCredit(10);
		Line();
		Line("You have purchased 10.00 credits!");
		Line();
		Line("Your credit is now - ");
		OptionCost(app->GetCurrentUser()->getCredit());
		Line();
		OptionPlain("Back");
		Utils::getCharFromUser();

	} break;
	case 'O':
	{
		system("CLS");
		app->GetCurrentUser()->addCredit(100);
		Line();
		Line("You have purchased 100.0 credits!");
		Line();
		Line("Your credit is now - ");
		OptionCost(app->GetCurrentUser()->getCredit());
		Line();
		OptionPlain("Back");
		Utils::getCharFromUser();

	} break;
	case 'P':
	{
		system("CLS");
		app->GetCurrentUser()->addCredit(1000);
		Line();

		Line("You have purchased 1000.0 credits!");
		Line();
		Line("Your credit is now - ");
		OptionCost(app->GetCurrentUser()->getCredit());
		Line();
		OptionPlain("B) Back");
		Utils::getCharFromUser();

	} break;
	case 'L': {
		std::string temp = Question("Which game would you like to review? (Enter name)");
		for (int i = 0; i < app->GetStore().GetGames().length(); i++) {
			if (temp == app->GetStore().GetGames()[i]->GetName()) {
				app->GetStore().GetGames()[i]->addLike();
				app->GetStore().GetGames()[i]->setRating();
			}
		}
	}break;
	case 'D': {
		std::string temp = Question("Which game would you like to review? (Enter name)");
		for (int i = 0; i < app->GetStore().GetGames().length(); i++) {
			if (temp == app->GetStore().GetGames()[i]->GetName()) {
				app->GetStore().GetGames()[i]->addDislikes();
				app->GetStore().GetGames()[i]->setRating();
			}
		}
	}break;

	default:
		break;
	}
	return false;
}




