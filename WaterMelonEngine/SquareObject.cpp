#include "SquareObject.h"

SquareObject::SquareObject(sf::Vector2f pos, sf::Vector2f size, sf::Vector2f scale, float degree, sf::Color color)
{
	TextureManager::init();
	int tex_id = TextureManager::requestID("./sprites/dragonFrames.png");
	this->tile = new Sprite(TextureManager::requestTexture(tex_id));
	this->tile->setPosition(16, 0);
}

SquareObject::~SquareObject()
{
}

void SquareObject::update(sf::Clock & gameTime)
{
	/*anim.stop();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		anim.trigger(0);
		anim.moveBy(0, 1);
		anim.go();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		anim.trigger(1);
		anim.moveBy(-1, 0);
		anim.go();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		anim.trigger(2);
		anim.moveBy(1, 0);
		anim.go();
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
	}*/
}

void SquareObject::render(sf::RenderWindow & window)
{
	//window.draw(gameView);
	//window.draw(menuView);
	tile->render(window);
	map.render(window);
}

void SquareObject::receiveMessage(Package * package)
{
}

std::string SquareObject::getName()
{
	return "SquareObject";
}
