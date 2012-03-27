package x10firm.goals;

import java.io.IOException;

import polyglot.frontend.AllBarrierGoal;
import polyglot.frontend.ExtensionInfo;
import polyglot.frontend.Goal;
import polyglot.frontend.Job;
import polyglot.frontend.Scheduler;
import x10firm.CompilerOptions;
import x10firm.visit.FirmGenerator;
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

	private Goal prereqRedirection = null;
	private FirmGenerator generator;

	/** Constructos a new LoweringFirm goal. */
	public LoweringFirm(final Scheduler scheduler, final FirmGenerator generator) {
		super("LoweringFirm", scheduler);
		this.generator = generator;
	}

	@Override
	public boolean runTask() {
		final ExtensionInfo info = scheduler.extensionInfo();
		final CompilerOptions options = (CompilerOptions)info.getOptions();

		generator.genPostCompile();
		generator.getFirmTypeSystem().finishTypeSystem();

		/* dump the firm typegraph */
		if (options.isDumpFirmGraphs()) {
			try {
				Dump.dumpTypeGraph("typegraph.vcg");
			} catch (IOException e) {
				e.printStackTrace();
			}
		}

		/* Dump the normal firm graph */
		if (options.isDumpFirmGraphs()) {
			for (Graph g : Program.getGraphs()) {
				Dump.dumpGraph(g, "--fresh");
			}
		}

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
	public void addPrereq(final Goal goal) {
		if (prereqRedirection == null) {
			super.addPrereq(goal);
		} else {
			prereqRedirection.addPrereq(goal);
		}
	}

	@Override
	public Goal prereqForJob(final Job job) {
		// TODO DELETE_ME: Delete the second condition when library support is implemented
		if (!scheduler.shouldCompile(job) && !x10firm.ExtensionInfo.isAllowedClassName(job.toString())) {
			return null;
		}

		return scheduler.End(job);
	}
}
