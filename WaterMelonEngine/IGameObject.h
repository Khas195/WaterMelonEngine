#pragma once
#include <SFML\Graphics.hpp>
class Configuration;
// interface
class IGameObject
{
protected:
	bool awake;
	bool enabled;
	virtual void onAwake() = 0;
	virtual void onSleep() = 0;
	virtual void onEnable() = 0;
	virtual void onDisable() = 0;
public:
	IGameObject() = default;
	virtual ~IGameObject() = default;

	virtual void init() = 0;
	virtual void update() = 0;
	virtual void render(sf::RenderWindow& window) = 0;


	void setEnabled(bool enable);
	void setAwake(bool awake);
};

