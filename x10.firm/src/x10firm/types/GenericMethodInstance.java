package x10firm.types;

import java.util.List;

import polyglot.types.Type;
import x10.types.MethodInstance;
import x10.types.ParameterType;
import x10.types.ReinstantiatedMethodInstance;
import x10.types.TypeParamSubst;
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
		def = mi.x10Def();

		if(mi instanceof ReinstantiatedMethodInstance) {
			// Handling of ReininstiatedMethodInstances with "pseudo" parameter types. (Closures for example)
			final ReinstantiatedMethodInstance rmi = (ReinstantiatedMethodInstance)mi;
			assert(rmi.typeParamSubst() != null);
			final TypeParamSubst typeSub = rmi.typeParamSubst();
			mapping = new ParameterTypeMapping();
			final List<Type> typeArgs  			 = typeSub.copyTypeArguments();
			final List<ParameterType> typeParams = typeSub.copyTypeParameters();
			assert(typeArgs.size() == typeParams.size());
			// Handling of type subst
			for(int i = 0; i < typeArgs.size(); i++) {
			Type typeArg = typeArgs.get(i);
				if(typeArg.isParameterType()) // Watch out for recursive type mappings.
					typeArg = x10TypeSystem.getConcreteType(typeArg);
				final ParameterType typeParam = typeParams.get(i);

				mapping.add(typeParam, typeArg);
			}
			// Handling of normal type parameters
			for(int i = 0; i < def.typeParameters().size(); i++)
				mapping.add(def.typeParameters().get(i), x10TypeSystem.getConcreteType(mi.typeParameters().get(i)));
		} else {
			if (def.typeParameters().isEmpty())
				mapping = null;
			else {
				mapping = new ParameterTypeMapping();
				for (int i = 0; i < def.typeParameters().size(); i++)
					mapping.add(def.typeParameters().get(i), x10TypeSystem.getConcreteType(mi.typeParameters().get(i)));
			}
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
