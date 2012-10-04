package x10firm;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;

import polyglot.frontend.Goal;
import polyglot.frontend.Job;
import polyglot.frontend.SourceGoal_c;
import polyglot.types.TypeSystem_c;
import polyglot.util.ErrorQueue;
import x10.ExtensionInfo;
import x10.ExtensionInfo.X10Scheduler;
import x10.ast.X10NodeFactory_c;
import x10c.visit.ClosureRemover;
import x10firm.goals.AsmEmitted;
import x10firm.goals.FirmGenerated;
import x10firm.goals.Linked;
import x10firm.goals.LoweringFirm;
import x10firm.goals.OptimizeFirm;
import x10firm.visit.StaticInitializer;

/**
 * Setting the goals for the Firm backend and depend on the X10 scheduler for
 * the rest.
 */
public class FirmScheduler extends X10Scheduler {
	private static final String ASM_PREFIX = "x10firm_";
	private static final String ASM_SUFFIX = ".s";

	private File asmOutput;
	private final TypeSystem_c typeSystem;
	private final CompilerOptions options;
	private final X10NodeFactory_c nodeFactory;

	/** A source goal which does nothing. */
	private class SourceNop extends SourceGoal_c {
		public SourceNop(final String name, final Job job) {
			super(name, job);
			scheduler = FirmScheduler.this;
		}
		@Override
		public boolean runTask() {
			return true;
		}
	}

	/**
	 * Initialize the scheduler.
	 * @param info "==ExtensionInfo.this", because this inner class is static
	 * (strange design by X10)
	 */
	public FirmScheduler(final ExtensionInfo info) {
		super(info);
		typeSystem = (TypeSystem_c)info.typeSystem();
		options = (CompilerOptions)info.getOptions();
		nodeFactory = (X10NodeFactory_c)info.nodeFactory();
	}

	@Override
	protected Goal PostCompiled() {
		final Goal loweringFirm = new LoweringFirm(this).intern(this);

		if (options.x10_config.ONLY_TYPE_CHECKING)
			return loweringFirm;

		final Goal optimized;
		optimized = new OptimizeFirm().intern(this);
		optimized.addPrereq(loweringFirm);

		try {
			if (options.assembleAndLink()) {
				asmOutput = File.createTempFile(ASM_PREFIX, ASM_SUFFIX);
			} else {
				if (options.executable_path == null) {
					final String defaultFile = "asm_output.s";
					System.err.println("Warning: -o not specified, defaulting to " + defaultFile);
					asmOutput = new File(defaultFile);
				} else {
					asmOutput = new File(options.executable_path);
				}
			}
		} catch (IOException e) {
			throw new RuntimeException("Could not create asm file", e);
		}

		final Goal asmEmitted = new AsmEmitted(asmOutput).intern(this);
		asmEmitted.addPrereq(optimized);

		final Goal last;
		if (options.assembleAndLink()) {
			final ErrorQueue errorQueue = extInfo.compiler().errorQueue();
			last = new Linked(options, asmOutput, errorQueue).intern(this);
			last.addPrereq(asmEmitted);
		} else {
			last = asmEmitted;
		}

		return last;
	}

	@Override
	public Goal CodeGenerated(final Job job) {
		return new SourceNop("Nop(CodeGenerated)", job);
	}

	@Override
	public Goal CodeGenBarrier() {
		return new FirmGenerated(this, typeSystem, nodeFactory, options).intern(this);
	}

	@Override
	public List<Goal> goals(final Job job) {
		final List<Goal> superGoals = super.goals(job);
		final List<Goal> goals = new ArrayList<Goal>();
		final Goal cg = Lowerer(job);
		for (final Goal g : superGoals) {
			if (g == cg) {
				goals.add(StaticInitializer(job));
				//goals.add(StaticNestedClassRemover(job));
				goals.add(g); /* g (Lowerer) might construct new closures, so ClosureRemover must run afterwards */
				goals.add(ClosureRemover(job));
			} else {
				goals.add(g);
			}
		}

		return goals;
	}

	/** returns requirement for codegen barrier. */
	public Goal codeGenPrereq(final Job job) {
		return ClosureRemover(job);
	}

	@Override
	public Goal NativeClassVisitor(final Job job) {
		return new SourceNop("Nop(NativeClassVisitor)", job).intern(this);
	}

	private Goal ClosureRemover(final Job job) {
		return new ValidatingVisitorGoal("ClosureRemover", job,
				new ClosureRemover(job, typeSystem, nodeFactory)).intern(this);
	}

	private Goal StaticInitializer(final Job job) {
		return new ValidatingVisitorGoal("StaticInitialized", job,
				new StaticInitializer(job, typeSystem, nodeFactory)).intern(this);
	}

	@Override
	public boolean shouldCompile(final Job job) {
		if (commandLineJobs().contains(job))
			return true;
		if (x10firm.ExtensionInfo.shouldGenerateCodeFor(job))
			return true;
		return super.shouldCompile(job);
	}

	private void dumpGoalGraph(final String filename) {
		try {
			final FileOutputStream out = new FileOutputStream(filename);
			final PrintWriter writer = new PrintWriter(out);
			final Goal root = EndAll();
			GoalGraphDumper.dumpGoalGraph(writer, root);
			writer.close();
			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	@Override
	public boolean runToCompletion() {
		if (options.dumpGoalGraph()) {
			dumpGoalGraph("goalgraph-before.vcg");
		}
		final boolean result = super.runToCompletion();
		if (options.dumpGoalGraph()) {
			dumpGoalGraph("goalgraph-after.vcg");
		}
		return result;
	}
}
