package x10firm.goals;

import java.io.BufferedReader;
import java.io.File;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

import polyglot.frontend.AbstractGoal_c;
import polyglot.util.ErrorInfo;
import polyglot.util.ErrorQueue;
import x10firm.CompilerOptions;
import x10firm.FirmState;
import x10firm.MachineTriple;

/**
 * Final Goal, which links the generated asm with the stdlib.
 */
public class Linked extends AbstractGoal_c {
	private CompilerOptions options;
	private final File asmFile;
	private final ErrorQueue errorQueue;

	/** Constructs a new Linked goal. */
	public Linked(final CompilerOptions options, final File asmFile,
			final ErrorQueue errorQueue) {
		super("Linked");
		this.options = options;
		this.asmFile = asmFile;
		this.errorQueue = errorQueue;
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
		if (os.equals("darwin11")) {
			return "gcc";
		}

		final String gcc = target + "-gcc";
		return gcc;
	}

	private boolean generate32BitCode() {
		final MachineTriple target = options.getTargetTriple();
		final String os = target.getOS();
		if (os.equals("darwin11"))
			return true;

		final MachineTriple host = options.getHostTriple();
		return host.getCpu().equals("x86_64") && target.getCpu().equals("i686");
	}

	private String queryGccPath(final String path) {
		final String gcc = getGCC();

		final String[] cmdLine;
		if (generate32BitCode()) {
			cmdLine = new String[] {gcc, "-m32", "--print-file-name=" + path};
		} else {
			cmdLine = new String[] {gcc, "--print-file-name=" + path};
		}

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

	private static String distPath() {
		return System.getProperty("x10.dist", ".");
	}

	private String octoposPrefix() {
		final MachineTriple target = options.getTargetTriple();
		final String octoposArch;
		// Choose OctoPOS architecture
		if (target.getCpu().equals("sparc")) {
			octoposArch = "leon";
		} else if (target.getCpu().equals("i686")) {
			octoposArch = "x86guest";
		} else if (target.getCpu().equals("x86_64")) {
			octoposArch = "x64native";
		} else {
			throw new RuntimeException("only sparc/i686 supported for octopos");
		}
		final String octoposVariant;
		if (target.getOSVariant() != null) {
			octoposVariant = target.getOSVariant();
		} else {
			octoposVariant = "default";
		}

		return distPath() + "/../octopos-app/releases/current/" + octoposArch + "/" + octoposVariant + "/";
	}

	@Override
	public boolean runTask() {
		final String exeFilename = options.executable_path == null
		                           ? "a.out"
		                           : options.executable_path;
		final MachineTriple target = options.getTargetTriple();
		final String x10DistPath = distPath();
		final String libooPath = x10DistPath + "/../liboo/build/" + target;
		final String gcc = getGCC();
		final boolean usesElf = target.isUnixishOS();
		final String cpu = target.getCpu();
		final String os = target.getOS();
		boolean linkStatically = options.linkStatically();
		String linkerScript = options.getLinkerScriptPath();

		final List<String> cmd = new ArrayList<String>();
		cmd.add(gcc);
		if (generate32BitCode()) {
			cmd.add("-m32");
		}

		if (os.equals("octopos") || os.equals("irtss")) {
			if (cpu.equals("sparc")) {
				cmd.add("-mcpu=v8");
				cmd.add("-L" + octoposPrefix() + "lib");
				cmd.add("-nostdlib");
			} else {
				cmd.add("-L" + octoposPrefix() + "lib");
				cmd.add("-nostdlib");
			}

			cmd.add(queryGccPath("crti.o"));
			cmd.add(queryGccPath("crtbegin.o"));
			/* octopos only supports static linking */
			linkStatically = true;
			/* octopos always needs a linkerscript */
			if (linkerScript == null)
				linkerScript = octoposPrefix() + "lib/sections.x";
		}

		if (linkerScript != null)
			cmd.add("-Wl,-T," + linkerScript);
		if (linkStatically)
			cmd.add("-static");

		cmd.add(asmFile.getAbsolutePath());
		for (String flag : options.getLinkerObjects()) {
			cmd.add(flag);
		}

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

		final String libicorePath = x10DistPath + "/../libicore";
		final File libicore = new File(libicorePath);
		if (cpu.equals("sparc") && libicore.exists() && libicore.isDirectory()) {
			cmd.add("-L" + libicorePath + "/build");
			cmd.add("-licore");
		}

		final String stdlibPath = x10DistPath + "/../x10.firm_runtime/build/" + target;
		if (!FirmState.libraryLoaded("x10"))
			cmd.add(stdlibPath + "/libx10.a");
		if (cpu.equals("sparc"))
			cmd.add(stdlibPath + "/libdoublereg.a");

		if (os.equals("octopos") || os.equals("irtss")) {
			cmd.add("-loctopos");
			cmd.add("-lcsubset");
			cmd.add("-loctomem");
			// Workaround: Pass -loctopos again because of circular dependencies in OctoPOS
			cmd.add("-loctopos");
			cmd.add("-lgcc");
			cmd.add(queryGccPath("crtend.o"));
			cmd.add(queryGccPath("crtn.o"));
			if (cpu.equals("sparc"))
				cmd.add("-lotail");
		} else {
			cmd.add(x10DistPath + "/../bdwgc/build/" + target + "/gc.a");
			cmd.add("-lm");
			cmd.add("-lrt");
			if (!cpu.equals("x86_64")) {
				cmd.add("-L" + distPath() + "/../octopos-app/releases/current/extras/libethcomm/i686/");
				cmd.add("-lethcomm");
			}
			cmd.add("-pthread");
		}

		cmd.add("-o");
		cmd.add(exeFilename);

		final String[] cmdLine = cmd.toArray(new String[0]);
		printCommandline(cmdLine);

		try {
			final Runtime runtime = Runtime.getRuntime();
			final Process process = runtime.exec(cmdLine);

			final InputStreamReader err = new InputStreamReader(process.getErrorStream());
			try {
				final int bufferSize = 256;
				final char[] c = new char[bufferSize];
				final StringBuffer sb = new StringBuffer();
				int len;
				while ((len = err.read(c)) > 0) {
					sb.append(String.valueOf(c, 0, len));
				}

				if (sb.length() != 0) {
					errorQueue.enqueue(ErrorInfo.POST_COMPILER_ERROR, sb.toString());
				}
			} finally {
				err.close();
			}

			final int ret = process.waitFor();
			if (ret != 0) {
				errorQueue.enqueue(ErrorInfo.POST_COMPILER_ERROR, "assembling and linking failed");
				return false;
			}
		} catch (Exception e) {
			errorQueue.enqueue(ErrorInfo.POST_COMPILER_ERROR, "assembling and linking failed");
			return false;
		}

		if (options.keep_output_files) {
			return true;
		}

		return asmFile.delete();
	}
}
