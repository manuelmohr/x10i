package x10firm.visit;

import polyglot.ast.NodeFactory;
import polyglot.ast.Node;
import polyglot.ast.SourceFile;
import polyglot.ast.TopLevelDecl;
import polyglot.frontend.Job;
import polyglot.frontend.TargetFactory;
import polyglot.types.ClassType;
import polyglot.types.Name;
import polyglot.types.TypeSystem;
import polyglot.util.CodeWriter;
import polyglot.visit.Translator;
import x10.visit.StaticNestedClassRemover;

/**
 * We need a Translator to hook into the Polyglot/X10 framework, but we do not
 * generate files directly. Therefore, we must ensure that no actual code from
 * Translator is called.
 * 
 * @author zwinkau
 * 
 */
public class X10FirmTranslator extends Translator {
	public X10FirmTranslator(Job j, TypeSystem ty, NodeFactory n,
			TargetFactory ta) {
		super(j, ty, n, ta);
	}

	@Override
	public void print(Node parent, Node child, CodeWriter w) {
		throw new RuntimeException("Must not be called");
	}

	@Override
	protected boolean translateSource(SourceFile sfn) {
		throw new RuntimeException("Must not be called");
	}

	@Override
	protected void translateTopLevelDecl(CodeWriter w, SourceFile source,
			TopLevelDecl decl) {
		throw new RuntimeException("Must not be called");
	}

	@Override
	protected Object clone() throws CloneNotSupportedException {
		throw new RuntimeException("Must not be called");
	}

	@Override
	public boolean translate(Node ast) {
		final X10FirmCodeGenerator v = new X10FirmCodeGenerator(this);
		v.visitAppropriate(ast);
		return true; // success
	}

	/**
	 * Return the dir where classes in the given package will be generated. Does
	 * not include output directory prefix. Accepts null input.
	 */
	private static String packagePath(String pkg) {
		return (pkg == null ? "" : pkg.replace('.', '/') + '/');
	}

	// returns the full class name of the given class type (with package name
	// etc.)
	public static String getFullClassName(ClassType ct) {
		String pkg = null;
		if (ct.package_() != null)
			pkg = ct.package_().fullName().toString();
		// Remove static nested classes in the AST.
		Name name = StaticNestedClassRemover.mangleName(ct.def());
		return X10FirmTranslator.packagePath(pkg) + name.toString();
	}
}
