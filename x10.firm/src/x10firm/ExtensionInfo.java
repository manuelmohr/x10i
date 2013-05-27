package x10firm;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
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
	private static boolean whiteListInitialized;

	private static void initWhitelist(final CompilerOptions options) {
		if (whiteListInitialized)
			return;

		final String whiteListFile = options.getWhiteListFile();
		if (whiteListFile != null) {
			BufferedReader reader = null;
			try {
				reader = new BufferedReader(new InputStreamReader(new FileInputStream(whiteListFile)));
				String line;
				while ((line = reader.readLine()) != null) {
					line = line.trim();
					if (line.length() == 0)
						continue;
					if (line.charAt(0) == '#')
						continue;
					allowedFiles.add(line);
				}
			} catch (IOException e) {
				throw new RuntimeException(e);
			} finally {
				if (reader != null) {
					try {
						reader.close();
					} catch (IOException e) {
						/* we don't care */
					}
				}
			}
		} else {
			allowedFiles.add("x10/array/Array.x10");
			allowedFiles.add("x10/array/BlockDist.x10");
			allowedFiles.add("x10/array/BlockBlockDist.x10");
			allowedFiles.add("x10/array/ConstantDist.x10");
			allowedFiles.add("x10/array/Dist.x10");
			allowedFiles.add("x10/array/DistArray.x10");
			allowedFiles.add("x10/array/EmptyRegion.x10");
			allowedFiles.add("x10/array/FullRegion.x10");
			allowedFiles.add("x10/array/MatBuilder.x10");
			allowedFiles.add("x10/array/Mat.x10");
			allowedFiles.add("x10/array/PeriodicDist.x10");
			allowedFiles.add("x10/array/PlaceGroup.x10");
			allowedFiles.add("x10/array/Point.x10");
			allowedFiles.add("x10/array/PolyMat.x10");
			allowedFiles.add("x10/array/PolyMatBuilder.x10");
			allowedFiles.add("x10/array/PolyRegion.x10");
			allowedFiles.add("x10/array/PolyRow.x10");
			allowedFiles.add("x10/array/PolyScanner.x10");
			allowedFiles.add("x10/array/Range.x10");
			allowedFiles.add("x10/array/RectRegion1D.x10");
			allowedFiles.add("x10/array/RectRegion.x10");
			allowedFiles.add("x10/array/RectLayout.x10");
			allowedFiles.add("x10/array/Region.x10");
			allowedFiles.add("x10/array/RemoteArray.x10");
			allowedFiles.add("x10/array/Row.x10");
			allowedFiles.add("x10/array/SparsePlaceGroup.x10");
			allowedFiles.add("x10/array/UnboundedRegionException.x10");
			allowedFiles.add("x10/array/UniqueDist.x10");
			allowedFiles.add("x10/array/VarMat.x10");
			allowedFiles.add("x10/array/ValRow.x10");
			allowedFiles.add("x10/array/VarRow.x10");
			allowedFiles.add("x10/array/WrappedDistPlaceRestricted.x10");
			allowedFiles.add("x10/array/WrappedDistRegionRestricted.x10");
			allowedFiles.add("x10/compiler/CompilerFlags.x10");
			allowedFiles.add("x10/compiler/InitDispatcher.x10");
			allowedFiles.add("x10/compiler/StackAllocate.x10");
			allowedFiles.add("x10/io/Console.x10");
			allowedFiles.add("x10/io/CustomSerialization.x10");
			allowedFiles.add("x10/io/EOFException.x10");
			allowedFiles.add("x10/io/File.x10");
			allowedFiles.add("x10/io/FileNotFoundException.x10");
			allowedFiles.add("x10/io/FileReader.x10");
			allowedFiles.add("x10/io/FileWriter.x10");
			allowedFiles.add("x10/io/FilterReader.x10");
			allowedFiles.add("x10/io/FilterWriter.x10");
			allowedFiles.add("x10/io/InputStreamReader.x10");
			allowedFiles.add("x10/io/IOException.x10");
			allowedFiles.add("x10/io/Marshal.x10");
			allowedFiles.add("x10/io/OutputStreamWriter.x10");
			allowedFiles.add("x10/io/Printer.x10");
			allowedFiles.add("x10/io/PutbackReader.x10");
			allowedFiles.add("x10/io/Readable.x10");
			allowedFiles.add("x10/io/Reader.x10");
			allowedFiles.add("x10/io/ReaderIterator.x10");
			allowedFiles.add("x10/io/SerialData.x10");
			allowedFiles.add("x10/io/StringWriter.x10");
			allowedFiles.add("x10/io/Writable.x10");
			allowedFiles.add("x10/io/Writer.x10");
			allowedFiles.add("x10/lang/Activity.x10");
			allowedFiles.add("x10/lang/Any.x10");
			allowedFiles.add("x10/lang/Arithmetic.x10");
			allowedFiles.add("x10/lang/ArrayIndexOutOfBoundsException.x10");
			allowedFiles.add("x10/lang/BadPlaceException.x10");
			allowedFiles.add("x10/lang/Bitwise.x10");
			allowedFiles.add("x10/lang/Boolean.x10");
			allowedFiles.add("x10/lang/Byte.x10");
			allowedFiles.add("x10/lang/Char.x10");
			allowedFiles.add("x10/lang/CheckedException.x10");
			allowedFiles.add("x10/lang/CheckedThrowable.x10");
			allowedFiles.add("x10/lang/Cell.x10");
			allowedFiles.add("x10/lang/ClassCastException.x10");
			allowedFiles.add("x10/lang/Comparable.x10");
			allowedFiles.add("x10/lang/Complex.x10");
			allowedFiles.add("x10/lang/Double.x10");
			allowedFiles.add("x10/lang/Empty.x10");
			allowedFiles.add("x10/lang/Exception.x10");
			allowedFiles.add("x10/lang/FailedDynamicCheckException.x10");
			allowedFiles.add("x10/lang/FinishState.x10");
			allowedFiles.add("x10/lang/Float.x10");
			allowedFiles.add("x10/lang/GlobalCell.x10");
			allowedFiles.add("x10/lang/GlobalRef.x10");
			allowedFiles.add("x10/lang/IllegalArgumentException.x10");
			allowedFiles.add("x10/lang/IllegalOperationException.x10");
			allowedFiles.add("x10/lang/Indexable.x10");
			allowedFiles.add("x10/lang/IndexOutOfBoundsException.x10");
			allowedFiles.add("x10/lang/IntRange.x10");
			allowedFiles.add("x10/lang/Int.x10");
			allowedFiles.add("x10/lang/Iterable.x10");
			allowedFiles.add("x10/lang/Iterator.x10");
			allowedFiles.add("x10/lang/LongRange.x10");
			allowedFiles.add("x10/lang/Long.x10");
			allowedFiles.add("x10/lang/Math.x10");
			allowedFiles.add("x10/lang/NativeSupport.x10");
			allowedFiles.add("x10/lang/NoSuchElementException.x10");
			allowedFiles.add("x10/lang/Object.x10");
			allowedFiles.add("x10/lang/Place.x10");
			allowedFiles.add("x10/lang/PlaceLocalHandle.x10");
			allowedFiles.add("x10/lang/Pointer.x10");
			allowedFiles.add("x10/lang/Rail.x10");
			allowedFiles.add("x10/lang/Reducible.x10");
			allowedFiles.add("x10/lang/Runtime.x10");
			allowedFiles.add("x10/lang/Sequence.x10");
			allowedFiles.add("x10/lang/Settable.x10");
			allowedFiles.add("x10/lang/Short.x10");
			allowedFiles.add("x10/lang/String.x10");
			allowedFiles.add("x10/lang/System.x10");
			allowedFiles.add("x10/lang/Thread.x10");
			allowedFiles.add("x10/lang/UByte.x10");
			allowedFiles.add("x10/lang/UInt.x10");
			allowedFiles.add("x10/lang/ULong.x10");
			allowedFiles.add("x10/lang/UnsupportedOperationException.x10");
			allowedFiles.add("x10/lang/UShort.x10");
			allowedFiles.add("x10/lang/WrappedThrowable.x10");
			allowedFiles.add("x10/lang/Zero.x10");
			allowedFiles.add("x10/util/AbstractCollection.x10");
			allowedFiles.add("x10/util/AbstractContainer.x10");
			allowedFiles.add("x10/util/ArrayList.x10");
			allowedFiles.add("x10/util/ArrayUtils.x10");
			allowedFiles.add("x10/util/Box.x10");
			allowedFiles.add("x10/util/Builder.x10");
			allowedFiles.add("x10/util/Collection.x10");
			allowedFiles.add("x10/util/concurrent/AtomicBoolean.x10");
			allowedFiles.add("x10/util/concurrent/AtomicDouble.x10");
			allowedFiles.add("x10/util/concurrent/AtomicFloat.x10");
			allowedFiles.add("x10/util/concurrent/AtomicInteger.x10");
			allowedFiles.add("x10/util/concurrent/AtomicLong.x10");
			allowedFiles.add("x10/util/concurrent/Future.x10");
			allowedFiles.add("x10/util/concurrent/Latch.x10");
			allowedFiles.add("x10/util/concurrent/Lock.x10");
			allowedFiles.add("x10/util/concurrent/Monitor.x10");
			allowedFiles.add("x10/util/concurrent/Signal.x10");
			allowedFiles.add("x10/util/Container.x10");
			allowedFiles.add("x10/util/CollectionIterator.x10");
			allowedFiles.add("x10/util/GrowableIndexedMemoryChunk.x10");
			allowedFiles.add("x10/util/HashMap.x10");
			allowedFiles.add("x10/util/HashSet.x10");
			allowedFiles.add("x10/util/IndexedMemoryChunk.x10");
			allowedFiles.add("x10/util/Indexed.x10");
			allowedFiles.add("x10/util/List.x10");
			allowedFiles.add("x10/util/ListIterator.x10");
			allowedFiles.add("x10/util/Map.x10");
			allowedFiles.add("x10/util/MapIterator.x10");
			allowedFiles.add("x10/util/MapSet.x10");
			allowedFiles.add("x10/util/NoSuchElementException.x10");
			allowedFiles.add("x10/util/Ordered.x10");
			allowedFiles.add("x10/util/Pair.x10");
			allowedFiles.add("x10/util/Random.x10");
			allowedFiles.add("x10/util/Set.x10");
			allowedFiles.add("x10/util/Stack.x10");
			allowedFiles.add("x10/util/StringBuilder.x10");
			allowedFiles.add("x10/util/Timer.x10");
		}
		whiteListInitialized = true;
	}

	/** returns true if it is expected, that the given class compiles cleanly
	 * with the current compiler.
	 */
	public static boolean shouldGenerateCodeFor(final Job job) {
		initWhitelist((CompilerOptions)job.extensionInfo().getOptions());

		final String fileName = job.toString();
		for (final String str: allowedFiles) {
			if (fileName.endsWith(str))
				return true;
		}
		return false;
	}
}
