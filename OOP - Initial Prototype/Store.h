#pragma once

#include "Game.h"
#include <vector>

class Store
{
	public:
		Store();
		~Store();
		Game* games[9] = { }; // TODO: should be a dynamic collection
		std::vector<std::string> games2;
	private:
};