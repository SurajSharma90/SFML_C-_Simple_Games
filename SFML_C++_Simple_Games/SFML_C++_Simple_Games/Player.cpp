#include "stdafx.h"
#include "Player.h"

void Player::initVariables()
{
	this->moving = false;
}

void Player::initTexture()
{
	if (!this->textureSheet.loadFromFile("Textures/player_sheet.png"))
	{
		std::cout << "ERROR::PLAYER::Could not load the player sheet!" << "\n";
	}
}

void Player::initSprite()
{
	this->sprite.setTexture(this->textureSheet);
	this->currentFrame = sf::IntRect(0, 0, 40, 50); //SHOULD BE 40 50

	this->sprite.setTextureRect(this->currentFrame);
	this->sprite.setScale(5.5f, 5.5f);
}

void Player::initAnimations()
{
	this->animationTimer.restart();
}

Player::Player()
{
	this->initVariables();
	this->initTexture();
	this->initSprite();
	this->initAnimations();
}

Player::~Player()
{

}

void Player::updateMovement()
{
	this->moving = false;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) //Left
	{
		this->sprite.move(-1.f, 0.f);
		this->moving = true;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) //Right
	{
		this->sprite.move(1.f, 0.f);
		this->moving = true;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) //Top
	{
		this->sprite.move(0.f, -1.f);
		this->moving = true;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) //Down
	{
		this->sprite.move(0.f, 1.f);
		this->moving = true;
	}
}

void Player::updateAnimations()
{
	if (this->animationTimer.getElapsedTime().asSeconds() >= 0.2f)
	{
		if (this->moving == false) //IDLE Animation
		{
			this->currentFrame.left += 40.f;
			if (this->currentFrame.left >= 160.f)
				this->currentFrame.left = 0;
		}

		this->animationTimer.restart();
		this->sprite.setTextureRect(this->currentFrame);
	}
}

void Player::update()
{
	this->updateMovement();
	this->updateAnimations();
}

void Player::render(sf::RenderTarget & target)
{
	target.draw(this->sprite);
}
