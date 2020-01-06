#ifndef ENEMY_H
#define ENEMY_H

#include<SFML/Graphics.hpp>

class Enemy
{
private:
	sf::CircleShape shape;
	int type;
	int hp;
	int hpMax;
	int damage;
	int points;

	void initShape();
	void initVariables();

public:
	Enemy(float pos_x, float pos_y);
	virtual ~Enemy();

	//Functions
	void update();
	void render(sf::RenderTarget* target);
};

#endif //!ENEMY_H