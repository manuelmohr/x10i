package x10firm.visit;

import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Set;

import polyglot.ast.Expr;
import polyglot.ast.Field_c;
import polyglot.ast.LocalDecl_c;
import polyglot.ast.Local_c;
import polyglot.types.LocalInstance;
import x10.ast.Closure_c;

/**
 * Visitor that visits a closure body ast node and collects all
 * "real" locals in the closure. In addition the visitor also
 * collects all var instances which form the context of the closure. 
 */
public class X10ClosureVisitor extends X10DummyDelegatingVisitor {
	
	/**
	 * The formals of the closures. 
	 */
	private List<LocalInstance> formals;
	
	/**
	 * Will hold all local instances of the closure
	 */
	private List<LocalInstance> locals = new LinkedList<LocalInstance>();
	
	/**
	 * Will hold all local instances which form the context of the closure
	 */
	private Set<LocalInstance> savedLocals = new HashSet<LocalInstance>();
	
	/** 
	 * Will be true if we need a reference to the appropriate object in the context of the closure
	 */
	private boolean needSavedThis = false;
	
	/**
	 * Constructor
	 * @param formals_ All formals of the closure
	 */
	public X10ClosureVisitor(final List<LocalInstance> formals_) {
		formals = formals_;
	}
	
	/**
	 * Check if we need a reference to the appropriate object in the context of the closure
	 * @return True if we need a reference to the appropriate object
	 */
	public boolean needSavedThis() {
		return needSavedThis;
	}
	
	/**
	 * Returns all "real" local instances of the closure
	 * @return All "real" local instances of the closure
	 */
	public List<LocalInstance> getLocals() {
		return locals;
	}
	
	/**
	 * Returns all local instances which form the context of the closure
	 * @return All local instances which form the context of the closure
	 */
	public Set<LocalInstance> getSavedLocalInstances() {
		return savedLocals;
	}
	
	@Override
	public void visit(LocalDecl_c n) {
		LocalInstance loc = n.localDef().asInstance();
		assert !locals.contains(loc);
		
		// collect all "real" local instances in the closure
		locals.add(loc);
		
		Expr initexpr = n.init();

		if (initexpr != null)
			visitAppropriate(initexpr);
	}
	
	@Override
	public void visit(Local_c n) {
		LocalInstance loc = n.localInstance();
		
		// don`t include local instances to the context of the closure
		// which are actually "real" local instances. 
		if(!locals.contains(loc) && !formals.contains(loc))
			savedLocals.add(loc);
	}
	
	@Override
	public void visit(Closure_c n) {
		/* DO NOTHING -> Don`t visit inner closures */
	}
	
	@Override
	public void visit(Field_c n) {
		// field access in the closure -> mark that we need an additional reference to the appropriate object
		needSavedThis = true;
	}
}