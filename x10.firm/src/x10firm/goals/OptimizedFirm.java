package x10firm.goals;

import polyglot.frontend.Job;
import polyglot.frontend.SourceGoal_c;
import x10firm.OOSupport;
import x10firm.types.TypeSystem;
import firm.Backend;

/**
 * This defines the FirmGeneration goal (other people would say "phase")
 * for polyglot.
 * @author matze
 */
public class OptimizedFirm extends SourceGoal_c {
	/**
	 * Remember the typeSystem until the code generator is actually invoked.
	 */
	private final TypeSystem typeSystem;

	/** Constructor */
	public OptimizedFirm(Job job, TypeSystem typeSystem) {
		super("OptimizedFirm", job);
		this.typeSystem = typeSystem;
	}

	@Override
	public boolean runTask() {
		OOSupport.lowerOO(typeSystem);
		Backend.lowerForTarget();
		return true;
	}
}
