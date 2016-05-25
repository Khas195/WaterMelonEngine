#include "GameScene.h"

#include "SquareObject.h"
#include "CoreLibraries\PostOffice\PostOffice.h"
GameScene::GameScene()
{
	this->godObject->enable();
	this->office = new PostOffice();
	SquareObject* square = new SquareObject(sf::Vector2f(50, 50), sf::Vector2f(50, 50), sf::Vector2f(1, 1), 0, sf::Color::Red);
	this->addGameObject(square);
	this->office->add(square);
}


GameScene::~GameScene()
{
}

void GameScene::onPushed()
{
}

void GameScene::onPoped()
{
}

void GameScene::onReturnToTop()
{
}

void GameScene::onPressed()
{
}
