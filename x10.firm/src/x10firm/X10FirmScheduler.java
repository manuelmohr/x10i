package x10firm;

import polyglot.frontend.Compiler;
import polyglot.frontend.Goal;
import polyglot.frontend.Job;
import polyglot.main.Options;
import polyglot.util.ErrorQueue;
import polyglot.visit.PostCompiled;
import x10.ExtensionInfo.X10Scheduler;
import x10firm.goals.AsmEmitted;
import x10firm.goals.FirmGenerated;
import x10firm.goals.GoalSequence;
import x10firm.goals.OptimizedFirm;
import x10firm.types.TypeSystem;

/**
 * Setting the goals for the Firm backend and depend on the X10 scheduler for
 * the rest.
 */
class X10FirmScheduler extends X10Scheduler {
	/**
	 * Constructor
	 */
	public X10FirmScheduler(ExtensionInfo info) {
		super(info);
	}

	@Override
	protected Goal PostCompiled() {
		/*
		 * The other X10 backends and Polyglot use this goal to invoke javac/gcc
		 * the generated source code. In the Firm context this corresponds to li
		 * the assembler output.
		 */
		final Goal postCompiled = new PostCompiled(extInfo) {
			@Override
			protected boolean invokePostCompiler(Options options,
					Compiler compiler, ErrorQueue eq) {
				// TODO invoke the assembler/linker
				return true;
			}
		};

		final Goal asmEmitted = new AsmEmitted(this);
		postCompiled.addPrereq(asmEmitted);

		return intern(postCompiled);
	}

	@Override
	public Goal CodeGenerated(Job job) {
		final GoalSequence seq = new GoalSequence("FirmSequence", job);

		final TypeSystem typeSystem = (TypeSystem) extInfo.typeSystem();

		final Goal firm_generated = intern(new FirmGenerated(job, typeSystem));
		intern(firm_generated);
		seq.append(firm_generated);

		final Goal optimized_firm = intern(new OptimizedFirm(job, typeSystem));
		intern(optimized_firm);
		seq.append(optimized_firm);

		return intern(seq);
	}
}