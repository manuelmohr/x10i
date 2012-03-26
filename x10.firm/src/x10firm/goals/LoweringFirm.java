package x10firm.goals;

import java.io.IOException;

import polyglot.frontend.AllBarrierGoal;
import polyglot.frontend.ExtensionInfo;
import polyglot.frontend.Goal;
import polyglot.frontend.Job;
import polyglot.frontend.Scheduler;
import x10.ast.X10NodeFactory_c;
import x10firm.CompilerOptions;
import x10firm.types.FirmTypeSystem;
import x10firm.types.GenericTypeSystem;
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

	private FirmTypeSystem firmTypeSystem;

	/** Constructos a new LoweringFirm goal. */
	public LoweringFirm(final Scheduler scheduler, final FirmTypeSystem firmTypeSystem) {
		super("LoweringFirm", scheduler);
		this.firmTypeSystem = firmTypeSystem;
	}

	@Override
	public boolean runTask() {
		final ExtensionInfo info = scheduler.extensionInfo();
		final CompilerOptions options = (CompilerOptions)info.getOptions();
		final X10NodeFactory_c nodeFactory = (X10NodeFactory_c)info.nodeFactory();
		final GenericTypeSystem x10TypeSystem = (GenericTypeSystem)info.typeSystem();

		firmTypeSystem.finishTypeSystem();

		// do post compile
		final FirmGenerator firmGen = new FirmGenerator(firmTypeSystem, x10TypeSystem, nodeFactory, options);
		firmGen.genPostCompile();

		firmTypeSystem.finishTypeSystem();

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
