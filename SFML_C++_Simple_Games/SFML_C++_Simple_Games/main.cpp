#include"stdafx.h"
#include "Game.h"

int main()
{
	srand(time(static_cast<unsigned>(0)));

	Game game;

	while (game.getWindow().isOpen())
	{
		game.update();
		game.render();
	}

	//End of application
	return 0;
}