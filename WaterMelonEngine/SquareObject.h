#pragma once
#include "GameObject.h"
#include"Animation.h"
#include "SFML\Graphics.hpp"
#include"TextureManager.h"
class SquareObject : public GameObject, public TextureManager
{
	Animation anim;
public:
	SquareObject() = default;
	SquareObject(sf::Vector2f pos, sf::Vector2f size, sf::Vector2f scale, float degree, sf::Color color);
	~SquareObject();

	// Inherited via GameObject
	virtual void update(sf::Clock & gameTime) override;
	virtual void render(sf::RenderWindow & window) override;
	virtual void receiveMessage(Package * package) override;
	virtual std::string getName() override;
};

