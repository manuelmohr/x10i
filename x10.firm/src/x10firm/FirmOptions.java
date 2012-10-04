package x10firm;

import java.util.LinkedHashMap;
import java.util.Map;

import x10firm.FirmOptimizations.FirmOptimization;
import firm.Backend;

/**
 * Firm options, just like cparser's "-f" switches.
 * 
 * @author julian
 */
public class FirmOptions {
	
	/** don't instantiate this class */
	private FirmOptions() {}
	
	/** < enable constant folding */
	public static boolean constFolding = true;
	/** < enable common-subexpression elimination */
	public static boolean cse = true;
	/** < enable Confirm optimization */
//	public static boolean confirm = true;
	/** < enable architecture dependent mul optimization */
//	public static boolean muls = true;
	/** < enable architecture dependent div optimization */
//	public static boolean divs = true;
	/** < enable architecture dependent mod optimization */
//	public static boolean mods = true;
	/** < enable Alias Analysis */
	public static boolean aliasAnalysis = true;
	/** < enable strict Alias Analysis (using type based AA) */
//	public static boolean strictAlias = false;
	/** < no aliasing possible. */
//	public static boolean noAlias = false;
	/** < Firm verifier setting */
//	public static boolean verify = true;
	/** < enable checking all Firm phases */
//	public static boolean checkAll = true;
	/** < Maximum function size for inlining. */
	public static int inlineMaxsize = 750;
	/** < Inlining benefice threshold. */
	public static int inlineThreshold = 0;
	/**< The threshold value for procedure cloning. */
	public static int cloneThreshold = 0;

	@SuppressWarnings("javadoc")
	public static abstract class FirmOption {
		private String name;
		private String description;

		FirmOption(String name, String description) {
			this.name = name;
			this.description = description;
		}

		public String getName() {
			return name;
		}

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
	public static boolean setOption(String arg) {
		String argName = arg, argVal = null;
		if (arg.contains("=")) {
			String[] arr = arg.split("=");
			argName = arr[0];
			argVal = arr[1];
		}
		if (knownOptions.containsKey(argName))
			return knownOptions.get(argName).activate(argVal);
	
		return optimizationOption.activate(arg);
	}
	
	/**
	 * Select an -O level.
	 * 
	 * @param level the level.
	 */
	public static void chooseOptimizationPack(int level) {
		/* apply optimization level */
		switch(level) {
		case 0:
			setOption("no-opt");
			break;
		case 1:
			setOption("no-inline");
			break;
		default:
		case 4:
			/* use_builtins = true; */
			// $FALL-THROUGH$
		case 3:
			setOption("thread-jumps");
			setOption("if-conversion");
			// $FALL-THROUGH$
		case 2:
//			setOption("strict-aliasing");
			setOption("inline");
			setOption("fp-vrp");
			setOption("deconv");
			
			FirmState.initializeFirm();
			Backend.option("omitfp");
			break;
		}
	}

	private static final Map<String, FirmOption> knownOptions = new LinkedHashMap<String, FirmOption>();
	static {
		knownOptions.put("no-opt", new FirmOption("no-opt", "disable all firm optimizations") {
			@Override
			boolean activate(String arg) {
				cse = false;
				constFolding = false;
				// TODO: when adding new flags, set them to false too.
				FirmOptimizations.disableAllOptimizations();
				return true;
			}
		});
		knownOptions.put("cse", new FirmOption("cse", "enable common subexpression elimination") {
			@Override
			boolean activate(String arg) {
				cse = true;
				return true;
			}
		});
		knownOptions.put("no-cse", new FirmOption("no-cse", "disable common subexpression elimination") {
			@Override
			boolean activate(String arg) {
				cse = false;
				return true;
			}
		});
		knownOptions.put("const-fold", new FirmOption("const-fold", "enable constant folding") {
			@Override
			boolean activate(String arg) {
				constFolding = true;
				return true;
			}
		});
		knownOptions.put("no-const-fold", new FirmOption("no-const-fold", "disable constant folding") {
			@Override
			boolean activate(String arg) {
				constFolding = false;
				return true;
			}
		});
		knownOptions.put("inline-max-size", new FirmOption("inline-max-size=<size>", "set maximum size for function inlining") {
			@Override
			boolean activate(String arg) {
				inlineMaxsize = Integer.parseInt(arg);
				return true;
			}
		});
		knownOptions.put("inline-threshold", new FirmOption("inline-threshold=<size>", "set benefice threshold for function inlining") {
			@Override
			boolean activate(String arg) {
				inlineThreshold = Integer.parseInt(arg);
				return true;
			}
		});
		knownOptions.put("opt-alias", new FirmOption("opt-alias", "enable alias analysis") {
			@Override
			boolean activate(String arg) {
				aliasAnalysis = true;
				return true;
			}
		});
		knownOptions.put("no-opt-alias", new FirmOption("no-opt-alias", "disable alias analysis") {
			@Override
			boolean activate(String arg) {
				aliasAnalysis = false;
				return true;
			}
		});
		knownOptions.put("clone_threshold", new FirmOption("clone_threshold=<value>", "set clone threshold to <value>") {
			@Override
			boolean activate(String arg) {
				cloneThreshold = Integer.parseInt(arg);
				return true;
			}
		});
		/* The values set by the following options are currently ignored,
		 * -> don't let the user set them */
//		knownOptions.put("alias", new FirmOption("alias", "aliasing occurs") {
//			@Override
//			boolean activate(String arg) {
//				noAlias = false;
//				return true;
//			}
//		});
//		knownOptions.put("no-alias", new FirmOption("no-alias", "no aliasing occurs") {
//			@Override
//			boolean activate(String arg) {
//				noAlias = true;
//				return true;
//			}
//		});
//		knownOptions.put("strict-aliasing", new FirmOption("strict-aliasing", "enable strict alias rules") {
//			@Override
//			boolean activate(String arg) {
//				strictAlias = true;
//				return true;
//			}
//		});
//		knownOptions.put("no-strict-aliasing", new FirmOption("no-strict-aliasing", "disable strict alias rules") {
//			@Override
//			boolean activate(String arg) {
//				strictAlias = false;
//				return true;
//			}
//		});
	}
	
	/** a special option for enabling/disabling the optimization phases */
	private static FirmOption optimizationOption = new FirmOption(null, null) {
		@Override
		boolean activate(String arg) {
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
		return knownOptions;
	}
}
