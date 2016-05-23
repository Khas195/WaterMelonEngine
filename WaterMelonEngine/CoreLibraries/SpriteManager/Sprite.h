#pragma once
#include"SFML\Graphics.hpp"
#include<string>
#define DEFAULT_MILISENCONDS_PER_FRAME 16

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
	sf::Int32 timeFromLastFrame;
	sf::Int32 millisecondsPerFrame;

	sf::IntRect rectSource;
public:
	Sprite();
	Sprite(sf::Texture & texture, sf::Vector2f frameSize, sf::Vector2f spriteDim);
	
	void setFixedRow(int rowIndex);
	void reset();

	void update(sf::Clock& gameTime);
	void render(sf::RenderWindow& window);
	std::string getName();
};

