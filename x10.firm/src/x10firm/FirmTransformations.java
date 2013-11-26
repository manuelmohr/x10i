package x10firm;

import java.util.HashMap;
import java.util.Map;

import com.sun.jna.Pointer;

import firm.Backend;
import firm.Graph;
import firm.GraphBase;
import firm.OO;
import firm.Util;
import firm.bindings.binding_irconsconfirm;
import firm.bindings.binding_irflag;
import firm.bindings.binding_irgopt;
import firm.bindings.binding_iroptimize;
import firm.bindings.binding_lowering;

/**
 * An interface to libFirm's optimization phases.
 *
 * @author julian
 */
public final class FirmTransformations {
	private static final int NONE         = 0;
	private static final int ENABLED      = 1 << 0;
	private static final int NO_DUMP      = 1 << 1;
	private static final int NO_VERIFY    = 1 << 2;
	private static final int HIDE_OPTIONS = 1 << 3;
	private static final int ESSENTIAL    = 1 << 4;
	private static final int IRG_OPT      = 1 << 10;
	private static final int IRP_OPT      = 1 << 11;

	private FirmTransformations() { }

	/**
	 * A firm optimization phase.
	 *
	 * @author julian
	 */
	public abstract static class Transformation {
		private String name;
		private String description;
		private int flags;

		/**
		 * @param name the optimization's name
		 * @param description a short description (will be displayed in help)
		 * @param flags flags, or'ed together from the constants in FirmOptimizations
		 */
		public Transformation(final String name, final String description, final int flags) {
			this.name = name;
			this.description = description;
			this.flags = flags;
		}

		/**
		 * enable the optimization.
		 */
		public void enable() {
			flags |= ENABLED;
			System.out.println("FirmOptimizations: enabling " + name);
		}

		/**
		 * disable the optimization.
		 */
		public void disable() {
			flags &= ~ENABLED;
			System.out.println("FirmOptimizations: disabling " + name);
		}

		/**
		 * @return whether the optimization is enabled.
		 */
		public boolean isEnabled() {
			return (flags & ENABLED) != 0;
		}

		/**
		 * @return whether the optimization is hidden.
		 */
		public boolean isHidden() {
			return (flags & HIDE_OPTIONS) != 0;
		}

		/**
		 * @return the name
		 */
		public String getName() {
			return name;
		}

		/**
		 * @return the description
		 */
		public String getDescription() {
			return description;
		}

		/**
		 * @return the flags
		 */
		public int getFlags() {
			return flags;
		}

		/**
		 * To be overriden with the actual call to the optimization's main method.
		 * @param graph the graph to be optimized.
		 */
		protected abstract void performOptimization(final Graph graph);

		/**
		 * Perform the optimization.
		 *
		 * @param graph the graph to perform the optimization on.
		 * @return true if the optimization was performed (so the graph may be changed), false otherwise.
		 */
		public boolean perform(final Graph graph) {
			if (!isEnabled())
				return false;

			if ((flags & IRG_OPT) != 0) {
				final Graph old = GraphBase.getCurrent();
				GraphBase.setCurrent(graph);
				performOptimization(graph);
				GraphBase.setCurrent(old);
			} else {
				assert graph == null;
				performOptimization(null);
			}

			return true;
		}
	}

