package x10firm;

import java.util.HashSet;
import java.util.Set;

import polyglot.ast.NodeFactory;
import polyglot.frontend.Scheduler;
import x10.X10CompilerOptions;
import x10c.ast.X10CNodeFactory_c;
import x10firm.types.GenericTypeSystem;

import firm.Firm;
import firm.Mode;
import firm.Mode.ir_mode_arithmetic;
import firm.OO;

/**
 * Defines our extension (Firm backend in X10 compiler) within the Polyglot framework
 *
 */
public class ExtensionInfo extends x10.ExtensionInfo {

	/**
	 * Initializes our extension.
	 * E.g. loads the native libFirm via JNA.
	 */
	public ExtensionInfo() {
		Firm.init();
		Firm.enableOptimisations();
		setPointerSize(32);
		OO.init();
	}

	@Override
	public String compilerName() {
		return "x10firm";
	}

	@Override
	public polyglot.main.Version version() {
		return new Version();
	}

	@Override
	protected Scheduler createScheduler() {
		return new FirmScheduler(this);
	}

	@Override
	protected polyglot.types.TypeSystem createTypeSystem() {
		return new GenericTypeSystem(this);
	}

	@Override
    protected NodeFactory createNodeFactory() {
    	return new X10CNodeFactory_c(this);
    }

	@Override
	protected X10CompilerOptions createOptions() {
		return new CompilerOptions(this);
	}

	/**
	 *
	 */
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

		final ir_mode_arithmetic arithmetic = ir_mode_arithmetic.irma_twos_complement;
		final Mode mode = Mode.createReferenceMode("p" + pointerSize, arithmetic, pointerSize, eqSignedInt, eqUnsignedInt);
		Mode.setDefaultModeP(mode);
	}

	// TODO: DELETE ME: Need library support
	private static Set<String> allowedClassNames = new HashSet<String>();
	static {
		allowedClassNames.add("x10/lang/Any.x10");
		allowedClassNames.add("x10/lang/Object.x10");

		allowedClassNames.add("x10/lang/UInt.x10");
		allowedClassNames.add("x10/lang/UByte.x10");
		allowedClassNames.add("x10/lang/UShort.x10");
		allowedClassNames.add("x10/lang/ULong.x10");
		allowedClassNames.add("x10/lang/Short.x10");
		allowedClassNames.add("x10/lang/Byte.x10");
		allowedClassNames.add("x10/lang/Boolean.x10");
		allowedClassNames.add("x10/lang/Long.x10");
		allowedClassNames.add("x10/lang/Int.x10");
		allowedClassNames.add("x10/lang/Float.x10");
		allowedClassNames.add("x10/lang/Double.x10");
		allowedClassNames.add("x10/lang/Char.x10");
		allowedClassNames.add("x10/lang/Pointer.x10");

//		allowedClassNames.add("x10/lang/Math.x10");
//		allowedClassNames.add("x10/lang/Complex.x10");
//		allowedClassNames.add("x10/lang/Cell.x10");
		allowedClassNames.add("x10/lang/LongRange.x10");

		allowedClassNames.add("x10/lang/Zero.x10");

//		allowedClassNames.add("x10/lang/Acc.x10");
//		allowedClassNames.add("x10/lang/Reducible.x10");
		allowedClassNames.add("x10/lang/Indexable.x10");
		allowedClassNames.add("x10/lang/Comparable.x10");
		allowedClassNames.add("x10/lang/Bitwise.x10");
		allowedClassNames.add("x10/lang/Arithmetic.x10");
		allowedClassNames.add("x10/lang/Iterable.x10");

		allowedClassNames.add("x10/lang/Iterable.x10");
		allowedClassNames.add("x10/lang/Iterator.x10");
		allowedClassNames.add("x10/lang/Thread.x10");

		allowedClassNames.add("x10/util/concurrent/AtomicFloat.x10");
		allowedClassNames.add("x10/util/concurrent/AtomicDouble.x10");
		allowedClassNames.add("x10/util/concurrent/AtomicInteger.x10");
		allowedClassNames.add("x10/util/concurrent/AtomicLong.x10");
		allowedClassNames.add("x10/util/concurrent/AtomicBoolean.x10");
		allowedClassNames.add("x10/util/concurrent/Fences.x10");
		allowedClassNames.add("x10/util/concurrent/Lock.x10");
		allowedClassNames.add("x10/util/Container.x10");
//		allowedClassNames.add("x10/util/Option.x10");
//		allowedClassNames.add("x10/util/Ordered.x10");
//		allowedClassNames.add("x10/util/Timer.x10");
//		allowedClassNames.add("x10/util/Box.x10");
		allowedClassNames.add("x10/util/IndexedMemoryChunk.x10");
//		allowedClassNames.add("x10/util/GrowableIndexedMemoryChunk.x10");

//		allowedClassNames.add("x10/io/SerialData.x10");
//		allowedClassNames.add("x10/io/CustomSerialization.x10");

		allowedClassNames.add("x10/compiler/InitDispatcher.x10");
	}

	/** returns true if it is expected, that the given class compiles cleanly
	 * with the current compiler.
	 * TODO DELETE ME: Delete this method when library support is implemented.
	 */
	public static boolean isAllowedClassName(final String className) {
		for(final String str: allowedClassNames)
			if(className.endsWith(str))
				return true;
		return false;
	}

}
