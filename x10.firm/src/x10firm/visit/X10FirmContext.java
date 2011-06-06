package x10firm.visit;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import polyglot.ast.ClassMember;
import polyglot.ast.Stmt;
import polyglot.types.LocalInstance;
import polyglot.types.VarInstance;
import x10.types.X10ClassType;
import x10.types.X10ProcedureInstance;
import firm.Entity;

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
	 * Reference to the current procedure type
	 */
	private X10ProcedureInstance<?> curProcedure;

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
	 * List with the class members which must be initialised explicitly in a constructor etc.
	 */
	private List<ClassMember> initClassMembers = null;

	/**
	 * Create a new Firm context
	 */
	public X10FirmContext() {
	}

	/**
	 * Sets the current procedure
	 * @param procedure The current procedure
	 */
	public void setCurProcedure(final X10ProcedureInstance<?> procedure) {
		this.curProcedure = procedure;
	}

	/**
	 * Returns the current procedure
	 * @return The current procedure
	 */
	public X10ProcedureInstance<?> getCurProcedure() {
		return curProcedure;
	}

	/**
	 * Sets the class members which must be intialized explicitly
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

	/** Sets the "VarEntry" for a given variable (local variable or field instance)
	 * @param entry The "VarEntry" for the given variable
	 */
	public void setVarEntry(X10VarEntry entry) {
		assert !varEntryMapper.containsKey(entry.getVarInstance());
		varEntryMapper.put(entry.getVarInstance(), entry);
	}

	/** Returns the "VarEntry" for a given instance variable in the current scope
	 * @return The "VarEntry" of the given instance variable in the current scope or
	 * null if the instance variable could not be found.
	 */
	public X10VarEntry getVarEntry(VarInstance<?> var) {
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

/**
 * Class for saving variable instances (locals and fields) and the appropriate "firm" indices.
 */
class X10VarEntry {
	/**
	 * Type of a normal variable -> can be set and accessed with setVariable and getVariable and has a unique index
	 */
	public static final int VARIABLE = 0x1;

	/**
	 * A normal (local) struct variable
	 */
	public static final int STRUCT   = 0x3;

	private Entity entity;
	private int type;
	private int idx;
	private VarInstance<?> var;

	private X10VarEntry(final VarInstance<?> var, final int idx, final int type, final Entity entity) {
		assert(var != null);
		assert(type == VARIABLE || type == STRUCT);

		this.var = var;
		this.idx = idx;
		this.type = type;
		this.entity = entity;
	}

	/**
	 * Returns the type of the var entry
	 */
	public int getType() {
		return type;
	}

	/**
	 * Creates a new var entry for a local instance
	 * @param loc The local instance
	 * @param idx The "local" index (firm) for the local variable
	 * @return The created var entry.
	 */
	public static X10VarEntry newVarEntryForLocalVariable(final LocalInstance loc, final int idx) {
		return new X10VarEntry(loc, idx, VARIABLE, null);
	}

	/**
	 * Creates a new var entry for a local struct instance
	 * @param loc The local struct instance
	 * @return The created var entry.
	 */
	public static X10VarEntry newVarEntryForStructVariable(final LocalInstance loc, final Entity entity) {
		return new X10VarEntry(loc, -1, STRUCT, entity);
	}

	/**
	 * The index of the var entry -> -1 if the var entry is actually a field instance
	 * @return The index of the local instance.
	 */
	public int getIdx() {
		return idx;
	}

	/** Returns the entity of the var entry
	 *
	 */
	public Entity getEntity() {
		assert(type == STRUCT);
		return entity;
	}

	/**
	 * Returns the var instance of the var key
	 * @return The var instance
	 */
	public VarInstance<?> getVarInstance() {
		return var;
	}
}