#include "Map.h"
#include "Definition.h"
#include "Sprite.h"
#include "WaterMelonEngine.h"
#include "TileLayer.h"
#include "TilesetTile.h"
#include "TextureManager.h"
#include <assert.h>

Map::~Map()
{
	FORIT(layerList, layer)
	{
		delete (*layer);
	}
	FORIT(tilesetList, tileset)
	{
		delete (*tileset);
	}
	FORIT(layout, tile)
	{
		delete (*tile);
	}
}

Map::Map(std::string name, std::string source, sf::Uint32 mapWidth, sf::Uint32 mapHeight, sf::Uint32 tileWidth, sf::Uint32 tileHeight)
		: Map(name, source, sf::Vector2u(mapWidth, mapHeight), sf::Vector2u(tileWidth, tileHeight))
	{
		// TODO: nothing here thought
	}
	Map::Map(std::string name, std::string source, sf::Vector2u mapSize, sf::Vector2u tileSize)
		: name(name), source(source), mapSize(mapSize), tileSize(tileSize)
	{
		this->layout.resize(mapSize.x * mapSize.y);
		float offset = (SCREEN_WIDTH - (mapSize.x * TILE_SIZE)) / 2.0f;
		FORI(0, mapSize.y, h)
		{
			FORI(0, mapSize.x, w)
			{
				int pos = w + h * mapSize.x;
				this->layout[pos] = new MapTile(this, pos, sf::Vector2f(offset + w * TILE_SIZE, h * TILE_SIZE));
			}
		}
	}
	void Map::addLayer(TileLayer* layer)
	{
		this->layerList.push_back(layer);
	}
	void Map::addTileset(TileSet * tileset)
	{
		this->tilesetList.push_back(tileset);
	}
	const std::vector<MapTile*>& Map::allTiles()
	{
		return layout;
	}
	const std::vector<TileLayer*>& Map::getLayerList()
	{
		return layerList;
	}
	const std::vector<TileSet*>& Map::getTilesetList()
	{
		return tilesetList;
	}
	void Map::update(sf::Event::EventType & type)
	{
		// TODO: somethign here
	}
	void Map::render(sf::RenderWindow & window)
	{
		FORIT(layout, mtile)
		{
			FORIT((*mtile)->tilesetTile, tile)
			{
				if (!(*tile)->tileset)
					continue;
				tileSprites[(*tile)->tilesetGid].setPosition((*mtile)->position);
				window.draw(tileSprites[(*tile)->tilesetGid]);
			}
		}
	}
	void Map::receiveMessage(Package * package)
	{
	}
	std::string Map::getName()
	{
		return name;
	}
	const MapTile & Map::getTile(int x, int y)
	{
		assert(x >= 0 && x < mapSize.x);
		assert(y >= 0 && y < mapSize.y);
		return *layout[x + (y * mapSize.x)];
	}
	const sf::Vector2u & Map::getMapSize()
	{
		return mapSize;
	}
	const sf::Vector2u & Map::getTileSize()
	{
		return tileSize;
	}
	const std::string & Map::getSource()
	{
		return source;
	}
