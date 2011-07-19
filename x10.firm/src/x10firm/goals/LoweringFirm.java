package x10firm.goals;

import java.io.IOException;

import polyglot.frontend.AllBarrierGoal;
import polyglot.frontend.Goal;
import polyglot.frontend.Job;
import polyglot.frontend.Scheduler;
import x10firm.CompilerOptions;
import x10firm.types.FirmTypeSystem;
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
		
		final CompilerOptions options =
			(CompilerOptions) scheduler.extensionInfo().getOptions();
		
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
		
		firmTypeSystem.finishTypeSystem(); 
		
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
		// TODO DELETE_ME: Delete the second condition when closures are implemented
		if (!scheduler.shouldCompile(job) && !job.toString().endsWith("x10/lang/Thread.x10")) {
			return null;
		}
		
		return scheduler.End(job);
	}
}