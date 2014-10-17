package invasic.constraints;

import x10.lang.Pointer;
import x10.compiler.LinkSymbol;

/** Specifies the minimum and maximum number of processing elements. */
public class PEQuantity extends Constraint {
    private val min:Int;
    private val max:Int;
    public def this(min:Int, max:Int) {
        this.min = min;
        this.max = max;
    }

    /** minimum == maximum */
    public def this(count:Int) {
        this(count, count);
    }

    @LinkSymbol("agent_constr_set_quantity")
    static native def set_quantity(constr:Pointer, min:Int, max:Int, typ:Int):void;

    public def toAgentConstr(constr:Pointer) {
      set_quantity(constr, min, max, 0);
    }
}
