#pragma once

#include <string>
#include "Player.h"
#include "Date.h"

class Account
{
	public:
		Account(const std::string&, const std::string&, Date* );
		~Account();
		List<Player*> users;
		std::string& GetEmail();
		std::string& GetPassword();
		const Date* GetCreated() const;
		const List<Player*> GetUsers() const;
	private:
		std::string email;
		std::string password;
		Date* created;
};