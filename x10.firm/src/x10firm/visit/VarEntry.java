package x10firm.visit;

import polyglot.types.LocalDef;
import polyglot.types.LocalInstance;
import firm.Entity;

/**
 * Class for saving local var declarations and the appropriate firm indices, types.
 */
public class VarEntry {
	/**
	 * Type of a normal variable -> Has a unique index
	 */
	public static final int VARIABLE = 0x1;

	/**
	 * A normal (local) struct variable -> Has a unique entity
	 */
	public static final int STRUCT   = 0x2;

	private Entity entity;
	private int type;
	private int idx;
	private LocalDef def;

	private VarEntry(final LocalDef def, final int idx, final int type, final Entity entity) {
		assert(def != null);
		assert(type == VARIABLE || type == STRUCT);

		this.def = def;
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
	 * Creates a new var entry for a local variable
	 * @param loc The local def
	 * @param idx The "local" index (firm) for the local def
	 * @return The created var entry.
	 */
	public static VarEntry newVarEntryForLocalVariable(final LocalInstance loc, final int idx) {
		return new VarEntry(loc.def(), idx, VARIABLE, null);
	}

	/**
	 * Creates a new var entry for a local struct def
	 * @param loc The local struct def
	 * @return The created var entry.
	 */
	public static VarEntry newVarEntryForStructVariable(final LocalInstance loc, final Entity entity) {
		return new VarEntry(loc.def(), -1, STRUCT, entity);
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
	 * Returns the var def of the var key
	 * @return The var def
	 */
	public LocalDef getVarDef() {
		return def;
	}
}
