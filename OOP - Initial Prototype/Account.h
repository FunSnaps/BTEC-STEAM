#pragma once

#include <string>
#include "Player.h"

class Account
{
	public:
		Account(const std::string&, const std::string&, const std::string&);
		~Account();
		List<Player*> users;
	private:
		//Player* users[3] = { }; // TODO: replace with custom List<T> class
		std::string email;
		std::string password;
		std::string created;  // TODO: replace with custom Date class, currently YYYY-MM-DD
};