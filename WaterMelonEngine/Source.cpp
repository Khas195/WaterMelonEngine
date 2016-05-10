#include"WaterMelonEngine.h"
#include"CoreLibraries/PostOffice/PostOffice.h"
#include"CoreLibraries/PostOffice/testObserver.h"

void main()
{/*
	WaterMelonEngine engine;
	engine.loop();
	return;*/

	PostOffice officer;
	testObserver t1(&officer);
	testObserver t2(&officer);
	testObserver t3(&officer);
	testObserver t4(&officer);
	testObserver t5(&officer);

	return;
}