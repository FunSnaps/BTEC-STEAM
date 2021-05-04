#pragma once

#include <string>
#include "Player.h"

class Admin : public Player
{
	public:
		Admin(const std::string&, const std::string&, Date*, const int&);
		~Admin();
};