#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include "LibraryItem.h"
#include "User.h"
#include "ListT.h"
#include "Date.h"

class Player : public User
{
	public:
		Player(const std::string&, const std::string&, Date*, const int&, bool);
		~Player();
		
		int getCredit() const;
		void addCredit(int add);

		void addLibraryItem(LibraryItem* item);
		std::vector<LibraryItem*> getLibraryItems() const;
		void buyGame(double cost);
		void sortGameName();
		void sortReleaseDate();
	private:
		int credit = 10.00;
		std::vector<LibraryItem*> library;
};