package x10firm.types;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

import polyglot.types.FieldInstance;
import x10.types.ConstrainedType_c;
import x10.types.X10ClassType;
import x10.types.X10ConstructorInstance;
import x10.types.X10Flags;
import x10.types.X10MethodInstance;
import x10.types.X10TypeSystem_c;
import firm.ClassType;
import firm.Entity;
import firm.Ident;
import firm.Mode;
import firm.Mode.ir_mode_arithmetic;
import firm.Mode.ir_mode_sort;
import firm.OO;
import firm.PointerType;
import firm.PrimitiveType;
import firm.Program;
import firm.Type;
import firm.bindings.binding_oo.ddispatch_binding;

/**
 * Includes everything to map X10 types to Firm types
 *
 * XXX While the mapping is static, the X10 type system is not,
 * because the runtime is loaded dynamically.
 */
public class TypeSystem extends X10TypeSystem_c {

	/** Maps polyglot types to firm types. */
	private Map<polyglot.types.Type, Type> firmCoreTypes = new HashMap<polyglot.types.Type, Type>();
	/** Maps some polyglot types to "native"/primitive firm types */
	private Map<polyglot.types.Type, Type> firmTypes = new HashMap<polyglot.types.Type, Type>();
	/** Maps fields to firm entities */
	private Map<FieldInstance, Entity> fieldMap = new HashMap<FieldInstance, Entity>();

	/** All class instances share the same location for the vptr (the pointer to the vtable) */
	private Entity vptrEntity;
	
	/**
	 * Creates a method type (= a member function). So we in addition to the
	 * type we need the flags to determine if it is static and the owner class
	 * to determine the type of the "this" parameter.
	 * @param methodInstance	an X10 method instance, for which a Firm type is needed
	 * @return	corresponding Firm type
	 */
	public firm.MethodType asFirmType(X10MethodInstance methodInstance) {
		final List<polyglot.types.Type> formalTypes
			= methodInstance.formalTypes();
		final X10Flags flags = X10Flags.toX10Flags(methodInstance.flags());
		final boolean isStatic = flags.isStatic();
		final int nParameters = formalTypes.size() + (isStatic ? 0 : 1);
		final int nResults = methodInstance.returnType() == Void() ? 0 : 1;
		final X10ClassType owner = (X10ClassType) methodInstance.container();
		final Type[] parameterTypes = new firm.Type[nParameters];
		final Type[] resultTypes = new firm.Type[nResults];

		int p = 0;
		if (!isStatic) {
			Type thisType = asFirmType(owner);
			parameterTypes[p++] = thisType;
		}
		for (polyglot.types.Type type : formalTypes) {
			parameterTypes[p++] = asFirmType(type);
		}
		assert (p == nParameters);

		if (nResults > 0) {
			assert nResults == 1;
			polyglot.types.Type type = methodInstance.returnType();
			resultTypes[0] = asFirmType(type);
		}

		return new firm.MethodType(parameterTypes, resultTypes);
	}

	/**
	 * create a method type for an X10 constructor
	 */
	public firm.MethodType asFirmType(X10ConstructorInstance instance) {
		final List<polyglot.types.Type> formalTypes
			= instance.formalTypes();
		final int nParameters = formalTypes.size() + 1;
		final int nResults = 0;
		final X10ClassType owner = (X10ClassType) instance.container();
		final Type[] parameterTypes = new firm.Type[nParameters];
		final Type[] resultTypes = new firm.Type[nResults];

		int p = 0;
		Type thisType = asFirmType(owner);
		parameterTypes[p++] = thisType;
		for (polyglot.types.Type type : formalTypes) {
			parameterTypes[p++] = asFirmType(type);
		}
		assert (p == nParameters);

		return new firm.MethodType(parameterTypes, resultTypes);
	}

