package x10firm;

import java.io.PrintStream;
import java.util.Set;

import polyglot.frontend.ExtensionInfo;
import polyglot.main.Main;
import polyglot.main.UsageError;
import x10.X10CompilerOptions;
import firm.Backend;

/**
 * Firm-Backend specific commandline option parsing.
 * @author matze
 */
public class CompilerOptions extends X10CompilerOptions {
	/**
	 * Decides whether compiler outputs FIRM graphs.
	 */
	private boolean dumpFirmGraphs = false;
	
	private String firmNativeTypesFilename = null; 

	/** constructor */
	public CompilerOptions(ExtensionInfo extension) {
		super(extension);
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
		assert firmNativeTypesFilename != null : "firmNativeTypesFilename not initialized";
		return firmNativeTypesFilename;
	}

	@Override
	protected int parseCommand(String args[], int index, Set<String> source)
			throws UsageError, Main.TerminationException {
		int i = super.parseCommand(args, index, source);
		if (i != index)
			return i;

		if (args[i].startsWith("-b")) {
			try {
				Backend.option(args[i].substring(2));
			} catch (IllegalArgumentException e) {
				throw new UsageError(String.format(
						"Invalid backend argument '%s'", args[i]));
			}
			return index + 1;
		}

		if (args[i].equals("-dumpgraphs")) {
			dumpFirmGraphs = true;
			return index + 1;
		} else if(args[i].equals("-firmNativeTypes")) {
			firmNativeTypesFilename = args[i+1]; 
			return index + 2;
		}

		return index;
	}

	/**
	 * Print usage information
	 */
	@Override
	public void usage(PrintStream out) {
		super.usage(out);
		usageForFlag(out, "-b<flag>",
				"Set firm backend options (use -bhelp for additional help)");
		usageForFlag(out, "-dumpgraphs",
				"Dump FIRM graphs");
		usageForFlag(out, "-firmNativeTypes <pathname>", 
				"Path of the firm native types configuration file");
	}
}