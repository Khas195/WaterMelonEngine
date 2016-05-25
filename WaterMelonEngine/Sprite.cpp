#include "Sprite.h"
#include<iostream>

Sprite::Sprite()
{
	this->fixedRow = -1;
}

Sprite::Sprite(sf::Texture & texture, sf::Vector2f frameSize, sf::Vector2f spriteDim)
{
	this->fixedRow = -1;

	this->frameSize = frameSize;
	this->spriteDim = spriteDim;
	this->sprite = sf::Sprite(texture);
	rectSource = sf::IntRect(0, 0, frameSize.x, frameSize.y);
	this->sprite.setTextureRect(rectSource);
}

void Sprite::setFixedRow(int rowIndex)
{
	this->fixedRow = rowIndex;
	if (rowIndex != -1)
		currentFrame.y = rowIndex;
}

void Sprite::setTimePerFrame(float seconds)
{
	framePerSecond = seconds * 1000;
}

void Sprite::reset()
{
	currentFrame.x = 0;
	if (fixedRow == -1)
		currentFrame.y = 0;
}

void Sprite::nextFrame()
{
	if (clock.getElapsedTime().asMilliseconds() >= framePerSecond)
	{
		++currentFrame.x;
		if (currentFrame.x >= spriteDim.x)
		{
			currentFrame.x = 0;
			if (fixedRow == -1)
			{
				++currentFrame.y;
				if (currentFrame.y >= spriteDim.y)
				{
					currentFrame.y = 0;
				}
			}
		}
		rectSource.left = currentFrame.x * frameSize.x;
		rectSource.top = currentFrame.y * frameSize.y;
		sprite.setTextureRect(rectSource);
		clock.restart();
	}
}

void Sprite::update(sf::Clock & gameTime)
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
