#include "Player.h"

Player::Player(const std::string& username, const std::string& password, const Date& created, const int& credit)
	: User(username, password, created, credit)
{
}

Player::~Player()
{
	for (int i = 0; i < library.size(); ++i)
	{
		delete library[i];
	}
}

/*List<LibraryItem*> Player::getLibraryItems() const
{
	return library;
}*/

void Player::addLibraryItem(LibraryItem* item)
{
	library.push_back(item);
}

