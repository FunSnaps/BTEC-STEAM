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

bool LibraryItem::sortVector(LibraryItem* item) {
	return game.GetName() < item->getGame().GetName();
}

//bool operator<(const LibraryItem& lhs, const LibraryItem& rhs) {
//	return lhs.sortVector(rhs);
//}