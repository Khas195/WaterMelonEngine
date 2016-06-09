#include "TilesetTile.h"
#include "TileSet.h"

	TilesetTile::TilesetTile(TileSet * tileset, sf::Int32 gid)
		: tileset(tileset), tilesetGid(gid)
	{
	}
	const TileSet * TilesetTile::getTileset()
	{
		return tileset;
	}
	const sf::Int32 & TilesetTile::getValue()
	{
		return tilesetGid;
	}
