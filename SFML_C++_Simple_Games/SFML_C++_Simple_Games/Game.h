#pragma once

class Game
{
private:
	sf::RenderWindow window;

	void initWindow();

public:

	//Functions

	Game();
	virtual ~Game();

	//Functions
	void update();
	void render();
	const sf::RenderWindow& getWindow() const;
};

