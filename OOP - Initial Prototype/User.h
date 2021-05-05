#pragma once

#include <string>
#include "Date.h"

class User
{
	public:
		User(const std::string& username, const std::string& password, Date* created, const int&, bool userStatus);
		virtual ~User() = 0;
		const std::string& GetUsername() const;
		const bool& GetUserStatus() const;
		const int& getCredit() const;
	private:
		bool userStatus = false;
		std::string username;
		std::string password;
		Date* created;
		const int credit;
};