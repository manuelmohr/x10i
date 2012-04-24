package x10firm.types;

import java.io.BufferedReader;
import java.io.FileReader;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedHashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.StringTokenizer;

import polyglot.types.ClassDef;
import polyglot.types.FieldDef;
import polyglot.types.FieldInstance;
import polyglot.types.Flags;
import polyglot.types.LocalDef;
import polyglot.types.MethodDef;
import polyglot.types.Name;
import polyglot.types.QName;
import polyglot.types.Ref;
import polyglot.types.TypeSystem_c;
import polyglot.types.Types;
import polyglot.util.Position;
import x10.types.MethodInstance;
import x10.types.ThisDef;
import x10.types.TypeParamSubst;
import x10.types.X10ClassDef;
import x10.types.X10ClassType;
import x10.types.X10ConstructorInstance;
import x10.types.X10MethodDef;
import x10.types.X10ParsedClassType;
import x10.types.X10ParsedClassType_c;
import x10firm.CompilerOptions;
import x10firm.visit.CodeGenError;
import x10firm.visit.GenericCodeInstantiationQueue;
import firm.ClassType;
import firm.CompoundType;
import firm.Entity;
import firm.MethodType;
import firm.Mode;
import firm.Mode.Arithmetic;
import firm.OO;
import firm.PointerType;
import firm.PrimitiveType;
import firm.Program;
import firm.Type;
import firm.bindings.binding_oo.ddispatch_binding;
import firm.bindings.binding_typerep.ir_linkage;
import firm.bindings.binding_typerep.ir_type_state;
import firm.bindings.binding_typerep.ir_visibility;

/**
 * Includes everything to map X10 types to Firm types.
 */
public class FirmTypeSystem {
	/** Maps polyglot types to firm types. */
	private final Map<polyglot.types.Type, Type> firmCoreTypes
		= new HashMap<polyglot.types.Type, Type>();

	/** Maps some polyglot types to "native"/primitive firm types. */
	private final Map<polyglot.types.Type, Type> firmTypes
		= new HashMap<polyglot.types.Type, Type>();

	private final Set<polyglot.types.Type> primitiveTypes = new HashSet<polyglot.types.Type>();

	/** We import C functions at the beginning. When we encounter the corresponding X10 native methods,
	 * we have to get the C function entity by the mangled name.
	 */
	private final Map<String, Entity> cStdlibEntities = new HashMap<String, Entity>();

	/** Maps X10 ConstructorInstances, MethodInstance, FieldInstances to firm entities.
	 * We use the mangled names here as keys. (They should be unique).
	 */
	private final Map<String, Entity> entities = new HashMap<String, Entity>();
	/** Maps struct types to the appropriate boxing types. */
	private final Map<X10ClassType, X10ClassType> structBoxingTypes
		= new HashMap<X10ClassType, X10ClassType>();

	private final GenericCodeInstantiationQueue instantiationQueue;

	/** All class instances share the same location for the vptr (the pointer to the vtable). */
	private Entity vptrEntity;

	/** information about native classes. */
	private static final class NativeClassInfo {
		private final int size;

		private NativeClassInfo(final int size) {
			this.size = size;
		}

		/** Returns size of native class in bytes. */
		public int getSize() {
			return size;
		}

		public static NativeClassInfo newNativeClassInfo(final int size) {
			return new NativeClassInfo(size);
		}
	}

	/** Maps between X10ClassTypes and the appropriate native class info. */
	private final Map<String, NativeClassInfo> x10NativeTypes = new HashMap<String, NativeClassInfo>();

	/** Name of the boxed value. */
	public static final String BOXED_VALUE = "__value__";

	/** Reference to the generic type system. */
	private final GenericTypeSystem typeSystem;

	/**
	 * Construct a firm type system object.
	 * @param typeSystem The X10 type system
	 */
	public FirmTypeSystem(final GenericTypeSystem typeSystem, final CompilerOptions options,
	                      final GenericCodeInstantiationQueue instantiationQueue) {
		this.typeSystem = typeSystem;
		this.instantiationQueue = instantiationQueue;
		init(options);
	}

