package x10firm;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import polyglot.ast.NodeFactory;
import polyglot.frontend.AllBarrierGoal;
import polyglot.frontend.BarrierGoal;
import polyglot.frontend.Goal;
import polyglot.frontend.Job;
import polyglot.frontend.VisitorGoal;
import polyglot.types.TypeSystem;
import polyglot.visit.NodeVisitor;
import x10.ExtensionInfo;
import x10.ExtensionInfo.X10Scheduler;
import x10.ast.X10NodeFactory_c;
import x10c.visit.ClosureRemover;
import x10firm.goals.AsmEmitted;
import x10firm.goals.FirmGenerated;
import x10firm.goals.GoalSequence;
import x10firm.goals.Linked;
import x10firm.goals.LoweringFirm;
import x10firm.goals.OptimizeFirm;
import x10firm.types.FirmTypeSystem;
import x10firm.types.GenericTypeSystem;
import x10firm.visit.FirmGenerator;
import x10firm.visit.StaticInitializer;

/**
 * Setting the goals for the Firm backend and depend on the X10 scheduler for
 * the rest.
 */
public class FirmScheduler extends X10Scheduler {
	private static final String ASM_PREFIX = "x10firm_";
	private static final String ASM_SUFFIX = ".s";

	private final FirmTypeSystem firmTypeSystem;
	private File asmOutput;
	private final FirmGenerator generator;

	/**
	 * Initialize the scheduler.
	 * @param info "==ExtensionInfo.this", because this inner class is static
	 * (strange design by X10)
	 */
	public FirmScheduler(final ExtensionInfo info) {
		super(info);
		final GenericTypeSystem typeSystem = (GenericTypeSystem)info.typeSystem();
		firmTypeSystem = new FirmTypeSystem(typeSystem);

		final CompilerOptions options = (CompilerOptions) info.getOptions();
		final X10NodeFactory_c nodeFactory = (X10NodeFactory_c) extInfo.nodeFactory();
		generator = new FirmGenerator(firmTypeSystem, typeSystem, nodeFactory, options);
	}

	@Override
	protected Goal PostCompiled() {

		/*
		 * The other X10 backends and Polyglot use this goal to invoke
		 * javac/gcc on the generated source code.  In the Firm context this
		 * corresponds to emitting assembler and linking with the stdlib.
		 */
		final GoalSequence seq = new GoalSequence("FirmOutputSequence");

		final Goal loweringFirm = new LoweringFirm(this, generator).intern(this);
		seq.append(loweringFirm);

		final CompilerOptions options = (CompilerOptions) this.extInfo.getOptions();
		if (options.x10_config.OPTIMIZE) {
			Goal optimized = new OptimizeFirm(this);
			optimized = optimized.intern(this);
			seq.append(optimized);
		}

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

		Goal asmEmitted = new AsmEmitted(this, asmOutput);
		asmEmitted = asmEmitted.intern(this);
		seq.append(asmEmitted);

		if (options.assembleAndLink()) {
			Goal linked = new Linked(extInfo, asmOutput);
			linked = linked.intern(this);
			seq.append(linked);
		}

		return seq.intern(this);
	}

	@Override
	public List<Goal> goals(final Job job) {
		final List<Goal> superGoals = super.goals(job);
		final List<Goal> goals = new ArrayList<Goal>();
		final Goal cg = codegenPrereq(job);
		for (final Goal g : superGoals) {
			if (g == cg) {
				goals.add(StaticNestedClassRemover(job));
				goals.add(StaticInitializer(job));
				goals.add(ClosureRemover(job));
			}
			goals.add(g);
		}

		return goals;
	}

	@Override
	public Goal CodeGenBarrier() {
		final String name = "CodeGenBarrier";
		if (extInfo.getOptions().compile_command_line_only) {
			final BarrierGoal barrier = new BarrierGoal(name, commandLineJobs()) {
				private static final long serialVersionUID = 2258041064037983928L;

				@Override
				public Goal prereqForJob(final Job job) {
					return codegenPrereq(job);
				}
			};
			return barrier.intern(this);
		}

		final AllBarrierGoal allBarrier = new AllBarrierGoal(name, this) {
			private static final long serialVersionUID = 4089824072381830523L;

			@Override
			public Goal prereqForJob(final Job job) {
				if (super.scheduler.shouldCompile(job)) {
					return codegenPrereq(job);
				} else if (x10firm.ExtensionInfo.isAllowedClassName(job
						.toString())) {
					// DELETE ME (whole else if): Need library support
					return codegenPrereq(job);
				}

				return null;
			}
		};
		return allBarrier.intern(this);
	}

	/** A visitor which does nothing. */
	private static class NoVisitor extends NodeVisitor {
		/** Constructs a new NoVisitor. */
		public NoVisitor() {
		}
	}

	@Override
	public Goal NativeClassVisitor(final Job job) {
		return new VisitorGoal("NoVisitor", job, new NoVisitor()).intern(this);
	}

	private Goal ClosureRemover(final Job job) {
		final TypeSystem ts = extInfo.typeSystem();
		final NodeFactory nf = extInfo.nodeFactory();
		return new ValidatingVisitorGoal("ClosureRemover", job,
				new ClosureRemover(job, ts, nf)).intern(this);
	}

	private Goal StaticInitializer(final Job job) {
		final TypeSystem ts = extInfo.typeSystem();
		final NodeFactory nf = extInfo.nodeFactory();
		return new ValidatingVisitorGoal("StaticInitialized", job,
				new StaticInitializer(job, ts, nf)).intern(this);
	}

	@Override
	public Goal CodeGenerated(final Job job) {
		final Goal firmGenerated = new FirmGenerated(job, generator).intern(this);
		return firmGenerated;
	}
}
