package x10firm.goals;

import polyglot.frontend.Job;
import polyglot.frontend.SourceGoal_c;
import x10firm.OOSupport;
import x10firm.types.TypeSystem;
import firm.Backend;
import firm.Util;

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
	
	private static boolean hasRun = false;

	@Override
	public boolean runTask() {
		// TODO: should not be necessary...
		if(hasRun) return true;
		hasRun = true;
		typeSystem.finishTypeSystem();
		OOSupport.lowerOO(typeSystem);
		Util.lowerSels();
		Backend.lowerForTarget();
		
		/*
		for(Graph g : Program.getGraphs()) {
			Dump.dumpGraph(g, "--lower");
		}
		*/
		
		return true;
	}
}