	private void findExistingEntities() {
		final ClassType glob = Program.getGlobalType();
		for (final Entity ent : glob.getMembers()) {
			if (ent.getVisibility() != ir_visibility.ir_visibility_default)
				continue;
			this.cStdlibEntities.put(ent.getLdName(), ent);
			/*
			 * We must put methods into their respective classes. However, this
			 * type does not even exist yet, so this is delayed until the entity
			 * is retrieved from cStdlibEntities.
			 */
		}
	}

	private static String getUniqueBoxingName(final X10ClassType clazz) {
		final StringBuffer buf = new StringBuffer();
		buf.append(clazz.name().toString());
		// handle type arguments
		if (clazz.typeArguments() != null && !clazz.typeArguments().isEmpty()) {
			buf.append("_");
			for (final polyglot.types.Type typeArg : clazz.typeArguments()) {
				buf.append(typeArg.name().toString());
			}
			buf.append("_");
		}
		buf.append("_FirmBox_");
		return buf.toString();
	}

	private boolean inited = false;

	/** Initializes the firm type system. */
	private void init(final CompilerOptions options) {
		if (inited)
			return;
		final String nativeTypesConfig = options.getFirmNativeTypesFilename();
		inited = true;
		findExistingEntities();
		readFirmNativeTypesConfig(nativeTypesConfig);
		initFirmTypes();
		NameMangler.setup(typeSystem, options);
	}

	private void readFirmNativeTypesConfig(final String firmNativeTypesFilename) {
		try {
			final BufferedReader in = new BufferedReader(new FileReader(firmNativeTypesFilename));

			String line = null;
			while ((line = in.readLine()) != null) {
				final StringTokenizer tokenizer = new StringTokenizer(line);
				if (tokenizer.countTokens() != 2)
					throw new RuntimeException("Illegal format in " + firmNativeTypesFilename);
				final String qualifiedName = tokenizer.nextToken();
				final String sizeString = tokenizer.nextToken();
				final int size;
				try {
					size = Integer.parseInt(sizeString);
				} catch (final NumberFormatException e) {
					throw new RuntimeException("Illegal size " + sizeString + " in " + firmNativeTypesFilename);
				}
				final NativeClassInfo info = NativeClassInfo.newNativeClassInfo(size);
				x10NativeTypes.put(qualifiedName, info);
			}

			in.close();
		} catch (final Exception exc) {
			System.err.println("Error in reading file" + firmNativeTypesFilename + " Exception: " + exc);
			System.exit(-1);
		}
	}

