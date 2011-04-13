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
	public boolean dump_firm_graphs = false;

	/** constructor */
	public CompilerOptions(ExtensionInfo extension) {
		super(extension);
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
			dump_firm_graphs = true;
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
		usageForFlag(out, "-b<flag>",
				"Set firm backend options (use -bhelp for additional help)");
		usageForFlag(out, "-dumpgraphs",
				"Dump FIRM graphs");
	}
}