	private static final Map<String, Transformation> TRANSFORMATIONS = new HashMap<String, Transformation>();
	static {
		TRANSFORMATIONS.put("bool", new Transformation("bool", "bool simplification", NONE | IRG_OPT) {
			@Override
			protected void performOptimization(final Graph graph) {
				binding_iroptimize.opt_bool(graph.ptr);
			}
		});
		TRANSFORMATIONS.put("combo", new Transformation("combo", "combined CCE, UCE and GVN", NONE | IRG_OPT) {
			@Override
			protected void performOptimization(final Graph graph) {
				binding_iroptimize.combo(graph.ptr);
			}
		});
		TRANSFORMATIONS.put("confirm", new Transformation("confirm", "confirm optimization", HIDE_OPTIONS | IRG_OPT) {
			@Override
			protected void performOptimization(final Graph graph) {
				binding_irconsconfirm.construct_confirms(graph.ptr);
			}
		});
		TRANSFORMATIONS.put("control-flow", new Transformation("control-flow", "optimization of control-flow",
				HIDE_OPTIONS | IRG_OPT) {
			@Override
			protected void performOptimization(final Graph graph) {
				binding_iroptimize.optimize_cf(graph.ptr);
			}
		});
		TRANSFORMATIONS.put("dead", new Transformation("dead", "dead node elimination",
				HIDE_OPTIONS | NO_DUMP | IRG_OPT) {
			@Override
			protected void performOptimization(final Graph graph) {
				binding_iroptimize.dead_node_elimination(graph.ptr);
			}
		});
		TRANSFORMATIONS.put("deconv", new Transformation("deconv", "conv node elimination", NONE | IRG_OPT) {
			@Override
			protected void performOptimization(final Graph graph) {
				binding_iroptimize.conv_opt(graph.ptr);
			}
		});
		TRANSFORMATIONS.put("fp-vrp", new Transformation("fp-vrp", "fixpoint value range propagation", NONE | IRG_OPT) {
			@Override
			protected void performOptimization(final Graph graph) {
				binding_iroptimize.fixpoint_vrp(graph.ptr);
			}
		});
		TRANSFORMATIONS.put("frame", new Transformation("frame", "remove unused frame entities", NONE | IRG_OPT) {
			@Override
			protected void performOptimization(final Graph graph) {
				binding_iroptimize.opt_frame_irg(graph.ptr);
			}
		});
		TRANSFORMATIONS.put("gvn-pre", new Transformation("gvn-pre",
				"global value numbering partial redundancy elimination", NONE | IRG_OPT) {
			@Override
			protected void performOptimization(final Graph graph) {
				binding_iroptimize.do_gvn_pre(graph.ptr);
			}
		});
		TRANSFORMATIONS.put("if-conversion", new Transformation("if-conversion", "if-conversion", NONE | IRG_OPT) {
			@Override
			protected void performOptimization(final Graph graph) {
				binding_iroptimize.opt_if_conv(graph.ptr);
			}
		});
		TRANSFORMATIONS.put("invert-loops", new Transformation("invert-loops", "loop inversion", NONE | IRG_OPT) {
			@Override
			protected void performOptimization(final Graph graph) {
				binding_iroptimize.do_loop_inversion(graph.ptr);
			}
		});
		TRANSFORMATIONS.put("ivopts", new Transformation("ivopts", "induction variable strength reduction",
				NONE | IRG_OPT) {
			@Override
			protected void performOptimization(final Graph graph) {
				binding_iroptimize.opt_osr(graph.ptr,
						  binding_iroptimize.osr_flags.osr_flag_lftr_with_ov_check.val
						| binding_iroptimize.osr_flags.osr_flag_keep_reg_pressure.val
						| binding_iroptimize.osr_flags.osr_flag_ignore_x86_shift.val);
			}
		});
		TRANSFORMATIONS.put("local", new Transformation("local", "local graph optimizations", HIDE_OPTIONS | IRG_OPT) {
			@Override
			protected void performOptimization(final Graph graph) {
				binding_irgopt.local_opts(graph.ptr);
			}
		});
		TRANSFORMATIONS.put("lower-mux", new Transformation("lower-mux", "mux lowering", NONE | IRG_OPT) {
			@Override
			protected void performOptimization(final Graph graph) {
				binding_lowering.lower_mux(graph.ptr, Pointer.NULL);
			}
		});
		TRANSFORMATIONS.put("opt-load-store", new Transformation("opt-load-store", "load store optimization",
				NONE | IRG_OPT) {
			@Override
			protected void performOptimization(final Graph graph) {
				binding_iroptimize.optimize_load_store(graph.ptr);
			}
		});
		TRANSFORMATIONS.put("opt-tail-rec", new Transformation("opt-tail-rec", "tail-recursion eliminiation",
				NONE | IRG_OPT) {
			@Override
			protected void performOptimization(final Graph graph) {
				binding_iroptimize.opt_tail_rec_irg(graph.ptr);
			}
		});
		TRANSFORMATIONS.put("parallelize-mem", new Transformation("parallelize-mem", "parallelize memory",
				NONE | IRG_OPT) {
			@Override
			protected void performOptimization(final Graph graph) {
				binding_iroptimize.opt_parallelize_mem(graph.ptr);
			}
		});
		TRANSFORMATIONS.put("gcse", new Transformation("gcse", "global common subexpression eliminiation",
				NONE | IRG_OPT) {
			@Override
			protected void performOptimization(final Graph graph) {
				binding_irflag.set_opt_global_cse(1);
				binding_irgopt.optimize_graph_df(graph.ptr);
				binding_irflag.set_opt_global_cse(0);
			}
		});
		TRANSFORMATIONS.put("place", new Transformation("place", "code placement", NONE | IRG_OPT) {
			@Override
			protected void performOptimization(final Graph graph) {
				binding_iroptimize.place_code(graph.ptr);
			}
		});
		TRANSFORMATIONS.put("reassociation", new Transformation("reassociation", "reassociation", NONE | IRG_OPT) {
			@Override
			protected void performOptimization(final Graph graph) {
				binding_iroptimize.optimize_reassociation(graph.ptr);
			}
		});
		TRANSFORMATIONS.put("remove-confirms", new Transformation("remove-confirms", "confirm removal",
				HIDE_OPTIONS | NO_DUMP | NO_VERIFY | IRG_OPT) {
			@Override
			protected void performOptimization(final Graph graph) {
				binding_irconsconfirm.remove_confirms(graph.ptr);
			}
		});
		TRANSFORMATIONS.put("remove-phi-cycles", new Transformation("remove-phi-cycles", "removal of phi cycles",
				HIDE_OPTIONS | IRG_OPT) {
			@Override
			protected void performOptimization(final Graph graph) {
				binding_iroptimize.remove_phi_cycles(graph.ptr);
			}
		});
		TRANSFORMATIONS.put("scalar-replace", new Transformation("scalar-replace", "scalar replacement",
				NONE | IRG_OPT) {
			@Override
			protected void performOptimization(final Graph graph) {
				binding_iroptimize.scalar_replacement_opt(graph.ptr);
			}
		});
		TRANSFORMATIONS.put("shape-blocks", new Transformation("shape-blocks", "block shaping", NONE | IRG_OPT) {
			@Override
			protected void performOptimization(final Graph graph) {
				binding_iroptimize.shape_blocks(graph.ptr);
			}
		});
		TRANSFORMATIONS.put("thread-jumps", new Transformation("thread-jumps", "path-sensitive jumpthreading",
				NONE | IRG_OPT) {
			@Override
			protected void performOptimization(final Graph graph) {
				binding_iroptimize.opt_jumpthreading(graph.ptr);
			}
		});
		TRANSFORMATIONS.put("unroll-loops", new Transformation("unroll-loops", "loop unrolling", NONE | IRG_OPT) {
			@Override
			protected void performOptimization(final Graph graph) {
				binding_iroptimize.do_loop_unrolling(graph.ptr);
			}
		});
		TRANSFORMATIONS.put("inline", new Transformation("inline", "inlining", NONE | IRP_OPT) {
			@Override
			protected void performOptimization(final Graph graph) {
				binding_iroptimize.inline_functions(
						FirmOptions.getInlineMaxsize(),
						FirmOptions.getInlineThreshold(),
						Pointer.NULL);
			}
		});
		TRANSFORMATIONS.put("lower-const", new Transformation("lower-const", "lowering of constant code",
				HIDE_OPTIONS | NO_DUMP | ESSENTIAL | IRP_OPT) {
			@Override
			protected void performOptimization(final Graph graph) {
				binding_lowering.lower_const_code();
			}
		});
		TRANSFORMATIONS.put("opt-func-call", new Transformation("opt-func-call", "function call optimization",
				NONE | IRP_OPT) {
			@Override
			protected void performOptimization(final Graph graph) {
				binding_iroptimize.optimize_funccalls();
			}
		});
		TRANSFORMATIONS.put("opt-proc-clone", new Transformation("opt-proc-clone", "procedure cloning",
				NONE | IRP_OPT) {
			@Override
			protected void performOptimization(final Graph graph) {
				binding_iroptimize.proc_cloning(FirmOptions.getCloneThreshold());
			}
		});
		TRANSFORMATIONS.put("remove-unused", new Transformation("remove-unused",
				"removal of unused functions/variables", NO_DUMP | NO_VERIFY | IRP_OPT) {
			@Override
			protected void performOptimization(final Graph graph) {
				binding_iroptimize.garbage_collect_entities();
			}
		});
		TRANSFORMATIONS.put("lower-oo", new Transformation("lower-oo",
				"lowering of object orientation features", IRP_OPT | ESSENTIAL) {
			@Override
			protected void performOptimization(final Graph graph) {
				OO.lowerProgram();
			}
		});
		TRANSFORMATIONS.put("lower-sels",  new Transformation("lower-sels",
				"replace Sel with address arithmetic", IRP_OPT | ESSENTIAL) {
			@Override
			protected void performOptimization(final Graph graph) {
				Util.lowerSels();
			}
		});
		TRANSFORMATIONS.put("target-lowering", new Transformation("target-lowering",
				"lower for target architecture", IRP_OPT | ESSENTIAL) {
			@Override
			protected void performOptimization(final Graph graph) {
				Backend.lowerForTarget();
			}
		});
		TRANSFORMATIONS.put("opt-cc", new Transformation("opt-cc",
				"optimize calling convention for private functions", IRP_OPT) {
			@Override
			protected void performOptimization(final Graph graph) {
				// TODO
				//binding_irmemory.mark_private_methods();
			}
		});

		enableSafeDefaults();
	}

