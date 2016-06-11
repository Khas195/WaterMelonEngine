#include "Sprite.h"
#include<iostream>
#include<assert.h>

Sprite::Sprite()
{
	this->fixedRow = -1;
}

Sprite::Sprite(sf::Texture & texture, sf::Vector2f frameSize, sf::Vector2u spriteDim)
{
	this->fixedRow = -1;

	this->frameSize = frameSize;
	this->spriteDim = spriteDim;
	this->sprite = sf::Sprite(texture);

	if (frameSize.x != 0 || frameSize.y != 0)
	{
		rectSource = sf::IntRect(0, 0, frameSize.x, frameSize.y);
		this->sprite.setTextureRect(rectSource);
	}
	else
	{
		sf::IntRect temp = sprite.getTextureRect();
		this->frameSize.x = temp.width;
		this->frameSize.y = temp.height;
		rectSource = sf::IntRect(0, 0, temp.width, temp.height);
	}
}

void Sprite::setFixedRow(int rowIndex)
{
	this->fixedRow = rowIndex;
	if (rowIndex != -1)
	{
		currentFrame.y = rowIndex;
		rectSource.top = currentFrame.y * frameSize.y;
		sprite.setTextureRect(rectSource);
	}
}

void Sprite::setTimePerFrame(float seconds)
{
	framePerSecond = seconds * 1000;
}

void Sprite::reset()
{
	if (fixedRow == -1)
		currentFrame.y = 0;
}
void Sprite::nextFrame()
{
	if (clock.getElapsedTime().asMilliseconds() >= framePerSecond)
	{
		++currentFrame.x;
		if (currentFrame.x >= spriteDim.x)
			currentFrame.x = 0;

		rectSource.left = currentFrame.x * frameSize.x;
		sprite.setTextureRect(rectSource);
		clock.restart();
	}
}

void Sprite::setCurrentFrame(int x, int y)
{
	assert(x >= 0 && x <= spriteDim.x);
	assert(y >= 0 && y <= spriteDim.y);
	currentFrame.x = x;
	currentFrame.y = y;
	rectSource.left = currentFrame.x * frameSize.x;
	rectSource.top = currentFrame.y * frameSize.y;
	sprite.setTextureRect(rectSource);
}

void Sprite::move(float x, float y)
{
	sprite.move(x, y);
}

void Sprite::setPosition(float x, float y)
{
	sprite.setPosition(x, y);
}

void Sprite::setPosition(sf::Vector2f position)
{
	this->sprite.setPosition(position);
}

sf::Vector2f Sprite::getPosition()
{
	return sprite.getPosition();
}

const sf::Vector2u& Sprite::getGlobalSize()
{
	return sprite.getTexture()->getSize();
}

sf::Vector2f Sprite::getLocalSize()
{
	return frameSize;
}

void Sprite::setScale(float x, float y)
{
	sprite.setScale(x, y);
}

sf::Vector2f Sprite::getScale()
{
	return sprite.getScale();
}

void Sprite::update()
{
}

void Sprite::render(sf::RenderWindow & window)
{
	window.draw(sprite);
}

std::string Sprite::getName()
{
	return spriteName;
}
