#include "LibraryItem.h"

LibraryItem::LibraryItem(const Date& date, const Game& game)
	: purchased(date), game(game)
{
}

LibraryItem::~LibraryItem()
{
	//delete an item?
}

Game LibraryItem::GetGame() const
{
	return game;
}