	/**
	 * Returns the boxing type for a given struct type.
	 * @param type The type for which the boxing type should be returned
	 * @return The boxing type for the given struct type
	 */
	public X10ClassType getBoxingType(final X10ClassType type) {
		assert typeSystem.isStructType(type);
		final X10ClassType ret = structBoxingTypes.get(type);
		if (ret != null)
			return ret;

		final Position pos = Position.COMPILER_GENERATED;
		final TypeSystem_c x10TypeSystem = typeSystem.getTypeSystem();
		final X10ClassType objectType = x10TypeSystem.Object();

		// use a unique name for the boxing class
		final String name = getUniqueBoxingName(type);

		final X10ClassDef boxedClass = x10TypeSystem.createClassDef();
		boxedClass.position(pos);
		boxedClass.name(Name.make(name));
		boxedClass.setPackage(Types.ref(type.package_()));
		boxedClass.kind(ClassDef.TOP_LEVEL);
		boxedClass.flags(Flags.FINAL);
		boxedClass.superType(Types.ref(objectType));

		final X10ClassType boxedClassType = boxedClass.asType();
		final Ref<X10ClassType> boxedClassRef = Types.ref(boxedClassType);
		final ThisDef thisDef = x10TypeSystem.thisDef(pos, boxedClassRef);

		final HashSet<polyglot.types.Type> ifaceSet = new HashSet<polyglot.types.Type>();

		for (final polyglot.types.Type t : type.interfaces()) {
			// interfaces() returns duplicates???
			if (ifaceSet.contains(t))
				continue;
			ifaceSet.add(t);

			final X10ParsedClassType iface = (X10ParsedClassType) t;
			final X10ClassDef interfaceDef = iface.x10Def();

			boxedClass.addInterface(Types.ref(iface));

			// get the substitution mapping
			final TypeParamSubst subst = iface.subst();

			for (final MethodDef mDef : interfaceDef.methods()) {
				final X10MethodDef md = x10TypeSystem.methodDef(pos,
						boxedClassRef, Flags.PUBLIC, mDef.returnType(),
						mDef.name(), mDef.formalTypes());
				md.setThisDef(thisDef);
				md.setGuard(mDef.guard());
				md.setTypeGuard(mDef.typeGuard());

				final List<Ref<? extends polyglot.types.Type>> formalTypes
					= new LinkedList<Ref<? extends polyglot.types.Type>>();
				final List<LocalDef> formalNames = new LinkedList<LocalDef>();

				final List<Ref<? extends polyglot.types.Type>> fTypes = mDef.formalTypes();
				final List<LocalDef> fNames = mDef.formalNames();

				assert fTypes.size() == fNames.size();
				for (int i = 0; i < fTypes.size(); i++) {
					final Ref<? extends polyglot.types.Type> fType = fTypes.get(i);
					final Ref<? extends polyglot.types.Type> newType = subst.reinstantiate(fType);
					final LocalDef fName = fNames.get(i);

					final LocalDef newName;
					if (newType != fType) {
						newName = x10TypeSystem.localDef(pos, fName.flags(), newType, fName.name());
					} else {
						newName = fName;
					}

					formalNames.add(newName);
					formalTypes.add(newType);
				}

				// Watch out for generic return types -> Do a substitution
				Ref<? extends polyglot.types.Type> returnType = mDef.returnType();
				returnType = subst.reinstantiate(returnType);
				md.setReturnType(returnType);

				md.setFormalNames(formalNames);
				md.setFormalTypes(formalTypes);

				boxedClass.addMethod(md);
			}
		}

		// add the boxed value to the class.
		final FieldDef boxValue = x10TypeSystem.fieldDef(pos,
				Types.ref(boxedClassType), Flags.PUBLIC, Types.ref(type),
				Name.make(BOXED_VALUE));
		boxedClass.addField(boxValue);

		// preinit the type
		asType(boxedClassType);
		final Type ft = asClass(boxedClassType);

		final FieldInstance fieldInstance = boxValue.asInstance();
		getFieldEntity(fieldInstance, ft);

		structBoxingTypes.put(type, boxedClassType);
		return boxedClassType;
	}

	/**
	 * Creates a method type (= a member function). So we in addition to the
	 * type we need the flags to determine if it is static and the owner class
	 * to determine the type of the "this" parameter.
	 * @param methodInstance an X10 method instance, for which a Firm type is needed
	 * @return corresponding Firm type
	 */
	private MethodType asFirmType(final MethodInstance methodInstance) {
		final List<polyglot.types.Type> formalTypes
			= methodInstance.formalTypes();
		final Flags flags = methodInstance.flags();
		final boolean isStatic = flags.isStatic();
		final int nParameters = formalTypes.size() + (isStatic ? 0 : 1);
		final int nResults = methodInstance.returnType() == typeSystem.getTypeSystem().Void() ? 0 : 1;
		final X10ClassType owner = (X10ClassType) methodInstance.container();
		final Type[] parameterTypes = new firm.Type[nParameters];
		final Type[] resultTypes = new firm.Type[nResults];

		int p = 0;
		if (!isStatic) {
			final Type thisType = asType(owner);
			parameterTypes[p++] = thisType;
		}

		for (final polyglot.types.Type type : formalTypes) {
			parameterTypes[p++] = asType(type);
		}
		assert p == nParameters;

		if (nResults > 0) {
			assert nResults == 1;
			final polyglot.types.Type type = methodInstance.returnType();
			resultTypes[0] = asType(type);
		}

		return new MethodType(parameterTypes, resultTypes);
	}

	/**
	 * Layouts a given type.
	 * @param type The type which should be layouted
	 */
	private void layoutType(final Type type) {
		if (type.getTypeState() == ir_type_state.layout_fixed)
			return;

		if (!(type instanceof ClassType))
			return;

		final ClassType klass = (ClassType)type;
		for (final Entity entity : klass.getMembers()) {
			layoutType(entity.getType());
		}

		klass.layoutFields();
		klass.finishLayout();
	}

