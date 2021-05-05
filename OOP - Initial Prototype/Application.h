#pragma once

#include "Account.h"
#include "User.h"
#include "Store.h"
#include "ListT.h"
#include "Date.h"
#include "Admin.h"

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
		//Account* GetAccount(const int& index) const;

		bool LoginAccount(const std::string& email, const std::string& password);
		bool LoginUser(const std::string& username, const std::string& password, int& index);
		void LogoutUser();
		void addAccount(Account* account);

		void Load();
		void Save();
		


		//Account* accounts[1] = { }; // TODO: this needs changing to a dynamic collection

	private:
		List<Account*> accounts;
		Store store;
		Account* currentAccount;
		Player* currentUser;
};