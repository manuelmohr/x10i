package x10firm.goals;

import java.io.IOException;

import polyglot.frontend.AllBarrierGoal;
import polyglot.frontend.ExtensionInfo;
import polyglot.frontend.Goal;
import polyglot.frontend.Job;
import polyglot.frontend.Scheduler;
import x10.ast.X10NodeFactory_c;
import x10firm.CompilerOptions;
import x10firm.types.FirmTypeSystem;
import x10firm.types.GenericTypeSystem;
import x10firm.visit.X10FirmCodeGenerator;
import firm.Backend;
import firm.Dump;
import firm.Graph;
import firm.OO;
import firm.Program;
import firm.Util;

/**
 * This defines the lowering pass.
 */
public class LoweringFirm extends AllBarrierGoal {
	
	private Goal prereq_redirection = null;
	
	private FirmTypeSystem firmTypeSystem; 
	
	/** Constructor */
	public LoweringFirm(Scheduler scheduler, FirmTypeSystem firmTypeSystem_) {
		super("LoweringFirm", scheduler);
		firmTypeSystem = firmTypeSystem_; 
	}
	
	@Override
	public boolean runTask() {
		final ExtensionInfo info 					= scheduler.extensionInfo();
		final polyglot.frontend.Compiler compiler 	= info.compiler();
		final CompilerOptions options 				= (CompilerOptions)info.getOptions();
		final X10NodeFactory_c nodeFactory 			= (X10NodeFactory_c)info.nodeFactory();
		final GenericTypeSystem x10TypeSystem 		= (GenericTypeSystem)info.typeSystem();
		
		firmTypeSystem.finishTypeSystem(); 
		
		// do post compile 
		X10FirmCodeGenerator firmGen = new X10FirmCodeGenerator(compiler, firmTypeSystem, x10TypeSystem, nodeFactory, options);
		firmGen.genPostCompile();
		
		/* dump the firm typegraph */
		if (options.isDumpFirmGraphs()) {
			try {
				Dump.dumpTypeGraph("typegraph.vcg");
			} catch (IOException e) {
				e.printStackTrace(); 
			}
		}
		
		/* Dump the normal firm graph */
		if (options.isDumpFirmGraphs()) {
			for (Graph g : Program.getGraphs()) {
				Dump.dumpGraph(g, "--fresh");
			}
		}
		
		OO.lowerProgram();
		Util.lowerSels();
		Backend.lowerForTarget();

		return true;
	}
	
	@Override
	public void addPrereq(Goal goal) {
		if (prereq_redirection == null) {
			super.addPrereq(goal);
		} else {
			prereq_redirection.addPrereq(goal);
		}
	}

	@Override
	public Goal prereqForJob(Job job) {
		// TODO DELETE_ME: Delete the second condition when library support is implemented
		if (!scheduler.shouldCompile(job) && !x10firm.ExtensionInfo.isAllowedClassName(job.toString())) {
			return null;
		}
		
		return scheduler.End(job);
	}
}
