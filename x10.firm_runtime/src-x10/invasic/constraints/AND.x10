package invasic.constraints;

import x10.lang.Pointer;
import x10.compiler.LinkSymbol;
import x10.util.ArrayList;

/** A constraint class to combine constraints,
  such that each constraint must be fulfilled. */
public class AND extends MultipleConstraints {
    public val cs = new ArrayList[Constraint]();

    public def this() { }

    /** add another constraint */
    public def add(c:Constraint):void {
        cs.add(c);
    }

    public def toAgentConstr(constr:Pointer) {
      for (c in cs) {
        c.toAgentConstr(constr);
      }
    }
}
