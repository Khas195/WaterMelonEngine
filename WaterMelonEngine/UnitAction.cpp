#include "UnitAction.h"

UnitAction::UnitAction()
{
	millisecondPerFrame = 0;
	act = nullptr;
}

UnitAction::~UnitAction()
{
	delete act;
}
