#pragma once
#include <SFML\Graphics.hpp>
#include "StateStack.h"
class IComponent;
class Scene;

class WaterMelonEngine 
{
	sf::RenderWindow window;
	const sf::Time timePerFrame;
	StateStack sceneStack;
protected:
	void update(sf::Clock& gameTime);
	void render();
public:
	WaterMelonEngine();
	~WaterMelonEngine();

	void loop();
};

