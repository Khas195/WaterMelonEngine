#pragma once
#include "UnitAction.h"
#include <string>
class DieAction : UnitAction
{
public:
	DieAction(std::string source);
	virtual UNIT_ACTION action(UNIT_ACTION action) override;
};

