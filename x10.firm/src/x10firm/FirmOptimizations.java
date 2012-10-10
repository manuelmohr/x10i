package x10firm;

import java.util.HashMap;
import java.util.Map;

import com.sun.jna.Pointer;

import firm.Backend;
import firm.bindings.binding_ircons;
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
public final class FirmOptimizations {
	private static final int NONE         = 0;
	private static final int ENABLED      = 1 << 0;
	private static final int NO_DUMP      = 1 << 1;
	private static final int NO_VERIFY    = 1 << 2;
	private static final int HIDE_OPTIONS = 1 << 3;
	private static final int ESSENTIAL    = 1 << 4;
	private static final int IRG_OPT      = 1 << 10;
	private static final int IRP_OPT      = 1 << 11;

	private FirmOptimizations() { }

	/**
	 * A firm optimization phase.
	 *
	 * @author julian
	 */
	public abstract static class FirmOptimization {
		private String name;
		private String description;
		private int flags;

		/**
		 * @param name the optimization's name
		 * @param description a short description (will be displayed in help)
		 * @param flags flags, or'ed together from the constants in FirmOptimizations
		 */
		public FirmOptimization(final String name, final String description, final int flags) {
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
		 * @param irg the graph to be optimized.
		 */
		protected abstract void performOptimization(final Pointer irg);

		/**
		 * Perform the optimization.
		 *
		 * @param irg the graph to perform the optimization on.
		 * @return true if the optimization was performed (so the graph may be changed), false otherwise.
		 */
		public boolean perform(final Pointer irg) {
			if (!isEnabled())
				return false;

			final Pointer oldIrg;
			if ((flags & IRG_OPT) != 0) {
				oldIrg = binding_ircons.get_current_ir_graph();
				binding_ircons.set_current_ir_graph(irg);
				performOptimization(irg);
				binding_ircons.set_current_ir_graph(oldIrg);
			} else {
				performOptimization(null);
			}
			
			return true;
		}
	}

