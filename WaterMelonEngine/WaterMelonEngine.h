#pragma once
#include <SFML\Graphics.hpp>

class IGameObject;
class WaterMelonEngine
{
	sf::RenderWindow window;
	IGameObject* gameObject;
	const sf::Time timePerFrame;
protected:
	void update();
	void render();
public:
	WaterMelonEngine();
	~WaterMelonEngine();

	void loop();
};

