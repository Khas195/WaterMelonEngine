#pragma once


#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define MAP_WIDTH 22
#define MAP_HEIGHT 14
#define MAP_OFFSET (SCREEN_WIDTH - MAP_WIDTH * TILE_SIZE) / 2
#define TILE_SIZE 32
#define FORI(begin,end,i) for(int i = begin; i < end; ++i)
#define FORD(begin,end,i) for(int i = begin; i > end; --i)
#define FORIT(t,it) for(auto it = t.begin(); it != t.end(); ++it)
#define FOREACH(arr, item) for(auto item : arr)


enum TILE_STATE
{
	FREE = 0,
	MUD = -1,
	SAND = -2,
	OCCUPIED = -100,
	SPAWN = -101
};

 // Menu Panel
#define CORNER_SIZE (SCREEN_HEIGHT - MAP_HEIGHT * TILE_SIZE)/2

#define PANEL_POS_X CORNER_SIZE
#define PANEL_POS_Y SCREEN_HEIGHT - CORNER_SIZE * 2
#define PANEL_WIDTH SCREEN_WIDTH - CORNER_SIZE * 2
#define PANEL_HEIGHT SCREEN_HEIGHT - MAP_HEIGHT * TILE_SIZE

#define AVATAR_OFFSET_X 40
#define AVATAR_OFFSET_Y 30
#define AVATAR_POS_X PANEL_POS_X + AVATAR_OFFSET_X
#define AVATAR_POS_Y PANEL_POS_Y + AVATAR_OFFSET_Y
#define AVATAR_WIDTH (PANEL_WIDTH) / 7
#define AVATAR_HEIGHT  100

#define STATS_OFFSET_X 20
#define STATS_OFFSET_Y 30
#define STATS_WIDTH (PANEL_WIDTH) / 12
#define TEXT_SIZE 14
#define SCORE_TEXT_SIZE 20

#define ATTACK_OFFSET 32

#define MAX_LAYERS 2


#define MOVE_TIME 100
#define MOVE_TIME_DELAY 300
#define DIE_TIME 300

#define HERO_MOVE_SPD TILE_SIZE
#define HERO_ATTACK_SPD 100

#define MONSTER_MOVE_SPD_MAX 3
#define MONSTER_MOVE_SPD_MIN 1
#define MONSTER_ATTACK_SPD_MAX 100
#define MONSTER_ATTACK_SPD_MIN 50

#define KNOCKBACK_DISTANCE 2

#define MAX_ACTORS 30
#define MONSTER_SPAWN_TIME 1500