package x10firm.goals;

import java.util.ArrayList;

import polyglot.frontend.Compiler;
import polyglot.frontend.ExtensionInfo;
import polyglot.main.Options;
import polyglot.util.ErrorInfo;
import polyglot.util.ErrorQueue;
import polyglot.visit.PostCompiled;
import x10cpp.visit.X10CPPTranslator;
import x10firm.CompilerOptions;

/**
 * Final Goal, which links the generated asm with the stdlib
 */
public class Linked extends PostCompiled {
	/** constructor */
	public Linked(ExtensionInfo extInfo) {
		super(extInfo);
	}

	@Override
	protected boolean invokePostCompiler(Options options,
			Compiler compiler, ErrorQueue eq) {
		CompilerOptions opts = (CompilerOptions) options;
		String exe_name = opts.executable_path;
		String asm_name = AsmEmitted.ASM_FILENAME;
		
		final String x10DistPath = System.getenv("X10_DIST");
		String stdlibPath = "";
		String libooPath  = "";
		
		if (x10DistPath != null) {
			stdlibPath = x10DistPath + "/src-stdlib";
			libooPath  = x10DistPath + "/../liboo/build";
		}
		else {
			stdlibPath = "src-stdlib";
			libooPath = "../liboo/build";
		}
		
		String[] cmd = {
				"gcc",
				"-std=c99",
				asm_name,
				stdlibPath + "/libx10std.a",
				"-lm",
				"-L" + libooPath, "-Wl,-R" + libooPath, "-loo_rt",
				"-o", exe_name
		};

		/* C++ backend decides according to options, whether to delete the output files */
		ArrayList<String> output_files = new ArrayList<String>();
		output_files.add(asm_name);

		/* reuse the C++ backend */
		if (! X10CPPTranslator.doPostCompile(options, eq, output_files, cmd)) {
			eq.enqueue(ErrorInfo.POST_COMPILER_ERROR, "linking failed");
			return false;
		}
		return true;
	}
}