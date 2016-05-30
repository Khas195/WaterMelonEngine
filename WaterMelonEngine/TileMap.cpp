#include "TileMap.h"



TileMap::TileMap()
{
	TextureManager::init();
	int tile_id = TextureManager::requestID("./sprites/tileset.png");
	tile = Sprite(TextureManager::requestTexture(tile_id), sf::Vector2f(64, 64));
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			tiles[i][j] = Tile(tile);
			tiles[i][j].setPosition(sf::Vector2f(16 + i * 64, j * 64));
		}
	}
}

void TileMap::update(sf::Clock & gameTime)
{
}

void TileMap::render(sf::RenderWindow & window)
{
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			tiles[i][j].render(window);
		}
	}
}

void TileMap::receiveMessage(Package * package)
{
}

std::string TileMap::getName()
{
	return std::string();
}
