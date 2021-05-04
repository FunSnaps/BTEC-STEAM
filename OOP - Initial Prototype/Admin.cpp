#include "Admin.h"

Admin::Admin(const std::string& username, const std::string& password, const Date& created, const int& something)
	: Player(username, password, created, something)
{
}

Admin::~Admin()
{
}