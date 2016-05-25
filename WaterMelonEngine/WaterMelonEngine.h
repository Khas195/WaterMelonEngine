#pragma once
#include <SFML\Graphics.hpp>
#include"Header.h"
class IComponent;
class WaterMelonEngine : public GameTime
{
	sf::RenderWindow window;
	const sf::Time timePerFrame;
	IComponent* testSquare;

protected:
	void update(sf::Clock & gameTime);
	void render();
public:
	WaterMelonEngine();
	~WaterMelonEngine();

	void loop();
};