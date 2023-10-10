#include"stdafx.h"
#include "Game.h"

void Game::initWindow()
{
	this->window.create(sf::VideoMode(800, 600), "Game 4", sf::Style::Close | sf::Style::Titlebar);
	this->window.setFramerateLimit(60);
}

void Game::initTileSheet()
{
	if (!this->tileSheet.loadFromFile("Textures/player_sheet.png"))
	{
		std::cout << "ERROR::GAME::Could not load the tile sheet!" << "\n";
	}
}

void Game::initPlayer()
{
	this->player = new Player();
}

void Game::initTileMap()
{
	this->tileMap = new TileMap(20, 20, &this->tileSheet, 50);
	this->tileMap->addTile(0, 0);
}

Game::Game()
{
	this->initWindow();
	this->initTileSheet();
	this->initPlayer();
	this->initTileMap();
}

Game::~Game()
{
	delete this->player;
	delete this->tileMap;
}

void Game::updatePlayer()
{
	this->player->update();
}

void Game::updateCollision()
{
	//Collision bottom of screen
	if (this->player->getPosition().y + this->player->getGlobalBounds().height > this->window.getSize().y)
	{
		this->player->setCanJump(true);
		this->player->resetVelocityY();
		this->player->setPosition(
			this->player->getPosition().x,
			this->window.getSize().y - this->player->getGlobalBounds().height
		);
	}
}

void Game::updateTileMap()
{
	this->tileMap->update();
}

void Game::update()
{
	//Polling window events
	while (this->window.pollEvent(this->ev))
	{
		if (this->ev.type == sf::Event::Closed)
			this->window.close();
		else if (this->ev.type == sf::Event::KeyPressed && this->ev.key.code == sf::Keyboard::Escape)
			this->window.close();

		if (
			this->ev.type == sf::Event::KeyReleased &&
			(
				this->ev.key.code == sf::Keyboard::A ||
				this->ev.key.code == sf::Keyboard::D ||
				this->ev.key.code == sf::Keyboard::W ||
				this->ev.key.code == sf::Keyboard::S
				)
			)
		{
			this->player->resetAnimationTimer();
		}
	}

	this->updatePlayer();

	this->updateCollision();

	this->updateTileMap();
}

void Game::renderPlayer()
{
	this->player->render(this->window);
}

void Game::renderTileMap()
{
	this->tileMap->render(this->window);
}

void Game::render()
{
	this->window.clear();

	//Render game
	this->renderTileMap();
	this->renderPlayer();

	this->window.display();
}

const sf::RenderWindow & Game::getWindow() const
{
	// TODO: insert return statement here
	return this->window;
}
