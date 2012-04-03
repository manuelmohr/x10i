package x10firm.goals;

import java.io.File;
import java.io.IOException;

import polyglot.frontend.AllBarrierGoal;
import polyglot.frontend.Goal;
import polyglot.frontend.Job;
import polyglot.frontend.Scheduler;
import x10firm.CompilerOptions;
import x10firm.ExtensionInfo;
import firm.Backend;
import firm.Dump;
import firm.Graph;
import firm.Program;
import firm.bindings.binding_irgopt;
import firm.bindings.binding_iroptimize;

/**
 * Assembler emission goal.
 */
public class AsmEmitted extends AllBarrierGoal {
	private final File output;

	private static final String COMPILATION_UNIT_NAME = "x10program";

	private Goal prereqRedirection = null;

	/** Constructs a new AsmEmitted goal. */
	public AsmEmitted(final Scheduler scheduler, final File output) {
		super("AsmEmitted", scheduler);
		this.output = output;
	}

	@Override
	public boolean runTask() {
		final CompilerOptions options =
			(CompilerOptions) scheduler.extensionInfo().getOptions();

		/* make sure all unreachable code is eliminated or the backend
		 * may be confused */
		for (Graph g : Program.getGraphs()) {
			binding_irgopt.optimize_graph_df(g.ptr);
			binding_iroptimize.optimize_cf(g.ptr);
			binding_irgopt.remove_bads(g.ptr);
			if (options.isDumpFirmGraphs()) {
				Dump.dumpGraph(g, "--before-backend");
			}
		}

		/* emit asm */
		try {
			Backend.option("omitfp"); // makes the assembler a bit more readable
			Backend.createAssembler(output.getAbsolutePath(), COMPILATION_UNIT_NAME);
		} catch (IOException e) {
			System.out.println("Could not create asm file");
			e.printStackTrace();
			return false;
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
		// TODO DELETE ME: Delete the second condition when library support is implemented
		if (!scheduler.shouldCompile(job) && !ExtensionInfo.isAllowedClassName(job.toString())) {
			return null;
		}

		return scheduler.End(job);
	}

	@Override
	public String toString() {
		return name() + " - " + output;
	}
}
