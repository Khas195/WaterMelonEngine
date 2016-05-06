#pragma once
#include <SFML\Graphics.hpp>

class WaterMelonEngine
{
	sf::RenderWindow window;
	const sf::Time timePerFrame;
protected:
	void update();
	void render();
public:
	WaterMelonEngine();
	~WaterMelonEngine();

	void loop();
};

