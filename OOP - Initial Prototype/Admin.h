#pragma once

#include <string>
#include "Player.h"
#include "Date.h"

class Admin : public Player
{
	public:
		Admin(const std::string& username, const std::string& password, const Date& created, const int& something);
		~Admin();
};