	private static final Map<String, FirmOptimization> OPTIMIZATIONS = new HashMap<String, FirmOptimization>();
	static {
		OPTIMIZATIONS.put("bool", new FirmOptimization("bool", "bool simplification", NONE | IRG_OPT) {
			@Override
			protected void performOptimization(final Pointer irg) {
				binding_iroptimize.opt_bool(irg);
			}
		});
		OPTIMIZATIONS.put("combo", new FirmOptimization("combo", "combined CCE, UCE and GVN", NONE | IRG_OPT) {
			@Override
			protected void performOptimization(final Pointer irg) {
				binding_iroptimize.combo(irg);
			}
		});
		OPTIMIZATIONS.put("confirm", new FirmOptimization("confirm", "confirm optimization", HIDE_OPTIONS | IRG_OPT) {
			@Override
			protected void performOptimization(final Pointer irg) {
				binding_irconsconfirm.construct_confirms(irg);
			}
		});
		OPTIMIZATIONS.put("control-flow", new FirmOptimization("control-flow", "optimization of control-flow",
				HIDE_OPTIONS | IRG_OPT) {
			@Override
			protected void performOptimization(final Pointer irg) {
				binding_iroptimize.optimize_cf(irg);
			}
		});
		OPTIMIZATIONS.put("dead", new FirmOptimization("dead", "dead node elimination",
				HIDE_OPTIONS | NO_DUMP | IRG_OPT) {
			@Override
			protected void performOptimization(final Pointer irg) {
				binding_iroptimize.dead_node_elimination(irg);
			}
		});
		OPTIMIZATIONS.put("deconv", new FirmOptimization("deconv", "conv node elimination", NONE | IRG_OPT) {
			@Override
			protected void performOptimization(final Pointer irg) {
				binding_iroptimize.conv_opt(irg);
			}
		});
		OPTIMIZATIONS.put("fp-vrp", new FirmOptimization("fp-vrp", "fixpoint value range propagation", NONE | IRG_OPT) {
			@Override
			protected void performOptimization(final Pointer irg) {
				binding_iroptimize.fixpoint_vrp(irg);
			}
		});
		OPTIMIZATIONS.put("frame", new FirmOptimization("frame", "remove unused frame entities", NONE | IRG_OPT) {
			@Override
			protected void performOptimization(final Pointer irg) {
				binding_iroptimize.opt_frame_irg(irg);
			}
		});
		OPTIMIZATIONS.put("gvn-pre", new FirmOptimization("gvn-pre",
				"global value numbering partial redundancy elimination", NONE | IRG_OPT) {
			@Override
			protected void performOptimization(final Pointer irg) {
				binding_iroptimize.do_gvn_pre(irg);
			}
		});
		OPTIMIZATIONS.put("if-conversion", new FirmOptimization("if-conversion", "if-conversion", NONE | IRG_OPT) {
			@Override
			protected void performOptimization(final Pointer irg) {
				binding_iroptimize.opt_if_conv(irg);
			}
		});
		OPTIMIZATIONS.put("invert-loops", new FirmOptimization("invert-loops", "loop inversion", NONE | IRG_OPT) {
			@Override
			protected void performOptimization(final Pointer irg) {
				binding_iroptimize.do_loop_inversion(irg);
			}
		});
		OPTIMIZATIONS.put("ivopts", new FirmOptimization("ivopts", "induction variable strength reduction",
				NONE | IRG_OPT) {
			@Override
			protected void performOptimization(final Pointer irg) {
				binding_iroptimize.opt_osr(irg,
						  binding_iroptimize.osr_flags.osr_flag_lftr_with_ov_check.val
						| binding_iroptimize.osr_flags.osr_flag_keep_reg_pressure.val
						| binding_iroptimize.osr_flags.osr_flag_ignore_x86_shift.val);
			}
		});
		OPTIMIZATIONS.put("local", new FirmOptimization("local", "local graph optimizations", HIDE_OPTIONS | IRG_OPT) {
			@Override
			protected void performOptimization(final Pointer irg) {
				binding_irgopt.local_opts(irg);
			}
		});
		OPTIMIZATIONS.put("lower", new FirmOptimization("lower", "lowering", HIDE_OPTIONS | ESSENTIAL | IRG_OPT) {
			@Override
			protected void performOptimization(final Pointer irg) {
				binding_lowering.lower_highlevel_graph(irg);
			}
		});
		OPTIMIZATIONS.put("lower-mux", new FirmOptimization("lower-mux", "mux lowering", NONE | IRG_OPT) {
			@Override
			protected void performOptimization(final Pointer irg) {
				binding_lowering.lower_mux(irg, Pointer.NULL);
			}
		});
		OPTIMIZATIONS.put("opt-load-store", new FirmOptimization("opt-load-store", "load store optimization",
				NONE | IRG_OPT) {
			@Override
			protected void performOptimization(final Pointer irg) {
				binding_iroptimize.optimize_load_store(irg);
			}
		});
		OPTIMIZATIONS.put("opt-tail-rec", new FirmOptimization("opt-tail-rec", "tail-recursion eliminiation",
				NONE | IRG_OPT) {
			@Override
			protected void performOptimization(final Pointer irg) {
				binding_iroptimize.opt_tail_rec_irg(irg);
			}
		});
		OPTIMIZATIONS.put("parallelize-mem", new FirmOptimization("parallelize-mem", "parallelize memory",
				NONE | IRG_OPT) {
			@Override
			protected void performOptimization(final Pointer irg) {
				binding_iroptimize.opt_parallelize_mem(irg);
			}
		});
		OPTIMIZATIONS.put("gcse", new FirmOptimization("gcse", "global common subexpression eliminiation",
				NONE | IRG_OPT) {
			@Override
			protected void performOptimization(final Pointer irg) {
				binding_irflag.set_opt_global_cse(1);
				binding_irgopt.optimize_graph_df(irg);
				binding_irflag.set_opt_global_cse(0);
			}
		});
		OPTIMIZATIONS.put("place", new FirmOptimization("place", "code placement", NONE | IRG_OPT) {
			@Override
			protected void performOptimization(final Pointer irg) {
				binding_iroptimize.place_code(irg);
			}
		});
		OPTIMIZATIONS.put("reassociation", new FirmOptimization("reassociation", "reassociation", NONE | IRG_OPT) {
			@Override
			protected void performOptimization(final Pointer irg) {
				binding_iroptimize.optimize_reassociation(irg);
			}
		});
		OPTIMIZATIONS.put("remove-confirms", new FirmOptimization("remove-confirms", "confirm removal",
				HIDE_OPTIONS | NO_DUMP | NO_VERIFY | IRG_OPT) {
			@Override
			protected void performOptimization(final Pointer irg) {
				binding_irconsconfirm.remove_confirms(irg);
			}
		});
		OPTIMIZATIONS.put("remove-phi-cycles", new FirmOptimization("remove-phi-cycles", "removal of phi cycles",
				HIDE_OPTIONS | IRG_OPT) {
			@Override
			protected void performOptimization(final Pointer irg) {
				binding_iroptimize.remove_phi_cycles(irg);
			}
		});
		OPTIMIZATIONS.put("scalar-replace", new FirmOptimization("scalar-replace", "scalar replacement",
				NONE | IRG_OPT) {
			@Override
			protected void performOptimization(final Pointer irg) {
				binding_iroptimize.scalar_replacement_opt(irg);
			}
		});
		OPTIMIZATIONS.put("shape-blocks", new FirmOptimization("shape-blocks", "block shaping", NONE | IRG_OPT) {
			@Override
			protected void performOptimization(final Pointer irg) {
				binding_iroptimize.shape_blocks(irg);
			}
		});
		OPTIMIZATIONS.put("thread-jumps", new FirmOptimization("thread-jumps", "path-sensitive jumpthreading",
				NONE | IRG_OPT) {
			@Override
			protected void performOptimization(final Pointer irg) {
				binding_iroptimize.opt_jumpthreading(irg);
			}
		});
		OPTIMIZATIONS.put("unroll-loops", new FirmOptimization("unroll-loops", "loop unrolling", NONE | IRG_OPT) {
			@Override
			protected void performOptimization(final Pointer irg) {
				binding_iroptimize.do_loop_unrolling(irg);
			}
		});
		OPTIMIZATIONS.put("inline", new FirmOptimization("inline", "inlining", NONE | IRP_OPT) {
			@Override
			protected void performOptimization(final Pointer irg) {
				binding_iroptimize.inline_functions(
						FirmOptions.getInlineMaxsize(),
						FirmOptions.getInlineThreshold(),
						Pointer.NULL);
			}
		});
		OPTIMIZATIONS.put("lower-const", new FirmOptimization("lower-const", "lowering of constant code",
				HIDE_OPTIONS | NO_DUMP | ESSENTIAL | IRP_OPT) {
			@Override
			protected void performOptimization(final Pointer irg) {
				binding_lowering.lower_const_code();
			}
		});
		OPTIMIZATIONS.put("target-lowering", new FirmOptimization("target-lowering",
				"lowering necessary for target architecture", HIDE_OPTIONS | ESSENTIAL | IRP_OPT) {
			@Override
			protected void performOptimization(final Pointer irg) {
				Backend.lowerForTarget();
			}
		});
		OPTIMIZATIONS.put("opt-func-call", new FirmOptimization("opt-func-call", "function call optimization",
				NONE | IRP_OPT) {
			@Override
			protected void performOptimization(final Pointer irg) {
				binding_iroptimize.optimize_funccalls();
			}
		});
		OPTIMIZATIONS.put("opt-proc-clone", new FirmOptimization("opt-proc-clone", "procedure cloning",
				NONE | IRP_OPT) {
			@Override
			protected void performOptimization(final Pointer irg) {
				binding_iroptimize.proc_cloning(FirmOptions.getCloneThreshold());
			}
		});
		OPTIMIZATIONS.put("remove-unused", new FirmOptimization("remove-unused",
				"removal of unused functions/variables", NO_DUMP | NO_VERIFY | IRP_OPT) {
			@Override
			protected void performOptimization(final Pointer irg) {
				binding_iroptimize.garbage_collect_entities();
			}
		});

		enableSafeDefaults();
	}

	private static void enableSafeDefaults() {
		getOptimization("remove-unused").enable();
		getOptimization("opt-tail-rec").enable();
		getOptimization("opt-func-call").enable();
		getOptimization("control-flow").enable();
		getOptimization("local").enable();
		getOptimization("lower-const").enable();
		getOptimization("scalar-replace").enable();
		getOptimization("dead").enable();
		getOptimization("remove-phi-cycles").enable();
		getOptimization("frame").enable();
	}

	/**
	 * Disables all but the essential optimizations.
	 */
	public static void disableAllOptimizations() {
		for (FirmOptimization opt : OPTIMIZATIONS.values()) {
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
	public static FirmOptimization getOptimization(final String name) {
		return OPTIMIZATIONS.get(name);
	}

	/**
	 * @return the map of all known optimizations.
	 */
	public static Map<String, FirmOptimization> getOptimizations() {
		return OPTIMIZATIONS;
	}
}
