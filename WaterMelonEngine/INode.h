#pragma once
#include <SFML\Graphics.hpp>
#include <string>
// interface
class INode
{
protected:
	bool isAwaken;
	bool isEnable;
	virtual void onAwake() = 0;
	virtual void onSleep() = 0;
	virtual void onEnable() = 0;
	virtual void onDisable() = 0;
public:
	INode() = default;
	virtual ~INode() = default;

	virtual void init() = 0;
	virtual void update() = 0;
	virtual void render(sf::RenderWindow& window) = 0;
	virtual std::string getName() = 0;

	void enable();
	void disable();
	void awake();
	void sleep();
};

