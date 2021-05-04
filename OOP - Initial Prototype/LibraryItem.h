#pragma once

#include "Game.h"
#include "Date.h"

class LibraryItem
{
	public:
		LibraryItem(const Date& date, const Game& game);
		~LibraryItem();

		Game GetGame()const;
	private:
		const Game game;
		const Date purchased;  
};