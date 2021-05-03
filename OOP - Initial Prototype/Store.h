#pragma once

#include "ListT.h"
#include "Game.h"
#include <vector>

class Store
{
	public:
		Store();
		~Store();
		void addGame(Game* game);
	private:
		List<Game*> games = {};
};