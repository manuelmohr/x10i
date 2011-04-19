package x10firm.types;

import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

import polyglot.frontend.ExtensionInfo;
import polyglot.types.ClassDef;
import polyglot.types.FieldDef;
import polyglot.types.FieldInstance;
import polyglot.types.Flags;
import polyglot.types.MethodDef;
import polyglot.types.Name;
import polyglot.types.Named;
import polyglot.types.QName;
import polyglot.types.TypeObject;
import polyglot.types.Types;
import polyglot.util.Position;
import x10.types.MethodInstance;
import x10.types.X10ClassDef;
import x10.types.X10ClassDef_c;
import x10.types.X10ClassType;
import x10.types.X10ConstructorInstance;
import x10.types.X10MethodDef;
import x10c.types.X10CTypeSystem_c;
import firm.ClassType;
import firm.Entity;
import firm.Ident;
import firm.MethodType;
import firm.Mode;
import firm.Mode.ir_mode_arithmetic;
import firm.Mode.ir_mode_sort;
import firm.OO;
import firm.PointerType;
import firm.PrimitiveType;
import firm.Program;
import firm.Type;
import firm.bindings.binding_oo.ddispatch_binding;
import firm.bindings.binding_typerep.ir_type_state;

/**
 * Includes everything to map X10 types to Firm types
 *
 * XXX While the mapping is static, the X10 type system is not,
 * because the runtime is loaded dynamically.
 */
public class TypeSystem extends X10CTypeSystem_c {

	/** Maps polyglot types to firm types. */
	private Map<polyglot.types.Type, Type> firmCoreTypes = new HashMap<polyglot.types.Type, Type>();

	/** Maps some polyglot types to "native"/primitive firm types */
	private Map<polyglot.types.Type, Type> firmTypes = new HashMap<polyglot.types.Type, Type>();

	/** Maps fields to firm entities */
	private Map<FieldInstance, Entity> fieldMap = new HashMap<FieldInstance, Entity>();

	/** Maps struct types to the appropriate boxing types */
	private Map<X10ClassType, X10ClassType> structBoxingTypes = new HashMap<X10ClassType, X10ClassType>();

	/** All class instances share the same location for the vptr (the pointer to the vtable) */
	private Entity vptrEntity;

	private static long boxingID = 1;

	/**
	 * Name of the boxed value.
	 */
	public static String BOXED_VALUE = "__value__";

	/**
	 * @param extInfo language extension this type system is for
	 */
	public TypeSystem(final ExtensionInfo extInfo) {
		super(extInfo);
	}

	private String getUniqueBoxingName(final String structName) {
		return structName + "__FirmBox__" + (boxingID++);
	}

	/**
	 * Returns the boxing type for a given struct type
	 * @param type The type for which the boxing type should be returned
	 * @return The boxing type for the given struct type
	 */
	public X10ClassType getBoxingType(final X10ClassType type) {
		assert Types.isX10Struct(type);

		final X10ClassType ret = structBoxingTypes.get(type);
		if(ret != null) return ret;

        final Position pos = Position.COMPILER_GENERATED;

        X10ClassDef cd = new X10ClassDef_c(this, null);

        // use a unique name for the boxing class
        final String name = getUniqueBoxingName(type.name().toString());

        // Get the "Object" class and set it as the super class
        final X10ClassType objectType = getObjectType();

        cd.position(pos);
        cd.name(Name.make(name));
        cd.setPackage(null);
        cd.kind(ClassDef.TOP_LEVEL);
        cd.flags(Flags.FINAL);
        cd.superType(Types.ref(objectType));

        X10ClassType ct = cd.asType();

        final Set<polyglot.types.Type> intSet = new HashSet<polyglot.types.Type>();

        for(polyglot.types.Type t : type.interfaces()) { // "interfaces" method returns duplicates ???
        	if(intSet.contains(t)) continue;
        	intSet.add(t);

        	final X10ClassType intervace = (X10ClassType)t;
        	final X10ClassDef  intervaceDef = intervace.x10Def();

        	cd.addInterface(Types.ref(intervace));

        	for(final MethodDef mDef : intervaceDef.methods())  {

				/* DELETE ME START: "following methods are not supported yet" */
        		final MethodInstance mi = mDef.asInstance();
    			final String x = mi.name().toString();
    			if(x.equals("compareTo") || x.equals("toString") || x.equals("hashCode") || x.equals("equals") ||
    			   x.equals("_struct_equals") || x.equals("typeName")) {
    				continue;
    			}
    			/* DELETE ME END: */

        		final X10MethodDef md = methodDef(pos, Types.ref(ct), Flags.PUBLIC, mDef.returnType(), mDef.name(),
        										  mDef.formalTypes());

                cd.addMethod(md);
        	}
        }

        // add the boxed value to the class.
        final FieldDef boxValue = fieldDef(pos, Types.ref(ct), Flags.PUBLIC, Types.ref(type), Name.make(BOXED_VALUE));
        cd.addField(boxValue);

        // preinit the type
        asFirmType(ct);
        final Type ft  = asFirmCoreType(ct);

        final FieldInstance fieldInstance = boxValue.asInstance();
        addField(fieldInstance, ft);

        structBoxingTypes.put(type, ct);

		return ct;
	}

