#include "Admin.h"

Admin::Admin(const std::string& username, const std::string& password, const std::string& created)
	: Player(username, password, created)
{
}

Admin::~Admin()
{
}