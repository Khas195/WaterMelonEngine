#include "MenuPanel.h"
#include "Definition.h"
#include <iostream>
using namespace std;

MenuPanel::MenuPanel()
{
	pos.x = PANEL_POS_X;
	pos.y = PANEL_POS_Y;
	size.x = PANEL_WIDTH;
	size.y = PANEL_HEIGHT;

	int cornerID = TextureManager::requestID("./sprites/menuPanelConors.png");
	int lineID = TextureManager::requestID("./sprites/menuPanelLine.png");
	int menuBackground = TextureManager::requestID("./sprites/menuPanelBackground.png");

	background = new Sprite(TextureManager::requestTexture(menuBackground), sf::Vector2f(SCREEN_WIDTH, PANEL_HEIGHT));
	corner = new Sprite(TextureManager::requestTexture(cornerID), sf::Vector2f(76, 76));
	corner->setScale(CORNER_SIZE / 76, CORNER_SIZE / 76);
	background->setPosition(0, pos.y);

	avatar.setPosition(AVATAR_POS_X, AVATAR_POS_Y);
	avatar.setSize(sf::Vector2f(AVATAR_WIDTH, AVATAR_HEIGHT));
	avatar.setFillColor(sf::Color::White);

	health = new StatisticBox(sf::Vector2f(STATS_WIDTH, TEXT_SIZE), sf::Vector2f(AVATAR_POS_X + 9, AVATAR_POS_Y + AVATAR_HEIGHT));
	health->setString("00000/00000");
	health->setColor(sf::Color::Red);
	mana = new StatisticBox(sf::Vector2f(STATS_WIDTH, TEXT_SIZE), sf::Vector2f(AVATAR_POS_X + 9, health->getPosition().y + TEXT_SIZE));
	mana->setString("00000/00000");
	mana->setColor(sf::Color::Blue);
	
	attackDamage = new StatisticBox(sf::Vector2f(STATS_WIDTH, TEXT_SIZE)
		, sf::Vector2f(AVATAR_POS_X + AVATAR_WIDTH + STATS_OFFSET_X, AVATAR_POS_Y));
	attackDamage->setString("Attack: 00000");
	attackDamage->setColor(sf::Color::Black);

	spellDamage = new StatisticBox(sf::Vector2f(STATS_WIDTH, TEXT_SIZE)
		, sf::Vector2f(attackDamage->getPosition().x, AVATAR_POS_Y + TEXT_SIZE * 3));
	spellDamage->setString("Spell: 00000");
	spellDamage->setColor(sf::Color::Black);

	armor = new StatisticBox(sf::Vector2f(STATS_WIDTH, TEXT_SIZE)
		, sf::Vector2f(attackDamage->getPosition().x + attackDamage->getSize().x + STATS_OFFSET_X * 2, AVATAR_POS_Y));
	armor->setString("Armor: 00000");
	armor->setColor(sf::Color::Black);

	spellResist = new StatisticBox(sf::Vector2f(STATS_WIDTH, TEXT_SIZE)
		, sf::Vector2f(attackDamage->getPosition().x + attackDamage->getSize().x + STATS_OFFSET_X * 2, AVATAR_POS_Y + TEXT_SIZE * 3));
	spellResist->setString("Shield: 00000");
	spellResist->setColor(sf::Color::Black);

	this->addGameObject(spellResist);
	this->addGameObject(armor);
	this->addGameObject(spellDamage);
	this->addGameObject(attackDamage);
	this->addGameObject(health);
	this->addGameObject(mana);
}


MenuPanel::~MenuPanel()
{
	delete corner;
	delete background;
}

void MenuPanel::update(sf::Event::EventType & type)
{
}

void MenuPanel::render(sf::RenderWindow & window)
{
	background->render(window);

	// tope left 
	corner->setPosition(0, pos.y);
	corner->setScale(1, 1);
	corner->render(window);
	// top right
	corner->setPosition(SCREEN_WIDTH, pos.y);
	corner->setScale(-1, 1);
	corner->render(window);
	// bottom left
	corner->setPosition(0, SCREEN_HEIGHT);
	corner->setScale(1, -1);
	corner->render(window);
	// bottom right 
	corner->setPosition(SCREEN_WIDTH, SCREEN_HEIGHT);
	corner->setScale(-1, -1);
	corner->render(window);
	window.draw(avatar);
	this->renderChildren(window);
}

void MenuPanel::receiveMessage(Package * package)
{
}

std::string MenuPanel::getName()
{
	return "Menu Panel";
}
