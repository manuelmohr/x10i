package x10firm.goals;

import java.io.IOException;

import polyglot.ast.Node;
import polyglot.frontend.AllBarrierGoal;
import polyglot.frontend.Goal;
import polyglot.frontend.Job;
import polyglot.types.TypeSystem_c;
import polyglot.util.ErrorInfo;
import polyglot.util.ErrorQueue;
import x10.ast.X10NodeFactory_c;
import x10.extension.X10Ext;
import x10firm.CompilerOptions;
import x10firm.FirmScheduler;
import x10firm.FirmState;
import x10firm.visit.FirmGenerator;
import firm.Dump;
import firm.Graph;
import firm.Program;

/**
 * This defines the FirmGeneration goal (other people would say "phase")
 * for polyglot.
 * @author matze
 */
public class FirmGenerated extends AllBarrierGoal {
	private final TypeSystem_c typeSystem;
	private final X10NodeFactory_c nodeFactory;
	private final CompilerOptions options;

	/** Constructs a new FirmGenerated goal. */
	public FirmGenerated(final FirmScheduler scheduler, final TypeSystem_c typeSystem,
			final X10NodeFactory_c nodeFactory, final CompilerOptions options) {
		super("FirmGenerated", scheduler);
		this.typeSystem = typeSystem;
		this.nodeFactory = nodeFactory;
		this.options = options;
	}

	@Override
	public boolean runTask() {
		if (options.x10_config.ONLY_TYPE_CHECKING)
			return true;

		FirmState.initializeCodeGen(options);
		if (options.useFirmLibraries()) {
			final String libName = "x10";
			final boolean loaded = FirmState.loadFirmLibrary(options, libName);
			if (!loaded) {
				final ErrorQueue errorQueue = scheduler.extensionInfo().compiler().errorQueue();
				errorQueue.enqueue(ErrorInfo.WARNING,
				                   String.format("Unable to load compilergraphs for '%s'", libName));
			}
		}

		final FirmGenerator generator = new FirmGenerator(typeSystem, nodeFactory, options);

		for (final Job job : scheduler.jobs()) {
			final Node ast = job.ast();
			if (!((X10Ext) ast.ext()).subtreeValid())
				return false;
			if (!scheduler.shouldCompile(job))
				continue;

			/* if you hit the following assert, then more Jobs got scheduled
			 * during the FirmGenerator run. This is not allowed! */
			assert ((FirmScheduler)scheduler).codeGenPrereq(job).hasBeenReached();

			final boolean isCommandLineJob = scheduler.commandLineJobs().contains(job);
			generator.setIsCommandLineJob(isCommandLineJob);

			System.out.println("FirmGenerated: " + ast);
			generator.visitAppropriate(ast);
		}

		generator.genPostCompile();

		/* dump the firm typegraph */
		if (options.isDumpTypeGraph()) {
			try {
				Dump.dumpTypeGraph("typegraph.vcg");
			} catch (IOException e) {
				e.printStackTrace();
			}
		}

		/* Dump the normal firm graph */
		for (Graph g : Program.getGraphs()) {
			if (options.shouldDumpGraph(g)) {
				Dump.dumpGraph(g, "--fresh");
			}
		}

		Program.check();

		return true;
	}

	@Override
	public Goal prereqForJob(final Job job) {
		if (!scheduler.shouldCompile(job)) {
			return null;
		}

		final FirmScheduler firmScheduler = (FirmScheduler)scheduler;
		return firmScheduler.codeGenPrereq(job);
	}
}
