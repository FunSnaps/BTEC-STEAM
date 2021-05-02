#pragma once

#include <string>
#include "Player.h"

class Admin : public Player
{
	public:
		Admin(const std::string&, const std::string&, const std::string&);
		~Admin();
};