	private static void enableSafeDefaults() {
		getOptimization("remove-unused").enable();
		getOptimization("opt-tail-rec").enable();
		getOptimization("control-flow").enable();
		getOptimization("local").enable();
		getOptimization("lower-const").enable();
		getOptimization("scalar-replace").enable();
		getOptimization("dead").enable();
		getOptimization("remove-phi-cycles").enable();
		getOptimization("frame").enable();
		getOptimization("lower-oo").enable();
		getOptimization("lower-sels").enable();
		getOptimization("target-lowering").enable();
		getOptimization("opt-load-store").enable();
	}

	/**
	 * Disables all but the essential optimizations.
	 */
	public static void disableAllOptimizations() {
		for (Transformation opt : TRANSFORMATIONS.values()) {
			if ((opt.getFlags() & ESSENTIAL) != 0) {
				opt.enable();
			} else {
				opt.disable();
			}
		}
	}

	/**
	 * Gets the object representing the optimization by name.
	 * @param name optimization name
	 * @return the optimization object
	 */
	public static Transformation getOptimization(final String name) {
		return TRANSFORMATIONS.get(name);
	}

	/**
	 * @return the map of all known optimizations.
	 */
	public static Map<String, Transformation> getOptimizations() {
		return TRANSFORMATIONS;
	}
}
