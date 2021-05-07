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
		Game getIndex(const int& index);
		List <Game*> GetGames();
		List <std::string> searchGameName();

	private:
		List<Game*> games;
};