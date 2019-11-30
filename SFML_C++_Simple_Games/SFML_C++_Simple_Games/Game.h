#pragma once

#include"Player.h"

class Game
{
private:
	sf::RenderWindow* window;

	//Player
	Player* player;

	//Private functions
	void initWindow();
	void initPlayer();

public:
	Game();
	virtual ~Game();

	//Functions
	void run();

	void update();
	void render();
};

