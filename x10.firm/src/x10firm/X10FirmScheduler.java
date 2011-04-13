package x10firm;

import polyglot.frontend.Goal;
import polyglot.frontend.Job;
import x10.ExtensionInfo.X10Scheduler;
import x10.ast.X10NodeFactory_c;
import x10firm.goals.AsmEmitted;
import x10firm.goals.FirmGenerated;
import x10firm.goals.GoalSequence;
import x10firm.goals.Linked;
import x10firm.goals.LoweringFirm;
import x10firm.goals.SourceGoalSequence;
import x10firm.types.TypeSystem;

/**
 * Setting the goals for the Firm backend and depend on the X10 scheduler for
 * the rest.
 */
class X10FirmScheduler extends X10Scheduler {
	/**
	 * Initialize the scheduler, duh.
	 * @param info	"==ExtensionInfo.this", because this inner class is static
	 * (strange design by X10)
	 */
	public X10FirmScheduler(ExtensionInfo info) {
		super(info);
	}

	@Override
	protected Goal PostCompiled() {
		/*
		 * The other X10 backends and Polyglot use this goal to invoke
		 * javac/gcc on the generated source code.  In the Firm context this
		 * corresponds to emitting assembler and linking with the stdlib.
		 */

		final TypeSystem typeSystem = (TypeSystem)extInfo.typeSystem();

		final Goal lowering_firm = new LoweringFirm(extInfo, typeSystem);
		lowering_firm.intern(this);

		final Goal asmEmitted = new AsmEmitted(this);
		asmEmitted.intern(this);

		final Goal linked = new Linked(extInfo);
		linked.intern(this);

		final GoalSequence seq = new GoalSequence("FirmOutputSequence");
		seq.append(lowering_firm);
		seq.append(asmEmitted);
		seq.append(linked);

		return seq.intern(this);
	}

	@Override
	public Goal CodeGenerated(Job job) {

		final TypeSystem typeSystem = (TypeSystem) extInfo.typeSystem();
		final X10NodeFactory_c nodeFactory =
				(X10NodeFactory_c) extInfo.nodeFactory();

		final Goal firm_generated =
				new FirmGenerated(job, typeSystem, nodeFactory);
		firm_generated.intern(this);

		/*
		 * Since source goals are per job/compilation unit/source file,
		 * they must include their job into their hashCode for the internal
		 * method.
		 */

		final SourceGoalSequence seq =
				new SourceGoalSequence("FirmTransformationSequence", job);
		seq.append(firm_generated);

		return seq.intern(this);
	}
}