#pragma once
#include"SFML\Graphics.hpp"

class  GameTime
{
protected:
	static sf::Clock game_time;
public:
	GameTime() = default;
};