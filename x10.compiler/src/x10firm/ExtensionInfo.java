package x10firm;

import polyglot.ast.NodeFactory;
import polyglot.frontend.Compiler;
import polyglot.frontend.Goal;
import polyglot.frontend.Job;
import polyglot.frontend.Scheduler;

import polyglot.main.Options;
import polyglot.types.TypeSystem;
import polyglot.util.ErrorQueue;
import polyglot.visit.PostCompiled;
import x10.ast.X10NodeFactory_c;
import x10firm.ast.X10FirmDelFactory_c;
import x10firm.ast.X10FirmExtFactory_c;
import x10firm.types.X10FirmTypeSystem_c;
import x10firm.visit.X10FirmTranslator;

public class ExtensionInfo extends x10cpp.ExtensionInfo {
	
	@Override
	public String compilerName() {
		return "x10firm";
	}

	@Override
	public polyglot.main.Version version() {
		return new Version();
	}

	@Override
	protected Options createOptions() {
		return new X10FirmCompilerOptions(this);
	}
	
	@Override
	protected NodeFactory createNodeFactory() {
		return new X10NodeFactory_c(this, new X10FirmExtFactory_c(), new X10FirmDelFactory_c()) { };
	}
	
	// X10Firm-specific goals and scheduling
	@Override
	protected Scheduler createScheduler() {
		return new X10FirmScheduler(this);
	}
	
	@Override
	protected TypeSystem createTypeSystem() {
		return new X10FirmTypeSystem_c();
	}
	
	// X10Firm job scheduler
	public static class X10FirmScheduler extends x10cpp.ExtensionInfo.X10CPPScheduler {
		protected X10FirmScheduler(ExtensionInfo info) {
			super(info);
		}
		// TODO: Add post compilation -> gen machine code from firm graph
		@Override
		protected Goal PostCompiled() {
		    return new PostCompiled(extInfo) {
		    	private static final long serialVersionUID = 6627554599276926259L;
		        @Override
				protected boolean invokePostCompiler(Options options, Compiler compiler, ErrorQueue eq) {
		        	return true;
		        }
		    }.intern(this);
		}
		// pack the x10 firm translator into the X10 firm scheduler
		@Override
		public Goal CodeGenerated(Job job) {
			TypeSystem ts = extInfo.typeSystem();
			NodeFactory nf = extInfo.nodeFactory();
			return new ValidatingOutputGoal(job, new X10FirmTranslator(job, ts, nf, extInfo.targetFactory())).intern(this);
		}
	}
}
