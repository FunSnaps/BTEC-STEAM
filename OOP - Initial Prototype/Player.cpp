#include "Player.h"

Player::Player(const std::string& username, const std::string& password, Date* created, const int& credit)
	: User(username, password, created, credit)
{
}

Player::~Player()
{
	for (int i = 0; i < 2; ++i)
	{
		delete library[i];
	}
}

//void Player::addItem(LibraryItem* libraryItem) {
//	library.addAtEnd(libraryItem);
//}

void Player::addLibraryItem(LibraryItem* item)
{
	library.push_back(item);
}