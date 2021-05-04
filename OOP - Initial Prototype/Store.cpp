#include "Store.h"

Store::Store()
{
}

Store::~Store()
{
	for (int i = 0; i < 9; ++i)
	{
		delete games[i];
	}
}

void Store::addGame(Game* game)
{
	games.addInFront(game);
}

Game Store::getIndex(const int& index) //pass by ref?
{
	return *games[index];
}

List<Game*> Store::GetGames()
{
	return List<Game*>(games);
}

List<std::string> Store::searchGameName()
{
	return List<std::string>(); //needs to b e implemented
}

