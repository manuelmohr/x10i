package x10firm.types;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import polyglot.frontend.ExtensionInfo;
import polyglot.types.Context;
import polyglot.types.Type;
import polyglot.types.TypeSystem;
import polyglot.types.Types;
import x10.types.ParameterType;
import x10.types.X10ClassDef;
import x10.types.X10ClassType;
import x10.types.X10ParsedClassType;
import x10c.types.X10CTypeSystem_c;

/**
 * Implements generic-aware versions of the methods provided by {@link TypeSystem}.
 * This means that passing ParameterTypes like T are handled correctly by all
 * methods by looking up the type that T is currently mapped to.
 */
public class GenericTypeSystem extends X10CTypeSystem_c {
	/** Remember type parameter mappings, used for example in name mangling. */
	private Map<ParameterType, polyglot.types.Type> typeParameters = new HashMap<ParameterType, polyglot.types.Type>();


	/**
	 * @param extInfo extension info
	 */
	public GenericTypeSystem(ExtensionInfo extInfo) {
		super(extInfo);
	}

	/**
	 * Insert a new (key->value) parameter type mapping
	 * @param paramType key type
	 * @param type      value type
	 */
	public void addTypeMapping(ParameterType paramType, Type type) {
		assert (!typeParameters.containsKey(paramType));
		typeParameters.put(paramType, type);
	}

	/**
	 * Remove an existing type mapping
	 * @param paramType key type to remove
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
	 * @param paramType  the key type, which is mapped to a value type
	 * @return           the corresponding value type
	 */
	public Type getTypeParamSub(ParameterType paramType) {
		polyglot.types.Type p = paramType;

		while ((p = Types.baseType(p)) != null && super.isParameterType(p)) {
			assert (typeParameters.containsKey(p));
			p = typeParameters.get(p);
		}

		return p;
	}

	/**
	 * @return True iff {@code param} is a struct type.
	 */
	public boolean isStructType0(Type type) {
		final Type ret = getConcreteType(type);
		return super.isStructType(ret);
	}

	/**
	 * @return True iff {@code t1} is a subtype of {@code t2}.
	 */
	public boolean isSubtype0(Type t1, Type t2) {
		final Type t1_ = getConcreteType(t1),
				   t2_ = getConcreteType(t2);

		return super.isSubtype(t1_, t2_);
	}

	/**
	 * @return True iff {@code t1} is equal to {@code t2} in {@code context}.
	 */
	public boolean typeEquals0(Type t1, Type t2, Context context) {
		final Type t1_ = getConcreteType(t1),
				   t2_ = getConcreteType(t2);

		return super.typeEquals(t1_, t2_, context);
	}

	/**
	 * @return True iff {@code t1} is equal to {@code t2} in {@code context}, ignoring their dep clauses and the dep clauses of their type arguments recursively.
	 */
	public boolean typeDeepBaseEquals0(Type t1, Type t2, Context context) {
		final Type t1_ = getConcreteType(t1),
				   t2_ = getConcreteType(t2);

		return super.typeDeepBaseEquals(t1_, t2_, context);
	}

	private Map<String, X10ParsedClassType> remapped_classes = new HashMap<String, X10ParsedClassType>();

	private static String getGenericClassName(final X10ParsedClassType klass, final List<polyglot.types.Type> typeArguments) {
		StringBuffer buf = new StringBuffer();
		buf.append(klass.name().toString());
		buf.append("[");
		for(final polyglot.types.Type arg: typeArguments)
			buf.append(arg);
		buf.append("]");
		return buf.toString();
	}

	private X10ParsedClassType getFixedClassTypeFromCache(final X10ParsedClassType klass, final List<polyglot.types.Type> typeArguments) {
		final String klassName = getGenericClassName(klass, typeArguments);
		X10ParsedClassType ret = remapped_classes.get(klassName);
		if(ret != null)
			return ret;
		ret = klass.typeArguments(typeArguments);
		remapped_classes.put(klassName, ret);
		return ret;
	}


	private X10ParsedClassType fixParsedClassType(final X10ParsedClassType klass) {
		if (klass.isMissingTypeArguments()) {
			final X10ClassDef def = klass.def();
			List<polyglot.types.Type> typeArguments = new ArrayList<polyglot.types.Type>();
			for (ParameterType pt : def.typeParameters())
				typeArguments.add(getConcreteType(pt));

			return getFixedClassTypeFromCache(klass, typeArguments);
		}
		else if (klass.typeArguments() != null && !klass.typeArguments().isEmpty()) {
			List<polyglot.types.Type> typeArguments = new ArrayList<polyglot.types.Type>();
			boolean hasUnknownTypeParams = false;
			for (polyglot.types.Type typeArg : klass.typeArguments()) {
				if (typeArg instanceof ParameterType) {  // No constrained types here.
					typeArguments.add(getConcreteType(typeArg));
					hasUnknownTypeParams = true;
				} else {
					typeArguments.add(typeArg);
				}
			}

			if(hasUnknownTypeParams)
				return getFixedClassTypeFromCache(klass, typeArguments);
		}

		return klass;
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
		else if(super.isParameterType(ret) && typeParameters.containsKey(ret)) {
			assert(typeParameters.containsKey(ret));
			ret = getTypeParamSub((ParameterType)ret);
		} else if(super.isParameterType(ret)) {
			// TODO: Need a better solution !!!
			ret = Object();
		}

		// isParsedClassType => !isMissingTypeArguments
		assert (!(ret instanceof X10ParsedClassType) || !((X10ParsedClassType) ret).isMissingTypeArguments());

		return ret;
	}

	/**
	 * Simplifies a given polyglot type -> Returns the base type of a given type. -> Removes constrained types, annotations etc.
	 * @param type The type which should be simplified
	 * @return The simplified version of the given type
	 */
	public static polyglot.types.Type simplifyType(final polyglot.types.Type type) {
		return Types.stripConstraints(Types.baseType(type));
	}

	/**
	 * @param t some type
	 * @return  is it a key mapped to a class type?
	 */
	public boolean isClass(Type t) {
		final Type ret = getConcreteType(t);
		return ret.isClass();
	}

	/**
	 * @return The type {@code t} casted to a class type or null
	 */
	public X10ClassType toClass(final Type t) {
		final Type ret = getConcreteType(t);
		return ret.toClass();
	}

	/**
	 * @return True iff {@code type} is a reference type.
	 */
	public boolean isRefType(final Type type) {
		final Type ret = getConcreteType(type);
		return !isStructType0(ret) && (ret == Null() || isClass(ret) || isInterfaceType(ret));
	}

	/** Own additions for the native pointer type */
	private X10ClassType Pointer_;

    /**
     * @return The FirmPointer class type.
     */
    public X10ClassType Pointer() {
        if (Pointer_ == null)
            Pointer_ = load("x10.lang.Pointer");
        return Pointer_;
    }

    /**
     * @param type Type to check.
     * @return True iff {@code type} is Pointer or a subtype of Pointer.
     */
	public boolean isPointer(final Type type) {
		return isSubtype(type, Pointer());
	}
}
