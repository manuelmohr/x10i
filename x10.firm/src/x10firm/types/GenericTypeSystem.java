package x10firm.types;

import java.util.HashMap;
import java.util.Map;

import polyglot.frontend.ExtensionInfo;
import polyglot.types.ClassType;
import polyglot.types.ContainerType;
import polyglot.types.Context;
import polyglot.types.Type;
import x10.types.MethodInstance;
import x10.types.ParameterType;
import x10c.types.X10CTypeSystem_c;

public class GenericTypeSystem extends X10CTypeSystem_c {
	/** Remember type parameter mappings, used for example in name mangling. */
	private Map<ParameterType, polyglot.types.Type> typeParameters = new HashMap<ParameterType, polyglot.types.Type>();


	public GenericTypeSystem(ExtensionInfo extInfo) {
		super(extInfo);
	}

	public void addTypeMapping(ParameterType paramType, Type type) {
		assert (!typeParameters.containsKey(paramType));
		typeParameters.put(paramType, type);
	}

	public void removeTypeMapping(ParameterType paramType) {
		assert (typeParameters.containsKey(paramType));
		typeParameters.remove(paramType);
	}

	public polyglot.types.Type getConcreteType(ParameterType paramType) {
		assert (typeParameters.containsKey(paramType));
		return typeParameters.get(paramType);
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
}
