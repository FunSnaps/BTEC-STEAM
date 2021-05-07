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

Date* LibraryItem::GetDatePurchased() const
{
	return purchased;
}

double LibraryItem::getHours() {
	return hoursPlayed;
}


void LibraryItem::setHours() {
	int temp = rand() % 60 + 10;
	hoursPlayed += temp;
}

