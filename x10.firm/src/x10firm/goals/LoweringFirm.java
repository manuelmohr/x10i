package x10firm.goals;

import polyglot.frontend.ExtensionInfo;
import polyglot.visit.PostCompiled;
import x10firm.types.TypeSystem;
import firm.Backend;
import firm.Util;

/**
 * This defines the lowering pass.
 */
public class LoweringFirm extends PostCompiled {
	/**
	 * Remember the typeSystem until the code generator is actually invoked.
	 */
	private final TypeSystem typeSystem;

	/** Constructor */
	public LoweringFirm(ExtensionInfo extInfo, TypeSystem typeSystem) {
		super(extInfo);
		this.typeSystem = typeSystem;
	}

	@Override
	public boolean runTask() {
		typeSystem.finishTypeSystem();
		Util.lowerSels();
		Backend.lowerForTarget();

		return true;
	}
}
