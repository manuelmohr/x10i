package x10firm;

import java.util.LinkedHashMap;
import java.util.Map;

import x10firm.FirmOptimizations.FirmOptimization;

/**
 * Firm options, just like cparser's "-f" switches.
 *
 * @author julian
 */
public final class FirmOptions {

	/** don't instantiate this class. */
	private FirmOptions() { }

	/** enable constant folding. */
	private static boolean constFolding = true;
	/** enable common-subexpression elimination. */
	private static boolean cse = true;
	/** enable Alias Analysis. */
	private static boolean aliasAnalysis = true;
	/** Maximum function size for inlining. */
	private static int inlineMaxsize = 750;
	/** Inlining benefice threshold. */
	private static int inlineThreshold = 0;
	/** The threshold value for procedure cloning. */
	private static int cloneThreshold = 0;

	/**
	 * @return whether constant folding is activated.
	 */
	public static boolean isConstFolding() {
		return constFolding;
	}

	/**
	 * @param constFolding enable/disable constant folding.
	 */
	public static void setConstFolding(final boolean constFolding) {
		FirmOptions.constFolding = constFolding;
	}

	/**
	 * @return whether local common subexpression elimination is activated.
	 */
	public static boolean isCse() {
		return cse;
	}

	/**
	 * @param cse enable/disable local common subexpression elimination.
	 */
	public static void setCse(final boolean cse) {
		FirmOptions.cse = cse;
	}

	/**
	 * @return whether the alias analysis is activated.
	 */
	public static boolean isAliasAnalysis() {
		return aliasAnalysis;
	}

	/**
	 * @param aliasAnalysis enable/disable alias analysis.
	 */
	public static void setAliasAnalysis(final boolean aliasAnalysis) {
		FirmOptions.aliasAnalysis = aliasAnalysis;
	}

	/**
	 * @return the maximum size for function inlining.
	 */
	public static int getInlineMaxsize() {
		return inlineMaxsize;
	}

	/**
	 * @param inlineMaxsize the maximum size for function inlining.
	 */
	public static void setInlineMaxsize(final int inlineMaxsize) {
		FirmOptions.inlineMaxsize = inlineMaxsize;
	}

	/**
	 * @return the inline benefice threshold.
	 */
	public static int getInlineThreshold() {
		return inlineThreshold;
	}

	/**
	 * @param inlineThreshold the benefice threshold for function inlining.
	 */
	public static void setInlineThreshold(final int inlineThreshold) {
		FirmOptions.inlineThreshold = inlineThreshold;
	}

	/**
	 * @return the clone threshold.
	 */
	public static int getCloneThreshold() {
		return cloneThreshold;
	}

	/**
	 * @param cloneThreshold the clone threshold to set.
	 */
	public static void setCloneThreshold(final int cloneThreshold) {
		FirmOptions.cloneThreshold = cloneThreshold;
	}

	/**
	 * A firm option.
	 * @author julian
	 */
	public abstract static class FirmOption {
		private String name;
		private String description;

		/**
		 * @param name the options name (to be displayed in the help).
		 * @param description a short description.
		 */
		public FirmOption(final String name, final String description) {
			this.name = name;
			this.description = description;
		}

		/**
		 * @return the name.
		 */
		public String getName() {
			return name;
		}

		/**
		 * @return the description.
		 */
		public String getDescription() {
			return description;
		}

		/**
		 * Activate the option on the given FirmOptions object.
		 *
		 * @param arg the option's argument, or null if the option is boolean.
		 * @return false if an error occured
		 */
		abstract boolean activate(String arg);
	}

	/**
	 * Parse argument; activates the corresponding option,
	 * or enables/disables an optimization phase.
	 *
	 * @param arg the argument to parse.
	 * @return true if the argument was accepted, false otherwise.
	 */
	public static boolean setOption(final String arg) {
		String argName = arg;
		String argVal = null;
		if (arg.contains("=")) {
			final String[] arr = arg.split("=");
			argName = arr[0];
			argVal = arr[1];
		}
		if (KNOWN_OPTIONS.containsKey(argName))
			return KNOWN_OPTIONS.get(argName).activate(argVal);

		return optimizationOption.activate(arg);
	}

