package x10firm;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.Set;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import polyglot.frontend.ExtensionInfo;
import polyglot.main.Main;
import polyglot.main.UsageError;
import x10.X10CompilerOptions;
import x10firm.goals.FirmGenerated;
import firm.Backend;

/**
 * Firm-Backend specific commandline option parsing.
 * @author matze
 */
public class CompilerOptions extends X10CompilerOptions {
	/** Represents a target triple. */
	public static final class TargetTriple {
		private final String cpu;
		private final String manufacturer;
		private final String operatingSystem;

		/** Constructs a target triple from a triple string.
		 *
		 * @param triple A triple string such as "i686-linux-gnu" or a quadruple like "sparc-unknown-linux-gnu"
		 */
		public TargetTriple(final String triple) throws UsageError {
			final Pattern quad = Pattern.compile("(\\w+)-(\\w+)-(\\w+)-(\\w+)");
			final Pattern trip = Pattern.compile("(\\w+)-(\\w+)-(\\w+)");
			Matcher matcher = quad.matcher(triple);

			if (matcher.matches()) {
				cpu = matcher.group(1);
				manufacturer = matcher.group(2);
				operatingSystem = matcher.group(3) + "-" + matcher.group(4);
				return;
			}

			matcher = trip.matcher(triple);
			if (matcher.matches()) {
				cpu = matcher.group(1);
				manufacturer = "unknown";
				operatingSystem = matcher.group(2) + "-" + matcher.group(3);
				return;
			}

			throw new UsageError("Invalid target triple: \"" + triple + "\"");
		}

		/** Get CPU string. */
		public String getCpu() {
			return cpu;
		}

		/** Get instruction set architecture. */
		public String getIsa() {
			if (cpu.equals("i386") || cpu.equals("i486") || cpu.equals("i586") || cpu.equals("i686"))
				return "ia32";
			return cpu;
		}

		@Override
		public String toString() {
			if (manufacturer.equals("unknown"))
				return cpu + "-" + operatingSystem;
			return cpu + "-" + manufacturer + "-" + operatingSystem;
		}
	}

	/** Decides whether compiler outputs FIRM graphs. */
	private boolean dumpFirmGraphs = false;
	private static final String firmNativeTypesFilename = "firmNativeTypes.conf";
	private String nativeTypesConfigPath = null;
	private TargetTriple target = null;
	private boolean useSoftFloat = false;
	private boolean assembleAndLink = true;

	/** constructor */
	public CompilerOptions(ExtensionInfo extension) {
		super(extension);
		try {
			setHostMachineTriple();
		} catch (Exception err) {
			throw new RuntimeException(err.getCause());
		}
	}

	private void setHostMachineTriple() throws IOException, UsageError {
		Process p = Runtime.getRuntime().exec("gcc -dumpmachine");
		BufferedReader stdOut = new BufferedReader(new InputStreamReader(p.getInputStream()));
		String output = stdOut.readLine();
		if (output == null)
			throw new RuntimeException("Failed to determine host architecture");
		target = new TargetTriple(output);
		stdOut.close();
	}

	/**
	 * @return True if the firm graphs should be dumped
	 */
	public boolean isDumpFirmGraphs() {
		return dumpFirmGraphs;
	}

	/**
	 * @return The full filename of the firm native types configuration file
	 */
	public String getFirmNativeTypesFilename() {
		assert nativeTypesConfigPath != null : "Path to native types config not initialized";
		return nativeTypesConfigPath + "/" + target + "/" + firmNativeTypesFilename;
	}

	/**
	 * @return The target triple.
	 */
	public TargetTriple getTargetTriple() {
		return target;
	}

	/**
	 * @return Returns whether software floating point should be used or not.
	 */
	public boolean useSoftFloat() {
		return useSoftFloat;
	}

	/**
	 * @return Returns whether generated assembly file should be assembled and linked.
	 */
	public boolean assembleAndLink() {
		return assembleAndLink;
	}

	private static void backendOption(String option) {
		FirmGenerated.initializeFirm();
		Backend.option(option);
	}

	@Override
	protected int parseCommand(String args[], int index, Set<String> source)
			throws UsageError, Main.TerminationException {
		int i = super.parseCommand(args, index, source);
		if (i != index)
			return i;

		if (args[i].startsWith("-b")) {
			try {
				backendOption(args[i].substring(2));
			} catch (IllegalArgumentException e) {
				throw new UsageError(String.format(
						"Invalid backend argument '%s'", args[i]));
			}
			return index + 1;
		} else if (args[i].startsWith("-target=") || args[i].startsWith("-mtarget=")) {
			target = new TargetTriple(args[i].substring(args[i].indexOf('=') + 1));
			backendOption("isa=" + target.getIsa());
			if (target.getIsa().equals("ia32"))
				backendOption("ia32-arch=" + target.getCpu());
			return index + 1;
		} else if (args[i].equals("-soft-float") || args[i].equals("-msoft-float")) {
			useSoftFloat = true;
			backendOption(target.getIsa() + "-fpunit=softfloat");
			return index + 1;
		} else if (args[i].equals("-dumpgraphs")) {
			dumpFirmGraphs = true;
			return index + 1;
		} else if (args[i].equals("-nativeTypesConfigPath")) {
			nativeTypesConfigPath = args[i+1];
			return index + 2;
		} else if (args[i].equals("-S")) {
			assembleAndLink = false;
			return index + 1;
		}

		return index;
	}

	/**
	 * Print usage information
	 */
	@Override
	public void usage(PrintStream out) {
		super.usage(out);
		usageForFlag(out, "-mtarget=TARGET",
				"Specify target architecture as machine-manufacturer-OS triple.");
		usageForFlag(out, "-msoft-float",
				"Use soft float.");
		usageForFlag(out, "-b<flag>",
				"Set firm backend options (use -bhelp for additional help)");
		usageForFlag(out, "-dumpgraphs",
				"Dump FIRM graphs");
		usageForFlag(out, "-nativeTypesConfigPath <pathname>",
				"Path to the firm native types configuration files");
		usageForFlag(out, "-S",
				"Do not assemble and link; keep .s files");
	}
}
