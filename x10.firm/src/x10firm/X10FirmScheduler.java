package x10firm;

import java.util.ArrayList;

import polyglot.frontend.Compiler;
import polyglot.frontend.Goal;
import polyglot.frontend.Job;
import polyglot.main.Options;
import polyglot.util.ErrorInfo;
import polyglot.util.ErrorQueue;
import polyglot.visit.PostCompiled;
import x10.ExtensionInfo.X10Scheduler;
import x10cpp.visit.X10CPPTranslator;
import x10firm.goals.AsmEmitted;
import x10firm.goals.FirmGenerated;
import x10firm.goals.GoalSequence;
import x10firm.goals.OptimizedFirm;
import x10firm.goals.SourceGoalSequence;
import x10firm.types.TypeSystem;

/**
 * Setting the goals for the Firm backend and depend on the X10 scheduler for
 * the rest.
 */
class X10FirmScheduler extends X10Scheduler {
	/**
	 * Initialize the scheduler, duh.
	 * @param info	"==ExtensionInfo.this", because this inner class is static (strange design by X10)
	 */
	public X10FirmScheduler(ExtensionInfo info) {
		super(info);
	}

	@Override
	protected Goal PostCompiled() {
		/*
		 * The other X10 backends and Polyglot use this goal to invoke javac/gcc
		 * the generated source code. In the Firm context this corresponds to li
		 * the assembler output.
		 */
		final Goal postCompiled = new PostCompiled(extInfo) {
			@Override
			protected boolean invokePostCompiler(Options options,
					Compiler compiler, ErrorQueue eq) {
				CompilerOptions opts = (CompilerOptions) options;
				String exe_name = opts.exe_name;
				String asm_name = AsmEmitted.ASM_FILENAME;
				// TODO link our standard library correctly
				String[] cmd = {"gcc",asm_name,"stdlib/primitive_types.c","stdlib/simple_lib.c","-lm","-o",exe_name};

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
		};
		postCompiled.intern(this);

		final Goal asmEmitted = new AsmEmitted(this);
		postCompiled.addPrereq(asmEmitted);
		asmEmitted.intern(this);

		final GoalSequence seq = new GoalSequence("FirmOutputSequence");
		seq.append(asmEmitted);
		seq.append(postCompiled);

		return seq.intern(this);
	}

	@Override
	public Goal CodeGenerated(Job job) {

		final TypeSystem typeSystem = (TypeSystem) extInfo.typeSystem();

		final Goal firm_generated = new FirmGenerated(job, typeSystem);
		firm_generated.intern(this);

		final Goal optimized_firm = new OptimizedFirm(job, typeSystem);
		optimized_firm.intern(this);

		/* Since source goals are per job/compilation unit/source file,
		 * they must include their job into their hashCode for the intern method.
		 */

		final SourceGoalSequence seq = new SourceGoalSequence("FirmTransformationSequence", job);
		seq.append(firm_generated);
		seq.append(optimized_firm);

		return seq.intern(this);
	}
}