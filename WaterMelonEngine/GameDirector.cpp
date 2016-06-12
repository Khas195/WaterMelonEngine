#include "GameDirector.h"
#include "StartGame.h"


std::vector<sf::RectangleShape> GameDirector::getChosenMenu(MENU menu)
{
	std::vector<sf::RectangleShape> menuButtons;
	switch (menu)
	{
	case MENU::START:
		menuButtons.push_back(exit);
		menuButtons.push_back(start);
		break;
	case MENU::GAMEOVER:
		menuButtons.push_back(backToMain);
		menuButtons.push_back(retry);
		break;
	case MENU::PAUSE:
		menuButtons.push_back(exit);
		menuButtons.push_back(backToMain);
		menuButtons.push_back(resume);
		break;
	default:
		break;
	}
	return menuButtons;
}

GameDirector::GameDirector(Scene* scene) : currentScene(scene)
{
	start.setSize(sf::Vector2f(60.f, 60.f));
	start.setFillColor(sf::Color::Green);

	exit.setSize(sf::Vector2f(60.f, 60.f));
	exit.setFillColor(sf::Color::Red);
	
	retry.setSize(sf::Vector2f(60.f, 60.f));
	retry.setFillColor(sf::Color::Red);
	
	resume.setSize(sf::Vector2f(60.f, 60.f));
	resume.setFillColor(sf::Color::Cyan);

	backToMain.setSize(sf::Vector2f(60.f, 60.f));
	retry.setFillColor(sf::Color::Magenta);

	previousState = nullptr;
	curState = nullptr;
	startState = new StartGame(this);
	curState = startState;
	curState->onPushed();
}


GameDirector::~GameDirector()
{
	delete startState;
}

void GameDirector::renderChosenMenu(MENU menu, sf::RenderWindow& window)
{
	std::vector<sf::RectangleShape> buttons = getChosenMenu(menu);
	for each (sf::RectangleShape button in buttons)
	{
		window.draw(button);
	}
}

void GameDirector::setCurrentState(GameState * state)
{
	assert(state);
	this->curState = state;
}

void GameDirector::setPreviousState(GameState * state)
{
	assert(state);
	this->previousState = state;
}

GameState * const GameDirector::getState(MENU menu)
{
	switch (menu)
	{
	case GameDirector::PAUSE:
		return pauseState;
		break;
	case GameDirector::START:
		return startState;
		break;
	case GameDirector::GAMEOVER:
		return gameOverState;
		break;
	case GameDirector::INGAME:
		return inGameState;
		break;
	default:
		assert(false);
		break;
	}
}


void GameDirector::moveGameMenu(MENU menu, const sf::Vector2f& targetPos)
{
	std::vector<sf::RectangleShape> menuButtons = getChosenMenu(menu);
	for (int i = 0; i < menuButtons.size(); ++i)
	{
		if (targetPos.x < menuButtons[i].getPosition().x)
			menuButtons[i].move(-moveSpeed, 0);
		else if (targetPos.x > menuButtons[i].getPosition().x)
			menuButtons[i].move(moveSpeed, 0);

		if (targetPos.y < (menuButtons[i].getPosition().y + i * 60.f))
			menuButtons[i].move(0, -moveSpeed);
		else if (targetPos.y >(menuButtons[i].getPosition().y + i * 60.f))
			menuButtons[i].move(0, moveSpeed);
	}

}

bool GameDirector::isMenuAt(const sf::Vector2f & pos, MENU menu)
{
	std::vector<sf::RectangleShape> menuButtons = getChosenMenu(menu);
	for (int i = 0; i < menuButtons.size(); ++i)
	{
		if ((pos.x != menuButtons[i].getPosition().x) || pos.y != (menuButtons[i].getPosition().y + i * 60.f))
			return false;
	}
	return true;
}

void GameDirector::setMenuPosition(MENU menu, const sf::Vector2f& pos)
{
	std::vector<sf::RectangleShape> menuButtons = getChosenMenu(menu);
	for (int i = 0; i < menuButtons.size(); ++i)
	{
		menuButtons[i].setPosition(pos.x, pos.y + i * 60.f);
	}
}

void GameDirector::update(sf::Event::EventType & type)
{
	if (curState)
	   curState->update(type);
	if (!transitionDone)
		previousState->update(type);
}

void GameDirector::render(sf::RenderWindow & window)
{
	if (curState)
		curState->render(window);
	if (!transitionDone)
		previousState->render(window);
}

void GameDirector::receiveMessage(Package * package)
{
}

std::string GameDirector::getName()
{
	return std::string();
}
