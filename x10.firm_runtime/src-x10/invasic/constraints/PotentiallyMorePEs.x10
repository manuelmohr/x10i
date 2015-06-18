package invasic.constraints;

import x10.lang.Pointer;
import x10.compiler.LinkSymbol;

/** Specifies that the scheduler can provide more parallelism for executing activities
	than previously invaded into the corresponding claim.
 */
public class PotentiallyMorePEs extends Hint {
    public def toAgentConstr(constr:Pointer) {
        // FIXME support from irtss required
    }
}