	/**
	 * Finishes the type system.
	 * This should be called when no further modification or new type
	 * creations are planned. Fixes the final type memory layout.
	 */
	public void finishTypeSystem() {
		for (final Type type : firmCoreTypes.values()) {
			layoutType(type);
		}
	}

	/**
	 * Checks if we need the core type for a given type (for example: Parameter passing).
	 * @param type The type which should be checked
	 * @return True if we need the core type for the given type
	 */
	public boolean isFirmStructType(final polyglot.types.Type type) {
		final polyglot.types.Type concrete = typeSystem.getConcreteType(type);
		return typeSystem.isStructType(concrete) && !primitiveTypes.contains(concrete);
	}

	/**
	 * Creates a method type for an X10 constructor.
	 */
	public MethodType getConstructorType(final X10ConstructorInstance instance) {
		final List<polyglot.types.Type> formalTypes = instance.formalTypes();
		final X10ClassType owner = (X10ClassType) instance.container();
		final Type[] parameterTypes;
		final Type[] resultTypes;

		/* we have 2 variants:
		 * - struct types simply return the struct, they don't have a
		 *   this pointer as parameter.
		 * - native constructors perform allocation themselves for increased
		 *   flexibility
		 * - class types don't return anything but expect allocated memory
		 *   in the implicit this pointer.
		 */
		int p = 0;
		if (typeSystem.isStructType(owner)) {
			final int nParameters = formalTypes.size();
			final polyglot.types.Type returnType = instance.returnType();
			resultTypes = new Type[] {asType(returnType)};
			parameterTypes = new Type[nParameters];
		} else {
			final int nParameters = formalTypes.size() + 1;
			resultTypes = new Type[0];
			parameterTypes = new Type[nParameters];

			final Type thisType = asType(owner);
			parameterTypes[p++] = thisType;
		}

		for (final polyglot.types.Type type : formalTypes) {
			parameterTypes[p++] = asType(type);
		}
		assert p == parameterTypes.length;

		return new MethodType(parameterTypes, resultTypes);
	}

	/**
	 * Returns the corresponding Firm type for the given polyglot type.
	 *
	 * For primitive types (x10.lang.Int, etc) returns "native" Firm types (Is, etc).
	 * If you need class Firm types use the {@code asClass} method.
	 */
	public Type asType(final polyglot.types.Type type) {
		/* strip type-constraints */
		final polyglot.types.Type baseType = typeSystem.getConcreteType(type);

		Type result = firmTypes.get(baseType);
		if (result != null)
			return result;

		result = asClass(baseType);
		/* we have references to stuff unless it is a struct type */
		if (!typeSystem.isStructType(baseType)) {
			result = new PointerType(result);
		}
		firmTypes.put(baseType, result);

		return result;
	}

	private Entity getVptrEntity() {
		if (vptrEntity == null) {
			final firm.Type pointerType = Mode.getP().getType();
			vptrEntity = new Entity(Program.getGlobalType(), "$vptr", pointerType);
		}
		return vptrEntity;
	}

	/**
	 * Adds a new field to the type system.
	 * @param field The field which should be added
	 * @param klass The defining class of the field
	 * @return The firm entity for the field
	 */
	private Entity getFieldEntity(final FieldInstance field, final firm.Type owner) {
		final String name = NameMangler.mangleField(field);
		final Entity existingEntity = entities.get(name);
		if (existingEntity != null)
			return existingEntity;

		final Type type = asType(field.type());
		/* the asType call could have created the type for us */
		final Entity existingEntity2 = entities.get(name);
		if (existingEntity2 != null)
			return existingEntity2;

		/* we mustn't create entities in native classes with known size */
		assert owner.getTypeState() != ir_type_state.layout_fixed;
		final Entity entity = new Entity(owner, name, type);
		entity.setLdIdent(name);
		OO.setEntityBinding(entity, ddispatch_binding.bind_static);
		entities.put(name, entity);
		return entity;
	}

