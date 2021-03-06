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
import x10firm.FirmTransformations.Transformation;
import x10firm.FirmOptions.FirmOption;
import firm.bindings.binding_irdump;

/**
 * Firm-Backend specific commandline option parsing.
 * @author matze
 */
public class CompilerOptions extends X10CompilerOptions {
	private boolean dumpFirmGraphs = false;
	private boolean dumpTypeGraph = false;
	private static final String FIRM_NATIVE_TYPES_FILENAME = "firmNativeTypes.conf";
	private String nativeTypesConfigPath = null;
	private MachineTriple host = null;
	private MachineTriple target = null;
	private boolean useSoftFloat = false;
	private boolean assembleAndLink = true;
	private boolean useFirmLibraries = true;
	private boolean linkStatically = false;
	private boolean printCommandline = false;
	private boolean dumpGoalGraph = false;
	private String whiteList = null;
	private String linkerScriptPath = null;
	private List<String> linkerObjects = new ArrayList<String>();

	/** Constructs new CompilerOptions. */
	public CompilerOptions(final ExtensionInfo extension) {
		super(extension);
		try {
			setHostMachineTriple();
			target = host;
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
		host = new MachineTriple(output);
		stdOut.close();
	}

	/**
	 * Returns true if type graph should be dumped.
	 */
	public boolean isDumpTypeGraph() {
		return dumpTypeGraph;
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
	 * Returns filename of a file containing class whitelist entries.
	 */
	public String getWhiteListFile() {
		return whiteList;
	}

	/**
	 * Returns the host machine triple.
	 */
	public MachineTriple getHostTriple() {
		return host;
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

	/** Returns path to custom linker script, if specified, or null. */
	public String getLinkerScriptPath() {
		return linkerScriptPath;
	}

	/** Returns list of additional linker objects. */
	public List<String> getLinkerObjects() {
		return linkerObjects;
	}

	private void setupBackend() {
		if (target.getIsa().equals("ia32"))
			FirmState.backendOption("ia32-arch=" + target.getCpu());
	}

	@Override
	protected int parseCommand(final String[] args, final int index,
			final Set<String> source) throws UsageError {
		final String arg0 = args[index];
		if (!arg0.startsWith("-") && (arg0.endsWith(".o") || arg0.endsWith(".a"))) {
			linkerObjects.add(arg0);
			return index + 1;
		}

		final int i = super.parseCommand(args, index, source);
		if (i != index)
			return i;

		final String arg = args[index];
		if (arg.startsWith("-b")) {
			try {
				FirmState.backendOption(arg.substring(2));
			} catch (IllegalArgumentException e) {
				throw new UsageError(String.format(
						"Invalid backend argument '%s'", arg));
			}
			return index + 1;
		} else if (arg.startsWith("-f")) {
			if (arg.length() == 2) {
				if (!FirmOptions.setOption(args[index + 1]))
					throw new UsageError(String.format(
							"Invalid firm option '%s'", args[index + 1]));
				return index + 2;
			}

			if (!FirmOptions.setOption(arg.substring(2)))
				throw new UsageError(String.format(
						"Invalid firm option '%s'", arg));
			return index + 1;
		} else if (arg.startsWith("-O")) {
			final String optLevel = arg.substring(2);
			FirmOptions.chooseOptimizationPack(Integer.parseInt(optLevel));
			return index + 1;
		} else if (arg.startsWith("-target=") || arg.startsWith("-mtarget=")) {
			target = new MachineTriple(arg.substring(arg.indexOf('=') + 1));
			setupBackend();
			return index + 1;
		} else if (arg.equals("-m32")) {
			final String cpu64 = "x86_64";
			if (target.getCpu().equals(cpu64)) {
				final String tgt = "i686" + target.toString().substring(cpu64.length());
				target = new MachineTriple(tgt);
				setupBackend();
			}
			return index + 1;
		} else if (arg.equals("-soft-float") || arg.equals("-msoft-float")) {
			useSoftFloat = true;
			FirmState.backendOption(target.getIsa() + "-fpunit=softfloat");
			return index + 1;
		} else if (arg.startsWith("-whitelist=")) {
			whiteList = arg.substring(arg.indexOf('=') + 1);
			return index + 1;
		} else if (arg.equals("-dumpgraphs")) {
			dumpFirmGraphs = true;
			return index + 1;
		} else if (arg.startsWith("-dumpfilter=")) {
			final String filter = arg.substring(arg.indexOf('=') + 1);
			binding_irdump.ir_set_dump_filter(filter);
			dumpFirmGraphs = true; // User probably wants this
			return index + 1;
		} else if (arg.equals("-dumptypes")) {
			dumpTypeGraph = true;
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
		} else if (arg.equals("-V")) {
			printCommandline = true;
			return index + 1;
		} else if (arg.equals("-linkerScript")) {
			linkerScriptPath = args[i + 1];
			return index + 2;
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
		usageForFlag(out, "-O<n>",
				"Set optimization level");
		usageForFlag(out, "-f<flag>",
				"Set firm options");
		usageForFlag(out, "-dumpgoalgraph",
				"Dump compiler scheduler job graph");
		usageForFlag(out, "-dumptypes",
				"Dump type graphs");
		usageForFlag(out, "-dumpgraphs",
				"Dump all FIRM graphs");
		usageForFlag(out, "-dumpfilter=<pattern>",
				"Dump only FIRM graphs whose name matches regular expression <pattern>");
		usageForFlag(out, "-nativeTypesConfigPath <pathname>",
				"Path to the firm native types configuration files");
		usageForFlag(out, "-V",
		        "Print commandline when invoking external tools");
		usageForFlag(out, "-S",
				"Do not assemble and link; keep .s files");
		usageForFlag(out, "-noUseFirmLibraries",
				"Do not load libraries as firm-ir files");
		usageForFlag(out, "-static",
				"link external libraries statically");
		usageForFlag(out, "-linkerScript",
				"Use custom linker script");
		usageForFlag(out, "-whitelist=<whitelistfile>",
		        "Path to file with standard library class whitelist");

		for (FirmOption option : FirmOptions.getKnownOptions().values()) {
			usageForFlag(out, "-f " + option.getName(), option.getDescription());
		}
		for (Transformation opt : FirmTransformations.getOptimizations().values()) {
			if (opt.isHidden())
				continue;

			usageForFlag(out, "-f " + opt.getName(), "enable " + opt.getDescription());
			usageForFlag(out, "-f no-" + opt.getName(), "disable " + opt.getDescription());
		}
	}
}
