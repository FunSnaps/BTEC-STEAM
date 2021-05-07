#include "Account.h"

Account::Account(const std::string& email, const std::string& password, Date* created)
	: email(email), password(password), created(created)
{
}

Account::~Account()
{
	for (int i = 0; i < users.length(); ++i)
	{
		users.deleteFirst();
	}
}

std::string& Account::GetEmail() {
	return email;
}

std::string& Account::GetPassword() {
	return password;
}

const Date* Account::GetCreated() const
{
	return created;
}

const List<Player*> Account::GetUsers() const
{
	return users;
}