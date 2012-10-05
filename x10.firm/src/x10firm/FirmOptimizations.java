package x10firm;

import java.util.HashMap;
import java.util.Map;

import com.sun.jna.Pointer;

import firm.Backend;
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
public class FirmOptimizations {
	private static final int NONE         = 0;
	private static final int ENABLED      = 1 << 0;
	private static final int NO_DUMP      = 1 << 1;
	private static final int NO_VERIFY    = 1 << 2;
	private static final int HIDE_OPTIONS = 1 << 3;
	private static final int ESSENTIAL    = 1 << 4;
	private static final int IRG_OPT      = 1 << 10;
	private static final int IRP_OPT      = 1 << 11;
	
	@SuppressWarnings("javadoc")
	public static abstract class FirmOptimization {
		private String name;
		private String description;
		private int flags;
		
		public FirmOptimization(String name, String description, int flags) {
			this.name = name;
			this.description = description;
			this.flags = flags;
		}
		
		public void enable() {
			flags |= ENABLED;
			System.out.println("FirmOptimizations: enabling " + name);
		}
		public void disable() {
			flags &= ~ENABLED;
			System.out.println("FirmOptimizations: disabling " + name);
		}
		public boolean isEnabled() {
			return (flags & ENABLED) != 0;
		}
		public boolean isHidden() {
			return (flags & HIDE_OPTIONS) != 0;
		}
		
		public String getName() {
			return name;
		}
		public String getDescription() {
			return description;
		}
		public int getFlags() {
			return flags;
		}
		
		protected abstract void performOptimization(final Pointer irg);
		
		/**
		 * Perform the optimization.
		 * 
		 * @param irg the graph to perform the optimization on.
		 * @return true if the optimization was performed (so the graph may be changed), false otherwise.
		 */
		public boolean perform(final Pointer irg) {
			if (! isEnabled())
				return false;
			
			performOptimization(irg);
			
			return true;
		}
	}
	
