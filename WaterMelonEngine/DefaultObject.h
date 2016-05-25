#pragma once
#include "GameObject.h"

class DefaultObject : public GameObject
{
	// Inherited via GameObject
	virtual void update(sf::Clock & gameTime) override;
	virtual void render(sf::RenderWindow & window) override;
	virtual void receiveMessage(Package * package) override;
	virtual std::string getName() override;
};