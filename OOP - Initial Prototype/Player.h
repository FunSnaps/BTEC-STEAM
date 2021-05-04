#pragma once

#include <string>
#include "LibraryItem.h"
#include "Date.h"
#include "User.h"
#include "ListT.h"

class Player : public User
{
	public:
		Player(const std::string&, const std::string&, const Date&, const int& something);
		~Player();

		void addLibraryItem(LibraryItem* item);
		List<LibraryItem*> getLibraryItems() const;
	private:
		List<LibraryItem*> library = {}; //get set
};