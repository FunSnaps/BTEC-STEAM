#pragma once

#include <string>
#include <iostream>
#include "LibraryItem.h"
#include "User.h"
#include "ListT.h"

class Player : public User
{
	public:
		Player(const std::string&, const std::string&, const std::string&);
		~Player();
	private:
		List<LibraryItem*> library = {}; //get set
};