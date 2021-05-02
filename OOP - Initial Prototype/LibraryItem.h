#pragma once

#include "Game.h"

class LibraryItem
{
	public:
		LibraryItem(const std::string&, Game*);
		~LibraryItem();
	private:
		const Game *game;
		const std::string purchased;  // TODO: replace with custom Date class, currently YYYY-MM-DD
};