	private static final Map<String, FirmOptimization> optimizations = new HashMap<String, FirmOptimization>();
	static {
		optimizations.put("bool", new FirmOptimization("bool", "bool simplification", NONE | IRG_OPT) {
			@Override
			protected void performOptimization(final Pointer irg) {
				binding_iroptimize.opt_bool(irg);
			}
		});
		optimizations.put("combo", new FirmOptimization("combo", "combined CCE, UCE and GVN", NONE | IRG_OPT) {
			@Override
			protected void performOptimization(final Pointer irg) {
				binding_iroptimize.combo(irg);
			}
		});
		optimizations.put("confirm", new FirmOptimization("confirm", "confirm optimization", HIDE_OPTIONS | IRG_OPT) {
			@Override
			protected void performOptimization(final Pointer irg) {
				binding_irconsconfirm.construct_confirms(irg);
			}
		});
		optimizations.put("control-flow", new FirmOptimization("control-flow", "optimization of control-flow", HIDE_OPTIONS | IRG_OPT) {
			@Override
			protected void performOptimization(final Pointer irg) {
				binding_iroptimize.optimize_cf(irg);
			}
		});
		optimizations.put("dead", new FirmOptimization("dead", "dead node elimination", HIDE_OPTIONS | NO_DUMP | IRG_OPT) {
			@Override
			protected void performOptimization(final Pointer irg) {
				binding_iroptimize.dead_node_elimination(irg);
				
			}
		});
		optimizations.put("deconv", new FirmOptimization("deconv", "conv node elimination", NONE | IRG_OPT) {
			@Override
			protected void performOptimization(final Pointer irg) {
				binding_iroptimize.conv_opt(irg);
			}
		});			
		optimizations.put("fp-vrp", new FirmOptimization("fp-vrp", "fixpoint value range propagation", NONE | IRG_OPT) {
			@Override
			protected void performOptimization(final Pointer irg) {
				binding_iroptimize.fixpoint_vrp(irg);
			}
		});
		optimizations.put("frame", new FirmOptimization("frame", "remove unused frame entities", NONE | IRG_OPT) {
			@Override
			protected void performOptimization(final Pointer irg) {
				binding_iroptimize.opt_frame_irg(irg);
			}
		});
		optimizations.put("gvn-pre", new FirmOptimization("gvn-pre", "global value numbering partial redundancy elimination", NONE | IRG_OPT) {
			@Override
			protected void performOptimization(final Pointer irg) {
				binding_iroptimize.do_gvn_pre(irg);
			}
		});
		optimizations.put("if-conversion", new FirmOptimization("if-conversion", "if-conversion", NONE | IRG_OPT) {
			@Override
			protected void performOptimization(final Pointer irg) {
				binding_iroptimize.opt_if_conv(irg);
			}
		});
		optimizations.put("invert-loops", new FirmOptimization("invert-loops", "loop inversion", NONE | IRG_OPT) {
			@Override
			protected void performOptimization(final Pointer irg) {
				binding_iroptimize.do_loop_inversion(irg);
			}
		});
		optimizations.put("ivopts", new FirmOptimization("ivopts", "induction variable strength reduction", NONE | IRG_OPT) {
			@Override
			protected void performOptimization(final Pointer irg) {
				binding_iroptimize.opt_osr(irg, 
						  binding_iroptimize.osr_flags.osr_flag_lftr_with_ov_check.val 
						| binding_iroptimize.osr_flags.osr_flag_keep_reg_pressure.val 
						| binding_iroptimize.osr_flags.osr_flag_ignore_x86_shift.val);
			}
		});
		optimizations.put("local", new FirmOptimization("local", "local graph optimizations", HIDE_OPTIONS | IRG_OPT) {
			@Override
			protected void performOptimization(final Pointer irg) {
				binding_irgopt.local_opts(irg);
			}
		});
		optimizations.put("lower", new FirmOptimization("lower", "lowering", HIDE_OPTIONS | ESSENTIAL | IRG_OPT) {
			@Override
			protected void performOptimization(final Pointer irg) {
				binding_lowering.lower_highlevel_graph(irg);
			}
		});
		optimizations.put("lower-mux", new FirmOptimization("lower-mux", "mux lowering", NONE | IRG_OPT) {
			@Override
			protected void performOptimization(final Pointer irg) {
				binding_lowering.lower_mux(irg, Pointer.NULL);
			}
		});
		optimizations.put("opt-load-store", new FirmOptimization("opt-load-store", "load store optimization", NONE | IRG_OPT) {
			@Override
			protected void performOptimization(final Pointer irg) {
				binding_iroptimize.optimize_load_store(irg);
			}
		});
		optimizations.put("opt-tail-rec", new FirmOptimization("opt-tail-rec", "tail-recursion eliminiation", NONE | IRG_OPT) {
			@Override
			protected void performOptimization(final Pointer irg) {
				binding_iroptimize.opt_tail_rec_irg(irg);
			}
		});
		optimizations.put("parallelize-mem", new FirmOptimization("parallelize-mem", "parallelize memory", NONE | IRG_OPT) {
			@Override
			protected void performOptimization(final Pointer irg) {
				binding_iroptimize.opt_parallelize_mem(irg);
			}
		});
		optimizations.put("gcse", new FirmOptimization("gcse", "global common subexpression eliminiation", NONE | IRG_OPT) {
			@Override
			protected void performOptimization(final Pointer irg) {
				binding_irflag.set_opt_global_cse(1);
				binding_irgopt.optimize_graph_df(irg);
				binding_irflag.set_opt_global_cse(0);
			}
		});
		optimizations.put("place", new FirmOptimization("place", "code placement", NONE | IRG_OPT) {
			@Override
			protected void performOptimization(final Pointer irg) {
				binding_iroptimize.place_code(irg);
			}
		});
		optimizations.put("reassociation", new FirmOptimization("reassociation", "reassociation", NONE | IRG_OPT) {
			@Override
			protected void performOptimization(final Pointer irg) {
				binding_iroptimize.optimize_reassociation(irg);
			}
		});
		optimizations.put("remove-confirms", new FirmOptimization("remove-confirms", "confirm removal", HIDE_OPTIONS | NO_DUMP | NO_VERIFY | IRG_OPT) {
			@Override
			protected void performOptimization(final Pointer irg) {
				binding_irconsconfirm.remove_confirms(irg);
			}
		});
		optimizations.put("remove-phi-cycles", new FirmOptimization("remove-phi-cycles", "removal of phi cycles", HIDE_OPTIONS | IRG_OPT) {
			@Override
			protected void performOptimization(final Pointer irg) {
				binding_iroptimize.remove_phi_cycles(irg);
			}
		});
		optimizations.put("scalar-replace", new FirmOptimization("scalar-replace", "scalar replacement", NONE | IRG_OPT) {
			@Override
			protected void performOptimization(final Pointer irg) {
				binding_iroptimize.scalar_replacement_opt(irg);
			}
		});
		optimizations.put("shape-blocks", new FirmOptimization("shape-blocks", "block shaping", NONE | IRG_OPT) {
			@Override
			protected void performOptimization(final Pointer irg) {
				binding_iroptimize.shape_blocks(irg);
			}
		});
		optimizations.put("thread-jumps", new FirmOptimization("thread-jumps", "path-sensitive jumpthreading", NONE | IRG_OPT) {
			@Override
			protected void performOptimization(final Pointer irg) {
				binding_iroptimize.opt_jumpthreading(irg);
			}
		});
		optimizations.put("unroll-loops", new FirmOptimization("unroll-loops", "loop unrolling", NONE | IRG_OPT) {
			@Override
			protected void performOptimization(final Pointer irg) {
				binding_iroptimize.do_loop_unrolling(irg);
			}
		});
//		optimizations.put("vrp", new FirmOptimization("vrp", "value range propagation", NONE | IRG_OPT) {
//			@Override
//			public void perform(final Pointer irg) {
//				// XXX: no jFirm binding for set_vrp_data?
//			}
//		});
		optimizations.put("inline", new FirmOptimization("inline", "inlining", NONE | IRP_OPT) {
			@Override
			protected void performOptimization(final Pointer irg) {
				binding_iroptimize.inline_functions(
						FirmOptions.inlineMaxsize, 
						FirmOptions.inlineThreshold,
						Pointer.NULL);
			}
		});
		optimizations.put("lower-const", new FirmOptimization("lower-const", "lowering of constant code", HIDE_OPTIONS | NO_DUMP | ESSENTIAL | IRP_OPT) {
			@Override
			protected void performOptimization(final Pointer irg) {
				binding_lowering.lower_const_code();
			}
		});
		optimizations.put("target-lowering", new FirmOptimization("target-lowering", "lowering necessary for target architecture", HIDE_OPTIONS | ESSENTIAL | IRP_OPT) {
			@Override
			protected void performOptimization(final Pointer irg) {
				Backend.lowerForTarget();
			}
		});
		optimizations.put("opt-func-call", new FirmOptimization("opt-func-call", "function call optimization", NONE | IRP_OPT) {
			@Override
			protected void performOptimization(final Pointer irg) {
				binding_iroptimize.optimize_funccalls();
			}
		});
		optimizations.put("opt-proc-clone", new FirmOptimization("opt-proc-clone", "procedure cloning", NONE | IRP_OPT) {
			@Override
			protected void performOptimization(final Pointer irg) {
				binding_iroptimize.proc_cloning(FirmOptions.cloneThreshold);
			}
		});
		optimizations.put("remove-unused", new FirmOptimization("remove-unused", "removal of unused functions/variables", NO_DUMP | NO_VERIFY | IRP_OPT) {
			@Override
			protected void performOptimization(final Pointer irg) {
				binding_iroptimize.garbage_collect_entities();
			}
		});
//		optimizations.put("rts", new FirmOptimization("rts", "optimization of known library functions", NONE | IRP_OPT) {
//			@Override
//			protected void performOptimization(final Pointer irg) {
//				// XXX: NYI
//			}
//		});
//		optimizations.put("opt-cc", new FirmOptimization("opt-cc", "calling conventions optimization", NONE | IRP_OPT) {
//			@Override
//			protected void performOptimization(final Pointer irg) {
//				// XXX: no binding for mark_private_methods?
//			}
//		});
		
		enableSafeDefaults();
	}

