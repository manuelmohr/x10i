package x10firm;

import java.io.File;
import java.util.ArrayList;

import firm.Firm;
import firm.Mode;
import firm.Mode.Arithmetic;
import firm.OO;
import firm.bindings.binding_irio;

/**
 * Keeps track of global firm state
 * @author matze
 */
public class FirmState {
	private static final ArrayList<String> firmLibraries = new ArrayList<String>();
	/**
	 * Attempt to load a library as firm-graphs if available.
	 * (Search the libraryPath for NAME.ir files and loads them
	 *  if found).
	 */
	public static void loadFirmLibrary(final CompilerOptions options, final String name) {
		if (firmLibraries.contains(name))
			return;

		/* construct searchpath, for now only the builddir in x10.dist */
		String x10dist = System.getProperty("x10.dist");
		String libPath = x10dist + "/src-stdlib/build/" + options.getTargetTriple();
		File file = new File(libPath + "/" + name + ".ir");
		if (file.exists()) {
			binding_irio.ir_import(file.toString());
			firmLibraries.add(name);
		}
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
