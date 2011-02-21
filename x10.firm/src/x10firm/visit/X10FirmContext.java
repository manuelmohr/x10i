package x10firm.visit;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

import polyglot.ast.ClassMember;
import polyglot.ast.Stmt;
import polyglot.types.FieldInstance;
import polyglot.types.LocalInstance;
import polyglot.types.VarInstance;
import x10.types.X10ClassType;

/** 
 * Class for saving variable instances (locals and fields) and the appropriate "firm" indices. 
 */
class X10VarEntry {
	private int idx;
	private VarInstance<?> var;
	
	private X10VarEntry(final VarInstance<?> var_, final int idx_) {
		assert(var_ != null);
		var = var_;
		idx = idx_;
	}
	
	/**
	 * Creates a new var entry for a local instance
	 * @param loc_ The local instance
	 * @param idx_ The "local" index (firm) for the local variable
	 * @return The created var entry. 
	 */
	public static X10VarEntry newVarEntryForLocalInstance(final LocalInstance loc_, final int idx_) {
		return new X10VarEntry(loc_, idx_);
	}
	
	/**
	 * Creates a new var entry for a field instance
	 * @param field_ The field instance
	 * @return The created var entry.
	 */
	public static X10VarEntry newVarEntryForFieldInstance(final FieldInstance field_) {
		return new X10VarEntry(field_, -1);
	}
	
	/**
	 * The index of the var entry -> -1 if the var entry is actually a field instance
	 * @return The index of the local instance.
	 */
	public int getIdx() {
		return idx;
	}
	
	/**
	 * Returns the var instance of the var key
	 * @return The var instance
	 */
	public VarInstance<?> getVarInstance() {
		return var;
	}
}


/**
 * Class that holds attributes (scopes, mapping of local instance variables etc.) for a new method.
 * For every new method entry we will create a new firm context.
 */
public class X10FirmContext {
	/** Holds the topmost firmScope. -> Push a dummy frame in the current FirmContext */
	private X10FirmScope topFirmScope = new X10FirmScope();

	/** Maps VarInstances to the appropriate "VarEntry" entries */
	private Map<VarInstance<?>, X10VarEntry> varEntryMapper = new HashMap<VarInstance<?>, X10VarEntry>();
	
	/**
	 * Reference to the current class type
	 */
	private X10ClassType curClass;

	/**
	 * Will hold the corresponding statement if we have reached a labeled statement. Otherwise null.
	 */
	private Stmt stmt;

	/**
	 * Will hold the corresponding label if we have reached a labeled statement. Otherwise null.
	 */
	private String label;
	
	/**
	 * Reference to the upper firm context
	 */
	private X10FirmContext outer;
	
	/**
	 * True if we are currently in a closure
	 */
	private boolean inClosure = false;
	
	/**
	 * List with the class members which must be initialised explicitly in a constructor etc. 
	 */
	private List<ClassMember> initClassMembers = null;

	/**
	 * Create a new Firm context
	 */
	public X10FirmContext() {
		
	}
	
	/**
	 * Sets the current class
	 */
	public void setCurClass(X10ClassType curClass) {
		this.curClass = curClass;
	}
	
	/**
	 * Returns the current class
	 */
	public X10ClassType getCurClass() {
		return curClass;
	}
	
	/**
	 * Sets the class members which must be intialised explicitly
	 */
	public void setInitClassMembers(List<ClassMember> members) {
		assert(initClassMembers == null); // method should only be called once
		if(initClassMembers != null) {
			System.out.println("YES");
		}
		initClassMembers = members;
	}
	
	/**
	 * Returns all class members which must be manually initialized
	 * @return A list with all class members which must be manually intialized. 
	 */
	public List<ClassMember> getInitClassMembers() {
		assert(initClassMembers != null);
		return initClassMembers;
	}
	
	/**
	 * Pushes a new firm context
	 * @param newContext The new firm context which should be pushed
	 * @return The new firm context which was pushed.
	 */
	public X10FirmContext pushFirmContext(X10FirmContext newContext) {
		assert newContext != null;
		newContext.outer = this;
		return newContext;
	}
	
	/**
	 * Pops the topmost firm context
	 * @return The upper firm context
	 */
	public X10FirmContext popFirmContext() {
		assert outer != null;
		return outer;
	}
	
	/**
	 * Marking that we are currently in a closure
	 * @param in True if we are currently in a closure 
	 */
	public void setInClosure(boolean in) {
		inClosure = in;
	}
	
	/**
	 * Checks if we are currently in a closure
	 * @return True if we are currently in a closure
	 */
	public boolean isInClosure() {
		return inClosure;
	}
	
	/** Sets the "VarEntry" for a given variable (local variable or field instance)
	 * @param entry The "VarEntry" for the given variable
	 */
	public void setVarEntry(X10VarEntry entry) {
		assert !varEntryMapper.containsKey(entry.getVarInstance());
		varEntryMapper.put(entry.getVarInstance(), entry);
	}

	/** Returns the "VarEntry" for a given variable (local variable or field instance)
	 * @return The "VarEntry" of the given variable or null if the variable could not be found
	 */
	public X10VarEntry getVarEntry(VarInstance<?> var) {
		X10VarEntry ret = varEntryMapper.get(var);
		if(ret == null) {
			if(outer != null) 
				return outer.getVarEntry(var);
			assert(false);
			return null;
		}
		
		return ret;
	}
	
	/** Returns the "VarEntry" for a given instance variable in the current scope
	 * @return The "VarEntry" of the given instance variable in the current scope or 
	 * null if the instance variable could not be found.
	 */
	public X10VarEntry getVarEntryInThisScope(VarInstance<?> var) {
		return varEntryMapper.get(var);
	}

	/** Pushes a new firm scope
	 * @param scope The firm scope which should be pushed
	 * @return The new firm scope
	 */
	public X10FirmScope pushFirmScope(X10FirmScope scope) {
		scope.setPrev(topFirmScope);
		topFirmScope = scope;
		return scope;
	}

	/** Pops the topmost firm scope
	 * @return The upper firm scope of the topmost firm scope
	 */
	public X10FirmScope popFirmScope() {
		assert topFirmScope != null;
		topFirmScope = topFirmScope.getPrev();
		return topFirmScope;
	}

	/** Returns the topmost firm scope
	 * @return Topmost firm scope
	 */
	public X10FirmScope getTopScope() {
		assert topFirmScope != null;
		return topFirmScope;
	}

	/**
	 * Set the statement and label in a labeled statement
	 * @param label The label of the labeled statement
	 * @param stmt The statement of the labeled statement
	 */
	public void setLabeledStmt(String label, Stmt stmt) {
		this.label = label;
		this.stmt  = stmt;
	}

	/**
	 * Resets the saved statement and label in the last seen labeled statement
	 */
	public void resetLabeledStmt() {
		this.label = null;
		this.stmt  = null;
	}

	/**
	 * Returns the statement of the last seen labeled statement
	 * @return The statement
	 */
	public Stmt getLabeledStmt() {
		return stmt;
	}

	/**
	 * Returns the label of the last seen labeled statement
	 * @return The label
	 */
	public String getLabel() {
		assert label != null;
		return label;
	}
}

