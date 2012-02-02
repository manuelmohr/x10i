package x10firm.types;

import java.util.HashMap;
import java.util.Map;
import java.util.Set;
import polyglot.types.Type;
import polyglot.types.TypeObject;
import x10.types.ParameterType;

/**
 * Container for parameter type mappings
 *
 */
public class ParameterTypeMapping {
	private final Map<ParameterType, Type> mapping;

	public ParameterTypeMapping() {
		this.mapping = new HashMap<ParameterType, Type>();
	}

	public ParameterTypeMapping(Map<ParameterType, Type> map) {
		this.mapping = map;
	}
	/**
	 * Add new mapping
	 * @param param			type parameter
	 * @param concreteType	concrete type it is currently mapped to
	 */
	public void add(final ParameterType param, final Type concreteType) {
		mapping.put(param, concreteType);
	}

	/**
	 * @return	a key of all type parameters
	 */
	public Set<ParameterType> getKeySet() {
		return mapping.keySet();
	}

	/**
	 * @param type		a type parameter
	 * @return			the concrete type, it is currently mapped to
	 */
	public Type getMappedType(final ParameterType type) {
		assert (mapping.containsKey(type));
		return mapping.get(type);
	}

	@Override
	public String toString() {
		return mapping.toString();
	}

	@Override
	public boolean equals(Object o) {
		if (!(o instanceof ParameterTypeMapping))
			return false;

		final ParameterTypeMapping other = (ParameterTypeMapping) o;
		if (mapping.size() != other.mapping.size())
			return false;

		for (final ParameterType pt : mapping.keySet()) {
			ParameterType qt = null;
			/* A simple "other.mapping.containsKey" is not enough because we can have same types with different hash
			 * codes (different instances).
			 * We also can`t compare the parameter types with equalsImpl because the 2 parameter type mappings can
			 * have different contexts (for example: 1. parameter type mapping for a method "a", 2. parameter type mapping
			 * for a method "b". -> The contexts are different but the parameter type mappings can be the same)
			 * Solution: We have to do a simple name comparison for the parameter types and a context dependent
			 * comparison with "equalsImpl" for the concrete types of the parameter types.
			 */
			for(final ParameterType et: other.mapping.keySet()) {
				if(pt.name().toString().equals(et.name().toString())) {
					qt = et;
					break;
				}
			}
			if(qt == null)
				return false;

			final Type myT = mapping.get(pt);
			final Type otherT = other.mapping.get(qt);

			if (!myT.equalsImpl((TypeObject) otherT))
				return false;
		}

		return true;
	}
}
