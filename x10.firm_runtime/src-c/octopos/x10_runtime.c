#include "x10_runtime.h"

// x10.lang.Runtime.getHere() : Int
x10_int _ZN3x104lang7Runtime9getHereIdEv()
{
	unsigned tile_id = get_tile_id();

	if (tile_id > get_io_tile_id())
		tile_id--;

	return tile_id;
}
