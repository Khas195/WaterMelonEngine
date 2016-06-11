#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "UnitAction.h"
class ActionAdapter : public GameObject
{
	UnitAction * action;
public:
	ActionAdapter();
	~ActionAdapter();

	virtual void update(sf::Event::EventType& type) override;
	virtual void render(sf::RenderWindow & window) override;
	virtual void receiveMessage(Package * package) override;
	virtual std::string getName() override;
};

