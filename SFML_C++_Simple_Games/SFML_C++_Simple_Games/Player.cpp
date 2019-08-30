#include "Player.h"

void Player::initVariables()
{

}

void Player::initShape()
{
	this->shape.setFillColor(sf::Color::Green);
	this->shape.setSize(sf::Vector2f(50.f, 50.f));
}

Player::Player()
{
	this->initVariables();
	this->initShape();
}

Player::~Player()
{

}

void Player::update()
{

}

void Player::render(sf::RenderTarget * target)
{
	target->draw(this->shape);
}
