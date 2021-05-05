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
		Player(const std::string& username, const std::string& password, Date* created, const int& credit, bool userStatus);
		~Player();
		//query
		int getCredit() const;
	
    void addLibraryItem(LibraryItem* item);
		std::vector<LibraryItem*> getLibraryItems() const;
	private:
		int credit = 1000;
    std::vector<LibraryItem*> library;
};