package x10firm.goals;

import polyglot.frontend.AbstractGoal_c;
import firm.Backend;
import firm.OO;
import firm.Util;

/**
 * This defines the lowering pass.
 */
public class LoweringFirm extends AbstractGoal_c {
	@Override
	public boolean runTask() {
		OO.lowerProgram();
		Util.lowerSels();
		Backend.lowerForTarget();

		return true;
	}
}