	@SuppressWarnings("unused")
	private firm.Type createClassType(final X10ClassType classType) {
		final Flags flags = classType.flags();
		final ClassType result = new ClassType(classType.toString());
		final QName qname = classType.fullName();
		final NativeClassInfo classInfo = x10NativeTypes.get(qname.toString());
		if (classInfo != null) {
			result.setSizeBytes(classInfo.getSize());
			result.setTypeState(ir_type_state.layout_fixed);
		}

		instantiationQueue.instantiateGenericClass(classType);

		/* put the class into the core types already, because we could
		 * have a field referencing ourself */
		firmCoreTypes.put(classType, result);

		/* create supertypes */
		final polyglot.types.Type superType = classType.superClass();
		if (superType != null) {
			final Type firmSuperType = asClass(superType);
			result.addSuperType(firmSuperType);
			new Entity(result, "$super", firmSuperType);
		} else if (flags.isStruct() || classType.isAnonymous()) {
			final X10ClassType any = typeSystem.getTypeSystem().Any();
			final Type firmAny = asClass(any);
			result.addSuperType(firmAny);
		} else if (flags.isInterface()) {
			/* no superclass interface */
			OO.setClassIsInterface(result, true);
		} else {
			/* the only thing left without a superclass should be x10.lang.Object */
			assert classType.toString().equals("x10.lang.Object");
			getVptrEntity().setOwner(result);
		}

		/* create interfaces */
		final Set<polyglot.types.Type> interfaces = new LinkedHashSet<polyglot.types.Type>(classType.interfaces());
		for (final polyglot.types.Type iface : interfaces) {
			final Type firmIface = asClass(iface);
			result.addSuperType(firmIface);
		}

		/* create fields */
		for (final FieldInstance field : classType.fields()) {
			final Type owner = field.flags().isStatic() ? Program.getGlobalType() : result;
			getFieldEntity(field, owner);
		}

		/* creates fields for properties */
		for (final FieldInstance field : classType.properties()) {
			/* when calling X10ParsedClassType.fields() the fields get reinstantiated,
			 * for some reason (simply a bug?) this does not happen for properties() */
			final FieldInstance reinstantiated;
			if (classType instanceof X10ParsedClassType_c) {
				final X10ParsedClassType_c x10c = (X10ParsedClassType_c) classType;
				reinstantiated = x10c.subst().reinstantiate(field);
			} else {
				reinstantiated = field;
			}
			final Type owner = reinstantiated.flags().isStatic() ? Program.getGlobalType() : result;
			getFieldEntity(reinstantiated, result);
		}

		final Type global = Program.getGlobalType();
		final Type pointerType = Mode.getP().getType();

		if (!flags.isStruct())
			OO.setClassVPtrEntity(result, getVptrEntity());

		if (!flags.isInterface() && !flags.isStruct()) {
			final String vtableName = NameMangler.mangleVTable(classType);
			final Entity cEntity = cStdlibEntities.get(vtableName);
			final Entity vtable;
			if (cEntity != null) {
				if (!cEntity.hasLinkage(ir_linkage.IR_LINKAGE_WEAK)) {
					throw new RuntimeException(
							"Existing entity for vtable in c-library (" + vtableName + ") is not weak");
				}
				cEntity.removeLinkage(ir_linkage.IR_LINKAGE_WEAK);
				vtable = cEntity;
			} else {
				vtable = new Entity(global, vtableName, pointerType);
			}
			vtable.setVisibility(ir_visibility.ir_visibility_default);
			vtable.addLinkage(ir_linkage.IR_LINKAGE_CONSTANT);
			OO.setClassVTableEntity(result, vtable);
		}

		final String rttiName = NameMangler.mangleTypeinfo(classType);
		final Entity classInfoEntity = new Entity(global, rttiName, pointerType);
		classInfoEntity.setVisibility(ir_visibility.ir_visibility_local);
		classInfoEntity.addLinkage(ir_linkage.IR_LINKAGE_CONSTANT);
		OO.setClassRTTIEntity(result, classInfoEntity);

		// Layouting of classes must be done explicitly by finishTypes

		return result;
	}

