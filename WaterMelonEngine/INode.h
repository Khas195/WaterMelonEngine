#pragma once
#include <SFML\Graphics.hpp>
#include <string>
// interface
class INode
{
public:
	INode() = default;
	virtual ~INode() = default;

	virtual void update() = 0;
	virtual void render(sf::RenderWindow& window) = 0;
	virtual std::string getName() = 0;
};

