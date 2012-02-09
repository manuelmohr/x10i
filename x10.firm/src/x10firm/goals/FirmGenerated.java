package x10firm.goals;

import polyglot.ast.Node;
import polyglot.frontend.Compiler;
import polyglot.frontend.Job;
import polyglot.frontend.SourceGoal_c;
import polyglot.types.TypeSystem;
import x10.ast.X10NodeFactory_c;
import x10.extension.X10Ext;
import x10firm.CompilerOptions;
import x10firm.types.FirmTypeSystem;
import x10firm.types.GenericTypeSystem;
import x10firm.visit.FirmGenerator;
import firm.Firm;
import firm.Mode;
import firm.Mode.Arithmetic;
import firm.OO;
import firm.bindings.binding_irio;

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

	private static void loadStdLibGraphs(CompilerOptions options) {
		final String stdlibPath = System.getProperty("x10.dist")
				+ "/src-stdlib/build/" + options.getTargetTriple()
				+ "/stdlib.ir";
		binding_irio.ir_import(stdlibPath);
	}

	@Override
	public boolean runTask() {
		initializeCodeGen();

		final Node ast = job().ast();
		System.out.println("FirmGenerated: " + ast);
		assert (ast != null);
		if (!((X10Ext) ast.ext()).subtreeValid())
			return false;

		final CompilerOptions options = (CompilerOptions) scheduler.extensionInfo().getOptions();
		if (options.useFirmLibraries())
			loadStdLibGraphs(options);

		firmTypeSystem.init(options.getFirmNativeTypesFilename());

		final Compiler compiler = job().compiler();
		final FirmGenerator v = new FirmGenerator(compiler, firmTypeSystem, x10TypeSystem, nodeFactory, options);
		v.visitAppropriate(ast);

		return true;
	}

	private static boolean firmInitialized = false;
	/** ensure that libFirm is initialized */
	public static void initializeFirm() {
		if (firmInitialized)
			return;
		firmInitialized = true;

		Firm.init();
		Firm.enableOptimisations();
	}

	private static boolean codegenInitialized = false;
	/** ensure that libOO and pointer size is initialized to prepare
	 * code generation. */
	public static void initializeCodeGen() {
		if (codegenInitialized)
			return;
		codegenInitialized = true;

		initializeFirm();

		setPointerSize(32);
		OO.init();
	}

	private static void setPointerSize(final int pointerSize) {
		final Mode eqSignedInt;
		final Mode eqUnsignedInt;

		if (pointerSize == 32) {
			eqSignedInt = Mode.getIs();
			eqUnsignedInt = Mode.getIu();
		} else if (pointerSize == 64) {
			eqSignedInt = Mode.getLs();
			eqUnsignedInt = Mode.getLu();
		} else {
			throw new RuntimeException("Unsupported pointer size: " + pointerSize);
		}

		final Arithmetic arithmetic = Arithmetic.TwosComplement;
		final Mode mode = Mode.createReferenceMode("p" + pointerSize, arithmetic, pointerSize, eqSignedInt, eqUnsignedInt);
		Mode.setDefaultModeP(mode);
	}
}
