#pragma once

#include <string>
#include "LibraryItem.h"
#include "Date.h"
#include "User.h"
#include "ListT.h"
#include <vector>

class Player : public User
{
	public:
		Player(const std::string&, const std::string&, const Date&, const int& credit);
		~Player();

		void addLibraryItem(LibraryItem* item);
		//std::vector<LibraryItem*> getLibraryItems() const;
	private:
		std::vector<LibraryItem*> library; //get set
};