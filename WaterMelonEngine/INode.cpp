#include "INode.h"

void INode::enable()
{
	if (isEnable)
		return;
	this->onEnable();
	this->awake();
	this->isEnable = true;
}

void INode::disable()
{
	if (!isEnable)
		return;
	this->onDisable();
	this->sleep();
	this->isAwaken = false;
}

void INode::awake()
{
	if (isAwaken)
		return;
	this->onAwake();
	this->isAwaken = true;
}

void INode::sleep()
{
	if (!isAwaken)
		return;
	this->onSleep();
	this->isAwaken = false;
}
