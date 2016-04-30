#include "IGameObject.h"


void IGameObject::setEnabled(bool enable)
{
	if (this->enabled != enable)
		if (enable)
			this->onAwake();
		else 
			this->onDisable();

	this->enabled = enable;
}

void IGameObject::setAwake(bool awake)
{
	if (this->awake != awake)
		if (awake)
			this->onAwake();
		else
			this->onSleep();

	this->awake = awake;
}
