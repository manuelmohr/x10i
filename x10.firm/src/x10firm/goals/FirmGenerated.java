package x10firm.goals;

import polyglot.ast.Node;
import polyglot.frontend.Job;
import polyglot.frontend.SourceGoal_c;
import polyglot.util.ErrorInfo;
import polyglot.util.ErrorQueue;
import x10.extension.X10Ext;
import x10firm.CompilerOptions;
import x10firm.FirmState;
import x10firm.visit.FirmGenerator;

/**
 * This defines the FirmGeneration goal (other people would say "phase")
 * for polyglot.
 * @author matze
 */
public class FirmGenerated extends SourceGoal_c {
	private final FirmGenerator generator;

	/** Constructs a new FirmGenerated goal. */
	public FirmGenerated(final Job job, final FirmGenerator generator) {
		super("FirmGenerated", job);
		this.generator = generator;
	}

	@Override
	public boolean runTask() {
		FirmState.initializeCodeGen();

		final Node ast = job().ast();
		System.out.println("FirmGenerated: " + ast);
		assert ast != null;
		if (!((X10Ext) ast.ext()).subtreeValid())
			return false;

		final CompilerOptions options = generator.getOptions();
		if (options.useFirmLibraries()) {
			final String libName = "x10";
			final boolean loaded = FirmState.loadFirmLibrary(options, libName);
			if (!loaded) {
				final ErrorQueue errorQueue = job.compiler().errorQueue();
				errorQueue.enqueue(ErrorInfo.WARNING,
				                   String.format("Unable to load compilergraphs for '%s'", libName));
			}
		}
		generator.getFirmTypeSystem().init(options);
		generator.visitAppropriate(ast);
		return true;
	}
}
