#include "Game.h"

Game::Game(const int& id, const std::string& name, const std::string& desc, const int& cost, const int& agerating, const int& rating, const int& likes, const int& dislikes)
	: name(name), description(desc), cost(cost), ageRating(agerating), rating(rating), likes(likes), dislikes(dislikes), id(id)
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

void Game::setRating()
{
	if (likes != 0 && dislikes != 0) {
		rating = ((static_cast<double>(likes) / (static_cast<double>(dislikes) + static_cast<double>(likes))) * 100);
	}
	else if (likes > 0 && dislikes == 0) {
		rating = 100;
	}
	else {
		rating = 0;
	}
}

int Game::GetRating()
{
	return rating;
}

void Game::addLike()
{
	likes++;
}

void Game::addDislikes()
{
	dislikes++;
}

const int& Game::GetAgeRating() const
{
	return ageRating;
}

const int& Game::GetLikes() const
{
	return likes;
}

const int& Game::GetDislikes() const
{
	return dislikes;
}

const int& Game::GetID() const
{
	return id;
}






