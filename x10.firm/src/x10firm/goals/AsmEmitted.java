package x10firm.goals;

import java.io.IOException;
import java.util.HashSet;
import java.util.Set;
import java.util.UUID;

import polyglot.frontend.AllBarrierGoal;
import polyglot.frontend.Goal;
import polyglot.frontend.Job;
import polyglot.frontend.Scheduler;
import x10firm.CompilerOptions;
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
	public static final String ASM_FILENAME =
			UUID.randomUUID().toString() + ".s";

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
	
	// TODO: DELETE ME: Need closure support
	private static Set<String> allowedClassNames = new HashSet<String>();
	static {
		//allowedClassNames.add("x10/lang/Int.x10");
		allowedClassNames.add("x10/lang/Thread.x10");
		
		allowedClassNames.add("x10/util/concurrent/AtomicFloat.x10");
		allowedClassNames.add("x10/util/concurrent/AtomicDouble.x10");
		allowedClassNames.add("x10/util/concurrent/AtomicInteger.x10");
		allowedClassNames.add("x10/util/concurrent/AtomicLong.x10");
		allowedClassNames.add("x10/util/concurrent/AtomicBoolean.x10");
		allowedClassNames.add("x10/util/concurrent/Fences.x10");
		allowedClassNames.add("x10/util/concurrent/Lock.x10"); 
	}
	
	// TODO DELETE ME: Delete this method when closures are implemented. 
	public static boolean isAllowedClassName(final String className) {
		for(final String str: allowedClassNames) 
			if(className.endsWith(str))
				return true;
		return false; 
	}

	@Override
	public Goal prereqForJob(Job job) {
		// TODO DELETE ME: Delete the second condition when closures are implemented
		if (!scheduler.shouldCompile(job) && !isAllowedClassName(job.toString())) {
			return null;
		}
		
		return scheduler.End(job);
	}
}