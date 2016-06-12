#pragma once
#include "GameState.h"
class StartGame :
	public GameState
{
public:
	StartGame(GameDirector* director) : GameState(director) {};
	~StartGame();

	// Inherited via GameState
	virtual void update(sf::Event::EventType & type) override;
	virtual void render(sf::RenderWindow & window) override;

	// Inherited via GameState
	virtual void onPushed() override;
	virtual void onPoped() override;
	virtual void onReturnToTop() override;
	virtual void onPressed() override;
};

