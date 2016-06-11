#pragma once
#include <SFML\Graphics.hpp>
#include "Definition.h"
#include "Animation.h"
class UnitAction
{
protected:
	UNIT_ACTION currentAct;
	sf::Int32 millisecondPerFrame;
	Animation * act;
public:
	UnitAction();
	virtual ~UnitAction();
	virtual UNIT_ACTION action(UNIT_ACTION action) = 0;
};