#pragma once
#include<SFML\Graphics.hpp>
#include<string>
#include"Sprite.h"
#include"Definition.h"

// hold info of a tileset
	class Map;
	class TileSet
	{
		friend class Map;
		friend class Helper;
		// properities
		sf::Uint32 texId;

		sf::Uint32 firstgid;
		sf::Uint32 lastGrid;

		sf::Vector2u tileSize;
		sf::Vector2u tileAmount;
		sf::Vector2f scaleFactor;

		TILE_STATE state;

		Map * map;

		// hold source
		std::string source;
		std::string name;
	public:

		//methods
		TileSet() = default;
		TileSet(Map * map, sf::Uint32 firstgid, std::string name, sf::Uint32 tileWidth, sf::Uint32 tileHeight, TILE_STATE state, std::string source);

		sf::Vector2i gidToPos(int gid);
		const Map * getMap();
		const std::string & getSource();
		const std::string & getName();
		const TILE_STATE & getState();
		const sf::Uint32 getTexId();
		const sf::Uint32 getFirstGid();
		const sf::Uint32 getLastGid();
		const sf::Vector2u getTileSize();
		const sf::Vector2u getTileAmount();
		const sf::Vector2f getScaleFactor();
	};
