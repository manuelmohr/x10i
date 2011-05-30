package x10firm.types;

import java.util.HashMap;
import java.util.Map;
import java.util.Set;

import polyglot.types.Type;
import polyglot.types.TypeObject;
import x10.types.ParameterType;

public class ParameterTypeMapping {
	private Map<ParameterType, Type> mapping = new HashMap<ParameterType, Type>();
	
	public void add(final ParameterType param, final Type concreteType) {
		mapping.put(param, concreteType);
	}
	
	public Set<ParameterType> getKeySet() {
		return mapping.keySet();
	}
	
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
		
		ParameterTypeMapping other = (ParameterTypeMapping) o;
		if (mapping.size() != other.mapping.size())
			return false;
		
		for (ParameterType pt : mapping.keySet()) {
			if (!other.mapping.containsKey(pt))
				return false;

			final Type myT = mapping.get(pt);
			final Type otherT = other.mapping.get(pt);
			
			// TODO:  Check the exact meaning of equalsImpl.  Maybe pointer equality works, too?
			if (!myT.equalsImpl((TypeObject) otherT))
				return false;
		}
		
		return true;
	}
}
