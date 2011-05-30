package x10firm;

import polyglot.frontend.Scheduler;
import x10.X10CompilerOptions;
import x10firm.types.GenericTypeSystem;
import firm.Firm;
import firm.OO;

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
		OO.init();
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
		return new GenericTypeSystem(this);
	}

	@Override
	protected X10CompilerOptions createOptions() {
		return new CompilerOptions(this);
	}
}
