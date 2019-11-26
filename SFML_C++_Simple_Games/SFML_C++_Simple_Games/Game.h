#pragma once

#include"Player.h"

class Game
{
private:
	sf::RenderWindow* window;

	//Private functions
	void initWindow();

public:
	Game();
	virtual ~Game();

	//Functions
	void run();

	void update();
	void render();
};

