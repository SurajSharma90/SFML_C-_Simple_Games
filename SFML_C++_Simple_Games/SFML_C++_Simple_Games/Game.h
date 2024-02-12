#pragma once
#include"Player.h"
#include"TileMap.h"

class Game
{
private:
	sf::RenderWindow window;
	sf::Event ev;
	sf::Texture tileSheet;

	Player* player;
	TileMap* tileMap;
	std::map<std::string, sf::Keyboard::Key> keyboardMappings;
	std::map<std::string, sf::Mouse::Button> mouseMappings;

	void initWindow();
	void initInput();
	void initTileSheet();
	void initPlayer();
	void initTileMap();

public:

	//Functions
	Game();
	virtual ~Game();

	//Functions
	void updateInput();
	void updatePlayer();
	void updateCollision();
	void updateTileMap();
	void update();

	void renderPlayer();
	void renderTileMap();
	void render();

	const sf::RenderWindow& getWindow() const;
};

