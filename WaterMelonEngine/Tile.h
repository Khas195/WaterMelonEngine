#pragma once
#include"GameObject.h"
#include"Sprite.h"


class Tile : public GameObject
{
	enum TILE_STATE
	{
		OCCUPIED = -100,
		MUD = -1,
		SAND = -2,
		FREE = 0,
		ACCELERATE = 1
	};
	TILE_STATE state = FREE;
	Sprite tileTexture;
	sf::RectangleShape rect;
public:
	Tile() = default;
	Tile(Sprite& tileTexture);

	// class function
	void setBorderColor(sf::Color color);
	void setFillColor(sf::Color color);
	void setPosition(sf::Vector2f position);
	sf::Vector2f getPosition();
	void setSize(sf::Vector2f size);

	// Inherited via GameObject
	virtual void update(sf::Clock & gameTime) override;
	virtual void render(sf::RenderWindow & window) override;
	virtual void receiveMessage(Package * package) override;
	virtual std::string getName() override;
};

