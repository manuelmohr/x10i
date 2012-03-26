package x10firm.goals;

import polyglot.ast.Node;
import polyglot.frontend.Job;
import polyglot.frontend.SourceGoal_c;
import polyglot.util.ErrorInfo;
import polyglot.util.ErrorQueue;
import x10.ast.X10NodeFactory_c;
import x10.extension.X10Ext;
import x10firm.CompilerOptions;
import x10firm.FirmState;
import x10firm.types.FirmTypeSystem;
import x10firm.types.GenericTypeSystem;
import x10firm.visit.FirmGenerator;

/**
 * This defines the FirmGeneration goal (other people would say "phase")
 * for polyglot.
 * @author matze
 */
public class FirmGenerated extends SourceGoal_c {
	/**
	 * Remember the FIRM type system until the code generator is actually invoked.
	 */
	private final FirmTypeSystem firmTypeSystem;

	/**
	 * Remember the X10 type system until the code generator is actually invoked.
	 */
	private final GenericTypeSystem typeSystem;

	/**
	 * Remember the node factory until the code generator is actually invoked.
	 */
	private final X10NodeFactory_c nodeFactory;

	/** Constructs a new FirmGenerated goal. */
	public FirmGenerated(final Job job, final GenericTypeSystem typeSystem,
			final FirmTypeSystem firmTypeSystem,
			final X10NodeFactory_c nodeFactory) {

		super("FirmGenerated", job);
		this.firmTypeSystem = firmTypeSystem;
		this.typeSystem = typeSystem;
		this.nodeFactory = nodeFactory;
	}

	@Override
	public boolean runTask() {
		FirmState.initializeCodeGen();

		final Node ast = job().ast();
		System.out.println("FirmGenerated: " + ast);
		assert ast != null;
		if (!((X10Ext) ast.ext()).subtreeValid())
			return false;

		final CompilerOptions options = (CompilerOptions) scheduler.extensionInfo().getOptions();
		if (options.useFirmLibraries()) {
			final String libName = "x10";
			final boolean loaded = FirmState.loadFirmLibrary(options, libName);
			if (!loaded) {
				final ErrorQueue errorQueue = job.compiler().errorQueue();
				errorQueue.enqueue(ErrorInfo.WARNING,
				                   String.format("Unable to load compilergraphs for '%s'", libName));
			}
		}
		firmTypeSystem.init(options);

		final FirmGenerator v = new FirmGenerator(firmTypeSystem, typeSystem, nodeFactory, options);
		v.visitAppropriate(ast);

		return true;
	}
}
