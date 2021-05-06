#include "LoginAccountMenu.h"

LoginAccountMenu::LoginAccountMenu(const std::string& title, Application* app)
	: Menu(title, app)
{
	Paint();
}

void LoginAccountMenu::OutputOptions() {

	for (int i = 0; i < app->GetAccounts().length(); i++) {
		Option(i + 1, app->GetAccounts().operator[](i)->GetEmail());
	}
}

bool LoginAccountMenu::HandleChoice(char choice) {

	int index = choice - '1';
	if (index >= 0 && index < app->GetAccounts().length()) {
		
		std::string email = app->GetAccounts()[index]->GetEmail();

		std::cout << "  Enter password for " << email << ": ";
		if (app->LoginAccount(email, Utils::getLineFromUser(), index)) {
			return true;
		}
		else return false;

	}
	return false;
}