#pragma once
#include"GameObject.h"
#include"Sprite.h"
#include"MapTile.h"
#include"TileSet.h"
#include"TileLayer.h"
#include<string>
#include<unordered_map>
#include<vector>

class Helper;
	class Map : public GameObject
	{
		friend class Helper;

		// hold sprite that is used in the map
		std::unordered_map<int, sf::Sprite> tileSprites;

		// tilese tlist and layer list
		std::vector<TileSet*> tilesetList;
		std::vector<TileLayer*> layerList;

		// layout of the map
		std::vector<MapTile*> layout;

		// map properities
		sf::Vector2u mapSize;
		sf::Vector2u tileSize;

		// source and name
		std::string source;
		std::string name;
	public:
		Map() = default;
		~Map();

		Map(std::string name, std::string source, sf::Uint32 mapWidth, sf::Uint32 mapHeight, sf::Uint32 tileWidth, sf::Uint32 tileHeight);
		Map(std::string name, std::string source, sf::Vector2u mapSize, sf::Vector2u tileSize);

		void addLayer(TileLayer * layer);
		void addTileset(TileSet * tileset);
		const std::vector<MapTile*> & allTiles();
		const std::vector<TileLayer*> & getLayerList();
		const std::vector<TileSet*> & getTilesetList();

		// Inherited via GameObject
		virtual void update(sf::Event::EventType& type) override;
		virtual void render(sf::RenderWindow & window) override;
		virtual void receiveMessage(Package * package) override;
		virtual std::string getName() override;

		// get properities
		const MapTile & getTile(int x, int y);
		const sf::Vector2u & getMapSize();
		const sf::Vector2u & getTileSize();
		const std::string & getSource();
	};

