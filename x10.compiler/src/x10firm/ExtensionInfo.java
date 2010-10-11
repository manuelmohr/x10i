package x10firm;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.lang.reflect.Constructor;
import java.util.List;

import polyglot.ast.NodeFactory;
import polyglot.frontend.Compiler;
import polyglot.frontend.Goal;
import polyglot.frontend.JLScheduler;
import polyglot.frontend.Job;
import polyglot.frontend.Scheduler;
import polyglot.frontend.VisitorGoal;

import polyglot.main.Options;
import polyglot.main.Report;
import polyglot.types.MemberClassResolver;
import polyglot.types.SemanticException;
import polyglot.types.TopLevelResolver;
import polyglot.types.TypeSystem;
import polyglot.util.ErrorQueue;
import polyglot.util.InternalCompilerError;
import polyglot.visit.ContextVisitor;
import polyglot.visit.PostCompiled;
import x10.Configuration;
import x10.ExtensionInfo.X10Scheduler.ValidatingOutputGoal;
import x10.ExtensionInfo.X10Scheduler.ValidatingVisitorGoal;
import x10.ast.X10NodeFactory_c;
import x10.optimizations.Optimizer;
import x10.visit.CheckNativeAnnotationsVisitor;
import x10.visit.NativeClassVisitor;
import x10cpp.X10CPPCompilerOptions;
import x10cpp.ExtensionInfo.X10CPPScheduler;
import x10cpp.postcompiler.CXXCommandBuilder;
import x10cpp.types.X10CPPSourceClassResolver;
import x10cpp.types.X10CPPTypeSystem_c;
import x10cpp.visit.X10CPPTranslator;
import x10firm.ast.X10FirmDelFactory_c;
import x10firm.ast.X10FirmExtFactory_c;
import x10firm.types.X10FirmTypeSystem_c;
import x10firm.visit.X10FirmTranslator;

public class ExtensionInfo extends x10cpp.ExtensionInfo {
	
	public String compilerName() {
		return "x10firm";
	}

	public polyglot.main.Version version() {
		return new Version();
	}

	protected Options createOptions() {
		return new X10FirmCompilerOptions(this);
	}
	
	protected NodeFactory createNodeFactory() {
		return new X10NodeFactory_c(this, new X10FirmExtFactory_c(), new X10FirmDelFactory_c()) { };
	}
	
	// X10Firm-specific goals and scheduling
	protected Scheduler createScheduler() {
		return new X10FirmScheduler(this);
	}
	
	protected TypeSystem createTypeSystem() {
		return new X10FirmTypeSystem_c();
	}
	
	// X10Firm job scheduler
	public static class X10FirmScheduler extends x10cpp.ExtensionInfo.X10CPPScheduler {
		protected X10FirmScheduler(ExtensionInfo extInfo) {
			super(extInfo);
		}
		// TODO: Add post compilation -> gen machine code from firm graph
		@Override
		protected Goal PostCompiled() {
		    return new PostCompiled(extInfo) {
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
