#pragma once
#include"GameObject.h"
#include"Sprite.h"
#include"Definition.h"
#include<vector>

class TileMap;
class Tile
{
	friend class  TileMap;
	TILE_STATE state;
	sf::Uint32 firstgid;
	sf::Vector2f position;
	sf::Rect<float> box;
	sf::Color borderColor;
	sf::Color fillColor;
	std::vector<Tile*> neighbour;
public:
	Tile() : firstgid(-1) ,position(sf::Vector2f(0, 0)), box(sf::Rect<float>(0,0,0,0)), state(FREE), borderColor(sf::Color::Green), fillColor(sf::Color::Transparent){};
	void setState(TILE_STATE state) { this->state = state; }
	void setColor(sf::Color color) { this->fillColor = color; }
	sf::Vector2f getPosition() { return position; }
	const TILE_STATE getState() { return state; }
};

