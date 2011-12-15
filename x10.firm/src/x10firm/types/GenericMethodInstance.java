package x10firm.types;

import x10.types.MethodInstance;
import x10.types.ParameterType;
import x10.types.X10MethodDef;

public class GenericMethodInstance {
	private X10MethodDef def;
	private ParameterTypeMapping mapping;

	GenericMethodInstance(final X10MethodDef def, final ParameterTypeMapping mapping) {
		assert (def != null && !def.typeParameters().isEmpty() && mapping != null);
		this.def = def;
		this.mapping = mapping;
	}

	GenericMethodInstance(final MethodInstance mi, final GenericTypeSystem x10TypeSystem) {
		this.def = mi.x10Def();

		if (def.typeParameters().isEmpty())
			this.mapping = null;
		else {
			this.mapping = new ParameterTypeMapping();
			for (int i = 0; i < def.typeParameters().size(); ++i)
				this.mapping.add(def.typeParameters().get(i), x10TypeSystem.getConcreteType(mi.typeParameters().get(i)));
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
		if (!(other instanceof GenericMethodInstance))
			return false;

		GenericMethodInstance rhs = (GenericMethodInstance) other;
		if (this.mapping == null)
			return this.def == rhs.def && rhs.mapping == null;

		return this.def == rhs.def && rhs.mapping != null && this.mapping.equals(rhs.mapping);
	}

	@Override
	public String toString() {
		return def.toString() + (mapping != null ? " WITH " + mapping.toString() : "");
	}
}
