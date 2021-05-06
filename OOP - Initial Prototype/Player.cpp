#include "Player.h"


Player::Player(const std::string& username, const std::string& password, Date* created, const int& credit, bool userStatus)
	: User(username, password, created, credit, userStatus)
{
}

Player::~Player()
{
	for (int i = 0; i < 2; ++i)
	{
		delete library[i];
	}
}

void Player::addLibraryItem(LibraryItem* item)
{
	library.push_back(item);
}

std::vector<LibraryItem*> Player::getLibraryItems() const {
	return library;
}

void Player::addCredit(int add)
{
	credit = credit + add;
}