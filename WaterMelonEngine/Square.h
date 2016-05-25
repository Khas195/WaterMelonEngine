#pragma once
#include "IComponent.h"
#include"Animation.h"
#include "TextureManager.h"

class Square : public IComponent, TextureManager
{
	Animation anim;
protected:
	virtual void onAwake() override;
	virtual void onSleep() override;
	virtual void onEnable() override;
	virtual void onDisable() override;
public:
	Square();
	~Square();

	// Inherited via IComponent
	virtual void init() override;
	virtual void update(sf::Clock & gameTime) override;
	virtual void render(sf::RenderWindow & window) override;
	virtual std::string getName() override;
};

