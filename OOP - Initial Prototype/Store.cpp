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