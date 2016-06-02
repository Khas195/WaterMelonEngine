#pragma once
#include<SFML\Graphics.hpp>
#include<string>
#include<unordered_map>
#include"TextureManager.h"
#include"Sprite.h"
#include"Definition.h"

// hold info of a tileset
class TileSet : public TextureManager
{
public:
	std::string name;
	sf::Uint32 texId;
	sf::Uint32 firstgid;
	sf::Uint32 lastGrid;
	sf::Uint32 tileWidth;
	sf::Uint32 tileHeight;
	sf::Uint32 tileAmountWidth;
	sf::Uint32 tileAmountHeight;
	sf::Vector2f scaleFactor;
	TILE_STATE state;
	// hold source
	std::string source;

	TileSet(sf::Uint32 firstgid, std::string name, sf::Uint32 tileWidth, sf::Uint32 tileHeight, TILE_STATE state, std::string source);
};

