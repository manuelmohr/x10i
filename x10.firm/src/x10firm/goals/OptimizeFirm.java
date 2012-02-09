package x10firm.goals;

import polyglot.frontend.AllBarrierGoal;
import polyglot.frontend.ExtensionInfo;
import polyglot.frontend.Goal;
import polyglot.frontend.Job;
import polyglot.frontend.Scheduler;
import x10firm.CompilerOptions;

import com.sun.jna.Pointer;

import firm.Dump;
import firm.Graph;
import firm.Program;

/**
 * This defines the lowering pass.
 */
public class OptimizeFirm extends AllBarrierGoal {

	private static final int INLINE_THRESHOLD = 0;
	private static final int INLINE_MAXSIZE = 1000;

	/** Constructor */
	public OptimizeFirm(Scheduler scheduler) {
		super("OptimizeFirm", scheduler);
	}

	@Override
	public boolean runTask() {
		final ExtensionInfo info = scheduler.extensionInfo();
		final CompilerOptions options = (CompilerOptions)info.getOptions();

		performAllFirmOptimizations();

		/* Dump the normal firm graph */
		if (options.isDumpFirmGraphs()) {
			for (Graph g : Program.getGraphs()) {
				Dump.dumpGraph(g, "--optimized");
			}
		}

		return true;
	}

	private static void performAllFirmOptimizations() {
		System.out.println("performing firm optimizations");

		intraproceduralOptimizations();
		interproceduralOptimizations();
		intraproceduralOptimizations();

		firm.bindings.binding_iroptimize.garbage_collect_entities();
	}

	/**
	 *
	 */
	private static void intraproceduralOptimizations() {
		for (final Graph graph : Program.getGraphs()) {
			final Pointer irg = graph.ptr;

			/* first some basic control and data flow optimizations */
			firm.bindings.binding_iroptimize.optimize_cf(irg);
			firm.bindings.binding_irgopt.optimize_graph_df(irg);

			/* then some optimizations in random order */
			firm.bindings.binding_iroptimize.scalar_replacement_opt(irg);
			firm.bindings.binding_iroptimize.do_loop_inversion(irg);
			firm.bindings.binding_iroptimize.do_loop_unrolling(irg);
			//firm.bindings.binding_iroptimize.optimize_reassociation(irg); // TODO out of memory
			firm.bindings.binding_iroptimize.place_code(irg);
			//firm.bindings.binding_iroptimize.opt_ldst(irg); // TODO panics
			firm.bindings.binding_iroptimize.fixpoint_vrp(irg);
			firm.bindings.binding_iroptimize.opt_parallelize_mem(irg);
			firm.bindings.binding_iroptimize.dead_node_elimination(irg);
			firm.bindings.binding_iroptimize.opt_frame_irg(irg);
			firm.bindings.binding_iroptimize.opt_if_conv(irg);
			// TODO some cleanup in between?

			/* finally the basic control and data flow optimizations again,
			 * because they "clean up" the program graphs. */
			firm.bindings.binding_iroptimize.optimize_cf(irg);
			firm.bindings.binding_irgopt.optimize_graph_df(irg);
		}
	}

	/**
	 *
	 */
	private static void interproceduralOptimizations() {
		firm.bindings.binding_iroptimize.garbage_collect_entities();
		firm.bindings.binding_iroptimize.opt_tail_recursion();
		firm.bindings.binding_iroptimize.optimize_funccalls();
		firm.bindings.binding_iroptimize.optimize_class_casts();
		firm.bindings.binding_lowering.lower_const_code();
		firm.bindings.binding_iroptimize.inline_functions(INLINE_MAXSIZE, INLINE_THRESHOLD, null);
	}

	@Override
	public Goal prereqForJob(Job job) {
		// TODO Auto-generated method stub
		return null;
	}
}
