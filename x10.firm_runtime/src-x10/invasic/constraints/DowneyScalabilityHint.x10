package invasic.constraints;

import x10.lang.Pointer;
import x10.compiler.LinkSymbol;

/** Specifies the scalability of the algorithm, which should be processed by the claims resources. */
public class DowneyScalabilityHint extends Hint {
	private val A:Int;
	private val sigma:Int;

	public def this(A:int, sigma:int) {
		this.A = A;
		this.sigma = sigma;
	}

	public def toAgentConstr(constr:Pointer) {
		set_curve(constr, A, sigma);
	}

	@LinkSymbol("agent_constr_set_downey_speedup_curve")
		static native def set_curve(constr:Pointer, A:Int, sigma:Int):void;
}
