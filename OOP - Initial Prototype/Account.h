#pragma once

#include <string>
#include "Player.h"
#include "Date.h"

class Account
{
	public:
		Account(const std::string&, const std::string&, /*const std::string&*/ Date* );
		~Account();
		List<Player*> users;
	private:
		//Player* users[3] = { }; // TODO: replace with custom List<T> class
		std::string email;
		std::string password;
		//std::string created;  // TODO: replace with custom Date class, currently YYYY-MM-DD
		Date* created;
};