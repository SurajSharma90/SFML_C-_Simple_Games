#pragma once

#include<map>
#include"Player.h"

class Game
{
private:
	//Window
	sf::RenderWindow* window;

	//Resources
	std::map<std::string, sf::Texture> textures;

	//Player
	Player* player;

	//Private functions
	void initWindow();
	void initTextures();

	void initPlayer();

public:
	Game();
	virtual ~Game();

	//Functions
	void run();

	void updatePollEvents();
	void updateInput();
	void update();
	void render();
};

