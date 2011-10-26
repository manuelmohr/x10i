package x10firm.visit;

import polyglot.types.LocalInstance;
import polyglot.types.VarInstance;
import firm.Entity;

/**
 * Class for saving variable instances (locals and fields) and the appropriate "firm" indices.
 */
public class X10VarEntry {
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
