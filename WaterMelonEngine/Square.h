#pragma once
#include "IComponent.h"
class Square : public IComponent
{
	sf::RectangleShape rectangle;
protected:
	virtual void onAwake() override;
	virtual void onSleep() override;
	virtual void onEnable() override;
	virtual void onDisable() override;
public:
	Square(sf::Color color, sf::Vector2f pos, sf::Vector2f size);
	~Square();

	// Inherited via IComponent
	virtual void init() override;
	virtual void update(sf::Clock & gameTime) override;
	virtual void render(sf::RenderWindow & window) override;
	virtual std::string getName() override;
};

