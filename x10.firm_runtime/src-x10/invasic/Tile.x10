package invasic;

import x10.compiler.LinkSymbol;

public class Tile {
	/** Returns total number of tiles in the system.

	This number includes all compute tiles, which can be invaded.
	Not included are I/O and TCPA tiles.
	*/
	@LinkSymbol("get_compute_tile_count")
	native public static def getComputeTileCount():uint;

	/** Returns total number of tiles in the system.

	This number includes all compute tiles, which can be invaded, plus the I/O
	and TCPA tiles, which cannot be invaded via regular means.
	*/
	@LinkSymbol("get_tile_count")
	native public static def getTileCount():uint;

	/** Returns total number of cores in the current tile. */
	@LinkSymbol("get_tile_core_count")
	native public static def getTileCoreCount():uint;
}
