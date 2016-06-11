#include "MenuPanel.h"
#include "Definition.h"
#include "TextureManager.h"
#include "Package.h"
#include <iostream>
using namespace std;

MenuPanel::MenuPanel()
{
	scoreVal = 0;
	HP = "0000000000000";
	pos.x = PANEL_POS_X;
	pos.y = PANEL_POS_Y;
	size.x = PANEL_WIDTH;
	size.y = PANEL_HEIGHT;

	int menuBoxID = TextureManager::requestID("./sprites/menu_box.png");
	int lineID = TextureManager::requestID("./sprites/menuPanelLine.png");
	int menuBackground = TextureManager::requestID("./sprites/menuPanelBackground.png");
	int avatarID = TextureManager::requestID("./sprites/hero.png");


	background = new Sprite(TextureManager::requestTexture(menuBackground), sf::Vector2f(SCREEN_WIDTH, PANEL_HEIGHT));

	menuBox = new Sprite(TextureManager::requestTexture(menuBoxID), sf::Vector2f(186, 186));
	menuBox->setPosition(0, pos.y);
	menuBox->setScale(SCREEN_WIDTH / 186.0f, 1);
	//corner = new Sprite(TextureManager::requestTexture(menuBoxID), sf::Vector2f(76, 76));
	//corner->setScale(CORNER_SIZE / 76, CORNER_SIZE / 76);
	background->setPosition(0, pos.y);

	Sprite temp = Sprite(TextureManager::requestTexture(avatarID), sf::Vector2f(64, 64), sf::Vector2u(9, 21));
	temp.setFixedRow(10);
	temp.setTimePerFrame(0.1f);
	temp.setPosition(AVATAR_POS_X, AVATAR_POS_Y);
	temp.setScale(AVATAR_WIDTH / 64.0f, AVATAR_HEIGHT / 64.0f);
	avatar.set(0, temp);
	avatarBox.setSize(sf::Vector2f(AVATAR_WIDTH, AVATAR_HEIGHT));
	avatarBox.setPosition(AVATAR_POS_X, AVATAR_POS_Y);
	avatarBox.setOutlineThickness(3);
	avatarBox.setOutlineColor(sf::Color::White);
	avatarBox.setFillColor(sf::Color(0,0,0,127));

	health = new StatisticBox(sf::Vector2f(STATS_WIDTH, TEXT_SIZE), sf::Vector2f(AVATAR_POS_X, AVATAR_POS_Y + AVATAR_HEIGHT + 3));
	health->setString(&HP[0]);
	health->setColor(sf::Color::Red);

	score = new StatisticBox(sf::Vector2f(STATS_WIDTH, SCORE_TEXT_SIZE), sf::Vector2f(AVATAR_POS_X + AVATAR_WIDTH + 9, AVATAR_POS_Y + AVATAR_HEIGHT / 2.0f));
	score->setString("Score: 0");
	score->setColor(sf::Color::White);

	this->addGameObject(health);
	this->addGameObject(score);
}


MenuPanel::~MenuPanel()
{
	delete menuBox;
	//delete corner;
	delete background;
}

void MenuPanel::update(sf::Event::EventType & type)
{
}

void MenuPanel::render(sf::RenderWindow & window)
{
	background->render(window);

	//// tope left 
	//corner->setPosition(0, pos.y);
	//corner->setScale(1, 1);
	//corner->render(window);
	//// top right
	//corner->setPosition(SCREEN_WIDTH, pos.y);
	//corner->setScale(-1, 1);
	//corner->render(window);
	//// bottom left
	//corner->setPosition(0, SCREEN_HEIGHT);
	//corner->setScale(1, -1);
	//corner->render(window);
	//// bottom right 
	//corner->setPosition(SCREEN_WIDTH, SCREEN_HEIGHT);
	//corner->setScale(-1, -1);
	//corner->render(window);
	menuBox->render(window);
	window.draw(avatarBox);
	avatar.render(window);
	this->renderChildren(window);
}

void MenuPanel::receiveMessage(Package * package)
{
	if (package->get<bool>("score"))
	{
		++scoreVal;
		string temp = "Score: " + to_string(scoreVal);
		score->setString(&temp[0]);
	}
	if (package->get<bool>("HP"))
	{
		if (HP.size())
		{
			HP.pop_back();
			health->setString(&HP[0]);
		}
	}
}

std::string MenuPanel::getName()
{
	return "Menu Panel";
}
