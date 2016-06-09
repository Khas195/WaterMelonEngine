#pragma once
#include"GameObject.h"
#include"Sprite.h"
#include"Definition.h"
#include<vector>

	class Map;
	class TilesetTile;
	class MapTile
	{
		friend class Map;
		friend class Helper;
		// let's it public for now
		TILE_STATE state;

		sf::Uint32 mapGid;

		sf::Vector2f position;

		sf::FloatRect collBox;

		Map * map;

		std::vector<TilesetTile *> tilesetTile;

		// color
		sf::Color borderColor;
		sf::Color fillColor;
	public:

		// methods
		MapTile() = default;
		MapTile(Map * map, sf::Uint32 mapGid, sf::Vector2f position);

		void setFillColor(sf::Color color);
		void setBorderColor(sf::Color color);
		void setState(TILE_STATE state);

		// some constants
		const Map * getMap();
		const TILE_STATE & getState();
		const sf::Vector2f & getPosition();
		const sf::Uint32 & getPos();
		const sf::Color & getBorderColor();
		const sf::Color & getFillColor();
	};
