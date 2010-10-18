package x10firm.visit;

import polyglot.ast.NodeFactory;
import polyglot.frontend.Job;
import polyglot.frontend.TargetFactory;
import polyglot.types.ClassType;
import polyglot.types.Name;
import polyglot.types.TypeSystem;
import polyglot.visit.Translator;
import x10.visit.StaticNestedClassRemover;

public class X10FirmTranslator extends Translator {
	public X10FirmTranslator(Job j, TypeSystem ty, NodeFactory n, TargetFactory ta) {
		super(j, ty, n, ta);
	}
	
	/** Return the dir where classes in the given package will be generated. Does not include 
	 * output directory prefix. Accepts null input. 
	 */
	private static String packagePath (String pkg) {
		return (pkg==null ? "" : pkg.replace('.', '/') + '/');
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
}
