#pragma once

#include"Tile.h"

class TileMap
{
private:
	std::vector< std::vector<Tile*> > tiles;
	sf::Texture* tileSheet;
	unsigned tileSize;

public:
	TileMap();
	TileMap(unsigned width, unsigned height, sf::Texture* tile_sheet, unsigned tile_size);
	~TileMap();

	//Inline functions
	inline const unsigned& getTileSize() const { return this->tileSize; };

	//Functions
	void addTile(unsigned x, unsigned y);
	void removeTile(unsigned x, unsigned y);

	void update();
	void render(sf::RenderTarget& target);
};

