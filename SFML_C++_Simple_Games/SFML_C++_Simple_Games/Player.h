#pragma once

class Player
{
private:
	sf::Sprite sprite;
	sf::Texture textureSheet;
	bool moving;
	sf::Clock animationTimer;

	//Animation
	sf::IntRect currentFrame;

	//Movement

	//Core

	void initVariables();
	void initTexture();
	void initSprite();
	void initAnimations();

public:
	Player();
	virtual ~Player();

	//Functions	
	void updateMovement();
	void updateAnimations();
	void update();
	void render(sf::RenderTarget& target);
};

