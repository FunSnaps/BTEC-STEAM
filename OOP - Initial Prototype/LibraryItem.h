#pragma once

#include "Game.h"
#include "Date.h"

class LibraryItem
{
	public:
		LibraryItem(Date*, const Game& game);
		~LibraryItem();

		Game getGame() const;
		bool sortVector( LibraryItem* item) ;

	private:
		const Game game;
		//const std::string purchased;  // TODO: replace with custom Date class, currently YYYY-MM-DD
		Date* purchased;
		
};