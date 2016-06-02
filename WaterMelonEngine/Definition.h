#pragma once

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define MAP_WIDTH 23
#define MAP_HEIGHT 15
#define TILE_SIZE 32
#define FORI(begin,end,i) for(int i = begin; i < end; ++i)
#define FORD(begin,end,i) for(int i = begin; i > end; --i)
#define FORIT(t,it) for(auto it = t.begin(); it != t.end(); ++it)


enum TILE_STATE
{
	OCCUPIED = -100,
	MUD = -1,
	SAND = -2,
	FREE = 0,
	SPAWN = -101
};