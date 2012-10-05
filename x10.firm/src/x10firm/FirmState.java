package x10firm;

import java.io.File;
import java.util.ArrayList;

import firm.Firm;
import firm.Mode;
import firm.Mode.Arithmetic;
import firm.OO;
import firm.bindings.binding_irio;

/**
 * Keeps track of global firm state.
 * @author matze
 */
public final class FirmState {
	private static final ArrayList<String> FIRM_LIBRARIES = new ArrayList<String>();

	/** Utility class, do not instantiate. */
	private FirmState() {
	}

	/**
	 * Attempt to load a library as firm-graphs if available.
	 * (Search the libraryPath for NAME.ir files and loads them
	 *  if found).
	 */
	public static boolean loadFirmLibrary(final CompilerOptions options, final String name) {
		if (FIRM_LIBRARIES.contains(name))
			return true;

		/* construct searchpath, for now only the builddir in x10.dist */
		final String x10dist = System.getProperty("x10.dist", ".");
		final String libPath = x10dist + "/../x10.firm_runtime/build/" + options.getTargetTriple();
		final File file = new File(libPath + "/" + name + ".ir");
		if (!file.exists())
			return false;

		binding_irio.ir_import(file.toString());
		FIRM_LIBRARIES.add(name);
		return true;
	}

	/**
	 * Returns true if a library has been loaded as firm compilergraphs.
	 */
	public static boolean libraryLoaded(final String name) {
		return FIRM_LIBRARIES.contains(name);
	}

	private static boolean firmInitialized = false;
	/** Ensures that libFirm is initialized. */
	public static void initializeFirm() {
		if (firmInitialized)
			return;
		firmInitialized = true;

		Firm.init();
	}

	private static void initializeImplicitOptimizations() {
		Firm.enableOptimisations();
		firm.bindings.binding_irflag.set_opt_constant_folding(FirmOptions.isConstFolding() ? 1 : 0);
		firm.bindings.binding_irflag.set_opt_algebraic_simplification(FirmOptions.isConstFolding() ? 1 : 0);
		firm.bindings.binding_irflag.set_opt_cse(FirmOptions.isCse() ? 1 : 0);
		firm.bindings.binding_irflag.set_opt_global_cse(0);
	}

	private static boolean codegenInitialized = false;
	/** Ensure that libOO and pointer size is initialized to prepare
	 * code generation. */
	public static void initializeCodeGen() {
		if (codegenInitialized)
			return;
		codegenInitialized = true;

		initializeFirm();
		initializeImplicitOptimizations();

		setPointerSize(PointerSize.Size32);
		OO.init();
	}

	/** Target Word/Pointer size. */
	public static enum PointerSize {
		/** 32bits. */
		Size32(32),
		/** 64bits. */
		Size64(64);

		private final int size;
		private PointerSize(final int size) {
			this.size = size;
		}

		/** Returns size in bits. */
		public int getSize() {
			return size;
		}
	}

	private static void setPointerSize(final PointerSize size) {
		final Mode eqSignedInt;
		final Mode eqUnsignedInt;

		switch (size) {
		case Size32:
			eqSignedInt = Mode.getIs();
			eqUnsignedInt = Mode.getIu();
			break;
		case Size64:
			eqSignedInt = Mode.getLs();
			eqUnsignedInt = Mode.getLu();
			break;
		default:
			throw new RuntimeException("Invalid pointer size");
		}

		final Arithmetic arithmetic = Arithmetic.TwosComplement;
		final int bits = size.getSize();
		final String name = "p" + bits;
		final Mode mode
			= Mode.createReferenceMode(name, arithmetic, bits, eqSignedInt, eqUnsignedInt);
		Mode.setDefaultModeP(mode);
	}
}
