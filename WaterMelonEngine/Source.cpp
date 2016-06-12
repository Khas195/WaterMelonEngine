#include "Definition.h"
#include "WaterMelonEngine.h"
#include <iostream>
#include<vector>
using namespace std;
void main()
{
#if _DEBUG
	WaterMelonEngine::isDebug = true;
#else
	WaterMelonEngine::isDebug = false;
#endif
	WaterMelonEngine engine;
	engine.loop();
	return;
}
