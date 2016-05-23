#pragma once
#include <SFML\Graphics.hpp>
class IComponent;
class WaterMelonEngine 
{
	sf::RenderWindow window;
	const sf::Time timePerFrame;
	IComponent* testSquare;

protected:
	void update();
	void render();
public:
	WaterMelonEngine();
	~WaterMelonEngine();

	void loop();
};

