#pragma once
#include "GameObject.h"
#include "Animation.h"
#include "SFML\Graphics.hpp"
#include "TextureManager.h"
#include "TileMap.h"

class HeroObject : public GameObject, public TextureManager
{
	Animation heroAction;
public:
	HeroObject() = default;
	HeroObject(sf::Vector2f startPosition);
	~HeroObject();

	// Inherited via GameObject
	virtual void update(sf::Event::EventType& type) override;
	virtual void render(sf::RenderWindow & window) override;
	virtual void receiveMessage(Package * package) override;
	virtual std::string getName() override;
};

