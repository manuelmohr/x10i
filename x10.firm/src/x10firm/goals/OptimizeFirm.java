package x10firm.goals;

import polyglot.frontend.AbstractGoal_c;
import polyglot.frontend.ExtensionInfo;
import x10firm.CompilerOptions;
import x10firm.FirmOptimizations;
import x10firm.FirmOptions;

import com.sun.jna.Pointer;

import firm.Dump;
import firm.Graph;
import firm.Program;
import firm.bindings.binding_irflag;

/**
 * This defines the lowering pass.
 */
public class OptimizeFirm extends AbstractGoal_c {

	/** Constructs a new OptimizeFirm goal. */
	public OptimizeFirm() {
		super("OptimizeFirm");
	}

	@Override
	public boolean runTask() {
		final ExtensionInfo info = scheduler.extensionInfo();
		final CompilerOptions options = (CompilerOptions)info.getOptions();

		performFirmOptimizations();

		/* Dump the normal firm graph */
		if (options.isDumpFirmGraphs()) {
			for (final Graph g : Program.getGraphs()) {
				Dump.dumpGraph(g, "--optimized");
			}
		}

		return true;
	}
	
	private static boolean optimize(final Pointer irg, String name) {
		return FirmOptimizations.getOptimization(name).perform(irg);
	}
	private static boolean optimize(String name) {
		return optimize(Pointer.NULL, name);
	}
	
	private static void performFirmOptimizations() {

		binding_irflag.set_opt_alias_analysis(FirmOptions.aliasAnalysis ? 1 : 0);
		
		// XXX: missing bindings for changing the alias model.
//		int aa_opt = ???.ir_disambuigator_options.aa_opt_no_opt.val;
//		if (FirmOptions.strictAlias)
//			aa_opt |= ???.ir_disambuigator_options.aa_opt_type_based.val 
//			       |  ???.ir_disambuigator_options.aa_opt_byte_type_may_alias.val;
//		if (FirmOptions.noAlias)
//			aa_opt = ???.ir_disambuigator_options.aa_opt_no_alias.val;
//		
//		???.set_irp_memory_disambiguator_options(aa_opt);
		
		if (FirmOptimizations.getOptimization("confirm").isEnabled())
			FirmOptimizations.getOptimization("remove-confirms").enable(); 

		/* osr supersedes remove_phi_cycles */
		if (FirmOptimizations.getOptimization("ivopts").isEnabled())
			FirmOptimizations.getOptimization("remove-phi-cycles").disable();

		// doOpt("rts"); // optimization NYI

		/* first step: kill dead code */
		for (final Graph graph : Program.getGraphs()) {
			final Pointer irg = graph.ptr;
			optimize(irg, "combo");
			optimize(irg, "local");
			optimize(irg, "control-flow");
		}

		optimize("remove-unused");
		for (final Graph graph : Program.getGraphs()) {
			final Pointer irg = graph.ptr;
			optimize(irg, "opt-tail-rec");
		}
		optimize("opt-func-call");
		optimize("lower-const");

		for (final Graph graph : Program.getGraphs()) {
			final Pointer irg = graph.ptr;

			optimize(irg, "scalar-replace");
			optimize(irg, "invert-loops");
			optimize(irg, "unroll-loops");
			optimize(irg, "local");
			optimize(irg, "reassociation");
			optimize(irg, "local");
			optimize(irg, "gcse");
			optimize(irg, "place");

			if (FirmOptimizations.getOptimization("confirm").isEnabled()) {
				/* Confirm construction currently can only handle blocks with only
				   one control flow predecessor. Calling optimize_cf here removes
				   Bad predecessors and help the optimization of switch constructs.
				 */
				optimize(irg, "control-flow");
				optimize(irg, "confirm");
				// optimize(irg, "vrp"); // optimization NYI.
				optimize(irg, "local");
			}

			optimize(irg, "control-flow");
			optimize(irg, "opt-load-store");
			optimize(irg, "fp-vrp");
			optimize(irg, "lower"); // the highlevel lowering was already done.
			optimize(irg, "deconv");
			optimize(irg, "thread-jumps");
			optimize(irg, "remove-confirms");
			optimize(irg, "gvn-pre");
			optimize(irg, "gcse");
			optimize(irg, "place");
			optimize(irg, "control-flow");

			if (optimize(irg, "if-conversion")) {
				optimize(irg, "local");
				optimize(irg, "control-flow");
			}
			/* this doesn't make too much sense but tests the mux destruction... */
			optimize(irg, "lower-mux");

			optimize(irg, "bool");
			optimize(irg, "shape-blocks");
			optimize(irg, "ivopts");
			optimize(irg, "local");
			optimize(irg, "dead");
		}

		optimize("inline");
		optimize("opt-proc-clone");

		for (final Graph graph : Program.getGraphs()) {
			final Pointer irg = graph.ptr;
			optimize(irg, "local");
			optimize(irg, "control-flow");
			optimize(irg, "thread-jumps");
			optimize(irg, "local");
			optimize(irg, "control-flow");

			// vrp optimization NYI.
//			if( optimize(irg, "vrp") ) { // if vrp is enabled
//				optimize(irg, "local");
//				optimize(irg, "vrp");
//				optimize(irg, "local");
//				optimize(irg, "vrp");
//			}
		}
		// XXX: stats and dumping missing
		// XXX: cparser: a function called do_firm_lower is called afterwards, where some additonal opts are run.
	}
}
