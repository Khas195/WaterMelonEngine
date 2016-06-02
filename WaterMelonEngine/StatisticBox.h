#pragma once
#include "GameObject.h"
#include "SFML\Graphics.hpp"
class StatisticBox : public GameObject
{
	sf::Font font;
	sf::Vector2f size;
	sf::Text text;
public:
	StatisticBox( sf::Vector2f size,  sf::Vector2f position);
	~StatisticBox();
	void setString(char* text);
	void setColor(sf::Color color);
	const sf::Vector2f& getPosition();
	const sf::Vector2f& getSize();

	// Inherited via GameObject
	virtual void update(sf::Event::EventType & type) override;
	virtual void render(sf::RenderWindow & window) override;
	virtual void receiveMessage(Package * package) override;
	virtual std::string getName() override;
};

