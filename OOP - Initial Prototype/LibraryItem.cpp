#include "LibraryItem.h"

LibraryItem::LibraryItem(Date* date, const Game& game)
	: purchased(date), game(game)
{
}

LibraryItem::~LibraryItem()
{
}

Game LibraryItem::getGame() const {
	return game;
}
