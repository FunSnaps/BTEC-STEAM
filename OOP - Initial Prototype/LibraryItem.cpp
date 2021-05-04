#include "LibraryItem.h"

LibraryItem::LibraryItem(const std::string& date, const Game& game)
	: purchased(date), game(game)
{
}

LibraryItem::~LibraryItem()
{
}

Game LibraryItem::getGame() const {
	return game;
}
