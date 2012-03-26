package x10firm.visit;

import java.util.LinkedList;
import java.util.List;

import polyglot.ast.LocalDecl_c;
import x10.ast.Closure_c;

/**
 * Visitor which collects all local declarations in an ast.
 */
public class LocalDeclVisitor extends DummyDelegatingVisitor {

	/** Will hold all local declarations. */
	private List<LocalDecl_c> localDecls = new LinkedList<LocalDecl_c>();

	/**
	 * Returns all found local declaration.
	 * @return All found local declarations
	 */
	public List<LocalDecl_c> getLocals() {
		return localDecls;
	}

	@Override
	public void visit(final LocalDecl_c n) {
		assert !localDecls.contains(n);
		localDecls.add(n);
		// Watch out a local declaration can declare other local declarations
		// in their initialization expression (stmt expressions) !!!
		if (n.init() != null) {
			visitAppropriate(n.init());
		}
	}

	@Override
	public void visit(final Closure_c n) {
		/* Don`t visit inner closures */
	}
}