	/**
	 * Creates a method type (= a member function). So we in addition to the
	 * type we need the flags to determine if it is static and the owner class
	 * to determine the type of the "this" parameter.
	 * @param methodInstance	an X10 method instance, for which a Firm type is needed
	 * @return	corresponding Firm type
	 */
	public MethodType asFirmType(MethodInstance methodInstance) {
		final List<polyglot.types.Type> formalTypes
			= methodInstance.formalTypes();
		final Flags flags = methodInstance.flags();
		final boolean isStatic = flags.isStatic();
		final int nParameters = formalTypes.size() + (isStatic ? 0 : 1);
		final int nResults = methodInstance.returnType() == Void() ? 0 : 1;
		final X10ClassType owner = (X10ClassType) methodInstance.container();
		final Type[] parameterTypes = new firm.Type[nParameters];
		final Type[] resultTypes = new firm.Type[nResults];

		int p = 0;
		if (!isStatic) {
			final Type thisType = asFirmType(owner);
			parameterTypes[p++] = thisType;
		}

		for (polyglot.types.Type type : formalTypes) {
			final polyglot.types.Type simpType = simplifyType(type);
			if(isFirmStructType(simpType)) {
				parameterTypes[p++] = asFirmCoreType(simpType);
			} else {
				parameterTypes[p++] = asFirmType(simpType);
			}
		}
		assert (p == nParameters);

		if (nResults > 0) {
			assert nResults == 1;
			final polyglot.types.Type type = methodInstance.returnType();
			final polyglot.types.Type simpType = simplifyType(type);
			if(isFirmStructType(simpType)) {
				resultTypes[0] = asFirmCoreType(simpType);
			} else {
				resultTypes[0] = asFirmType(simpType);
			}
		}

		return new MethodType(parameterTypes, resultTypes);
	}

	/**
	 * Layouts a given type
	 * @param type The type which should be layouted
	 */
	private void layoutType(final Type type) {
		if(type.getTypeState() == ir_type_state.layout_fixed)
			return;

		if(!(type instanceof ClassType))
			return;

		ClassType klass = (ClassType)type;
		for(Entity entity : klass.getMembers())
			layoutType(entity.getType());

		klass.layoutFields();
		klass.finishLayout();
	}

	/**
	 * Finishes the type system.
	 */
	public void finishTypeSystem() {
		// Before layouting the types we need to run liboo's lowering first to remove method entities from the graph. 
		OO.lowerProgram();
		
		for(final Type type : firmCoreTypes.values())
			layoutType(type);
	}

	/**
	 * Checks if we need the core type for a given type (for example: Parameter passing)
	 * @param type The type which should be checked
	 * @return True if we need the core type for the given type
	 */
	public boolean isFirmStructType(final polyglot.types.Type type) {
		final polyglot.types.Type baseType = simplifyType(type);
		return Types.isX10Struct(baseType) && !isFirmPrimitiveType(baseType);
	}

	/**
	 * Simplifies a given polyglot type -> Returns the base type of a given type. -> Removes constrained types, annotations etc.
	 * @param type The type which should be simplified
	 * @return The simplified version of the given type
	 */
	public polyglot.types.Type simplifyType(final polyglot.types.Type type) {
		final polyglot.types.Type t =  Types.baseType(type);
		return Types.stripConstraints(t);
	}

	/**
	 * Checks if 2 types are equal
	 * @param type1 The first type
	 * @param type2 The second type
	 * @return True if both types are equal.
	 */
	private boolean equalTypes(final polyglot.types.Type type1, final polyglot.types.Type type2) {
		return equals((TypeObject)type1, (TypeObject)type2);
	}

	/**
	 * True if the given type is handled as a primitive type in firm.
	 * @param type_ The type which should be checked
	 * @return True if the given type is handled as a primitive type.
	 */
	public boolean isFirmPrimitiveType(final polyglot.types.Type type_) {
		final polyglot.types.Type type = simplifyType(type_);
		return equalTypes(type, Int())     || equalTypes(type, UInt())   ||
		   	   equalTypes(type, Long())    || equalTypes(type, ULong())  ||
		   	   equalTypes(type, Byte())    || equalTypes(type, UByte())  ||
			   equalTypes(type, Float())   || equalTypes(type, Double()) ||
			   equalTypes(type, Boolean()) ||
			   equalTypes(type, Char());
	}

