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
 * Setting the goals for the Firm backend
 * and depend on the X10 scheduler for the rest.
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
		/* The other X10 backends and Polyglot use this goal to invoke javac/gcc on
		 * the generated source code. In the Firm context this corresponds to linking
		 * the assembler output. */
		Goal goal = new PostCompiled(extInfo) {
			@Override
			protected boolean invokePostCompiler(Options options, Compiler compiler, ErrorQueue eq) {
				// TODO invoke the assembler/linker
				return true;
			}
		};
		return goal.intern(this);
	}

	@Override
	public Goal CodeGenerated(Job job) {
		final GoalSequence seq = new GoalSequence("FirmSequence", job);
		
		TypeSystem typeSystem = (TypeSystem)extInfo.typeSystem();
		
		final Goal firm_generated = new FirmGenerated(job, typeSystem);
		firm_generated.intern(this);
		seq.append(firm_generated);
		
		final Goal optimized_firm = new OptimizedFirm(job, typeSystem);
		optimized_firm.addPrereq(firm_generated);
		optimized_firm.intern(this);
		seq.append(optimized_firm);
		
		final AsmEmitted asm_emitted = new AsmEmitted(job);
		/* Technically we could output unoptimized Firm as well.
		 * However, it is the responsibility of the OptimizedFirm goal
		 * to decide whether and which optimizations to apply.
		 * Therefore, always require OptimizedFirm */
		asm_emitted.addPrereq(optimized_firm);
		asm_emitted.intern(this);
		seq.append(asm_emitted);
		
		return seq;
	}
}