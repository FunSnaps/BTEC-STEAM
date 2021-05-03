#pragma once

#include <string>

class User
{
	public:
		User(const std::string& username, const std::string& password, const std::string& created);
		virtual ~User() = 0;
		const std::string& GetUsername() const;
		const bool& GetUserStatus() const;
	private:
		bool userStatus = false;
		std::string username;
		std::string password;
		std::string created;  // TODO: replace with custom Date class, currently YYYY-MM-DD
};