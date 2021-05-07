#include "Store.h"

Store::Store()
{
}

Store::~Store()
{
	for (int i = 0; i < 9; ++i)
	{
		games.deleteFirst();
	}
}

void Store::addGame(Game* game) {
	games.addAtEnd(game);
}

Game Store::getIndex(const int& index) 
{
	return *games[index];
}

List<Game*> Store::GetGames()
{
	return List<Game*>(games);
}

List<std::string> Store::searchGameName()
{
	return List<std::string>(); 
}