package x10firm.types;

import java.util.HashMap;
import java.util.Map;

import polyglot.types.FieldInstance;

import x10.types.ParameterType;
import x10.types.X10ClassDef;
import x10.types.X10ClassType;
import x10.types.X10ConstructorDef;
import firm.Entity;
import firm.Type;

public class GenericClassInstance {
	private X10ClassDef def;
	private ParameterTypeMapping mapping;

	GenericClassInstance(X10ClassDef def) {
		assert (def != null && def.typeParameters().isEmpty());
		this.def = def;
	}

	GenericClassInstance(X10ClassDef def, ParameterTypeMapping mapping) {
		assert (def != null && !def.typeParameters().isEmpty() && mapping != null);
		this.def = def;
		this.mapping = mapping;
	}

	GenericClassInstance(X10ClassType classType) {
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