package x10firm.goals;

import java.io.IOException;

import polyglot.frontend.AllBarrierGoal;
import polyglot.frontend.Goal;
import polyglot.frontend.Job;
import polyglot.frontend.Scheduler;
import firm.Backend;

/**
 * This defines the FirmGeneration goal (other people would say "phase")
 * for polyglot.
 * @author matze
 */
public class AsmEmitted extends AllBarrierGoal {
	private Goal prereq_redirection = null;

	/** Constructor */
	public AsmEmitted(Scheduler scheduler) {
		super("AsmEmitted", scheduler);
	}

	@Override
	public boolean runTask() {
		/* try to generate some assembly */
		String compilationUnit = "x10program"; /* can we query the program name? */
		try {
			Backend.option("omitfp"); // makes the assembler a bit more readable
			Backend.createAssembler("test.s", compilationUnit);
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
