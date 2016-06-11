#include "TileSet.h"
#include "TextureManager.h"
#include "Map.h"

	TileSet::TileSet(Map * map, sf::Uint32 firstgid, std::string name, sf::Uint32 tileWidth, sf::Uint32 tileHeight, TILE_STATE state, std::string source)
		: map(map), firstgid(firstgid), name(name), tileSize(tileWidth,tileHeight), state(state), source(source)
	{
		state = FREE;
		texId = TextureManager::requestID(source);
		sf::Vector2u size = TextureManager::requestTexture(texId).getSize();
		tileAmount.x = size.x / tileWidth;
		tileAmount.y = size.y / tileHeight;
		lastGrid = tileAmount.x * tileAmount.y + firstgid - 1;
		scaleFactor = sf::Vector2f(TILE_SIZE * 1.0 / tileWidth, TILE_SIZE * 1.0 / tileWidth);
	}
	sf::Vector2i TileSet::gidToPos(int gid)
	{
		gid -= firstgid;
		if (gid < 0 || gid > lastGrid)
			return sf::Vector2i();

		int y = gid / tileAmount.x;
		int x = gid % tileAmount.x;
		return sf::Vector2i(x * tileSize.x, y * tileSize.y);
	}
	const Map * TileSet::getMap()
	{
		return map;
	}
	const std::string & TileSet::getSource()
	{
		return source;
	}
	const std::string & TileSet::getName()
	{
		return name;
	}
	const TILE_STATE & TileSet::getState()
	{
		return state;
	}
	const sf::Uint32 TileSet::getTexId()
	{
		return texId;
	}
	const sf::Uint32 TileSet::getFirstGid()
	{
		return firstgid;
	}
	const sf::Uint32 TileSet::getLastGid()
	{
		return lastGrid;
	}
	const sf::Vector2u TileSet::getTileSize()
	{
		return tileSize;
	}
	const sf::Vector2u TileSet::getTileAmount()
	{
		return tileAmount;
	}
	const sf::Vector2f TileSet::getScaleFactor()
	{
		return scaleFactor;
	}