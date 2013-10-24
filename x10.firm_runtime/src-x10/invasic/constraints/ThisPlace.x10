package invasic.constraints;

import x10.lang.Pointer;
import x10.compiler.LinkSymbol;

/** Requires processing elements to be on the current place

	<p>This guarantees that no <code>at</code> is necessary.</p>
 */
public class ThisPlace extends PredicateConstraint {
	public def apply(constr:Pointer) {
		set_tile(constr, here.id);
	}

	@LinkSymbol("agent_constr_set_tile")
	static native def set_tile(constr:Pointer, id:Int):void;
}

/* vim: set noexpandtab */