	/**
	 * create a method type for an X10 constructor
	 */
	public MethodType asFirmType(X10ConstructorInstance instance) {
		final List<polyglot.types.Type> formalTypes
			= instance.formalTypes();
		final int nParameters = formalTypes.size() + 1;
		final int nResults = 0;
		final X10ClassType owner = (X10ClassType) instance.container();
		final Type[] parameterTypes = new firm.Type[nParameters];
		final Type[] resultTypes = new firm.Type[nResults];

		int p = 0;
		final Type thisType = asFirmType(owner);
		parameterTypes[p++] = thisType;
		for (polyglot.types.Type type : formalTypes) {
			final polyglot.types.Type simpType = simplifyType(type);
			if(isFirmStructType(simpType)) {
				parameterTypes[p++] = asFirmCoreType(simpType);
			} else {
				parameterTypes[p++] = asFirmType(simpType);
			}
		}
		assert (p == nParameters);

		return new MethodType(parameterTypes, resultTypes);
	}

	/**
	 * Returns the corresponding Firm type for the given polyglot type
	 *
	 * @param type The given polyglot type
	 * @return corresponding Firm method type
	 */
	public firm.Type asFirmType(polyglot.types.Type type) {
		/* strip type-constraints */
		final polyglot.types.Type baseType = simplifyType(type);

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

	/**
	 * Adds a new field to the type system
	 * @param field The field which should be added
	 * @param klass The defining class of the field
	 */
	private void addField(final FieldInstance field, final firm.Type klass) {
		final Flags fieldFlags = field.flags();
		final String name = X10NameMangler.mangleTypeObjectWithDefClass(field);

		firm.Type type;
		if(isFirmStructType(field.type()))
			type = asFirmCoreType(field.type());
		else
			type = asFirmType(field.type());

		final firm.Type owner = fieldFlags.isStatic() ? Program.getGlobalType() : klass;
		final Entity entity = new Entity(owner, name, type);

		entity.setLdIdent(name);
		OO.setEntityBinding(entity, ddispatch_binding.bind_static);
		fieldMap.put(field, entity);
	}

	/**
	 * Adds a new static field instance to the type system
	 * @param field The field instance which should be added
	 */
	public void addExtraStaticField(final FieldInstance field) {
		assert field.flags().isStatic();

		final firm.Type klass = asFirmCoreType(field.container());
		addField(field, klass);
	}

	@SuppressWarnings("unused")
	private firm.Type createClassType(final X10ClassType classType) {
		final String className = X10NameMangler.mangleTypeObjectWithDefClass(classType);
		final Flags flags = classType.flags();
		ClassType result = new ClassType(className);

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
			OO.setClassIsInterface(result, true);
		} else {
			/* the only thing left without a superclass should be x10.lang.Object */
			assert classType.toString().equals("x10.lang.Object");
			getVptrEntity().setOwner(result);
		}

		/* create interfaces */
		for (polyglot.types.Type iface : classType.interfaces()) {
			Type firmIface = asFirmCoreType(iface);
			result.addSuperType(firmIface);
		}

		/* create fields */
		for (FieldInstance field : classType.fields())
			addField(field, result);

		/* creates fields for properties */
		for (FieldInstance field : classType.properties()) {
			// Fix by mohr on 2011-04-19
			//
			// At this point, classType holds the concrete type, i.e.
			// x10.lang.Array<x10.lang.Integer>.
			// Calling container() on field just returns the generic type, i.e.
			// x10.lang.Array<T> which breaks our mangling.
			// Therefore, we explicitly set the containing class type here.
			addField(field.container(classType), result);
		}

		OO.setClassVPtrEntity(result, getVptrEntity());

		if (!flags.isInterface() && !flags.isStruct()) {
			Entity vtable = new Entity(Program.getGlobalType(), X10NameMangler.mangleVTable(classType), Mode.getP().getType());
			OO.setClassVTableEntity(result, vtable);
		}

		Entity classInfoEntity = new Entity(Program.getGlobalType(), Ident.createUnique(className + "$"), Mode.getP().getType());

		OO.setClassRTTIEntity(result, classInfoEntity);

		// Layouting of classes must be done explicitly by finishTypes

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
		final polyglot.types.Type baseType = simplifyType(type);

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

	/**
	 * @return	a class type for x10.lang.Object
	 */
	public X10ClassType getObjectType() {
		final QName fullName = QName.make("x10.lang", "Object");
	    final List<polyglot.types.Type> types = systemResolver().check(fullName);
	    assert(types != null && types.size() == 1);
	    final Named n = types.get(0);
	    final X10ClassType objectType = (X10ClassType)n;
		return objectType;
	}
}