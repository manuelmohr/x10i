package x10firm.goals;

import polyglot.frontend.AbstractGoal_c;
import polyglot.frontend.Goal;

/**
 * This is a meta goal, which really consists of a linear sequence of goals.
 *
 * We only need this class to work around the Polyglot scheduler architecture,
 * where the CodeGenerated method can only return one goal.
 */
public class GoalSequence extends AbstractGoal_c {

	/** constructor calls super -- make Java happy */
	public GoalSequence(String name) {
		super(name);
	}

	/**
	 * First goal in the sequence.
	 * All prerequirements must be redirected to this goal.
	 */
	private Goal first = null;

	/**
	 * Last goal in the sequence.
	 * However, 'this' is really the last goal in the sequence.
	 */
	private Goal last = null;

	@Override
	public boolean runTask() {
		// Nothing to do itself, all functionality is in the sequence it
		// depends on.
		return true;
	}

	@Override
	public void addPrereq(Goal goal) {
		// Redirect to the first goal, since all other goals transitively get
		// the prereq as well then.
		first.addPrereq(goal);
	}

	/** append another goal to the end of the goal sequence */
	public void append(Goal goal) {
		// Depend on all goals in the sequence.
		super.addPrereq(goal);

		if (first == null) {
			first = goal;
			return;
		}

		if (last == null) {
			goal.addPrereq(first);
		} else {
			goal.addPrereq(last);
		}
		last = goal;
	}
}
