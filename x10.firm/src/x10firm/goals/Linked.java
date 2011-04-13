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
	protected boolean invokePostCompiler(Options options, Compiler compiler,
			ErrorQueue eq) {
		final CompilerOptions opts = (CompilerOptions) options;
		final String exeFilename = opts.executable_path == null
		                     ? "a.out"
		                     : opts.executable_path;
		final String asmFilename = AsmEmitted.ASM_FILENAME;

		final String x10DistPath = System.getenv("X10_DIST");
		final String stdlibPath = x10DistPath != null
		                          ? x10DistPath + "/src-stdlib"
		                          : "src-stdlib";
		final String libooPath  = x10DistPath != null
		                          ? x10DistPath + "/../liboo/build"
		                          : "../liboo/build";

		final String[] cmd = {
				"gcc",
				"-std=c99",
				asmFilename,
				stdlibPath + "/libx10std.a",
				"-lm",
				"-L" + libooPath, "-Wl,-R" + libooPath, "-loo_rt",
				"-o", exeFilename
		};

		// C++ backend decides according to options, whether to delete the
		// output files.
		final ArrayList<String> outputFiles = new ArrayList<String>();
		outputFiles.add(asmFilename);

		// Reuse the C++ backend.
		if (!X10CPPTranslator.doPostCompile(options, eq, outputFiles, cmd)) {
			eq.enqueue(ErrorInfo.POST_COMPILER_ERROR, "linking failed");
			return false;
		}

		return true;
	}
}