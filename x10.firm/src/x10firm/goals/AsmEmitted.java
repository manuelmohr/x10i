package x10firm.goals;

import java.io.File;
import java.io.IOException;

import com.sun.jna.LastErrorException;

import firm.Backend;
import firm.Dump;
import firm.Graph;
import firm.Program;
import firm.bindings.binding_irgopt;
import firm.bindings.binding_iroptimize;
import polyglot.frontend.AbstractGoal_c;
import x10firm.CompilerOptions;

/**
 * Assembler emission goal.
 */
public class AsmEmitted extends AbstractGoal_c {
	private final File output;

	private static final String COMPILATION_UNIT_NAME = "x10program";

	/** Constructs a new AsmEmitted goal. */
	public AsmEmitted(final File output) {
		super("AsmEmitted");
		this.output = output;
	}

	@Override
	public boolean runTask() {
		final CompilerOptions options =
			(CompilerOptions) scheduler.extensionInfo().getOptions();

		/* make sure all unreachable code is eliminated or the backend
		 * may be confused */
		for (Graph g : Program.getGraphs()) {
			binding_irgopt.optimize_graph_df(g.ptr);
			binding_iroptimize.optimize_cf(g.ptr);
			binding_irgopt.remove_bads(g.ptr);
			if (options.isDumpFirmGraphs()) {
				Dump.dumpGraph(g, "--before-backend");
			}
		}

		/* emit asm */
		try {
			Backend.createAssembler(output.getAbsolutePath(), COMPILATION_UNIT_NAME);
		} catch (LastErrorException e) {
			System.out.println("Closing asm file failed");
			// TODO if we use the LastErrorException magic elsewhere, this error message is misleading
			e.printStackTrace();
			return false;
		} catch (IOException e) {
			System.out.println("Could not create asm file");
			e.printStackTrace();
			return false;
		}

		return true;
	}

	@Override
	public String toString() {
		return name() + " - " + output;
	}
}
