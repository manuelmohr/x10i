package invasic.constraints;

import x10.lang.Pointer;
import x10.compiler.LinkSymbol;
import x10.compiler.StaticAllocate;

/** Specifies that this claim can share a tile with others.
	If the ONLY_WITHIN_APPLICATION variant is chosen, then
	only claims of the same application are allowed to share the tile.
	Note that both participants must allow sharing for it to happen.i

	ONLY_WITHIN_APPLICATION is redundant in the sense that
	it is the default behavior if TileSharing is not specified at all.
*/
public class TileSharing extends Hint {
	private val allow_other_applications:boolean;

	public static val WITH_OTHER_APPLICATIONS = @StaticAllocate new TileSharing(true);
	public static val ONLY_WITHIN_APPLICATION = @StaticAllocate new TileSharing(false);

	public def this() { this(true); }

	private def this(flag:boolean) { allow_other_applications = flag; }

	public def toAgentConstr(constr:Pointer):void {
		set_tile_shareable(constr,allow_other_applications);
	}

	@LinkSymbol("agent_constr_set_tile_shareable")
	static native def set_tile_shareable(constr:Pointer, shareable:boolean):void;
}

/* vim: set noexpandtab */
