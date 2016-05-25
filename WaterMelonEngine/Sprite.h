#pragma once
#include"SFML\Graphics.hpp"
#include"Header.h"
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
	Sprite(sf::Texture & texture, sf::Vector2f frameSize, sf::Vector2f spriteDim);	
	
	void setFixedRow(int rowIndex);
	void setTimePerFrame(float seconds);
	void reset();
	void nextFrame();

	void update(sf::Clock& gameTime);
	void render(sf::RenderWindow& window);
	std::string getName();
};

