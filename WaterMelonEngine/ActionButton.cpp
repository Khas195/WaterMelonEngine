#include "ActionButton.h"
#include "WaterMelonEngine.h"

bool ActionButton::checkBetween(int begin, int end, int target) const
{
	if (begin <= target && target <= end)
		return true;
	return false;
}
ActionButton::ActionButton(Sprite buttonSprite, sf::Vector2f clickedFramePos, sf::Vector2f normalFramePos)
	: buttonSprite(buttonSprite), clickedFrame(clickedFramePos), normalFrame(normalFramePos), hoverFrame(&normalFrame)
{}
void ActionButton::setHoverFrame(sf::Vector2f * hoverFrame)
{
	this->hoverFrame = hoverFrame;
}
void ActionButton::update(sf::Event::EventType & type)
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(WaterMelonEngine::getWindow());
	int buttonX = buttonSprite.getPosition().x;
	int buttonY = buttonSprite.getPosition().y;

	if (checkBetween(buttonX, buttonX + buttonSprite.getLocalSize().x, mousePos.x)
		&& checkBetween(buttonY, buttonY + buttonSprite.getLocalSize().y, mousePos.y))
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			buttonSprite.setCurrentFrame(clickedFrame.x, clickedFrame.y);
		}
		buttonSprite.setCurrentFrame(hoverFrame->x, hoverFrame->y);
	}
	else buttonSprite.setCurrentFrame(normalFrame.x, normalFrame.y);
}
void ActionButton::render(sf::RenderWindow & window)
{
	buttonSprite.render(window);
}
void ActionButton::receiveMessage(Package * package)
{
}
std::string ActionButton::getName()
{
	return std::string();
}
