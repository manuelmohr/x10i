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
 * Final Goal, which links the generated asm with the stdlib.
 */
public class Linked extends PostCompiled {
	private CompilerOptions options;
	private final File asmFile;

	/** Constructs a new Linked goal. */
	public Linked(final ExtensionInfo extInfo, final File asmFile) {
		super(extInfo);
		options = (CompilerOptions)extInfo.getOptions();
		this.asmFile = asmFile;
	}

	private void printCommandline(final String[] cmdLine) {
		if (!options.printCommandline())
			return;
		for (int i = 0; i < cmdLine.length; ++i) {
			if (i > 0)
				System.err.print(" ");
			System.err.print(cmdLine[i]);
		}
		System.err.println();
	}

	private String getGCC() {
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

	private String queryGccPath(final String path) {
		final String gcc = getGCC();

		final String[] cmdLine = new String[] {gcc, "--print-file-name=" + path};
		final String output;
		try {
			printCommandline(cmdLine);
			final Process p = Runtime.getRuntime().exec(cmdLine);
			final BufferedReader stdOut = new BufferedReader(new InputStreamReader(p.getInputStream()));
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
	protected boolean invokePostCompiler(final Options opts, final Compiler compiler,
			final ErrorQueue eq) {

		final String exeFilename = options.executable_path == null
		                           ? "a.out"
		                           : options.executable_path;
		final MachineTriple target = options.getTargetTriple();
		final String x10DistPath = System.getProperty("x10.dist", ".");
		final String libooPath = x10DistPath + "/../liboo/build/" + target;
		final String gcc = getGCC();
		final boolean usesElf = target.isUnixishOS();
		boolean linkStatically = options.linkStatically();

		final List<String> cmd = new ArrayList<String>();
		cmd.add(gcc);
		final String  os = target.getOS();
		// Produce a 32-bit binary when running on a 64-bit x86 host
		if (target.getCpu().equals("x86_64") || os.equals("darwin11")) {
			cmd.add("-m32");
		} else if (os.equals("octopos")) {
			final String octoposPrefix = x10DistPath + "/../octopos-app";
			cmd.add("-m32");
			cmd.add("-nostdlib");
			cmd.add("-Wl,-T" + octoposPrefix + "/sections.x");
			cmd.add(queryGccPath("crti.o"));
			cmd.add(queryGccPath("crtbegin.o"));
			/* octopos only supports static linking */
			linkStatically = true;
		}
		if (linkStatically)
			cmd.add("-static");

		cmd.add(asmFile.getAbsolutePath());
		if (options.useSoftFloat())
			cmd.add("-msoft-float");
		if (linkStatically) {
			cmd.add(libooPath + "/liboo_rt.a");
		} else {
			cmd.add("-L" + libooPath);
			if (usesElf)
				cmd.add("-Wl,-R" + libooPath);
			cmd.add("-loo_rt");
		}
		if (!FirmState.libraryLoaded("x10")) {
			final String stdlibPath = x10DistPath + "/../x10.firm_runtime/build/" + target;
			cmd.add(stdlibPath + "/libx10.a");
		}
		if (os.equals("octopos")) {
			final String octoposPrefix = x10DistPath + "/../octopos-app";
			cmd.add(octoposPrefix + "/liboctopos.a");
			cmd.add("-lgcc");
			cmd.add(queryGccPath("crtend.o"));
			cmd.add(queryGccPath("crtn.o"));
		} else {
			cmd.add("-lm");
			cmd.add("-pthread");
		}

		cmd.add("-o");
		cmd.add(exeFilename);

		// Reuse the C++ backend.
		final String[] cmdLine = cmd.toArray(new String[0]);
		printCommandline(cmdLine);
		if (!X10CPPTranslator.doPostCompile(options, eq, Collections.<String>emptyList(), cmdLine)) {
			eq.enqueue(ErrorInfo.POST_COMPILER_ERROR, "assembling and linking failed");
			return false;
		}

		return asmFile.delete();
	}
}
