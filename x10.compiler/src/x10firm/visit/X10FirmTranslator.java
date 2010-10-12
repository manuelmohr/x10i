package x10firm.visit;

import java.io.InputStreamReader;
import java.util.Collection;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Set;

import polyglot.ast.Assert;
import polyglot.ast.Block;
import polyglot.ast.Catch;
import polyglot.ast.ClassDecl;
import polyglot.ast.ClassMember;
import polyglot.ast.ConstructorDecl;
import polyglot.ast.FieldDecl;
import polyglot.ast.For;
import polyglot.ast.MethodDecl;
import polyglot.ast.Node;
import polyglot.ast.NodeFactory;
import polyglot.ast.SourceCollection;
import polyglot.ast.SourceFile;
import polyglot.ast.Stmt;
import polyglot.ast.SwitchBlock;
import polyglot.frontend.Compiler;
import polyglot.frontend.ExtensionInfo;
import polyglot.frontend.Job;
import polyglot.frontend.TargetFactory;
import polyglot.main.Options;
import polyglot.main.Report;
import polyglot.types.ClassType;
import polyglot.types.MemberDef;
import polyglot.types.Name;
import polyglot.types.TypeSystem;
import polyglot.util.CodeWriter;
import polyglot.util.ErrorInfo;
import polyglot.util.ErrorQueue;
import polyglot.util.InternalCompilerError;
import polyglot.util.StdErrorQueue;
import polyglot.visit.Translator;
import x10.util.ClassifiedStream;
import x10.util.StreamWrapper;
import x10.visit.StaticNestedClassRemover;
import x10cpp.X10CPPCompilerOptions;
import x10cpp.debug.LineNumberMap;
import x10cpp.postcompiler.CXXCommandBuilder;
import x10cpp.types.X10CPPContext_c;

public class X10FirmTranslator extends Translator {
	public X10FirmTranslator(Job job, TypeSystem ts, NodeFactory nf, TargetFactory tf) {
		super(job, ts, nf, tf);
	}
	
	/** Return the dir where classes in the given package will be generated. Does not include 
	 * output directory prefix. Accepts null input. 
	 */
	public static String packagePath (String pkg) {
		return (pkg==null ? "" : pkg.replace('.', '/') + '/');
	}
	
	// delegate the print to the pretty printer
	public void print(Node parent, Node n, CodeWriter w) {
		assert (n != null);
		super.print(parent, n, w);
	}
	
	// returns the full class name of the given class type (with package name etc.) 
    public static String getFullClassName(ClassType ct) {
        String pkg = null;
        if (ct.package_() != null)
            pkg = ct.package_().fullName().toString();
        // Remove static nested classes in the AST.
        Name name = StaticNestedClassRemover.mangleName(ct.def());
        return X10FirmTranslator.packagePath(pkg) + name.toString(); 
    }
	
	public static final String postcompile = "postcompile";
	
	// for post compilation of the firm graph
	public static boolean postCompile(X10CPPCompilerOptions options, Compiler compiler, ErrorQueue eq) {
		if (eq.hasErrors())
			return false;

		if (options.post_compiler != null && !options.output_stdout) {
			// use set to avoid duplicates
            Set<String> compilationUnits = new HashSet<String>(options.compilationUnits());
            CXXCommandBuilder ccb = CXXCommandBuilder.getCXXCommandBuilder(options, eq);
            String[] cxxCmd = ccb.buildCXXCommandLine(compilationUnits);

			if (!doPostCompile(options, eq, compilationUnits, cxxCmd)) return false;
            
			// FIXME: [IP] HACK: Prevent the java post-compiler from running
			options.post_compiler = null;
		}
		return true;
	}

    public static boolean doPostCompile(Options options, ErrorQueue eq, Collection<String> outputFiles, String[] cxxCmd) {
        if (Report.should_report(postcompile, 1)) {
        	StringBuffer cmdStr = new StringBuffer();
        	for (int i = 0; i < cxxCmd.length; i++)
        		cmdStr.append(cxxCmd[i]+" ");
        	Report.report(1, "Executing post-compiler " + cmdStr);
        }

        try {
            Runtime runtime = Runtime.getRuntime();
        	Process proc = runtime.exec(cxxCmd, null, options.output_directory);

        	InputStreamReader err = new InputStreamReader(proc.getErrorStream());

        	String output = null;
        	try {
        		char[] c = new char[72];
        		int len;
        		StringBuffer sb = new StringBuffer();
        		while((len = err.read(c)) > 0) {
        			sb.append(String.valueOf(c, 0, len));
        		}

        		if (sb.length() != 0) {
        			output = sb.toString();
        		}
        	}
        	finally {
        		err.close();
        	}

        	proc.waitFor();

        	if (!options.keep_output_files) {
        		String[] rmCmd = new String[1+outputFiles.size()];
        		rmCmd[0] = "rm";
        		Iterator<String> iter = outputFiles.iterator();
        		for (int i = 1; iter.hasNext(); i++)
        			rmCmd[i] = iter.next();
        		runtime.exec(rmCmd);
        	}

        	if (output != null)
        		eq.enqueue(proc.exitValue() > 0 ? ErrorInfo.POST_COMPILER_ERROR : ErrorInfo.WARNING, output);
        	if (proc.exitValue() > 0) {
        		eq.enqueue(ErrorInfo.POST_COMPILER_ERROR,
        				"Non-zero return code: " + proc.exitValue());
        		return false;
        	}
        }
        catch(Exception e) {
        	eq.enqueue(ErrorInfo.POST_COMPILER_ERROR, e.getMessage() != null ? e.getMessage() : e.toString());
        	return false;
        }
        return true;
    }
}
