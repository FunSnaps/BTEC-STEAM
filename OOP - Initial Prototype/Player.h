#pragma once

#include <string>
#include "LibraryItem.h"
#include "User.h"

class Player : public User
{
	public:
		//constructors + destructor
		Player(const std::string&, const std::string&, const std::string&);
		~Player();
		//query
		int getCredit() const;
		//library of games
		LibraryItem* library[2] = { }; // TODO: replace with custom List<T> class
	private:
		int credit = 1000;
};