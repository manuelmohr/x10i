package x10firm;

import polyglot.frontend.Goal;
import polyglot.frontend.Job;
import x10.ExtensionInfo.X10Scheduler;
import x10.ast.X10NodeFactory_c;
import x10firm.goals.AsmEmitted;
import x10firm.goals.FirmGenerated;
import x10firm.goals.GoalSequence;
import x10firm.goals.Linked;
import x10firm.goals.OptimizedFirm;
import x10firm.goals.SourceGoalSequence;
import x10firm.types.TypeSystem;

/**
 * Setting the goals for the Firm backend and depend on the X10 scheduler for
 * the rest.
 */
class X10FirmScheduler extends X10Scheduler {
	/**
	 * Initialize the scheduler, duh.
	 * @param info	"==ExtensionInfo.this", because this inner class is static (strange design by X10)
	 */
	public X10FirmScheduler(ExtensionInfo info) {
		super(info);
	}

	@Override
	protected Goal PostCompiled() {
		/*
		 * The other X10 backends and Polyglot use this goal to invoke javac/gcc
		 * the generated source code. In the Firm context this corresponds to
		 * emitting assembler and linking with the stdlib.
		 */

		final Goal asmEmitted = new AsmEmitted(this);
		asmEmitted.intern(this);

		final Goal linked = new Linked(extInfo);
		linked.intern(this);

		final GoalSequence seq = new GoalSequence("FirmOutputSequence");
		seq.append(asmEmitted);
		seq.append(linked);

		return seq.intern(this);
	}

	@Override
	public Goal CodeGenerated(Job job) {

		final TypeSystem typeSystem = (TypeSystem) extInfo.typeSystem();
		final X10NodeFactory_c nodeFactory = (X10NodeFactory_c)extInfo.nodeFactory();

		final Goal firm_generated = new FirmGenerated(job, typeSystem, nodeFactory);
		firm_generated.intern(this);

		final Goal optimized_firm = new OptimizedFirm(job, typeSystem);
		optimized_firm.intern(this);

		/* Since source goals are per job/compilation unit/source file,
		 * they must include their job into their hashCode for the intern method.
		 */

		final SourceGoalSequence seq = new SourceGoalSequence("FirmTransformationSequence", job);
		seq.append(firm_generated);
		seq.append(optimized_firm);

		return seq.intern(this);
	}
}