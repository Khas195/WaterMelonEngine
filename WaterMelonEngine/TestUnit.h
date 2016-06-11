#pragma once
#include <SFML\Graphics.hpp>
#include "GameObject.h"
#include "Animation.h"
class TestUnit : public GameObject
{
	sf::Sprite * test;
	sf::Transform transform;
public:
	TestUnit();
	~TestUnit();

	// Inherited via GameObject
	virtual void update(sf::Event::EventType& type) override;
	virtual void render(sf::RenderWindow & window) override;
	virtual void receiveMessage(Package * package) override;
	virtual std::string getName() override;
};

