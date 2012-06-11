package x10firm.goals;

import polyglot.frontend.AllBarrierGoal;
import polyglot.frontend.ExtensionInfo;
import polyglot.frontend.Goal;
import polyglot.frontend.Job;
import polyglot.frontend.Scheduler;
import x10firm.CompilerOptions;
import firm.Backend;
import firm.Dump;
import firm.Graph;
import firm.OO;
import firm.Program;
import firm.Util;

/**
 * This defines the lowering pass.
 */
public class LoweringFirm extends AllBarrierGoal {

	/** Constructs a new LoweringFirm goal. */
	public LoweringFirm(final Scheduler scheduler) {
		super("LoweringFirm", scheduler);
	}

	@Override
	public boolean runTask() {
		final ExtensionInfo info = scheduler.extensionInfo();
		final CompilerOptions options = (CompilerOptions)info.getOptions();

		if (options.x10_config.ONLY_TYPE_CHECKING)
			return true;

		OO.lowerProgram();
		Util.lowerSels();
		Backend.lowerForTarget();

		/* Dump the normal firm graph */
		if (options.isDumpFirmGraphs()) {
			for (Graph g : Program.getGraphs()) {
				Dump.dumpGraph(g, "--lowered");
			}
		}

		return true;
	}

	@Override
	public Goal prereqForJob(final Job job) {
		if (!scheduler.shouldCompile(job))
			return null;

		return scheduler.End(job);
	}
}
