#pragma once
#include "GameObject.h"
#include "SFML\Graphics.hpp"
#include "TileMap.h"
#include "HeroObject.h"
#include "TextureManager.h"
#include"Definition.h"

class DungeonMapObject : public GameObject, public TextureManager
{
	TileMap * map;
	HeroObject * hero;
public:
	DungeonMapObject();
	~DungeonMapObject();

	// Inherited via GameObject
	virtual void update(sf::Event::EventType& type) override;
	virtual void render(sf::RenderWindow & window) override;
	virtual void receiveMessage(Package * package) override;
	virtual std::string getName() override;
};
