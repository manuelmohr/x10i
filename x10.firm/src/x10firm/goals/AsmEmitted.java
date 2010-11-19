package x10firm.goals;

import java.io.IOException;

import firm.Backend;
import polyglot.frontend.Goal;
import polyglot.frontend.Job;
import polyglot.frontend.SourceGoal_c;

/**
 * This defines the FirmGeneration goal (other people would say "phase")
 * for polyglot.
 * @author matze
 */
public class AsmEmitted extends SourceGoal_c {
	private Goal prereq_redirection = null;

	/** Constructor */
	public AsmEmitted(Job job) {
		super("AsmEmitted", job);
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

	/**
	 * Redirect all addPrereq calls to this other goal.
	 * @param goal		originally a FirmGenerated goal
	 */
	public void redirectPrereq(Goal goal) {
		assert (goal != this);
		prereq_redirection = goal;
	}
}
