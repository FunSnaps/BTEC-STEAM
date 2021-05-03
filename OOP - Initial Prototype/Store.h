#pragma once

#include "ListT.h"
#include "Game.h"
#include <vector>

class Store
{
	public:
		Store();
		~Store();
		//Game* games[9] = { }; // TODO: should be a dynamic collection
		List<Game*> games = {};
	private:
};