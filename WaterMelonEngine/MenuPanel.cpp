#include "MenuPanel.h"
#include "Definition.h"
#include "TextureManager.h"
#include "Package.h"
#include "PostOffice.h"
#include "WaterMelonEngine.h"
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
	//int lineID = TextureManager::requestID("./sprites/menuPanelLine.png");
	//int menuBackground = TextureManager::requestID("./sprites/menuPanelBackground.png");
	int avatarID = TextureManager::requestID("./sprites/hero_move.png");


	//background = new Sprite(TextureManager::requestTexture(menuBackground), sf::Vector2f(SCREEN_WIDTH, PANEL_HEIGHT));

	menuBox = new Sprite(TextureManager::requestTexture(menuBoxID), sf::Vector2f(228, 228));
	menuBox->setPosition(0, pos.y);
	menuBox->setScale(SCREEN_WIDTH / 228.0f, 1);
	//corner = new Sprite(TextureManager::requestTexture(menuBoxID), sf::Vector2f(76, 76));
	//corner->setScale(CORNER_SIZE / 76, CORNER_SIZE / 76);
	//background->setPosition(0, pos.y);

	Sprite temp = Sprite(TextureManager::requestTexture(avatarID), sf::Vector2f(64, 64), sf::Vector2u(9, 4));
	temp.setFixedRow(2);
	temp.setTimePerFrame(0.1f);
	temp.setPosition(AVATAR_POS_X, AVATAR_POS_Y);
	temp.setScale(AVATAR_WIDTH / 64.0f, AVATAR_HEIGHT / 64.0f);
	avatar.set(0, temp);

	avatarBox.setSize(sf::Vector2f(AVATAR_WIDTH, AVATAR_HEIGHT));
	avatarBox.setPosition(AVATAR_POS_X, AVATAR_POS_Y);
	avatarBox.setOutlineThickness(3);
	avatarBox.setOutlineColor(sf::Color::White);
	avatarBox.setFillColor(sf::Color(0,0,0,127));

	buttonBox.setSize(sf::Vector2f(STATS_WIDTH * 2.0f, AVATAR_HEIGHT / 2.0f));
	buttonBox.setPosition(AVATAR_POS_X + AVATAR_WIDTH * 3 - STATS_WIDTH / 2.0f, AVATAR_POS_Y + AVATAR_HEIGHT / 2.0f - SCORE_TEXT_SIZE / 2.0f);
	buttonBox.setFillColor(sf::Color(69, 40, 161, 127));


	health = new StatisticBox(sf::Vector2f(STATS_WIDTH, TEXT_SIZE), sf::Vector2f(AVATAR_POS_X, AVATAR_POS_Y + AVATAR_HEIGHT + 3));
	health->setString(&HP[0]);
	health->setColor(sf::Color::Red);

	score = new StatisticBox(sf::Vector2f(STATS_WIDTH, SCORE_TEXT_SIZE), sf::Vector2f(AVATAR_POS_X + AVATAR_WIDTH + 9, AVATAR_POS_Y + AVATAR_HEIGHT / 2.0f));
	score->setString("Score: 0");
	score->setColor(sf::Color::White);

	button = new StatisticBox(sf::Vector2f(STATS_WIDTH, SCORE_TEXT_SIZE), sf::Vector2f(AVATAR_POS_X + AVATAR_WIDTH * 3, AVATAR_POS_Y + AVATAR_HEIGHT / 2.0f));
	button->setString("Start");
	button->setColor(sf::Color::White);

	this->addGameObject(health);
	this->addGameObject(score);
	this->addGameObject(button);
}


MenuPanel::~MenuPanel()
{
	delete menuBox;
	//delete button;
	//delete background;
}

void MenuPanel::update(sf::Event::EventType & type)
{
	if (type == sf::Event::EventType::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		sf::FloatRect b = buttonBox.getGlobalBounds();
		sf::Vector2i m = sf::Mouse::getPosition(WaterMelonEngine::getWindow());
		if (b.contains((sf::Vector2f)m))
		{
			button->setString("Restart");
			PackageManager * pm = PackageManager::getInstance();
			Package * p = pm->requestPackage();
			bool temp = true;
			p->put<bool>("restart", &temp);
			office->notifyAllObserver(p);
			pm->returnPackage(p);
		}
	}
}

void MenuPanel::render(sf::RenderWindow & window)
{
	//background->render(window);

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
	window.draw(buttonBox);
	this->renderChildren(window);
	avatar.render(window);
}

void MenuPanel::receiveMessage(Package * package)
{
	if (package && package->get<bool>("menu"))
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
	else if (package->get<bool>("restart"))
	{
		scoreVal = 0;
		HP = "00000000000000";
		score->setString("Score: 0");
		health->setString(&HP[0]);
	}
}

std::string MenuPanel::getName()
{
	return "Menu Panel";
}
