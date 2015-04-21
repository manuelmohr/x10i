package x10firm;

import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;

import com.sun.jna.Pointer;

import firm.Backend;
import firm.ClassType;
import firm.Entity;
import firm.Graph;
import firm.OO;
import firm.Program;
import firm.RTA;
import firm.Type;
import firm.Util;
import firm.bindings.binding_irconsconfirm;
import firm.bindings.binding_irflag;
import firm.bindings.binding_irgopt;
import firm.bindings.binding_irmemory;
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
		}

		/**
		 * disable the optimization.
		 */
		public void disable() {
			flags &= ~ENABLED;
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
				performOptimization(graph);
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
				binding_irgopt.optimize_graph_df(graph.ptr);
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
		TRANSFORMATIONS.put("rta", new Transformation("rta",
				"perform Rapid Type Analysis", IRP_OPT) {
			@Override
			protected void performOptimization(final Graph graph) {

				// fetch classes
				Map<String, Type> types = new HashMap<String, Type>();
				for (Type type : Program.getTypes()) {
					if (type instanceof ClassType) {
						ClassType klass = (ClassType)type;
						if (firm.bindings.binding_typerep.is_frame_type(klass.ptr) == 0) { // ignore frame types, seems wrong that they are classes
							String classname = klass.getName();
							//assert(!types.containsKey(classname) || types.get(classname).equals(klass)); // currently there are two of the basic FIRM classes like GlobalType
							types.put(classname, klass);
						}
					}
				}

				// fetch methods
				Map<String, Entity> methods = new HashMap<String, Entity>();
				for (Graph g : Program.getGraphs()) { // take all methods with graph
					Entity entity = g.getEntity();
					assert(entity.getType() instanceof firm.MethodType);
					String name = entity.getLdName(); // use ldname to identify methods, normal entity name can be ambiguous even with owner classname as prefix (e.g. instantiations of generic methods in GlobalType)
					assert(!methods.containsKey(name) || methods.get(name).equals(entity)); // using ldname when only looking on methods with graph should ensure we don't get duplicates
					methods.put(name, entity);
				}


				// find entry points
				/*
					Biggest problem is that in some cases entity linkage in FIRM graphs is incorrect due to duplicate entities. This seems to happen to functions declared extern in native runtime code.

							x10_static_initializer
							_ZN3x108compiler14InitDispatcher17get_staticMonitorEv
							_ZN3x105array5Array15makeStringArrayEPvi
							x10_main
							_ZN3x104lang7Runtime14printExceptionEPN3x104lang16CheckedThrowableE

						In an attempt to solve this, these functions need to be given as additional entry points.
						Problem is that this is probably incomplete and depends on the native code not changing. Also it could be platform dependent, for octopos/irtss could need a different set of entry points.

					static initializers:
					The C main function ("main") calls x10_static_initializer which is probably generated by the compiler.
					X10 does not have real static sections, so no real class initializer functions. Static fields are initialized by compiler-generated static field getters when accessed for the first time per place.

					Methods common to all classes via the interface "Any" (typeName, toString, equals, hashCode) are each mapped to a common native implementation by giving them a common linkername. RTA currently can't follow such redirections and doesn't find them. So they should be added to entry points to be safe.
					Struct types have their own generated versions of typeName, toString, equals and hashCode that are always statically bound. If necessary struct types will be boxed and the box classes work like usual classes.
				*/
				List<Entity> entrypoints = new LinkedList<Entity>();
				{
					Entity main = methods.get("main");
					if (main == null) { // workaround because CompilerOptions can't be queried from here
						// octopos/irtss
						main = methods.get("main_ilet");
						assert(main != null);
						assert(main.getGraph() != null);
						entrypoints.add(main);
						//...?
					} else {
						// posix
						assert(main != null);
						assert(main.getGraph() != null);
						entrypoints.add(main);
					}
					// common

					// because of broken references happening to functions declared extern in runtime C-code but implemented in X10 or generated by compiler
					Entity x10main = methods.get("x10_main");
					assert(x10main != null);
					assert(x10main.getGraph() != null);
					entrypoints.add(x10main);
					Entity staticInit = methods.get("x10_static_initializer");
					assert(staticInit != null);
					assert(staticInit.getGraph() != null);
					entrypoints.add(staticInit);
					Entity getStaticMonitor = methods.get("_ZN3x108compiler14InitDispatcher17get_staticMonitorEv");
					assert(getStaticMonitor != null);
					assert(getStaticMonitor.getGraph() != null);
					entrypoints.add(getStaticMonitor);
					Entity makeStringArray = methods.get("_ZN3x105array5Array15makeStringArrayEPvi");
					assert(makeStringArray != null);
					assert(makeStringArray.getGraph() != null);
					entrypoints.add(makeStringArray);
					Entity printException = methods.get("_ZN3x104lang7Runtime14printExceptionEPN3x104lang16CheckedThrowableE");
					assert(printException != null);
					assert(printException.getGraph() != null);
					entrypoints.add(printException);

					// because only reachable through linkername redirection
					Entity typeName = methods.get("x10_object_8typeNamev");
					assert(typeName != null);
					assert(typeName.getGraph() != null);
					entrypoints.add(typeName);
					Entity toString = methods.get("x10_object_8toStringv");
					assert(toString != null);
					assert(toString.getGraph() != null);
					entrypoints.add(toString);
					Entity equals = methods.get("x10_object_6equalsPN3x104lang3AnyE");
					assert(equals != null);
					assert(equals.getGraph() != null);
					entrypoints.add(equals);
					Entity hashCode = methods.get("x10_object_8hashCodev");
					assert(hashCode != null);
					assert(hashCode.getGraph() != null);
					entrypoints.add(hashCode);
				}


				// find initial live classes
				/*
					The following classes are defined as X10 objects in native runtime code:

						x10.lang.String
						x10.io.OutputStreamWriter
						x10.io.InputStreamReader
						x10.util.concurrent.Lock
						x10.util.concurrent.Signal

					But only x10.lang.String, x10.io.OutputStreamWriter and x10.io.InputStreamReader seem to be instantiated (via x10_alloc_object) in the native runtime code.

					X10 struct types seem to get boxed for dynamic method calls (when cast to Any or some other interface, otherwise calls are statically bound from the beginning). Normal detection via VptrIsSet should work.

					x10.array.Array[x10.lang.String] is used in native main, but actually created in X10 code in x10.array.Array.makeStringArray. It could be left out if x10.array.Array.makeStringArray is analyzed (which currently is not guaranteed because of problems with entity linkage).

					There are no reflection classes like in Java, so no "Class" needed.
					"Object" is in X10 "Any" which is an interface. A real common super class for class types seem to exist only behind the scenes (although things like "super.toString()" don't work to access).

					In deserialization code objects of any kind are (re)created. This is basically the kind of thing RTA will never be able to handle. But in this X10 implementation the serialization might be only used by the runtime system to send and receive objects between places in the context of one program, so this can hopefully be ignored. (Transfering objects between different programs using serialization would be like dynamic loading of classes.)

					constructors of the initial live classes:
					Mostly when X10 objects are created in the C runtime code, constructors aren't called for some reason. If an constructor would be called there, it would analyzed from there as long as the runtime code is compiled with the program. So, no need to add constructors as initially live.
				*/
				List<Type> liveclasses = new LinkedList<Type>();
				{
					Type string = types.get("x10.lang.String");
					assert(string != null);
					liveclasses.add(string);
					Type stringArray = types.get("x10.array.Array[x10.lang.String]");
					assert(stringArray != null);
					liveclasses.add(stringArray);
					Type outputStreamWriter = types.get("x10.io.OutputStreamWriter");
					assert(outputStreamWriter != null);
					liveclasses.add(outputStreamWriter);
					Type inputStreamReader = types.get("x10.io.InputStreamReader");
					assert(inputStreamReader != null);
					liveclasses.add(inputStreamReader);
					Type lock = types.get("x10.util.concurrent.Lock");
					assert(lock != null);
					liveclasses.add(lock);
					Type signal = types.get("x10.util.concurrent.Signal");
					assert(signal != null);
					liveclasses.add(signal);
				}


				Entity[] initialEntryPoints = entrypoints.toArray(new Entity[entrypoints.size()]);
				Type[] initialLiveClasses = liveclasses.toArray(new Type[liveclasses.size()]);
				RTA.runRTA(initialEntryPoints, initialLiveClasses);
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
		// TODO Enable alias analysis once quadratic worst-case complexity problems have been solved.
		binding_irmemory.set_irp_memory_disambiguator_options(
				binding_irmemory.ir_disambiguator_options.aa_opt_always_alias.val);
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
