#include "Player.h"

Player::Player(const std::string& username, const std::string& password, const Date& created, const int& something)
	: User(username, password, created, something)
{
}

Player::~Player()
{
	for (int i = 0; i < library.length(); ++i)
	{
		delete library[i];
	}
}

List<LibraryItem*> Player::getLibraryItems() const
{
	return library;
}

void Player::addLibraryItem(LibraryItem* item)
{
	library.addInFront(item);
}

