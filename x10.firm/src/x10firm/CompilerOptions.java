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
	 * name for the resulting executable
	 */
	public String exe_name = "a.out";

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

		if (args[i].startsWith("-o")) {
			exe_name = args[i+1];
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
		usageForFlag(out, "-bflag",
				"set firm backend option (use -bhelp for additional help)");
	}

	/**
	 * Override usage info for the -post flag.
	 *
	 * @see polyglot.main.Options#usageForFlag(java.io.PrintStream,
	 *      java.lang.String, java.lang.String)
	 */
	@Override
	protected void usageForFlag(PrintStream out, String flag, String description) {
		if (flag.startsWith("-b")) {
			super.usageForFlag(out, "-b<flag>", "pass option to firm backend.  ");
			return;
		}
		super.usageForFlag(out, flag, description);
	}
}
