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
		Date* GetDatePurchased() const;
		double getHours();
		void setHours();
	private:
		double hoursPlayed = 0;
		const Game game;
		Date* purchased;
		
};