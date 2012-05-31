package x10firm;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.List;
import java.util.Set;

import polyglot.frontend.ExtensionInfo;
import polyglot.main.UsageError;
import x10.X10CompilerOptions;
import firm.Backend;

/**
 * Firm-Backend specific commandline option parsing.
 * @author matze
 */
public class CompilerOptions extends X10CompilerOptions {
	/** Decides whether compiler outputs FIRM graphs. */
	private boolean dumpFirmGraphs = false;
	private static final String FIRM_NATIVE_TYPES_FILENAME = "firmNativeTypes.conf";
	private String nativeTypesConfigPath = null;
	private MachineTriple target = null;
	private boolean useSoftFloat = false;
	private boolean assembleAndLink = true;
	private boolean useFirmLibraries = true;
	private boolean linkStatically = false;
	private boolean printCommandline = false;
	private boolean dumpGoalGraph = false;
	private String whiteList = null;
	private List<String> linkerFlags = new ArrayList<String>();

	/** Constructs new CompilerOptions. */
	public CompilerOptions(final ExtensionInfo extension) {
		super(extension);
		try {
			setHostMachineTriple();
		} catch (Exception err) {
			throw new RuntimeException(err.getCause());
		}
	}

	private void setHostMachineTriple() throws IOException, UsageError {
		final Process p = Runtime.getRuntime().exec("gcc -dumpmachine");
		final BufferedReader stdOut = new BufferedReader(new InputStreamReader(p.getInputStream()));
		final String output = stdOut.readLine();
		if (output == null)
			throw new RuntimeException("Failed to determine host architecture");
		target = new MachineTriple(output);
		stdOut.close();
	}

	/**
	 * Returns true if the firm graphs should be dumped.
	 */
	public boolean isDumpFirmGraphs() {
		return dumpFirmGraphs;
	}

	/**
	 * Returns the full filename of the firm native types configuration file.
	 */
	public String getFirmNativeTypesFilename() {
		assert nativeTypesConfigPath != null : "Path to native types config not initialized";
		return nativeTypesConfigPath + "/" + target + "/" + FIRM_NATIVE_TYPES_FILENAME;
	}

	/**
	 * Returns filename of a file containing class whitelist entries
	 */
	public String getWhiteListFile() {
		return whiteList;
	}

	/**
	 * Returns the target triple.
	 */
	public MachineTriple getTargetTriple() {
		return target;
	}

	/**
	 * Returns whether software floating point should be used or not.
	 */
	public boolean useSoftFloat() {
		return useSoftFloat;
	}

	/**
	 * Returns whether generated assembly file should be assembled and linked.
	 */
	public boolean assembleAndLink() {
		return assembleAndLink;
	}

	/**
	 * Returns whether we should use libraries in firm (.ir) format if available.
	 * (This allows inlining of library functions)
	 */
	public boolean useFirmLibraries() {
		return useFirmLibraries;
	}

	/** Returns true if result should be linked statically. */
	public boolean linkStatically() {
		return linkStatically;
	}

	/** Returns true if commandline should be printed when invoking external tools. */
	public boolean printCommandline() {
		return printCommandline;
	}

	/** Returns true if goal graph should be dumped. */
	public boolean dumpGoalGraph() {
		return dumpGoalGraph;
	}

	/** Returns list of additional linker flags. */
	public List<String> getLinkerFlags() {
		return linkerFlags;
	}

	private static void backendOption(final String option) {
		FirmState.initializeFirm();
		Backend.option(option);
	}

	@Override
	protected int parseCommand(final String[] args, final int index,
			final Set<String> source) throws UsageError {
		final String arg0 = args[index];
		if (!arg0.startsWith("-") && (arg0.endsWith(".o") || arg0.endsWith(".a"))) {
			linkerFlags.add(arg0);
			return index + 1;
		}

		final int i = super.parseCommand(args, index, source);
		if (i != index)
			return i;

		final String arg = args[index];
		if (arg.startsWith("-b")) {
			try {
				backendOption(arg.substring(2));
			} catch (IllegalArgumentException e) {
				throw new UsageError(String.format(
						"Invalid backend argument '%s'", arg));
			}
			return index + 1;
		} else if (arg.startsWith("-target=") || arg.startsWith("-mtarget=")) {
			target = new MachineTriple(arg.substring(arg.indexOf('=') + 1));
			backendOption("isa=" + target.getIsa());
			if (target.getIsa().equals("ia32"))
				backendOption("ia32-arch=" + target.getCpu());
			return index + 1;
		} else if (arg.equals("-soft-float") || arg.equals("-msoft-float")) {
			useSoftFloat = true;
			backendOption(target.getIsa() + "-fpunit=softfloat");
			return index + 1;
		} else if (arg.startsWith("-whitelist=")) {
			whiteList = arg.substring(arg.indexOf('=')+1);
			return index + 1;
		} else if (arg.equals("-dumpgraphs")) {
			dumpFirmGraphs = true;
			return index + 1;
		} else if (arg.equals("-dumpgoalgraph")) {
			dumpGoalGraph = true;
			return index + 1;
		} else if (arg.equals("-nativeTypesConfigPath")) {
			nativeTypesConfigPath = args[i + 1];
			return index + 2;
		} else if (arg.equals("-S")) {
			assembleAndLink = false;
			return index + 1;
		} else if (arg.equals("-static")) {
			linkStatically = true;
			return index + 1;
		} else if (arg.equals("-noUseFirmLibraries")) {
			useFirmLibraries = false;
			return index + 1;
		} else if (arg.equals("-showCommandline")) {
			printCommandline = true;
			return index + 1;
		}

		return index;
	}

	/**
	 * Prints usage information.
	 */
	@Override
	public void usage(final PrintStream out) {
		super.usage(out);
		usageForFlag(out, "-mtarget=TARGET",
				"Specify target architecture as machine-manufacturer-OS triple.");
		usageForFlag(out, "-msoft-float",
				"Use soft float.");
		usageForFlag(out, "-b<flag>",
				"Set firm backend options (use -bhelp for additional help)");
		usageForFlag(out, "-dumpgoalgraph",
				"Dump compiler scheduler job graph");
		usageForFlag(out, "-dumpgraphs",
				"Dump FIRM graphs");
		usageForFlag(out, "-nativeTypesConfigPath <pathname>",
				"Path to the firm native types configuration files");
		usageForFlag(out, "-showCommandline",
		        "Print commandline when invoking external tools");
		usageForFlag(out, "-S",
				"Do not assemble and link; keep .s files");
		usageForFlag(out, "-noUseFirmLibraries",
				"Do not load libraries as firm-ir files");
		usageForFlag(out, "-static",
				"link external libraries statically");
	}
}
