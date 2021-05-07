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

int Player::getCredit() const
{
	return credit;
}
void Player::addCredit(int add)
{
	credit = credit + add;
}

void Player::addLibraryItem(LibraryItem* item)
{
	library.push_back(item);
}

std::vector<LibraryItem*> Player::getLibraryItems() const {
	return library;
}

void Player::buyGame(double cost)
{
	std::stringstream convertDouble;
	convertDouble << cost;
	std::string converted = convertDouble.str();

	std::string first;
	std::string second;

	for (int i = 0; i < converted.length() - 2; i++)
	{
		first += converted[i];
	}

	for (int i = converted.length() - 2; i < converted.length(); i++)
	{
		second += converted[i];
	}

	double temp = std::stod(first + "." + second);

	credit = credit - temp;
}

void Player::sortGameName()
{
	std::sort(library.begin(), library.end(), [](const LibraryItem* lhs, const LibraryItem* rhs) {
		return lhs->getGame().GetName() < rhs->getGame().GetName();
		});
}

void Player::sortReleaseDate()
{
	std::sort(library.begin(), library.end(), [](const LibraryItem* lhs, const LibraryItem* rhs) {
		return lhs->GetDatePurchased() < rhs->GetDatePurchased();
		});
}

