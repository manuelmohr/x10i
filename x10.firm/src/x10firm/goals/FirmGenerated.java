package x10firm.goals;

import polyglot.ast.Node;
import polyglot.frontend.Compiler;
import polyglot.frontend.Job;
import polyglot.frontend.SourceGoal_c;
import polyglot.types.TypeSystem;
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
	private final GenericTypeSystem x10TypeSystem;

	/**
	 * Remember the node factory until the code generator is actually invoked
	 */
	private final X10NodeFactory_c nodeFactory;

	/** Constructor */
	public FirmGenerated(final Job job, final TypeSystem x10TypeSystem,
			final FirmTypeSystem firmTypeSystem,
			final X10NodeFactory_c nodeFactory) {

		super("FirmGenerated", job);
		this.firmTypeSystem = firmTypeSystem;
		this.x10TypeSystem = (GenericTypeSystem) x10TypeSystem;
		this.nodeFactory = nodeFactory;
	}

	@Override
	public boolean runTask() {
		FirmState.initializeCodeGen();

		final Node ast = job().ast();
		System.out.println("FirmGenerated: " + ast);
		assert (ast != null);
		if (!((X10Ext) ast.ext()).subtreeValid())
			return false;

		final CompilerOptions options = (CompilerOptions) scheduler.extensionInfo().getOptions();
		if (options.useFirmLibraries())
			FirmState.loadFirmLibrary(options, "x10");
		firmTypeSystem.init(options.getFirmNativeTypesFilename());

		final Compiler compiler = job().compiler();
		final FirmGenerator v = new FirmGenerator(compiler, firmTypeSystem, x10TypeSystem, nodeFactory, options);
		v.visitAppropriate(ast);

		return true;
	}
}
