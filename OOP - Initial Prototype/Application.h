#pragma once

#include "Account.h"
#include "User.h"
#include "Store.h"
#include "ListT.h"

#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>

class Application
{
	public:
		Application();
		~Application();

		bool IsAccountLoggedIn() const;
		bool IsUserLoggedIn() const;
		Account* GetCurrentAccount() const;
		Player* GetCurrentUser() const;

		Store& GetStore();

		bool LoginAccount(const std::string& email, const std::string& password);
		bool LoginUser(const std::string& username, const std::string& password);
		void LogoutUser();

		void Load()const;
		void Save();
		

		List<Account*> accounts;

		//Account* accounts[1] = { }; // TODO: this needs changing to a dynamic collection

	private:
		Store store;
		Account* currentAccount;
		Player* currentUser;
};