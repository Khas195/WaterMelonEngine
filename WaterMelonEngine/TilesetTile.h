#pragma once
#include <SFML\Graphics.hpp>

	class TileSet;
	class TilesetTile
	{
		friend class Map;
		friend class Helper;
		TileSet * tileset;

		sf::Int32 tilesetGid;
	public:

		//method
		TilesetTile(TileSet * tileset, sf::Int32 tilesetGid);
		const TileSet * getTileset();
		const sf::Int32 & getValue();
	};
