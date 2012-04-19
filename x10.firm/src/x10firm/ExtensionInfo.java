package x10firm;

import java.util.HashSet;
import java.util.Set;

import polyglot.ast.NodeFactory;
import polyglot.frontend.Job;
import polyglot.frontend.Scheduler;
import polyglot.types.TypeSystem_c;
import x10.X10CompilerOptions;
import x10c.ast.X10CNodeFactory_c;

/**
 * Defines our extension (Firm backend in X10 compiler) within the Polyglot framework.
 */
public class ExtensionInfo extends x10.ExtensionInfo {

	/**
	 * Initializes our extension.
	 * E.g. loads the native libFirm via JNA.
	 */
	public ExtensionInfo() {
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
		return new TypeSystem_c(this);
	}

	@Override
	protected NodeFactory createNodeFactory() {
		return new X10CNodeFactory_c(this);
	}

	@Override
	protected X10CompilerOptions createOptions() {
		return new CompilerOptions(this);
	}

	// TODO: DELETE ME: Need library support
	private static Set<String> allowedFiles = new HashSet<String>();
	static {
		allowedFiles.add("x10/lang/Any.x10");
		allowedFiles.add("x10/lang/Object.x10");

		allowedFiles.add("x10/lang/UInt.x10");
		allowedFiles.add("x10/lang/UByte.x10");
		allowedFiles.add("x10/lang/UShort.x10");
		allowedFiles.add("x10/lang/ULong.x10");
		allowedFiles.add("x10/lang/Short.x10");
		allowedFiles.add("x10/lang/Byte.x10");
		allowedFiles.add("x10/lang/Boolean.x10");
		allowedFiles.add("x10/lang/Long.x10");
		allowedFiles.add("x10/lang/Int.x10");
		allowedFiles.add("x10/lang/Float.x10");
		allowedFiles.add("x10/lang/Double.x10");
		allowedFiles.add("x10/lang/Char.x10");
		allowedFiles.add("x10/lang/Pointer.x10");
		allowedFiles.add("x10/lang/String.x10");

		allowedFiles.add("x10/lang/LongRange.x10");

		allowedFiles.add("x10/lang/Zero.x10");

		allowedFiles.add("x10/lang/Indexable.x10");
		allowedFiles.add("x10/lang/Comparable.x10");
		allowedFiles.add("x10/lang/Bitwise.x10");
		allowedFiles.add("x10/lang/Arithmetic.x10");
		allowedFiles.add("x10/lang/Iterable.x10");
		allowedFiles.add("x10/lang/NativeSupport.x10");

		allowedFiles.add("x10/lang/Iterable.x10");
		allowedFiles.add("x10/lang/Iterator.x10");
		allowedFiles.add("x10/lang/Thread.x10");

		allowedFiles.add("x10/util/concurrent/AtomicFloat.x10");
		allowedFiles.add("x10/util/concurrent/AtomicDouble.x10");
		allowedFiles.add("x10/util/concurrent/AtomicInteger.x10");
		allowedFiles.add("x10/util/concurrent/AtomicLong.x10");
		allowedFiles.add("x10/util/concurrent/AtomicBoolean.x10");
		allowedFiles.add("x10/util/concurrent/Fences.x10");
		allowedFiles.add("x10/util/concurrent/Lock.x10");
		allowedFiles.add("x10/util/Container.x10");
		allowedFiles.add("x10/util/IndexedMemoryChunk.x10");

		allowedFiles.add("x10/compiler/CompilerFlags.x10");
		allowedFiles.add("x10/compiler/InitDispatcher.x10");
	}

	/** returns true if it is expected, that the given class compiles cleanly
	 * with the current compiler.
	 * TODO DELETE ME: Delete this method when library support is implemented.
	 */
	public static boolean shouldGenerateCodeFor(final Job job) {
		final String fileName = job.toString();
		for (final String str: allowedFiles) {
			if (fileName.endsWith(str))
				return true;
		}
		return false;
	}
}
