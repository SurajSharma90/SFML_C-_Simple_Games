#include "stdafx.h"
#include "Tile.h"

Tile::Tile(const unsigned& grid_pos_x, const unsigned& grid_pos_y, const unsigned& tile_size,
sf::Texture* texture_sheet, sf::IntRect texture_rect, bool damaging)
	: damaging(damaging)
{
	this->sprite.setTexture(*texture_sheet);
	this->sprite.setTextureRect(texture_rect);
	this->sprite.setPosition(float(grid_pos_x * tile_size), float(grid_pos_y * tile_size));
}

const sf::FloatRect Tile::getGlobalBounds() const
{
	return this->sprite.getGlobalBounds();
}

void Tile::update()
{

}

void Tile::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}
