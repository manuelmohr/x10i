package x10firm;

import firm.Firm;
import polyglot.frontend.Compiler;
import polyglot.frontend.Goal;
import polyglot.frontend.Job;
import polyglot.frontend.Scheduler;
import polyglot.main.Options;
import polyglot.util.ErrorQueue;
import polyglot.visit.PostCompiled;
import x10firm.goals.AsmEmitted;
import x10firm.goals.FirmGenerated;
import x10firm.goals.OptimizedFirm;
import x10firm.types.TypeSystem;

/**
 * Defines our extension (Firm backend in X10 compiler) within the Polyglot framework
 *
 */
public class ExtensionInfo extends x10.ExtensionInfo {
	
	/**
	 * Initializes our extension.
	 * E.g. loads the native libFirm via JNA.
	 */
	public ExtensionInfo() {
		Firm.init();
	} 

	@Override
	public String compilerName() {
		return "x10firm";
	}

	@Override
	public polyglot.main.Version version() {
		return new Version();
	}

	@Override
	protected Scheduler createScheduler() {
		return new X10FirmScheduler(this);
	}

	@Override
	protected polyglot.types.TypeSystem createTypeSystem() {
		return new TypeSystem();
	}

	@Override
	protected Options createOptions() {
		return new CompilerOptions(this);
	}

	private static class X10FirmScheduler extends X10Scheduler {
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
			TypeSystem typeSystem = (TypeSystem)extInfo.typeSystem();
			Goal firm_generated = new FirmGenerated(job, typeSystem);
			firm_generated.intern(this);
			
			Goal optimized_firm = new OptimizedFirm(job, typeSystem);
			optimized_firm.addPrereq(firm_generated);
			optimized_firm.intern(this);
			
			AsmEmitted asm_emitted = new AsmEmitted(job);
			/* Technically we could output unoptimized Firm as well.
			 * However, it is the responsibility of the OptimizedFirm goal
			 * to decide whether and which optimizations to apply.
			 * Therefore, always require OptimizedFirm */
			asm_emitted.addPrereq(optimized_firm);
			asm_emitted.intern(this);
			
			/* We must return asm_emitted, so the X10Scheduler will
			 * call "end_goal.addPrereq(asm_emitted)".
			 * Nevertheless, all "asm_emitted.addPrereq(X)" calls,
			 * must be redirected to "firm_generated.addPrereq(X)",
			 * otherwise firm_generated would have no dependencies,
			 * which lets it crash.
			 */
			asm_emitted.redirectPrereq(firm_generated);
			return asm_emitted;
		}
	}
}
