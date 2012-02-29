package x10firm.goals;

import java.io.BufferedReader;
import java.io.File;
import java.io.IOException;
import java.io.InputStreamReader;
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
import x10firm.MachineTriple;

/**
 * Final Goal, which links the generated asm with the stdlib
 */
public class Linked extends PostCompiled {
	/** constructor */
	public Linked(ExtensionInfo extInfo) {
		super(extInfo);
	}

	private static String getGCC(CompilerOptions options) {
		final MachineTriple target = options.getTargetTriple();
		/* darwin11 doesn't have a proper target-gcc installed, just used
		 * "gcc" */
		final String os = target.getOS();
		if (os.equals("darwin11") || os.equals("octopos")) {
			return "gcc";
		}

		final String gcc = target + "-gcc";
		return gcc;
	}

	private static String queryGccPath(CompilerOptions options, String path) {
		final String gcc = getGCC(options);

		final String[] arguments = new String[] { gcc, "--print-file-name="+path };
		BufferedReader stdOut = null;
		final String output;
		try {
			Process p = Runtime.getRuntime().exec(arguments);
			stdOut = new BufferedReader(new InputStreamReader(p.getInputStream()));
			output = stdOut.readLine();
			if (output == null)
				throw new RuntimeException("Failed to query gcc path '" + path + "'");
			stdOut.close();
		} catch (IOException e) {
			throw new RuntimeException("Failed to query gcc path '" + path + "'", e);
		}
		return output;
	}

	@Override
	protected boolean invokePostCompiler(Options opts, Compiler compiler,
			ErrorQueue eq) {

		final CompilerOptions options = (CompilerOptions) opts;
		final String exeFilename = options.executable_path == null
		                           ? "a.out"
		                           : options.executable_path;
		final File asm = new File(AsmEmitted.ASM_FILENAME);

		final MachineTriple target = options.getTargetTriple();
		final String x10DistPath = System.getProperty("x10.dist", ".");
		final String libooPath = x10DistPath + "/../liboo/build/" + target;
		final String gcc = getGCC(options);
		boolean linkStatically = options.linkStatically();

		final List<String> cmd = new ArrayList<String>();
		cmd.add(gcc);
		final String  os = target.getOS();
		// Produce a 32-bit binary when running on a 64-bit x86 host
		if (target.getCpu().equals("x86_64") || os.equals("darwin11")) {
			cmd.add("-m32");
		} else if (os.equals("octopos")) {
			final String octopos_prefix = x10DistPath + "/../octopos-app";
			cmd.add("-m32");
			cmd.add("-nostdlib");
			cmd.add("-Wl,-T" + octopos_prefix + "/sections.x");
			cmd.add(queryGccPath(options, "crti.o"));
			cmd.add(queryGccPath(options, "crtbegin.o"));
			/* octopos only supports static linking */
			linkStatically = true;
		}
		if (linkStatically)
			cmd.add("-static");

		cmd.add(asm.getAbsolutePath());
		if (options.useSoftFloat())
			cmd.add("-msoft-float");
		if (linkStatically) {
			cmd.add(libooPath + "/liboo_rt.a");
		} else {
			cmd.add("-L" + libooPath);
			cmd.add("-Wl,-R" + libooPath);
			cmd.add("-loo_rt");
		}
		if (!FirmState.libraryLoaded("x10")) {
			String stdlibPath = x10DistPath + "/../x10.firm_runtime/build/" + target;
			cmd.add(stdlibPath + "/libx10.a");
		}
		if (os.equals("octopos")) {
			final String octopos_prefix = x10DistPath + "/../octopos-app";
			cmd.add(octopos_prefix + "/liboctopos.a");
			cmd.add("-lgcc");
			cmd.add(queryGccPath(options, "crtend.o"));
			cmd.add(queryGccPath(options, "crtn.o"));
		} else {
			cmd.add("-lm");
			cmd.add("-lpthread");
		}

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
