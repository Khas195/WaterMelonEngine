#pragma once
#include "UnitAction.h"
#include <string>
class AttackAction : UnitAction
{
public:
	AttackAction(std::string source, sf::Int32 millisecondPerFrame);
	virtual UNIT_ACTION action(UNIT_ACTION action) override;
};

