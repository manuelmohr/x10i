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
import x10.types.ClosureDef;
import x10.types.ClosureInstance;

/**
 * Visitor that visits a closure body ast node and collects all
 * "real" locals in the closure. In addition the visitor also
 * collects all var instances which form the context of the closure. 
 */
public class X10ClosureVisitor extends X10DummyDelegatingVisitor {
	
	/**
	 * The formals of the closures. 
	 */
	private List<LocalInstance> formals = new LinkedList<LocalInstance>();
	
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
	 * @param formals All formals of the closure
	 */
	public X10ClosureVisitor(final List<LocalInstance> formals) {
		this.formals.addAll(formals);
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
		final LocalInstance loc = n.localDef().asInstance();
		assert !locals.contains(loc);
		
		// collect all "real" local instances in the closure
		locals.add(loc);
		
		final Expr initexpr = n.init();

		if (initexpr != null)
			visitAppropriate(initexpr);
	}
	
	@Override
	public void visit(Local_c n) {
		final LocalInstance loc = n.localInstance();
		
		// don`t include local instances
		// which are actually "real" local instances. 
		if(!locals.contains(loc) && !formals.contains(loc))
			savedLocals.add(loc);
	}
	
	@Override
	public void visit(Closure_c n) {
		// inner closures -> we must watch out for the formals of the inner closures -> append the formals 
		// of the inner closure to the current formals
		final ClosureDef def = n.closureDef();
		final ClosureInstance closureInstance = def.asInstance();
		
		formals.addAll(closureInstance.formalNames());
		// and now visit the inner closure
		visitAppropriate(n.body());
	}
	
	@Override
	public void visit(Field_c n) {
		// field access in the closure -> mark that we need an additional reference to the appropriate object
		needSavedThis = true;
	}
}