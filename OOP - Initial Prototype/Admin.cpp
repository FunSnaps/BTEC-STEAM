#include "Admin.h"

Admin::Admin(const std::string& username, const std::string& password, Date* created, const int& credit, bool userStatus)
	: Player(username, password, created, credit, userStatus)
{
}

Admin::~Admin()
{
}