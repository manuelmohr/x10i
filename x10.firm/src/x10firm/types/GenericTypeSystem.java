package x10firm.types;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import polyglot.frontend.ExtensionInfo;
import polyglot.types.ClassType;
import polyglot.types.Context;
import polyglot.types.Type;
import polyglot.types.Types;
import x10.types.ParameterType;
import x10.types.X10ClassType;
import x10.types.X10ParsedClassType;
import x10c.types.X10CTypeSystem_c;

/**
 * Type system stuff to handle type parameters
 *
 */
public class GenericTypeSystem extends X10CTypeSystem_c {
	/** Remember type parameter mappings, used for example in name mangling. */
	private Map<ParameterType, polyglot.types.Type> typeParameters = new HashMap<ParameterType, polyglot.types.Type>();


	/**
	 * @param extInfo	extension info
	 */
	public GenericTypeSystem(ExtensionInfo extInfo) {
		super(extInfo);
	}

	/**
	 * Insert a new (key->value) parameter type mapping
	 * @param paramType		key type
	 * @param type			value type
	 */
	public void addTypeMapping(ParameterType paramType, Type type) {
		assert (!typeParameters.containsKey(paramType));
		typeParameters.put(paramType, type);
	}

	/**
	 * Remove an existing type mapping
	 * @param paramType		key type to remove
	 */
	public void removeTypeMapping(ParameterType paramType) {
		assert (typeParameters.containsKey(paramType));
		typeParameters.remove(paramType);
	}

	/**
	 * Returns the type mapping 
	 * @return The type mapping
	 */
	public Map<ParameterType, Type> getMapping() {
		return typeParameters;
	}

	/**
	 * @param paramType		the key type, which is mapped to a value type
	 * @return				the corresponding value type
	 */
	public Type getTypeParamSub(ParameterType paramType) {
		polyglot.types.Type p = paramType;

		while ((p = Types.baseType(p)) != null && super.isParameterType(p)) {
			assert (typeParameters.containsKey(p));
			p = typeParameters.get(p);
		}

		return p;
	}

	@Override
	public boolean isStructType(Type type) {
		final Type ret = getConcreteType(type);
		return super.isStructType(ret);
	}

	@Override
	public boolean isSubtype(Type t1, Type t2) {
		final Type t1_ = getConcreteType(t1), 
				   t2_ = getConcreteType(t2);

		return super.isSubtype(t1_, t2_);
	}

	@Override
	public boolean typeEquals(Type t1, Type t2, Context context) {
		final Type t1_ = getConcreteType(t1), 
				   t2_ = getConcreteType(t2);

		return super.typeEquals(t1_, t2_, context);
	}

	@Override
	public boolean typeDeepBaseEquals(Type t1, Type t2, Context context) {
		final Type t1_ = getConcreteType(t1), 
				   t2_ = getConcreteType(t2);

		return super.typeDeepBaseEquals(t1_, t2_, context);
	}
	
	private X10ParsedClassType fixParsedClassType(final X10ParsedClassType t) {
		if (t.isMissingTypeArguments()) {
			List<polyglot.types.Type> typeArguments = new ArrayList<polyglot.types.Type>();
			for (ParameterType pt : t.def().typeParameters())
				typeArguments.add(getConcreteType(pt));

			return t.typeArguments(typeArguments);
		}
		else if (t.typeArguments() != null && !t.typeArguments().isEmpty()) {
			List<polyglot.types.Type> typeArguments = new ArrayList<polyglot.types.Type>();
			for (polyglot.types.Type typeArg : t.typeArguments())
				if (typeArg instanceof ParameterType)  // No constrained types here.
					typeArguments.add(getConcreteType(typeArg));
				else
					typeArguments.add(typeArg);
			if (!typeArguments.isEmpty())
				return t.typeArguments(typeArguments);
		}

		return t;
	}
	
	/**
	 * Returns the concrete type for a given type (after substitution of type parameters etc.)
	 * @param type The given type
	 * @return The concrete type
	 */
	public Type getConcreteType(final Type type) {
		Type ret = simplifyType(type);
		
		if(ret instanceof X10ParsedClassType)
			ret = fixParsedClassType((X10ParsedClassType)ret);
		else if(super.isParameterType(ret) && typeParameters.containsKey(ret))
			ret = getTypeParamSub((ParameterType)ret);
		
		// isParsedClassType => !isMissingTypeArguments
		assert (!(ret instanceof X10ParsedClassType) || !((X10ParsedClassType) ret).isMissingTypeArguments());
		
		return ret;
	}
	
	/**
	 * Simplifies a given polyglot type -> Returns the base type of a given type. -> Removes constrained types, annotations etc.
	 * TODO  Put this into a separate Util (or similar) class.
	 * @param type The type which should be simplified
	 * @return The simplified version of the given type
	 */
	public polyglot.types.Type simplifyType(final polyglot.types.Type type) {
		return Types.stripConstraints(Types.baseType(type));
	}

	/**
	 * @param t		some type
	 * @return		is it a key mapped to a class type?
	 */
	public boolean isClass(Type t) {
		final Type ret = getConcreteType(t);
		return ret.isClass();
	}

	public ClassType toClass(Type t) {
		final Type ret = getConcreteType(t);
		return ret.toClass();
	}
	
	public boolean isRefType(final Type type) {
		final Type ret = getConcreteType(type);
		return (ret == Null() || isClass(ret) || isInterfaceType(ret)) && !isStructType(ret);
	}
	
	// Own additions for the native pointer type 
    protected X10ClassType FirmPointer_;
	
    public X10ClassType FirmPointer() {
        if (FirmPointer_ == null)
            FirmPointer_ = load("x10.lang.FirmPointer");
        return FirmPointer_;
    }
}
