package x10firm.goals;

import polyglot.frontend.AllBarrierGoal;
import polyglot.frontend.ExtensionInfo;
import polyglot.frontend.Goal;
import polyglot.frontend.Job;
import polyglot.frontend.Scheduler;
import x10firm.CompilerOptions;
import x10firm.FirmOptions;
import x10firm.FirmTransformations;
import firm.Dump;
import firm.Graph;
import firm.Program;
import firm.bindings.binding_irarch;
import firm.bindings.binding_irarch.arch_dep_opts_t;
import firm.bindings.binding_irflag;
import firm.bindings.binding_irgraph.ir_graph_constraints_t;

/**
 * This defines the lowering pass.
 */
public class FirmTransform extends AllBarrierGoal {
	private CompilerOptions options;

	/** Constructs a new LoweringFirm goal. */
	public FirmTransform(final Scheduler scheduler) {
		super("FirmTransform", scheduler);
	}

	private boolean optimize(final Graph graph, final String name) {
		final boolean result = FirmTransformations.getOptimization(name).perform(graph);
		if (options.isDumpFirmGraphs())
			Dump.dumpGraph(graph, "-" + name);
		return result;
	}

	private boolean optimize(final String name) {
		final boolean result = FirmTransformations.getOptimization(name).perform(null);
		if (options.isDumpFirmGraphs()) {
			for (Graph graph : Program.getGraphs()) {
				Dump.dumpGraph(graph, "-" + name);
			}
		}
		return result;
	}

	@Override
	public boolean runTask() {
		final ExtensionInfo info = scheduler.extensionInfo();
		options = (CompilerOptions)info.getOptions();

		if (options.x10_config.ONLY_TYPE_CHECKING)
			return true;

		binding_irflag.set_opt_alias_analysis(FirmOptions.isAliasAnalysis() ? 1 : 0);

		if (FirmTransformations.getOptimization("confirm").isEnabled())
			FirmTransformations.getOptimization("remove-confirms").enable();

		/* osr supersedes remove_phi_cycles */
		if (FirmTransformations.getOptimization("ivopts").isEnabled())
			FirmTransformations.getOptimization("remove-phi-cycles").disable();

		// TODO: for some unknown reason, remove-unused removes too much stuff when called
		// before lower-oo
		//optimize("remove-unused");

		/* first step: kill dead code */
		for (final Graph graph : Program.getGraphs()) {
			optimize(graph, "combo");
			optimize(graph, "local");
			optimize(graph, "control-flow");
		}
		optimize("lower-oo");
		optimize("lower-sels");

		optimize("remove-unused");
		for (final Graph graph : Program.getGraphs()) {
			optimize(graph, "opt-tail-rec");
		}
		optimize("opt-func-call");
		optimize("lower-const");

		for (final Graph graph : Program.getGraphs()) {
			optimize(graph, "scalar-replace");
			optimize(graph, "invert-loops");
			optimize(graph, "unroll-loops");
			optimize(graph, "local");
			optimize(graph, "reassociation");
			optimize(graph, "local");
			optimize(graph, "gcse");
			optimize(graph, "place");

			if (FirmTransformations.getOptimization("confirm").isEnabled()) {
				/* Confirm construction currently can only handle blocks with only
				   one control flow predecessor. Calling optimize_cf here removes
				   Bad predecessors and help the optimization of switch constructs.
				 */
				optimize(graph, "control-flow");
				optimize(graph, "confirm");
				optimize(graph, "local");
			}

			optimize(graph, "control-flow");
			optimize(graph, "opt-load-store");
			optimize(graph, "deconv");
			optimize(graph, "thread-jumps");
			optimize(graph, "remove-confirms");
			optimize(graph, "gvn-pre");
			optimize(graph, "gcse");
			optimize(graph, "control-flow");

			if (optimize(graph, "if-conversion")) {
				optimize(graph, "local");
				optimize(graph, "control-flow");
			}
			/* this doesn't make too much sense but tests the mux destruction... */
			optimize(graph, "lower-mux");

			optimize(graph, "bool");
			optimize(graph, "shape-blocks");
			optimize(graph, "ivopts");
			optimize(graph, "local");
			optimize(graph, "dead");
		}

		optimize("inline");
		optimize("opt-proc-clone");

		for (final Graph graph : Program.getGraphs()) {
			optimize(graph, "local");
			optimize(graph, "control-flow");
			optimize(graph, "thread-jumps");
			optimize(graph, "local");
			optimize(graph, "control-flow");
			optimize(graph, "parallelize-mem");
		}

		optimize("remove-unused");

		/* enable architecture dependent optimizations */
		binding_irarch.arch_dep_set_opts(arch_dep_opts_t.arch_dep_mul_to_shift.val
		                                 | arch_dep_opts_t.arch_dep_div_by_const.val
		                                 | arch_dep_opts_t.arch_dep_mod_by_const.val);

		for (final Graph graph : Program.getGraphs()) {
			optimize(graph, "reassociation");
			optimize(graph, "local");
		}
		optimize("target-lowering");

		for (final Graph graph : Program.getGraphs()) {
			optimize(graph, "local");
			optimize(graph, "deconv");
			optimize(graph, "control-flow");
			optimize(graph, "opt-load-store");
			optimize(graph, "gcse");
			optimize(graph, "place");
			optimize(graph, "control-flow");

			if (optimize(graph, "if-conversion")) {
				optimize(graph, "local");
				optimize(graph, "control-flow");
			}

			graph.addConstraints(ir_graph_constraints_t.IR_GRAPH_CONSTRAINT_NORMALISATION2);
			optimize(graph, "local");

			optimize(graph, "parallelize-mem");
			optimize(graph, "frame");
		}

		optimize("remove-unused");
		//optimize("opt-cc"); // TODO

		return true;
	}

	@Override
	public Goal prereqForJob(final Job job) {
		if (!scheduler.shouldCompile(job))
			return null;

		return scheduler.End(job);
	}
}
