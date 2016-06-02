#pragma once
#include <SFML\Graphics.hpp>
#include "StateStack.h"
class IComponent;
class Scene;


class WaterMelonEngine
{
	static sf::RenderWindow window;
	const sf::Time timePerFrame;
	StateStack sceneStack;
protected:
	void update(sf::Event::EventType& type);
	void render();
public:
	WaterMelonEngine();
	~WaterMelonEngine();

	static const sf::RenderWindow& getWindow();

	void loop();
};

