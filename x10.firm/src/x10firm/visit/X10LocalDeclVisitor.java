package x10firm.visit;

import java.util.LinkedList;
import java.util.List;

import polyglot.ast.LocalDecl_c;
import x10.ast.Closure_c;

/** 
 * Visitor which extracts all local declarations from an ast
 */
public class X10LocalDeclVisitor extends X10DummyDelegatingVisitor {
	
	/** Will hold all local declarations. 
	 * 
	 */
	private List<LocalDecl_c> localDecls = new LinkedList<LocalDecl_c>();
	
	/**
	 * Returns all found local declaration
	 * @return All found local declarations
	 */
	public List<LocalDecl_c> getLocals() {
		return localDecls;
	}
	
	@Override
	public void visit(LocalDecl_c n) {
		assert !localDecls.contains(n);
		localDecls.add(n);
	}
	
	@Override
	public void visit(Closure_c n) {
		/* Don`t visit inner closures */
	}
}