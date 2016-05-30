#pragma once
#include"GameObject.h"
#include"TextureManager.h"
#include"Sprite.h"
#include"Tile.h"
#include"Definition.h"

class TileMap : public GameObject, public TextureManager
{
	Sprite tile;
	Tile tiles[MAP_WIDTH][MAP_HEIGHT];
public:
	TileMap();

	// Inherited via GameObject
	virtual void update(sf::Clock & gameTime) override;
	virtual void render(sf::RenderWindow & window) override;
	virtual void receiveMessage(Package * package) override;
	virtual std::string getName() override;
};

