#pragma once
#include "Map.h"
#include "TextureManager.h"
#include <string>
class Helper
{
public:
	static std::vector<std::string> strsplit(const std::string &s, char delim);
	static Map * LoadMapFromSource(std::string source, std::string name);
	//static int nextDirection(Map & map, sf::Vector2i startPos, sf::Vector2i endPos);
};