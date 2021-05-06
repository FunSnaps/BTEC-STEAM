#include "Game.h"

Game::Game(const std::string& name, const std::string& desc, const int& cost, const int& agerating, int& starrating)
	: name(name), description(desc), cost(cost), ageRating(agerating), starRating(starrating)
{
}

Game::~Game()
{
}

const std::string& Game::GetName() const
{
	return name;
}

const std::string& Game::GetDescription() const
{
	return description;
}

int Game::GetCost() const
{
	return cost;
}