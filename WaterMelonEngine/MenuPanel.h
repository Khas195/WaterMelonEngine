#pragma once
#include "GameObject.h"
#include "SFML\Graphics.hpp"
#include "Sprite.h"
#include "StatisticBox.h"
#include "Animation.h"
class MenuPanel : public GameObject
{
	sf::Clock clickDelay;
	sf::Font font;
	Sprite* background;
	Sprite* corner;
	Sprite* menuBox;
	sf::Vector2f pos;
	sf::Vector2f size;
	sf::RectangleShape avatarBox;
	sf::RectangleShape buttonBox;
	Animation avatar;
	StatisticBox* health;
	StatisticBox* score;
	StatisticBox* button;
	std::string HP;
	int scoreVal;
public:
	MenuPanel();
	~MenuPanel();

	// Inherited via GameObject
	virtual void update(sf::Event::EventType & type) override;
	virtual void render(sf::RenderWindow & window) override;
	virtual void receiveMessage(Package * package) override;
	virtual std::string getName() override;
};