	/**
	 * returns firm entity created for a FieldInstance.
	 * Note: this will only work if createClassType was already called for
	 * the fields class.
	 */
	public Entity getFieldEntity(final FieldInstance instance) {
		final firm.Type owner;
		if (!instance.flags().isStatic()) {
			/* make sure enclosing class-type has been created,
			 * this should in turn create all fields */
			owner = asClass(instance.container());
		} else {
			owner = Program.getGlobalType();
		}

		return getFieldEntity(instance, owner);
	}

	/**
	 * same as asClass() but expects parameter to be concrete already.
	 */
	private Type concreteAsClass(final polyglot.types.Type type) {
		Type result = firmCoreTypes.get(type);
		if (result != null)
			return result;

		if (!(type instanceof X10ClassType)) {
			throw new java.lang.RuntimeException("Attempt to create firm classtype from non-X10ClassType " + type);
		}

		result = createClassType((X10ClassType) type);
		return result;
	}

	/**
	 * For primitive types (x10.lang.Int, etc) returns class (compound) Firm types (Is, etc).
	 * If you need native Firm types (Is, etc) use the {@code asType} method.
	 *
	 * @param origType  The given polyglot ast-type
	 * @return the firm type for a given ast-type.
	 */
	public firm.Type asClass(final polyglot.types.Type origType) {
		final polyglot.types.Type type = typeSystem.getConcreteType(origType);
		return concreteAsClass(type);
	}

	/**
	 * Returns the mode for a given ast-type.
	 */
	public Mode getFirmMode(final polyglot.types.Type type) {
		final Type firmType = asType(type);
		Mode mode = firmType.getMode();
		if (mode == null) {
			assert typeSystem.isStructType(type);
			mode = Mode.getP();
		}
		return mode;
	}

	private void recordPrimitiveType(final polyglot.types.Type x10Type, final Type firmType, final String mangled) {
		firmTypes.put(x10Type, firmType);
		primitiveTypes.add(x10Type);
		NameMangler.addPrimitiveMangling(x10Type, mangled);
	}

