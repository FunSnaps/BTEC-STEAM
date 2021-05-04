#pragma once

#include "Game.h"

class LibraryItem
{
	public:
		LibraryItem(const std::string&, const Game& game);
		~LibraryItem();

		Game getGame() const;

	private:
		const Game game;
		const std::string purchased;  // TODO: replace with custom Date class, currently YYYY-MM-DD
};