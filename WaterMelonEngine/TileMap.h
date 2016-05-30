#pragma once
#include"GameObject.h"
#include"TextureManager.h"
#include"Sprite.h"
#include"Tile.h"

class TileMap : public GameObject, public TextureManager
{
	Sprite tile;
	Tile tiles[12][7];
public:
	TileMap();

	// Inherited via GameObject
	virtual void update(sf::Clock & gameTime) override;
	virtual void render(sf::RenderWindow & window) override;
	virtual void receiveMessage(Package * package) override;
	virtual std::string getName() override;
};

