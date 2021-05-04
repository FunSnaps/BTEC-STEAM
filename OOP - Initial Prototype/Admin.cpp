#include "Admin.h"

Admin::Admin(const std::string& username, const std::string& password, Date* created, const int& credit)
	: Player(username, password, created, credit)
{
}

Admin::~Admin()
{
}