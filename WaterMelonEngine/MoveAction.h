#pragma once
#include "UnitAction.h"
#include <string>
class MoveAction : UnitAction
{
public:
	MoveAction(std::string source);
	virtual UNIT_ACTION action(UNIT_ACTION action) override;
};

