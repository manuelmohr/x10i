package x10firm.goals;

import java.io.File;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

import polyglot.frontend.Compiler;
import polyglot.frontend.ExtensionInfo;
import polyglot.main.Options;
import polyglot.util.ErrorInfo;
import polyglot.util.ErrorQueue;
import polyglot.visit.PostCompiled;
import x10cpp.visit.X10CPPTranslator;
import x10firm.CompilerOptions;
import x10firm.FirmState;

/**
 * Final Goal, which links the generated asm with the stdlib
 */
public class Linked extends PostCompiled {
	/** constructor */
	public Linked(ExtensionInfo extInfo) {
		super(extInfo);
	}

	@Override
	protected boolean invokePostCompiler(Options opts, Compiler compiler,
			ErrorQueue eq) {

		final CompilerOptions options = (CompilerOptions) opts;
		final String exeFilename = options.executable_path == null
		                           ? "a.out"
		                           : options.executable_path;
		final File asm = new File(AsmEmitted.ASM_FILENAME);

		final CompilerOptions.TargetTriple target = options.getTargetTriple();
		final String x10DistPath = System.getProperty("x10.dist", ".");
		final String libooPath = x10DistPath + "/../liboo/build/" + target;
		final String gcc = target + "-gcc";

		final List<String> cmd = new ArrayList<String>();
		cmd.add(gcc);
		// Produce a 32-bit binary when running on a 64-bit x86 host
		if (options.getTargetTriple().toString().startsWith("x86_64"))
			cmd.add("-m32");
		if (options.linkStatically())
			cmd.add("-static");

		cmd.add(asm.getAbsolutePath());
		if (options.useSoftFloat())
			cmd.add("-msoft-float");
		if (options.linkStatically()) {
			cmd.add("-L" + libooPath);
			cmd.add("-Wl,-R" + libooPath);
			cmd.add("-loo_rt");
		} else {
			cmd.add(libooPath + "/liboo_rt.a");
		}
		if (!FirmState.libraryLoaded("x10")) {
			String stdlibPath = x10DistPath + "/../x10.firm_runtime/build/" + target;
			cmd.add(stdlibPath + "/libx10.a");
		}
		cmd.add("-lm");
		cmd.add("-lpthread");
		cmd.add("-o");
		cmd.add(exeFilename);

		// Reuse the C++ backend.
		if (!X10CPPTranslator.doPostCompile(options, eq, Collections.<String>emptyList(), cmd.toArray(new String[0]))) {
			eq.enqueue(ErrorInfo.POST_COMPILER_ERROR, "assembling and linking failed");
			return false;
		}

		return asm.delete();
	}
}
