package x10firm;

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
import x10firm.goals.SourceGoalSequence;
import x10firm.types.FirmTypeSystem;
import x10firm.types.GenericTypeSystem;
import x10firm.visit.X10StaticInitializer;

/**
 * Setting the goals for the Firm backend and depend on the X10 scheduler for
 * the rest.
 */
class X10FirmScheduler extends X10Scheduler {
	private final FirmTypeSystem firmTypeSystem;

	/**
	 * Initialize the scheduler, duh.
	 * @param info	"==ExtensionInfo.this", because this inner class is static
	 * (strange design by X10)
	 */
	public X10FirmScheduler(ExtensionInfo info) {
		super(info);
		this.firmTypeSystem = new FirmTypeSystem((GenericTypeSystem) info.typeSystem());
	}

	@Override
	protected Goal PostCompiled() {
		
		/*
		 * The other X10 backends and Polyglot use this goal to invoke
		 * javac/gcc on the generated source code.  In the Firm context this
		 * corresponds to emitting assembler and linking with the stdlib.
		 */
		
		final Goal loweringFirm = new LoweringFirm(this, firmTypeSystem);
		loweringFirm.intern(this);

		final Goal asmEmitted = new AsmEmitted(this);
		asmEmitted.intern(this);

		final Goal linked = new Linked(extInfo);
		linked.intern(this);

		final GoalSequence seq = new GoalSequence("FirmOutputSequence");
		seq.append(loweringFirm);
		seq.append(asmEmitted);
		seq.append(linked);

		return seq.intern(this);
	}
	
    @Override
    public List<Goal> goals(Job job) {
        List<Goal> superGoals = super.goals(job);
        List<Goal> goals = new ArrayList<Goal>(superGoals.size()+10);
        final Goal cg = codegenPrereq(job);
        for (Goal g : superGoals) {
            if (g == cg) {
                goals.add(StaticInitializer(job));
                goals.add(ClosureRemover(job));
            }
            goals.add(g);
        }
        return goals;
    }
    
    @Override
    public Goal CodeGenBarrier() {
        String name = "CodeGenBarrier";
        if (extInfo.getOptions().compile_command_line_only) {
            return new BarrierGoal(name, commandLineJobs()) {
                private static final long serialVersionUID = 2258041064037983928L;
                @Override
                public Goal prereqForJob(Job job) {
                    return codegenPrereq(job);
                }
            }.intern(this);
        } else {
            return new AllBarrierGoal(name, this) {
                private static final long serialVersionUID = 4089824072381830523L;
                @Override
                public Goal prereqForJob(Job job) {
                	if(super.scheduler.shouldCompile(job)) {
                		return codegenPrereq(job);
                	} else if(AsmEmitted.isAllowedClassName(job.toString())) // DELETE ME (whole else if): Need library support 
                		return codegenPrereq(job);
                	
                    return null;
                }
            }.intern(this);
        }
    }
    
    
    // Visitor that does nothing 
    private static class NoVisitor extends NodeVisitor {
       public NoVisitor() { }
    }
    
    @Override
    // Get out of the native class visitor in firm 
    public Goal NativeClassVisitor(Job job) {
       return new VisitorGoal("NoVisitor", job, new NoVisitor()).intern(this);
    }

    private Goal ClosureRemover(Job job) {
        TypeSystem ts = extInfo.typeSystem();
        NodeFactory nf = extInfo.nodeFactory();
		return new ValidatingVisitorGoal("ClosureRemoved", job, new ClosureRemover(job, ts, nf)).intern(this);
	}
    
    private Goal StaticInitializer(Job job) {
        TypeSystem ts = extInfo.typeSystem();
        NodeFactory nf = extInfo.nodeFactory();
        return new ValidatingVisitorGoal("StaticInitialized", job, new X10StaticInitializer(job, ts, nf)).intern(this);
    }

	@Override
	public Goal CodeGenerated(Job job) {

		final TypeSystem typeSystem = extInfo.typeSystem();
		final X10NodeFactory_c nodeFactory = (X10NodeFactory_c) extInfo.nodeFactory();

		final Goal firm_generated = new FirmGenerated(job, typeSystem, firmTypeSystem, nodeFactory);
		firm_generated.intern(this);

		/*
		 * Since source goals are per job/compilation unit/source file,
		 * they must include their job into their hashCode for the internal
		 * method.
		 */

		final SourceGoalSequence seq = new SourceGoalSequence("FirmTransformationSequence", job);
		seq.append(firm_generated);

		return seq.intern(this);
	}
}