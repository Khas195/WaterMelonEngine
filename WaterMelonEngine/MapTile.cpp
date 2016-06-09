#include "MapTile.h"
#include "Map.h"
#include "TilesetTile.h"

	MapTile::MapTile(Map * map, sf::Uint32 mapGid, sf::Vector2f position)
		: map(map), mapGid(mapGid), position(position), fillColor(sf::Color::Transparent), borderColor(sf::Color::Green), state(FREE),
		collBox(position, (sf::Vector2f)map->getTileSize())
	{
		tilesetTile.reserve(MAX_LAYERS);
	}
	void MapTile::setFillColor(sf::Color color)
	{
		fillColor = color;
	}
	void MapTile::setBorderColor(sf::Color color)
	{
		borderColor = color;
	}
	void MapTile::setState(TILE_STATE state)
	{
		this->state = state;
	}
	const Map * MapTile::getMap()
	{
		return map;
	}
	const TILE_STATE & MapTile::getState()
	{
		return state;
	}
	const sf::Vector2f & MapTile::getPosition()
	{
		return position;
	}
	const sf::Uint32 & MapTile::getPos()
	{
		return mapGid;
	}
	const sf::Color & MapTile::getBorderColor()
	{
		return borderColor;
	}
	const sf::Color & MapTile::getFillColor()
	{
		return fillColor;
	}