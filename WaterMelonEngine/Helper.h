#pragma once
#include "TileMap.h"
#include"TextureManager.h"
#include <string>
class Helper
{
public:
	static std::vector<std::string> strsplit(const std::string &s, char delim);
	static TileMap * LoadMapFromSource(std::string source, std::string name);
	static std::vector<sf::Uint32> getRoad(TileMap & map, sf::Uint32 moveWidth, sf::Uint32 start, sf::Uint32 end);
};