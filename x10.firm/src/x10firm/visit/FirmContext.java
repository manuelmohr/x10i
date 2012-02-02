package x10firm.visit;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;

import polyglot.ast.ClassMember;
import polyglot.ast.Stmt;
import polyglot.types.LocalDef;
import polyglot.types.LocalInstance;
import polyglot.types.Type;

/**
 * Class that holds attributes (scopes, mapping of local instance variables etc.) for a new method.
 * For every new method entry we will create a new firm context.
 */
public class FirmContext {
	/** Holds the topmost firmScope. -> Push a dummy frame in the current FirmContext */
	private FirmScope topFirmScope = new FirmScope();

	/** Maps local var defs to the appropriate var entries */
	private Map<LocalDef, VarEntry> varEntryMapper = new HashMap<LocalDef, VarEntry>();

	/**
	 * Reference to the current procedure return type
	 */
	private Type returnType;

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
	private FirmContext outer;

	/**
	 * List with the class members which must be initialised explicitly in a constructor etc.
	 */
	private List<ClassMember> initClassMembers = null;

	/**
	 * Create a new Firm context
	 */
	public FirmContext() {

	}

	/** Sets the return type of the current method
	 * @param retType The return type
	 */
	public void setReturnType(final Type retType) {
		returnType = retType;
	}

	/** Returns the return type of the current method */
	public Type getReturnType() {
		return returnType;
	}

	/**
	 * Sets the class members which must be initialized explicitly
	 */
	public void setInitClassMembers(List<ClassMember> members) {
		assert(initClassMembers == null); // method should only be called once
		initClassMembers = members;
	}

	/**
	 * Returns all class members which must be manually initialized
	 * @return A list with all class members which must be manually initialized.
	 */
	public List<ClassMember> getInitClassMembers() {
		if(initClassMembers == null)
			return new ArrayList<ClassMember>();
		return initClassMembers;
	}

	/**
	 * Pushes a new firm context
	 * @param newContext The new firm context which should be pushed
	 * @return The new firm context which was pushed.
	 */
	public FirmContext pushFirmContext(FirmContext newContext) {
		assert newContext != null;
		newContext.outer = this;
		return newContext;
	}

	/**
	 * Pops the topmost firm context
	 * @return The upper firm context
	 */
	public FirmContext popFirmContext() {
		assert outer != null;
		return outer;
	}

	/** Sets the "VarEntry" for a given variable (local variable or field instance)
	 * @param entry The "VarEntry" for the given variable
	 */
	public void setVarEntry(final VarEntry entry) {
		assert !varEntryMapper.containsKey(entry.getVarDef());
		varEntryMapper.put(entry.getVarDef(), entry);
	}

	/** Returns the "VarEntry" for a given instance variable in the current scope
	 * @return The "VarEntry" of the given instance variable in the current scope or
	 * null if the instance variable could not be found.
	 */
	public VarEntry getVarEntry(final LocalInstance var) {
		/*
		 * The TypeAlphaRenamer and ClassRemover visitors create and use copies of X10LocalDefs.
		 * This copies will not work with our X10LocalDef hashing mechanism. To handle this copies with will not
		 * adjust the visitors instead we will search for the appropriate X10LocalDef copy in our varEntryMapper.
		 */
		final LocalDef def = var.def();
		VarEntry ret = varEntryMapper.get(var.def());
		if(ret != null) return ret; // The def is equal; return the appropriate var entry
		// Search for the copy.
		for(final Entry<LocalDef, VarEntry> entry : varEntryMapper.entrySet()) {
			final LocalDef d = entry.getKey();
			// Copy search: Name, position and flags must be equal.
			if(def.name().equals(d.name()) && def.position().equals(d.position()) &&
			   def.flags().equals(d.flags())) {
				ret = entry.getValue();
				break;
			}
		}
		return ret;

	}

	/** Pushes a new firm scope
	 * @param scope The firm scope which should be pushed
	 * @return The new firm scope
	 */
	public FirmScope pushFirmScope(FirmScope scope) {
		scope.setPrev(topFirmScope);
		topFirmScope = scope;
		return scope;
	}

	/** Pops the topmost firm scope
	 * @return The upper firm scope of the topmost firm scope
	 */
	public FirmScope popFirmScope() {
		assert topFirmScope != null;
		topFirmScope = topFirmScope.getPrev();
		return topFirmScope;
	}

	/** Returns the topmost firm scope
	 * @return Topmost firm scope
	 */
	public FirmScope getTopScope() {
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