	/**
	 * Returns the corresponding Firm type for the given polyglot type
	 *
	 * @param type The given polyglot type
	 * @return corresponding Firm method type
	 */
	public firm.Type asFirmType(polyglot.types.Type type) {
		/* strip type-constraints */
		polyglot.types.Type baseType = type;
		while (baseType instanceof ConstrainedType_c) {
			baseType = ((ConstrainedType_c)baseType).baseType().get();
		}

		firm.Type result = firmTypes.get(baseType);
		if (result != null)
			return result;

		result = asFirmCoreType(baseType);
		if (result instanceof ClassType) {
			/* we really have references to classes */
			result = new PointerType(result);
		}
		firmTypes.put(baseType, result);

		/* currently we should never produce types without modes here */
		assert result.getMode() != null;
		
		return result;
	}
	
	private Entity getVptrEntity() {
		if (vptrEntity == null) {
			firm.Type pointerType = Mode.getP().getType();
			vptrEntity = new Entity(Program.getGlobalType(), "$vptr", pointerType);
		}
		return vptrEntity;
	}

	@SuppressWarnings("unused")
	private firm.Type createClassType(X10ClassType classType) {
		String className = X10NameMangler.mangleTypeObjectWithDefClass(classType);
		ClassType result = new ClassType(className);
		X10Flags flags   = X10Flags.toX10Flags(classType.flags());

		/* put the class into the core types already, because we could
		 * have a field referencing ourself */
		firmCoreTypes.put(classType, result);
		
		/* create supertypes */
		polyglot.types.Type superType = classType.superClass();
		if (superType != null) {
			Type firmSuperType = asFirmCoreType(superType);
			result.addSuperType(firmSuperType);
			new Entity(result, "$super", firmSuperType);
			
		} else if (flags.isStruct()) {
			/* no superclass */
		} else if(flags.isInterface()) {
			/* no superclass interface */
		} else {
			/* the only thing left without a superclass should be x10.lang.Object */
			assert classType.toString().equals("x10.lang.Object");
			getVptrEntity().setOwner(result);
		}

		/* create fields */
		for (FieldInstance field : classType.fields()) {
			X10Flags fieldFlags = X10Flags.toX10Flags(field.flags());
			/* properties have no "real" data in the object */
			if (fieldFlags.isProperty())
				continue;
			String name = X10NameMangler.mangleTypeObjectWithDefClass(field);
			firm.Type type = asFirmType(field.type());
			firm.Type owner = fieldFlags.isStatic() ? Program.getGlobalType() : result;
			Entity entity = new Entity(owner, name, type);
			entity.setLdIdent(name);
			if (fieldFlags.isStatic()) {
				OO.setEntityAltNamespace(entity, result);
			}
			OO.setEntityBinding(entity, ddispatch_binding.bind_static);
			fieldMap.put(field, entity);
		}
		
		OO.setClassVPtrEntity(result, getVptrEntity());
		
		Entity classInfoEntity = new Entity(Program.getGlobalType(),
				Ident.createUnique("class_info_%u"), // TODO: mangle "package.SomeClass.class$" and use it as this entity's ld name
				Mode.getP().getType());
		OO.setClassRTTIEntity(result, classInfoEntity);
		
		result.layoutFields();
		result.finishLayout();

		return result;
	}

	/**
	 * returns firm entity created for a FieldInstance.
	 * Note: this will only work if createClassType was already called for
	 * the fields class.
	 */
	public Entity getEntityForField(FieldInstance instance) {
		return fieldMap.get(instance);
	}

	/**
	 * return the firm type for a given ast-type.
	 * This variant does not return the "native"-type even if there is one.
	 */
	public firm.Type asFirmCoreType(polyglot.types.Type type) {
		/* strip type-constraints */
		polyglot.types.Type baseType = type;
		while (baseType instanceof ConstrainedType_c) {
			baseType = ((ConstrainedType_c)baseType).baseType().get();
		}

		firm.Type result = firmCoreTypes.get(baseType);
		if (result != null)
			return result;

		if (baseType instanceof X10ClassType) {
			result = createClassType((X10ClassType) baseType);
		} else {
			/* remember to put new types into coreTypeCache */
			firmCoreTypes.put(baseType, result);
			throw new java.lang.RuntimeException("No implement to get firm type for: " + baseType);
		}
		return result;
	}

