package x10firm.goals;

import java.io.IOException;
import java.util.UUID;

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
	/** name of the intermediate asm file */
	public static final String ASM_FILENAME = UUID.randomUUID().toString() + ".s";

	private Goal prereq_redirection = null;
	
	/** Constructor */
	public AsmEmitted(Scheduler scheduler) {
		super("AsmEmitted", scheduler);
	}

	@Override
	public boolean runTask() {
		
		/* try to generate some assembly */
		String compilationUnit = "x10program";
		
		final CompilerOptions options =
			(CompilerOptions) scheduler.extensionInfo().getOptions();

		/* make sure all unreachable code is eliminated or the backend
		 * may be confused */
		for (Graph g : Program.getGraphs()) {
			binding_irgopt.optimize_graph_df(g.ptr);
			binding_iroptimize.optimize_cf(g.ptr);
			binding_irgopt.remove_bads(g.ptr); // Without this line, the spiller faces situations it cannot cope with. Spiller should be fixed.
			if (options.isDumpFirmGraphs()) {
				Dump.dumpGraph(g, "--before-backend");
			}
		}

		try {
			Backend.option("omitfp"); // makes the assembler a bit more readable
			Backend.createAssembler(ASM_FILENAME, compilationUnit);
		} catch (IOException e) {
			e.printStackTrace();
		}

		return true;
	}

	@Override
	public void addPrereq(Goal goal) {
		if (prereq_redirection == null) {
			super.addPrereq(goal);
		} else {
			prereq_redirection.addPrereq(goal);
		}
	}
	
	@Override
	public Goal prereqForJob(Job job) {
		// TODO DELETE ME: Delete the second condition when library support is implemented
		if (!scheduler.shouldCompile(job) && !ExtensionInfo.isAllowedClassName(job.toString())) {
			return null;
		}
		
		return scheduler.End(job);
	}
}