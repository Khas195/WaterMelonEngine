#include "TileSet.h"
#include"TextureManager.h"

TileSet::TileSet(sf::Uint32 firstgid, std::string name, sf::Uint32 tileWidth, sf::Uint32 tileHeight, TILE_STATE state, std::string source)
	: firstgid(firstgid), name(name), tileWidth(tileWidth), tileHeight(tileHeight), state(state), source(source)
{
	state = FREE;
	texId = TextureManager::requestID(this->source);
	sf::Vector2u setSize = TextureManager::requestTexture(texId).getSize();
	tileAmountWidth = setSize.x / tileWidth;
	tileAmountHeight = setSize.y / tileHeight;
	lastGrid = tileAmountWidth * tileAmountHeight + firstgid - 1;
	scaleFactor = sf::Vector2f(TILE_SIZE * 1.0 / tileWidth, TILE_SIZE * 1.0 / tileWidth);
}