	/**
	 * Returns the mode for a given ast-type.
	 */
	public Mode getFirmMode(polyglot.types.Type type) {
		return asFirmType(type).getMode();
	}

	/**
	 * Should be called before the firm-graph is constructed. This extra step
	 * is necessary because at the time the type-system Object is created in
	 * the ExtensionInfo we must not use the Int(), Boolean(), ... functions
	 * yet.
	 */
	public void beforeGraphConstruction() {
		/* we "lower" some well-known types directly to firm modes */
		Mode modeLong = new Mode("Long", ir_mode_sort.irms_int_number, 64, 1,
				ir_mode_arithmetic.irma_twos_complement, 64);
		Type typeLong = new PrimitiveType(modeLong);
		firmTypes.put(Long(), typeLong);

		Mode modeULong = new Mode("ULong", ir_mode_sort.irms_int_number, 64, 0,
				ir_mode_arithmetic.irma_twos_complement, 64);
		Type typeULong = new PrimitiveType(modeULong);
		firmTypes.put(ULong(), typeULong);

		Mode modeInt = new Mode("Int", ir_mode_sort.irms_int_number, 32, 1,
				ir_mode_arithmetic.irma_twos_complement, 32);
		Type typeInt = new PrimitiveType(modeInt);
		firmTypes.put(Int(), typeInt);

		Mode modeUInt = new Mode("UInt", ir_mode_sort.irms_int_number, 32, 0,
				ir_mode_arithmetic.irma_twos_complement, 32);
		Type typeUInt = new PrimitiveType(modeUInt);
		firmTypes.put(UInt(), typeUInt);

		Mode modeShort = new Mode("Short", ir_mode_sort.irms_int_number, 16, 1,
				ir_mode_arithmetic.irma_twos_complement, 32);
		Type typeShort = new PrimitiveType(modeShort);
		firmTypes.put(Short(), typeShort);

		Mode modeUShort = new Mode("UShort", ir_mode_sort.irms_int_number, 16,
				0, ir_mode_arithmetic.irma_twos_complement, 32);
		Type typeUShort = new PrimitiveType(modeUShort);
		firmTypes.put(UShort(), typeUShort);

		Mode modeByte = new Mode("Byte", ir_mode_sort.irms_int_number, 8, 1,
				ir_mode_arithmetic.irma_twos_complement, 32);
		Type typeByte = new PrimitiveType(modeByte);
		firmTypes.put(Byte(), typeByte);

		Mode modeUByte = new Mode("UByte", ir_mode_sort.irms_int_number, 8, 0,
				ir_mode_arithmetic.irma_twos_complement, 32);
		Type typeUByte = new PrimitiveType(modeUByte);
		firmTypes.put(UByte(), typeUByte);

		Mode modeChar = new Mode("Char", ir_mode_sort.irms_int_number, 32, 0,
				ir_mode_arithmetic.irma_twos_complement, 0);
		Type typeChar = new PrimitiveType(modeChar);
		firmTypes.put(Char(), typeChar);

		Mode modeFloat = new Mode("Float", ir_mode_sort.irms_float_number, 32,
				1, ir_mode_arithmetic.irma_ieee754, 0);
		Type typeFloat = new PrimitiveType(modeFloat);
		firmTypes.put(Float(), typeFloat);

		Mode modeDouble = new Mode("Double", ir_mode_sort.irms_float_number, 64,
				1, ir_mode_arithmetic.irma_ieee754, 0);
		Type typeDouble = new PrimitiveType(modeDouble);
		firmTypes.put(Double(), typeDouble);

		Mode modeBoolean = Mode.getb();
		Type typeBoolean = new PrimitiveType(modeBoolean);
		firmTypes.put(Boolean(), typeBoolean);

		Type unknown = Type.getUnknown();
		Type nullRefType = new PointerType(unknown);
		firmTypes.put(Null(), nullRefType);
		/* Note: there is no sensible firmCoreType for Null() */
	}
}