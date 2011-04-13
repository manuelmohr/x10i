package x10firm.goals;

import java.io.IOException;
import java.util.UUID;

import polyglot.frontend.AllBarrierGoal;
import polyglot.frontend.Goal;
import polyglot.frontend.Job;
import polyglot.frontend.Scheduler;
import firm.Backend;

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
		if (!scheduler.shouldCompile(job)) {
			return null;
		}
		return scheduler.End(job);
	}
}
