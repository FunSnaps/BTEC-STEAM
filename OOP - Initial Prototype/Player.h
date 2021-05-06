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
		Player(const std::string&, const std::string&, Date*, const int&, bool);
		~Player();
		
		void addLibraryItem(LibraryItem* item);
		std::vector<LibraryItem*> getLibraryItems() const;
		void addCredit(int add);
	private:
		int credit = 1000;
		std::vector<LibraryItem*> library;
};