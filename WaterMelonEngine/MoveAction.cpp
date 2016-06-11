#include "MoveAction.h"
#include "TextureManager.h"
#include "Sprite.h"
#include <assert.h>


MoveAction::MoveAction(std::string source)
{
	millisecondPerFrame = MOVE_TIME;
	currentAct = IDLE;
	int moveId = TextureManager::requestID(source);

	act = new Animation();

	Sprite sprite(TextureManager::requestTexture(moveId), sf::Vector2f(64, 64), sf::Vector2u(6, 1));
	sprite.setScale(TILE_SIZE * 1.0f / 64, TILE_SIZE * 1.0f / 64);
	sprite.setTimePerFrame(MOVE_TIME / 1000.0f);

	FORI(MOVE_UP, MOVE_RIGHT + 1, i)
	{
		sprite.setFixedRow(i - MOVE_UP);
		act->set(i, sprite);
	}
}

UNIT_ACTION MoveAction::action(UNIT_ACTION action)
{
	assert(action >= MOVE_UP && action <= MOVE_UP);
	act->trigger(action);
	return MOVE;
}
