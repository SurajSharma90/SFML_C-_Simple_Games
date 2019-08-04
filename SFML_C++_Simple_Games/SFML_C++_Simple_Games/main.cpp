#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

//using namespace sf;

int main()
{
	//Window
	sf::RenderWindow window(sf::VideoMode(640, 480), "My first game", sf::Style::Titlebar | sf::Style::Close);
	sf::Event ev;

	//Game loop
	while (window.isOpen())
	{
		//Event polling
		while (window.pollEvent(ev))
		{
			switch (ev.type)
			{
			case sf::Event::Closed: 
				window.close();
				break;
			case sf::Event::KeyPressed:
				if (ev.key.code == sf::Keyboard::Escape)
					window.close();
				break;
			}
		}

		//Update


		//Render
		window.clear(sf::Color::Blue); //Clear old frame

		//Draw your game

		window.display(); //Tell app that window is done drawing
	}

	//End of application
	return 0;
}