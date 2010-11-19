package x10firm;

import firm.Firm;
import polyglot.frontend.Scheduler;
import polyglot.main.Options;
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
}
