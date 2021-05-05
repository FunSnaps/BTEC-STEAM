#pragma once

#include <string>
#include <iostream>
#include <vector>
#include "LibraryItem.h"
#include "User.h"
#include "ListT.h"
#include "Date.h"

class Player : public User
{
	public:
		//constructors + destructor

		Player(const std::string&, const std::string&, Date*, const int&, bool);

		~Player();
		//query
		int getCredit() const;
		std::vector<LibraryItem*> getLibraryItems() const;
		//mutate
		void addLibraryItem(LibraryItem* item);
		void buyGame(int cost);
	private:
		int credit = 3000;
		std::vector<LibraryItem*> library;
};