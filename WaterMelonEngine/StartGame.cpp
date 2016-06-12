#include "StartGame.h"
#include "GameDirector.h"
#include "Definition.h"



StartGame::~StartGame()
{
}

void StartGame::update(sf::Event::EventType & type)
{
	if (isShow)
	{
		if (!director->isMenuAt(sf::Vector2f(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2), GameDirector::START));
		{
			director->moveGameMenu(GameDirector::START, sf::Vector2f(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2));
			director->setTransitionDone(false);
			return;
		}
		director->setTransitionDone(true);
	}
	else
	{
		if (!director->isMenuAt(sf::Vector2f(0 - 60.f, SCREEN_HEIGHT / 2), GameDirector::START));
		{
			director->moveGameMenu(GameDirector::START, sf::Vector2f(0 - 60.f, SCREEN_HEIGHT / 2));
			director->setTransitionDone(false);
			return;
		}
		director->setTransitionDone(true);
	}
}

void StartGame::render(sf::RenderWindow & window)
{
	director->renderChosenMenu(GameDirector::START, window);
}

void StartGame::onPushed()
{
	isShow = true;
	director->setMenuPosition(GameDirector::MENU::START, sf::Vector2f(SCREEN_WIDTH + 60.0f, SCREEN_HEIGHT / 2));
	director->setPreviousState(director->getCurrentState());
	director->setCurrentState(this);
	director->setTransitionDone(false);
}

void StartGame::onPoped()
{
	isShow = false;
	director->setTransitionDone(false);

}

void StartGame::onReturnToTop()
{
	isShow = true;
	director->setMenuPosition(GameDirector::MENU::START, sf::Vector2f(SCREEN_WIDTH + 60.0f, SCREEN_HEIGHT / 2));
	director->setPreviousState(director->getCurrentState());
	director->setCurrentState(this);
	director->setTransitionDone(false);
}

void StartGame::onPressed()
{
	isShow = false;
	director->setTransitionDone(false);
}
