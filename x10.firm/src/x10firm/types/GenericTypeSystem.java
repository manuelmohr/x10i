package x10firm.types;

import java.util.HashMap;
import java.util.Map;

import polyglot.frontend.ExtensionInfo;
import polyglot.types.ClassType;
import polyglot.types.Context;
import polyglot.types.Type;
import polyglot.types.Types;
import x10.types.ParameterType;
import x10.types.X10ClassType;
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

	public Map<ParameterType, Type> getMapping() {
		return typeParameters;
	}

	/**
	 * @param paramType		the key type, which is mapped to a value type
	 * @return				the corresponding value type
	 */
	public Type getConcreteType(ParameterType paramType) {
		polyglot.types.Type p = paramType;

		while ((p = Types.baseType(p)) != null && super.isParameterType(p)) {
			if(!typeParameters.containsKey(p)) {
				System.out.println("");
			}
			assert (typeParameters.containsKey(p));
			p = typeParameters.get(p);
		}

		return p;
	}
	
	// TODO: Need other solution
	public Type getContextType(final Type type) {
		if(type instanceof ParameterType) 
			return getConcreteType((ParameterType)type);
		return type;
	}

	@Override
	public boolean isStructType(Type type) {
		if (type.getClass() == ParameterType.class && typeParameters.containsKey(type))
			return super.isStructType(typeParameters.get(type));

		return super.isStructType(type);
	}

	@Override
	public boolean isSubtype(Type t1, Type t2) {
		Type t1_ = t1, t2_ = t2;

		if (super.isParameterType(t1) && typeParameters.containsKey(t1))
			t1_ = typeParameters.get(t1);

		if (super.isParameterType(t2) && typeParameters.containsKey(t2))
			t2_ = typeParameters.get(t2);

		return super.isSubtype(t1_, t2_);
	}

	@Override
	public boolean typeEquals(Type t1, Type t2, Context context) {
		Type t1_ = t1, t2_ = t2;

		if (super.isParameterType(t1) && typeParameters.containsKey(t1))
			t1_ = typeParameters.get(t1);

		if (super.isParameterType(t2) && typeParameters.containsKey(t2))
			t2_ = typeParameters.get(t2);

		return super.typeEquals(t1_, t2_, context);
	}

	@Override
	public boolean typeDeepBaseEquals(Type t1, Type t2, Context context) {
		Type t1_ = t1, t2_ = t2;

		if (super.isParameterType(t1) && typeParameters.containsKey(t1))
			t1_ = typeParameters.get(t1);

		if (super.isParameterType(t2) && typeParameters.containsKey(t2))
			t2_ = typeParameters.get(t2);

		return super.typeDeepBaseEquals(t1_, t2_, context);
	}

	/**
	 * @param t		some type
	 * @return		is it a key mapped to a class type?
	 */
	public boolean isClass(Type t) {
		if (typeParameters.containsKey(t))
			return isClass(typeParameters.get(t));

		return t.isClass();
	}

	public ClassType toClass(Type t) {
		if (typeParameters.containsKey(t))
			return toClass(typeParameters.get(t));

		return t.toClass();
	}
	
	public boolean isRefType(final Type type) {
		return (type == Null() || isClass(type) || isInterfaceType(type)) && !isStructType(type);
	}
	
	// Own additions for the native pointer type 
    protected X10ClassType FirmPointer_;
	
    public X10ClassType FirmPointer() {
        if (FirmPointer_ == null)
            FirmPointer_ = load("x10.lang.FirmPointer");
        return FirmPointer_;
    }
}