	/**
	 * Select an -O level.
	 *
	 * @param level the level.
	 */
	public static void chooseOptimizationPack(final int level) {
		/* apply optimization level */
		switch(level) {
		case 0:
			setOption("no-opt");
			break;

		case 1:
			// -> FirmOptimizations.enableSafeDefaults()
			break;

		default:
		case 2:
			setOption("invert-loops");
			setOption("unroll-loops");
			setOption("reassociation");
			setOption("place");
			setOption("opt-load-store");
			setOption("fixpoint-vrp");
			setOption("parallelize-mem");
			setOption("if-conv");
			setOption("inline");
		}
	}

	private static final Map<String, FirmOption> KNOWN_OPTIONS = new LinkedHashMap<String, FirmOption>();
	static {
		KNOWN_OPTIONS.put("no-opt", new FirmOption("no-opt", "disable all firm optimizations") {
			@Override
			boolean activate(final String arg) {
				cse = false;
				constFolding = false;
				// TODO: when adding new flags, set them to false too.
				FirmOptimizations.disableAllOptimizations();
				return true;
			}
		});
		KNOWN_OPTIONS.put("cse", new FirmOption("cse", "enable common subexpression elimination") {
			@Override
			boolean activate(final String arg) {
				cse = true;
				return true;
			}
		});
		KNOWN_OPTIONS.put("no-cse", new FirmOption("no-cse", "disable common subexpression elimination") {
			@Override
			boolean activate(final String arg) {
				cse = false;
				return true;
			}
		});
		KNOWN_OPTIONS.put("const-fold", new FirmOption("const-fold", "enable constant folding") {
			@Override
			boolean activate(final String arg) {
				constFolding = true;
				return true;
			}
		});
		KNOWN_OPTIONS.put("no-const-fold", new FirmOption("no-const-fold", "disable constant folding") {
			@Override
			boolean activate(final String arg) {
				constFolding = false;
				return true;
			}
		});
		KNOWN_OPTIONS.put("inline-max-size", new FirmOption("inline-max-size=<size>",
				"set maximum size for function inlining") {
			@Override
			boolean activate(final String arg) {
				inlineMaxsize = Integer.parseInt(arg);
				return true;
			}
		});
		KNOWN_OPTIONS.put("inline-threshold", new FirmOption("inline-threshold=<size>",
				"set benefice threshold for function inlining") {
			@Override
			boolean activate(final String arg) {
				inlineThreshold = Integer.parseInt(arg);
				return true;
			}
		});
		KNOWN_OPTIONS.put("opt-alias", new FirmOption("opt-alias", "enable alias analysis") {
			@Override
			boolean activate(final String arg) {
				aliasAnalysis = true;
				return true;
			}
		});
		KNOWN_OPTIONS.put("no-opt-alias", new FirmOption("no-opt-alias", "disable alias analysis") {
			@Override
			boolean activate(final String arg) {
				aliasAnalysis = false;
				return true;
			}
		});
		KNOWN_OPTIONS.put("clone_threshold", new FirmOption("clone_threshold=<value>",
				"set clone threshold to <value>") {
			@Override
			boolean activate(final String arg) {
				cloneThreshold = Integer.parseInt(arg);
				return true;
			}
		});
	}

	/** a special option for enabling/disabling the optimization phases. */
	private static FirmOption optimizationOption = new FirmOption(null, null) {
		@Override
		boolean activate(final String arg) {
			FirmOptimization optimization = FirmOptimizations.getOptimization(arg);
			if (optimization != null) {
				optimization.enable();
				return true;
			}

			if (arg.startsWith("no-")) {
				optimization = FirmOptimizations.getOptimization(arg.substring(3));
				if (optimization != null) {
					optimization.disable();
					return true;
				}
			}

			return false;
		}
	};

	/**
	 * @return the map of all known options.
	 */
	public static Map<String, FirmOption> getKnownOptions() {
		return KNOWN_OPTIONS;
	}
}
