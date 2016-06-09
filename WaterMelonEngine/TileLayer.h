#pragma once
#include <SFML\Graphics.hpp>
#include <vector>

class Helper;

	class Map;
	class TilesetTile;
	class TileLayer
	{
		friend class Map;
		friend class Helper;
		// info
		std::string name;

		Map * map;

		std::vector<TilesetTile*> data;
		TilesetTile* operator[] (int gid);
	public:
		~TileLayer();
		//method
		TileLayer(std::string name, Map * map);
		const TilesetTile * getItem(int x, int y);
		const std::string & getName();
		const Map * getMap();
	};