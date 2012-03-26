package x10firm.types;

import java.util.HashMap;
import java.util.Map;

import polyglot.types.FieldDef;
import x10.types.X10ConstructorDef;
import firm.Entity;

/**
 * Represents a generic class context.
 * As we employ a form of template instantiation instead of type erasure,
 * each instantiation of a generic class is a separate context.  This means
 * that there is a new copy of all methods, constructors and fields inside the
 * generic class for each type the generic class is instantiated with.
 *
 * @author mohr
 */
public class GenericClassContext {
   /**
    * Mapping between GenericMethodInstances and firm entities.
    * Non-generic methods are adding with an empty {@link ParameterTypeMapping}.
    */
   private final Map<GenericMethodInstance, Entity> methodEntities = new HashMap<GenericMethodInstance, Entity>();

	/**
	 * Mapping between X10ConstructorDefs and firm entities. Constructors are
	 * not allowed to be generic, so we do not need a
	 * "GenericConstructorInstance".
	 */
	private final Map<X10ConstructorDef, Entity> constructorEntities = new HashMap<X10ConstructorDef, Entity>();

	/** Mapping between FieldDefs and firm entities. */
	private final Map<FieldDef, Entity> fieldEntities = new HashMap<FieldDef, Entity>();

	/** Create new empty {@link GenericClassContext}. */
	public GenericClassContext() {
	}

	/**
	 * @return The FIRM entity for the method instance {@code inst}.
	 */
	public Entity getMethodEntity(final GenericMethodInstance inst) {
		return methodEntities.get(inst);
	}

	/** Map {@code inst} to {@code entity}. */
	public void putMethodEntity(final GenericMethodInstance inst, final Entity entity) {
		methodEntities.put(inst, entity);
	}

	/**
	 * @return The FIRM entity for constructor {@code def}.
	 */
	public Entity getConstructorEntity(final X10ConstructorDef def) {
		return constructorEntities.get(def);
	}

	/** Map {@code def} to {@code entity}. */
	public void putConstructorEntity(final X10ConstructorDef def, final Entity entity) {
		constructorEntities.put(def, entity);
	}

	/**
	 * @return The FIRM entity for field {@code def}.
	 */
	public Entity getFieldEntity(final FieldDef def) {
		return fieldEntities.get(def);
	}

	/** Map {@code def} to {@code entity}. */
	public void putFieldEntity(final FieldDef def, final Entity entity) {
		fieldEntities.put(def, entity);
	}
}
