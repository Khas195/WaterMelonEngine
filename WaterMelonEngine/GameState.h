#pragma once
#include "SFML\Graphics.hpp"
#include "IState.h"
class GameDirector;
class GameState : public IState
{
protected:
	GameDirector* director;
	bool isShow = false;
public:
	GameState(GameDirector* director) : director(director) {};
	virtual ~GameState() = default;

	virtual void update(sf::Event::EventType & type) = 0;
	virtual void render(sf::RenderWindow & window) = 0;
};


