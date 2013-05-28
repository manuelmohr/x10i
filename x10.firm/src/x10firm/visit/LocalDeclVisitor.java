package x10firm.visit;

import java.util.LinkedList;
import java.util.List;

import polyglot.ast.Catch_c;
import polyglot.ast.LocalDecl_c;
import polyglot.ast.VarDecl;
import x10.ast.Closure_c;

/**
 * Visitor which collects all local declarations in an ast.
 */
public class LocalDeclVisitor extends DummyDelegatingVisitor {

	/** Will hold all local declarations. */
	private List<VarDecl> localDecls = new LinkedList<VarDecl>();

	/**
	 * Returns all found local declaration.
	 * @return All found local declarations
	 */
	public List<VarDecl> getLocals() {
		return localDecls;
	}

	@Override
	public void visit(final LocalDecl_c n) {
		assert !localDecls.contains(n);
		localDecls.add(n);
		super.visit(n);
	}

	@Override
	public void visit(final Catch_c n) {
		localDecls.add(n.formal());
		super.visit(n);
	}

	@Override
	public void visit(final Closure_c n) {
		/* Don't visit inner closures */
	}
}
