package x10firm;

import firm.Firm;
import polyglot.frontend.Compiler;
import polyglot.frontend.Goal;
import polyglot.frontend.Job;
import polyglot.frontend.Scheduler;
import polyglot.main.Options;
import polyglot.util.ErrorQueue;
import polyglot.visit.PostCompiled;
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
			/* a NULL goal... */
			Goal goal = new PostCompiled(extInfo) {
				@Override
				protected boolean invokePostCompiler(Options options, Compiler compiler, ErrorQueue eq) {
					return true;
				}
			};
			return goal.intern(this);
		}

		@Override
		public Goal CodeGenerated(Job job) {
			TypeSystem typeSystem = (TypeSystem)extInfo.typeSystem();
			Goal goal = new FirmGenerationGoal(job, typeSystem);
			return goal.intern(this);
		}
	}
}