	/**
	 * Should be called before the firm-graph is constructed. This extra step
	 * is necessary because at the time the type-system Object is created in
	 * the ExtensionInfo we must not use the Int(), Boolean(), ... functions
	 * yet.
	 */
	private void initFirmTypes() {
		final TypeSystem_c x10TypeSystem = typeSystem.getTypeSystem();

		/* we "lower" some well-known types directly to firm modes */
		final Mode modePointer = Mode.getP();
		final Type typePointer = new PrimitiveType(modePointer);
		recordPrimitiveType(typeSystem.pointer(), typePointer, "Pv");

		final int maxAlign = 4;

		final Mode modeLong = Mode.createIntMode("Long", Arithmetic.TwosComplement, 64, true, 64);
		final Type typeLong = new PrimitiveType(modeLong);
		typeLong.setAlignmentBytes(maxAlign);
		recordPrimitiveType(x10TypeSystem.Long(), typeLong, "x");

		final Mode modeULong = Mode.createIntMode("ULong", Arithmetic.TwosComplement, 64, false, 64);
		final Type typeULong = new PrimitiveType(modeULong);
		typeULong.setAlignmentBytes(maxAlign);
		recordPrimitiveType(x10TypeSystem.ULong(), typeULong, "y");

		final Mode modeInt = Mode.createIntMode("Int", Arithmetic.TwosComplement, 32, true, 32);
		final Type typeInt = new PrimitiveType(modeInt);
		recordPrimitiveType(x10TypeSystem.Int(), typeInt, "i");

		final Mode modeUInt = Mode.createIntMode("UInt", Arithmetic.TwosComplement, 32, false, 32);
		final Type typeUInt = new PrimitiveType(modeUInt);
		recordPrimitiveType(x10TypeSystem.UInt(), typeUInt, "j");

		final Mode modeShort = Mode.createIntMode("Short", Arithmetic.TwosComplement, 16, true, 32);
		final Type typeShort = new PrimitiveType(modeShort);
		recordPrimitiveType(x10TypeSystem.Short(), typeShort, "s");

		final Mode modeUShort = Mode.createIntMode("UShort", Arithmetic.TwosComplement, 16, false, 32);
		final Type typeUShort = new PrimitiveType(modeUShort);
		recordPrimitiveType(x10TypeSystem.UShort(), typeUShort, "t");

		final Mode modeByte = Mode.createIntMode("Byte", Arithmetic.TwosComplement, 8, true, 32);
		final Type typeByte = new PrimitiveType(modeByte);
		recordPrimitiveType(x10TypeSystem.Byte(), typeByte, "a");

		final Mode modeUByte = Mode.createIntMode("UByte", Arithmetic.TwosComplement, 8, false, 32);
		final Type typeUByte = new PrimitiveType(modeUByte);
		recordPrimitiveType(x10TypeSystem.UByte(), typeUByte, "h");

		/* since octopos has no real support for unicode yet, and we have a somewhat hardware-centric
		 * project we go for 8bit-chars for now. (You can still use UTF-8 strings after all) */
		final Mode modeChar = modeByte;
		final Type typeChar = new PrimitiveType(modeChar);
		recordPrimitiveType(x10TypeSystem.Char(), typeChar, "c");

		final Mode modeFloat = Mode.createFloatMode("Float", Arithmetic.IEE754, 8, 23);
		final Type typeFloat = new PrimitiveType(modeFloat);
		recordPrimitiveType(x10TypeSystem.Float(), typeFloat, "f");

		final Mode modeDouble = Mode.createFloatMode("Double", Arithmetic.IEE754, 11, 52);
		final Type typeDouble = new PrimitiveType(modeDouble);
		typeLong.setAlignmentBytes(maxAlign);
		recordPrimitiveType(x10TypeSystem.Double(), typeDouble, "d");

		/* Note that the mode_b in firm can't be used here, since it is an
		 * internal mode which cannot be used for fields/call parameters/return
		 * values. We will use mode_b only internally when generating code for
		 * conditional jumps. */
		final Mode modeBoolean = Mode.getBu();
		final Type typeBoolean = new PrimitiveType(modeBoolean);
		recordPrimitiveType(x10TypeSystem.Boolean(), typeBoolean, "b");

		/* do not fail for Null() types */
		firmTypes.put(x10TypeSystem.Null(), typePointer);

		NameMangler.addPrimitiveMangling(x10TypeSystem.Void(), "v");
	}

	/**
	 * @param instance a constructor method instance
	 * @return a Firm entity corresponding to the constructor
	 */
	public Entity getConstructorEntity(final X10ConstructorInstance instance) {
		final String name = NameMangler.mangleConstructor(instance);
		Entity entity = entities.get(name);

		if (entity == null) {
			final Flags flags = instance.flags();
			final firm.Type type = getConstructorType(instance);

			entity = new Entity(Program.getGlobalType(), name, type);
			entity.setLdIdent(name);

			if (flags.isAbstract()) {
				OO.setMethodAbstract(entity, true);
			}

			if (flags.isNative()) {
				entity.setVisibility(ir_visibility.ir_visibility_external);
			}

			OO.setMethodExcludeFromVTable(entity, true);
			/* the binding of a constructor is static as we will not use the
			 * vtable to determine which method to call.
			 * (Note that we still have a "this" pointer anyway) */
			OO.setEntityBinding(entity, ddispatch_binding.bind_static);
			entities.put(name, entity);
		}
		return entity;
	}

	/**
	 * Returns the potentially overridden method of a given method.
	 * @param instance The method instance which should be checked
	 * @return The overridden method instance or null
	 */
	private MethodInstance getOverriddenMethod(final MethodInstance instance) {
		final Flags flags = instance.flags();
		// static or abstract methods can't override other methods.
		if (flags.isStatic() || flags.isAbstract())
			return null;

		final List<MethodInstance> overrides = new LinkedList<MethodInstance>();

		overrides.addAll(instance.overrides(typeSystem.emptyContext()));
		final X10ClassType myClassType = (X10ClassType)instance.container();
		// Watch out for constructors of classes with super classes
		if (myClassType.superClass() != null && overrides.size() > 1) {
			// the overridden methods in overrides are sorted !!!
			return overrides.get(1);
		}
		return null;
	}

