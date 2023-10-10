#include "stdafx.h"
#include "TileMap.h"

TileMap::TileMap()
{
  this->tileSheet = NULL;
  this->tileSize = 0;
}

TileMap::TileMap(unsigned width, unsigned height, sf::Texture* tile_sheet, unsigned tile_size)
{
  this->tileSheet = tile_sheet;
  this->tileSize = tile_size;

  this->tiles.resize(width);
  for (int i = 0; i < this->tiles.size(); i++)
  {
    this->tiles[i].resize(height, nullptr);
  }
}

TileMap::~TileMap()
{
  for (int i = 0; i < this->tiles.size(); i++)
  {
    for (int k = 0; k < this->tiles[i].size(); k++)
    {
      delete this->tiles[i][k];
      this->tiles[i][k] = nullptr;
    }
  }
}

void TileMap::addTile(unsigned x, unsigned y)
{
  if(x < this->tiles.size())
  {
    if(y < this->tiles[x].size())
    {
      if(this->tiles[x][y] == nullptr)
        this->tiles[x][y] = new Tile(this->tileSheet, sf::IntRect(0, 0, this->tileSize, this->tileSize), false);
    }
  }
}

void TileMap::removeTile(unsigned x, unsigned y)
{
  if (x < this->tiles.size())
  {
    if (y < this->tiles[x].size())
    {
      if (this->tiles[x][y] != nullptr)
      {
        delete this->tiles[x][y];
        this->tiles[x][y] = nullptr;
      }
    }
  }
}

void TileMap::update()
{
  for (int i = 0; i < this->tiles.size(); i++)
  {
    for (int k = 0; k < this->tiles[i].size(); k++)
    {
      if (this->tiles[i][k] != nullptr)
        this->tiles[i][k]->update();
    }
  }
}

void TileMap::render(sf::RenderTarget& target)
{
  for (int i = 0; i < this->tiles.size(); i++)
  {
    for (int k = 0; k < this->tiles[i].size(); k++)
    {
      if (this->tiles[i][k] != nullptr)
        this->tiles[i][k]->render(target);
    }
  }
}
