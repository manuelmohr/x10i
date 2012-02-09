package x10firm.types;

import x10.types.ParameterType;
import x10.types.X10ClassDef;
import x10.types.X10ClassType;
/**
 * Represents an instantiation of a generic class.
 * Consists of a class definition and a parameter type mapping.
 *
 * @author mohr
 */
public class GenericClassInstance {
	private X10ClassDef def;
	private ParameterTypeMapping mapping;

	/**
	 * Construct a {@link GenericClassInstance} for a class definition and a parameter type mapping.
	 */
	protected GenericClassInstance(final X10ClassDef def, final ParameterTypeMapping mapping) {
		assert (def != null && !def.typeParameters().isEmpty() && mapping != null);
		this.def = def;
		this.mapping = mapping;
	}

	/**
	 * Construct a {@link GenericClassInstance} for a class type.
	 * For non generic classes, the mapping is set to null.
	 * For generic classes, the number of type arguments in the class type
	 * must match the number of type parameters the class definition expects.
	 */
	protected GenericClassInstance(final X10ClassType classType) {
		this.def = classType.x10Def();

		if (def.typeParameters().isEmpty())
			this.mapping = null;
		else {
			this.mapping = new ParameterTypeMapping();
			assert (def.typeParameters().size() == classType.typeArguments().size());
			for (int i = 0; i < def.typeParameters().size(); ++i)
				this.mapping.add(def.typeParameters().get(i), classType.typeArguments().get(i));
		}
	}

	@Override
	public int hashCode() {
		int hash = def.hashCode();

		if (mapping != null)
			for (ParameterType paramType : mapping.getKeySet())
				hash ^= mapping.getMappedType(paramType).hashCode();

		return hash;
	}

	@Override
	public boolean equals(Object other) {
		if (!(other instanceof GenericClassInstance))
			return false;

		final GenericClassInstance rhs = (GenericClassInstance) other;
		return this.def == rhs.def && this.mapping.equals(rhs.mapping);
	}

	@Override
	public String toString() {
		return def.toString() + (mapping != null ? " WITH " + mapping.toString() : "");
	}
}