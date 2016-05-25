#include "Square.h"
#include <stdio.h>


Square::Square()
{
	TextureManager::init();
	int tex_id = TextureManager::requestID("S:/3rd Year/Semester 2/CS411/Lab/Final/WaterMelonEngine/WaterMelonEngine/sprites/dragonFrames.png");
	Sprite temp(TextureManager::requestTexture(tex_id), sf::Vector2f(192, 192), sf::Vector2f(3, 4));
	temp.setTimePerFrame(0.2f);

	for (int i = 0; i < 4; i++)
	{
		temp.setFixedRow(i);
		anim.set(i, temp);
	}
}
Square::~Square()
{
}

void Square::init()
{
	TextureManager::init();
}

void Square::update(sf::Clock& gameTime)
{
	if (!isEnable || !isAwake)
		return;
	anim.stop();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		anim.go();
		anim.trigger(0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		anim.go();
		anim.trigger(1);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		anim.go();
		anim.trigger(2);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		anim.go();
		anim.trigger(3);
	}

	this->anim.update(gameTime);
	this->updateChildren(gameTime);
}

void Square::render(sf::RenderWindow & window)
{
	if (!isEnable)
		return;

	anim.render(window);
	this->renderChildren(window);
}

std::string Square::getName()
{
	return "Square";
}

void Square::onAwake()
{
}

void Square::onSleep()
{
}

void Square::onEnable()
{
}

void Square::onDisable()
{
}


