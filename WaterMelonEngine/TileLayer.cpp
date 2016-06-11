#include "TileLayer.h"
#include "Map.h"
#include "TilesetTile.h"
#include <algorithm>

	TilesetTile* TileLayer::operator[](int gid)
	{
		return data[gid];
	}
	TileLayer::~TileLayer()
	{
		FORIT(data, it)
		{
			delete (*it);
		}
	}
	TileLayer::TileLayer(std::string name, Map * map)
		: map(map), name(name)
	{
		sf::Vector2u size = map->getMapSize();
		data.resize(size.x * size.y);
	}

	const TilesetTile* TileLayer::getItem(int x, int y)
	{
		return data[x + (y * map->getMapSize().x)];
	}

	const std::string & TileLayer::getName()
	{
		return name;
	}

	const Map * TileLayer::getMap()
	{
		return map;
	}

