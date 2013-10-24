package invasic.constraints;

import x10.lang.Pointer;
import x10.compiler.LinkSymbol;

/** A constraint class to combine constraints,
  such that each constraint must be fulfilled. */
public class AND extends MultipleConstraints {
	public val constr:Pointer;

	public def this() {
		this.constr = create_constr();
	}

	@LinkSymbol("agent_constr_create")
	static native def create_constr():Pointer;

	/** add another constraint */
	public def add(c:Constraint):void {
		c.apply(this.constr);
	}

	def apply(constr2:Pointer) {
		overwrite(this.constr, constr2);
	}

	@LinkSymbol("agent_constr_overwrite")
	static native def overwrite(constrA:Pointer, constrB:Pointer):void;
}

/* vim: set noexpandtab */
