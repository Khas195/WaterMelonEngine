#include "TileMap.h"



TileMap::TileMap()
{
	TextureManager::init();
	int tile_id = TextureManager::requestID("./sprites/tileset.png");
	tile = Sprite(TextureManager::requestTexture(tile_id), sf::Vector2f(64, 64));
	float offset = (SCREEN_WIDTH - MAP_WIDTH * 32) / 2;
	for (int i = 0; i < MAP_WIDTH; i++)
	{
		for (int j = 0; j < MAP_HEIGHT; j++)
		{
			tiles[i][j] = Tile(tile);
			tiles[i][j].setPosition(sf::Vector2f(offset + i * 32, j * 32));
		}
	}
}

void TileMap::update(sf::Clock & gameTime)
{
}

void TileMap::render(sf::RenderWindow & window)
{
	for (int i = 0; i < MAP_WIDTH; i++)
	{
		for (int j = 0; j < MAP_HEIGHT; j++)
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
