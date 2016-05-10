#pragma once
#include "IScene.h"

class DefaultScene : public IScene
{
public:
	DefaultScene();
	~DefaultScene();

	// Inherited via IScene
	virtual void onAwake() override;
	virtual void onSleep() override;
	virtual void onEnable() override;
	virtual void onDisable() override;
	virtual void init() override;
	virtual void update() override;
	virtual void render(sf::RenderWindow & window) override;
};

