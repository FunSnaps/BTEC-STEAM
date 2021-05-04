#pragma once

#include <string>
#include "Date.h"

class User
{
	public:
		User(const std::string& username, const std::string& password, const Date& created, const int& something);
		virtual ~User() = 0; // double check
		const std::string& GetUsername() const;
		const bool& GetUserStatus() const;
		const int& getSomething() const;
	private:
		bool userStatus = false;
		std::string username;
		std::string password;
		const Date& created; 
		const int something;
};