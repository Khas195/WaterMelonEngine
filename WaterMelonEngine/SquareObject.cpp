#include "SquareObject.h"

SquareObject::SquareObject(sf::Vector2f pos, sf::Vector2f size, sf::Vector2f scale, float degree, sf::Color color)
{
	TextureManager::init();
	int tex_if = TextureManager::requestID("./sprites/dragonFrames.png");
	Sprite temp(TextureManager::requestTexture(tex_if), sf::Vector2f(192, 192), sf::Vector2f(3,4));
	temp.setTimePerFrame(0.1f);

	for (int i = 0; i < 4;i++)
	{
		temp.setFixedRow(i);
		anim.set(i, temp);
	}
}

SquareObject::~SquareObject()
{
}

void SquareObject::update(sf::Clock & gameTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		anim.trigger(0);
		anim.move(0, 1);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		anim.trigger(1);
		anim.move(-1, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		anim.trigger(2);
		anim.move(1, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		anim.trigger(3);
		anim.move(0, -1);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
	{
		// special effect
		anim.setScale(2,2);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
	{
		// special effect
		anim.setScale(1, 1);
	}
}

void SquareObject::render(sf::RenderWindow & window)
{
	anim.render(window);
}

void SquareObject::receiveMessage(Package * package)
{
}

std::string SquareObject::getName()
{
	return "SquareObject";
}