	private static void enableSafeDefaults() {
		getOptimization("remove-unused").enable();
		getOptimization("opt-tail-rec").enable();
		getOptimization("opt-func-call").enable();
		getOptimization("reassociation").enable();
		getOptimization("control-flow").enable();
		getOptimization("local").enable();
		getOptimization("lower-const").enable();
		getOptimization("scalar-replace").enable();
		getOptimization("place").enable();
		getOptimization("gcse").enable();
//		getOptimization("confirm").enable();
		getOptimization("opt-load-store").enable();
		getOptimization("lower").enable();
		getOptimization("deconv").enable();
//		getOptimization("remove-confirms").enable();
		getOptimization("ivopts").enable();
		getOptimization("dead").enable();
		getOptimization("remove-phi-cycles").enable();
		getOptimization("frame").enable();
		getOptimization("combo").enable();
		getOptimization("invert-loops").enable();
		getOptimization("target-lowering").enable();
//		getOptimization("rts").enable();
		getOptimization("parallelize-mem").enable();
//		getOptimization("opt-cc").enable();
	}
	
	/**
	 * Disables all but the essential optimizations.
	 */
	public static void disableAllOptimizations() {
		for (FirmOptimization opt : optimizations.values()) {
			if ((opt.getFlags() & ESSENTIAL) != 0)
				opt.enable();
			else
				opt.disable();
		}
	}
	
	/**
	 * Gets the object representing the optimization by name.
	 * @param name optimization name
	 * @return the optimization object
	 */
	public static FirmOptimization getOptimization(String name) {
		return optimizations.get(name);
	}
	
	/**
	 * @return the map of all known optimizations.
	 */
	public static Map<String, FirmOptimization> getOptimizations() {
		return optimizations;
	}
}
