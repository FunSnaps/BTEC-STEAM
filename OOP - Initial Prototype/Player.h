#pragma once

#include <string>
#include <iostream>
#include <vector>
#include "LibraryItem.h"
#include "User.h"
#include "ListT.h"

class Player : public User
{
	public:
		Player(const std::string&, const std::string&, const std::string&);
		~Player();
		
		//void addItem(LibraryItem* libraryItem);

		std::vector<LibraryItem*> library;
		//List<LibraryItem*> library;
		//LibraryItem* library[2] = { }; // TODO: replace with custom List<T> class
	private:
};