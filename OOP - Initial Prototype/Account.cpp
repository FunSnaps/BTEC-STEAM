#include "Account.h"

Account::Account(const std::string& email, const std::string& password, const std::string& created)
	: email(email), password(password), created(created)
{
}

Account::~Account()
{
	for (int i = 0; i < 3; ++i)
	{
		delete users[i];
	}
}