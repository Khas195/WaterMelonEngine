#pragma once
#include"SFML\Graphics.hpp"
#include<string>

class Sprite
{
private:
	//Transform *transform
	int fixedRow;

	std::string spriteName;

	sf::Sprite sprite;
	sf::Vector2f frameSize;
	sf::Vector2f currentFrame;
	sf::Vector2f spriteDim;

	sf::Clock clock;
	sf::Int64 framePerSecond;

	sf::IntRect rectSource;
public:
	Sprite();
	Sprite(sf::Texture & texture, sf::Vector2f frameSize = sf::Vector2f(0,0), sf::Vector2f spriteDim = sf::Vector2f(1, 1));
	
	void setFixedRow(int rowIndex);
	void setTimePerFrame(float seconds);
	void reset();
	void nextFrame();

	// transformation
	void move(float x, float y);

	void setPosition(float x, float y);
	void setPosition(sf::Vector2f position);
	sf::Vector2f getPosition();

	void setScale(float x, float y);
	sf::Vector2f getScale();

	void update(sf::Clock& gameTime);
	void render(sf::RenderWindow& window);
	std::string getName();
};