	private static boolean methodsCompatible(final MethodType type1, final MethodType type2) {
		if (type1.getVariadicity() != type2.getVariadicity())
			return false;
		if (type1.getNRess() != type2.getNRess())
			return false;
		if (type1.getNParams() != type2.getNParams())
			return false;
		for (int i = 0; i < type1.getNRess(); ++i) {
			final firm.Type param1 = type1.getResType(i);
			final firm.Type param2 = type2.getResType(i);
			if (param1 instanceof CompoundType != param2 instanceof CompoundType)
				return false;
			if (!(param1 instanceof CompoundType) && !param1.getMode().equals(param2.getMode()))
				return false;
		}
		for (int i = 0; i < type2.getNParams(); ++i) {
			final firm.Type param1 = type1.getParamType(i);
			final firm.Type param2 = type2.getParamType(i);
			if (!param1.getMode().equals(param2.getMode()))
				return false;
		}
		return true;
	}

	/**
	 * Returns entity for an X10 method.
	 */
	public Entity getMethodEntity(final MethodInstance instance) {
		final String name = NameMangler.mangleMethod(instance);
		final Entity entity = entities.get(name);

		if (entity != null)
			return entity;

		return createMethodEntity(name, instance);
	}

	private Entity createMethodEntity(final String name, final MethodInstance instance) {
		final firm.Type type = asFirmType(instance);
		final X10ClassType owner = (X10ClassType) instance.container();
		final String shortName = NameMangler.mangleMethodShort(instance);
		final Flags flags = instance.flags();
		final Type ownerFirm;
		if (!flags.isStatic()) {
			final firm.Type owningClass = asClass(owner);
			ownerFirm = owningClass;
		} else {
			ownerFirm = Program.getGlobalType();
		}

		Entity entity = null;

		/* try to get it from stdlib */
		final Entity cEntity = this.cStdlibEntities.get(name);
		if (cEntity != null) {
			/* make weak entities non-weak and remove existing implementation */
			if (cEntity.hasLinkage(ir_linkage.IR_LINKAGE_WEAK)) {
				cEntity.removeLinkage(ir_linkage.IR_LINKAGE_WEAK);
				Program.removeGraph(cEntity.getGraph());
			} else {
				assert flags.isNative();
			}

			final firm.Type entityType = cEntity.getType();
			if (!(entityType instanceof MethodType))
				throw new CodeGenError("native Entity without methodtype", instance.position());
			final MethodType entityMType = (MethodType) entityType;
			final MethodType mType = (MethodType) type;
			if (!methodsCompatible(entityMType, mType))
				throw new CodeGenError(
						String.format("native Entity '%s' does not match declared type", instance),
						instance.position());

			/* fix up stuff, which was impossible to do during the import */
			cEntity.setOwner(ownerFirm);

			entity = cEntity;
		}

		if (entity == null) {
			entity = new Entity(ownerFirm, shortName, type);
			entity.setLdIdent(name);
		}

		if (flags.isStatic()) {
			OO.setEntityBinding(entity, ddispatch_binding.bind_static);
		} else if (owner.flags().isInterface()) {
			OO.setEntityBinding(entity, ddispatch_binding.bind_interface);
		} else if (typeSystem.isStructType(owner)) {
			/* structs have no virtual table */
			OO.setEntityBinding(entity, ddispatch_binding.bind_static);
		} else if (!instance.def().typeParameters().isEmpty()) {
			/* generic methods have to be bound statically */
			OO.setEntityBinding(entity, ddispatch_binding.bind_static);
		} else {
			OO.setEntityBinding(entity, ddispatch_binding.bind_dynamic);
		}

		if (flags.isAbstract()) {
			OO.setMethodAbstract(entity, true);
		}
		if (flags.isNative()) {
			entity.setVisibility(ir_visibility.ir_visibility_external);
		}

		final MethodInstance m = getOverriddenMethod(instance);
		if (m != null) {
			final Entity ent = getMethodEntity(m);
			entity.addEntityOverwrites(ent);
		}

		entities.put(name, entity);
		return entity;
	}
}
