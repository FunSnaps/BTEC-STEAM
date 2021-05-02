#include "Game.h"

Game::Game(const std::string& name, const std::string& desc, int cost, int rating)
	: name(name), description(desc), cost(cost), ageRating(rating)
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