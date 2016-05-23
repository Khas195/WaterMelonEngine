#include "Sprite.h"

Sprite::Sprite()
{
	this->fixedRow = -1;
	this->timeFromLastFrame = 0;
	this->millisecondsPerFrame = DEFAULT_MILISENCONDS_PER_FRAME;
}

Sprite::Sprite(sf::Texture & texture, sf::Vector2f frameSize, sf::Vector2f spriteDim)
{
	this->fixedRow = -1;
	this->timeFromLastFrame = 0;
	this->millisecondsPerFrame = DEFAULT_MILISENCONDS_PER_FRAME;

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

void Sprite::reset()
{
	currentFrame.x = 0;
	if (fixedRow == -1)
		currentFrame.y = 0;
}

void Sprite::update(sf::Clock & gameTime)
{
	sf::Int32 offset = gameTime.getElapsedTime().asMilliseconds() - timeFromLastFrame;
	if (offset >= millisecondsPerFrame)
	{
		timeFromLastFrame = gameTime.getElapsedTime().asMilliseconds();

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
	}
}

void Sprite::render(sf::RenderWindow & window)
{
	window.draw(sprite);
}

std::string Sprite::getName()
{
	return spriteName;
}
