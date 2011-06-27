package x10firm.types;

import java.util.HashMap;
import java.util.Map;

import x10.types.X10ConstructorDef;
import firm.Entity;

public class GenericClassContext {
	/** Mapping between MethodDefs and firm entities. */
	private final Map<GenericMethodInstance, Entity> methodEntities = new HashMap<GenericMethodInstance, Entity>();

	/**
	 * Mapping between X10ConstructorDefs and firm entities. Constructors are
	 * not allowed to be generic, so we do not need a
	 * "GenericConstructorInstance".
	 */
	private final Map<X10ConstructorDef, Entity> constructorEntities = new HashMap<X10ConstructorDef, Entity>();

	public GenericClassContext() {
	}

	public Entity getMethodEntity(GenericMethodInstance inst) {
		return methodEntities.get(inst);
	}

	public void putMethodEntity(GenericMethodInstance inst, Entity entity) {
		methodEntities.put(inst, entity);
	}

	public Entity getConstructorEntity(X10ConstructorDef def) {
		return constructorEntities.get(def);
	}

	public void putConstructorEntity(X10ConstructorDef def, Entity entity) {
		constructorEntities.put(def, entity);
	}
}