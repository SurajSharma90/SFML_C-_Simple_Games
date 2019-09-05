#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class SwagBall
{
private:
	sf::CircleShape shape;

	void initShape();
public:
	SwagBall();
	virtual ~SwagBall();

	//Functions
	void update();
	void render(sf::RenderTarget& target);
};

