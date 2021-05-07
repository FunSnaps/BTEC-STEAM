#pragma once

#include "Account.h"
#include "User.h"
#include "Store.h"
#include "ListT.h"
#include "Date.h"
#include "Admin.h"
#include "Game.h"

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
		List<Account*> GetAccounts() const;

		bool LoginAccount(const std::string& email, const std::string& password, int& index);
		bool LoginUser(const std::string& username, const std::string& password, int& index);
		void LogoutUser();
		void LogoutAccount();
		void addAccount(Account* account);

		bool Load();
		void Save();

	private:
		List<Account*> accounts;
		Store store;
		Account* currentAccount;
		Player* currentUser;
		Game* game;
};