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
import polyglot.types.Context;
import polyglot.types.Def;
import polyglot.types.FieldDef;
import polyglot.types.FieldInstance;
import polyglot.types.Flags;
import polyglot.types.LocalDef;
import polyglot.types.MemberInstance;
import polyglot.types.MethodDef;
import polyglot.types.Name;
import polyglot.types.Ref;
import polyglot.types.Types;
import polyglot.util.Position;
import x10.types.MethodInstance;
import x10.types.ParameterType;
import x10.types.ThisDef;
import x10.types.TypeParamSubst;
import x10.types.X10ClassDef;
import x10.types.X10ClassDef_c;
import x10.types.X10ClassType;
import x10.types.X10ConstructorInstance;
import x10.types.X10MethodDef;
import x10.types.X10ParsedClassType;
import x10firm.CompilerOptions;
import x10firm.visit.CodeGenError;
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

	/** Maps struct types to the appropriate boxing types. */
	private final Map<X10ClassType, X10ClassType> structBoxingTypes
		= new HashMap<X10ClassType, X10ClassType>();

	private final GenericClassContext rootContext = new GenericClassContext();

	private final Map<GenericClassInstance, GenericClassContext> genericContexts
		= new HashMap<GenericClassInstance, GenericClassContext>();

	/** X10 Context. */
	private Context x10Context = null;

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
	private final Map<X10ClassType, NativeClassInfo> x10NativeTypes
		= new HashMap<X10ClassType, NativeClassInfo>();

	/** Maps between firm class types and the appropriate native object size. */
	private final Map<ClassType, NativeClassInfo> firmNativeTypes
		= new HashMap<ClassType, NativeClassInfo>();

	/** Name of the boxed value. */
	public static final String BOXED_VALUE = "__value__";

	/** Reference to the generic type system. */
	private final GenericTypeSystem x10TypeSystem;

	/**
	 * Construct a firm type system object.
	 * @param x10TypeSystem The X10 type system
	 */
	public FirmTypeSystem(final GenericTypeSystem x10TypeSystem) {
		this.x10TypeSystem = x10TypeSystem;
		this.x10Context    = new Context(this.x10TypeSystem);
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
	public void init(final CompilerOptions options) {
		if (inited)
			return;
		final String nativeTypesConfig = options.getFirmNativeTypesFilename();
		inited = true;
		findExistingEntities();
		readFirmNativeTypesConfig(nativeTypesConfig);
		initFirmTypes();
		NameMangler.setup(x10TypeSystem, options);
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
				int size = 0;

				try {
					size = Integer.parseInt(tokenizer.nextToken());
				} catch (final NumberFormatException nfexc) {
					throw new RuntimeException("Illegal size " + size  + " in " + firmNativeTypesFilename);
				}
				final X10ClassType klass = x10TypeSystem.load(qualifiedName);
				x10NativeTypes.put(klass, NativeClassInfo.newNativeClassInfo(size));
			}

			in.close();
		} catch (final Exception exc) {
			System.err.println("Error in reading file" + firmNativeTypesFilename + " Exception: " + exc);
			System.exit(-1);
		}
	}

	/**
	 * Returns the boxing type for a given struct type.
	 *
	 * @param type
	 *            The type for which the boxing type should be returned
	 * @return The boxing type for the given struct type
	 */
	public X10ClassType getBoxingType(final X10ClassType type) {
		final X10ClassType concreteType = (X10ClassType) x10TypeSystem.getConcreteType(type);

		assert x10TypeSystem.isStructType0(concreteType);

		final X10ClassType ret = structBoxingTypes.get(concreteType);
		if (ret != null)
			return ret;

		final Position pos = Position.COMPILER_GENERATED;

		final X10ClassDef cd = new X10ClassDef_c(x10TypeSystem, null);

		// use a unique name for the boxing class
		final String name = getUniqueBoxingName(concreteType);

		// Get the "Object" class and set it as the super class
		final X10ClassType objectType = x10TypeSystem.Object();

		cd.position(pos);
		cd.name(Name.make(name));
		cd.setPackage(null);
		cd.kind(ClassDef.TOP_LEVEL);
		cd.flags(Flags.FINAL);
		cd.superType(Types.ref(objectType));

		final X10ClassType ct = cd.asType();

		final Set<polyglot.types.Type> intSet = new HashSet<polyglot.types.Type>();

		// "interfaces" method returns duplicates???
		for (final polyglot.types.Type t : concreteType.interfaces()) {
			if (intSet.contains(t))
				continue;
			intSet.add(t);

			final X10ParsedClassType iface = (X10ParsedClassType) t;
			final X10ClassDef interfaceDef = iface.x10Def();

			cd.addInterface(Types.ref(iface));

			// get the substitution mapping
			final TypeParamSubst subst = iface.subst();
			final List<ParameterType> paramTypes = subst.copyTypeParameters();
			final List<polyglot.types.Type> argTypes = subst.copyTypeArguments();

			final ThisDef thisDef = x10TypeSystem.thisDef(pos, Types.ref(ct));
			for (final MethodDef mDef : interfaceDef.methods()) {
				final X10MethodDef md = x10TypeSystem.methodDef(pos, Types.ref(ct), Flags.PUBLIC, mDef.returnType(),
						mDef.name(), mDef.formalTypes());
				md.setTypeParameters(mDef.typeParameters());
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
					final polyglot.types.Type x = fTypes.get(i).get();
					Ref<? extends polyglot.types.Type> fType = fTypes.get(i);
					LocalDef fName = fNames.get(i);

					// formal type generic substitution
					if (x instanceof ParameterType) {
						fType = Types.ref(getConcreteTypeFromSubst(x, paramTypes, argTypes));
						fName = x10TypeSystem.localDef(Position.COMPILER_GENERATED, fName.flags(), fType, fName.name());
					}

					formalNames.add(fName);
					formalTypes.add(fType);
				}

				// Watch out for generic return types -> Do a substitution
				Ref<? extends polyglot.types.Type> returnType = mDef.returnType();
				final polyglot.types.Type retType = returnType.get();
				if (retType instanceof ParameterType) {
					returnType = Types.ref(getConcreteTypeFromSubst(retType, paramTypes, argTypes));
				}

				md.setFormalNames(formalNames);
				md.setFormalTypes(formalTypes);
				md.setReturnType(returnType);

				cd.addMethod(md);
			}
		}

		// add the boxed value to the class.
		final Ref<X10ClassType> boxType = Types.ref(concreteType);
		final Name boxName = Name.make(BOXED_VALUE);
		final Ref<X10ClassType> containerRef = Types.ref(ct);
		final FieldDef boxValue = x10TypeSystem.fieldDef(pos, containerRef, Flags.PUBLIC, boxType, boxName);
		cd.addField(boxValue);

		// preinit the type
		asType(ct);
		final Type ft = asClass(ct);

		final FieldInstance fieldInstance = boxValue.asInstance();
		addField(fieldInstance, ft);

		structBoxingTypes.put(concreteType, ct);

		return ct;
	}

	/**
	 * Returns the appropriate concrete type for a given generic type and a type mapping.
	 * @param genType The generic type for which the concrete type should be returned
	 * @param paramTypes A list which generic types
	 * @param argTypes A list with concrete types
	 * @return The concrete type for the given generic type
	 */
	private static polyglot.types.Type getConcreteTypeFromSubst(final polyglot.types.Type genType,
			final List<ParameterType> paramTypes, final List<polyglot.types.Type> argTypes) {
		int j = 0;
		for (; j < paramTypes.size(); j++) {
			if (paramTypes.get(j) == genType)
				break;
		}

		assert j < paramTypes.size();
		return argTypes.get(j);
	}

	/**
	 * Creates a method type (= a member function). So we in addition to the
	 * type we need the flags to determine if it is static and the owner class
	 * to determine the type of the "this" parameter.
	 * @param methodInstance an X10 method instance, for which a Firm type is needed
	 * @return corresponding Firm type
	 */
	public MethodType asFirmType(final MethodInstance methodInstance) {
		final List<polyglot.types.Type> formalTypes
			= methodInstance.formalTypes();
		final Flags flags = methodInstance.flags();
		final boolean isStatic = flags.isStatic();
		final int nParameters = formalTypes.size() + (isStatic ? 0 : 1);
		final int nResults = methodInstance.returnType() == x10TypeSystem.Void() ? 0 : 1;
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
		// set the appropriate native size of the firm type
		final NativeClassInfo classInfo = firmNativeTypes.get(klass);
		if (classInfo != null)
			klass.setSizeBytes(classInfo.getSize());
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
		final polyglot.types.Type concrete = x10TypeSystem.getConcreteType(type);
		return x10TypeSystem.isStructType(concrete) && !primitiveTypes.contains(concrete);
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
		if (x10TypeSystem.isStructType0(owner)) {
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
	 *
	 * @param type The given polyglot type
	 * @return corresponding Firm method type
	 */
	public firm.Type asType(final polyglot.types.Type type) {
		/* strip type-constraints */
		final polyglot.types.Type baseType = x10TypeSystem.getConcreteType(type);

		firm.Type result = firmTypes.get(baseType);
		if (result != null)
			return result;

		result = asClass(baseType);
		/* we have references to stuff unless it is a struct type */
		if (!x10TypeSystem.isStructType0(baseType)) {
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
	private Entity addField(final FieldInstance field, final firm.Type klass) {
		final Flags fieldFlags = field.flags();
		final String name = NameMangler.mangleField(field);

		final Type type = asType(field.type());
		final firm.Type owner = fieldFlags.isStatic() ? Program.getGlobalType() : klass;
		final Entity entity = new Entity(owner, name, type);

		entity.setLdIdent(name);
		OO.setEntityBinding(entity, ddispatch_binding.bind_static);
		final GenericClassContext context = getDefiningContext(field);
		context.putFieldEntity(field.def(), entity);

		return entity;
	}

	@SuppressWarnings("unused")
	private firm.Type createClassType(final X10ClassType classType) {
		final Flags flags = classType.flags();
		final ClassType result = new ClassType(classType.toString());
		final NativeClassInfo classInfo = x10NativeTypes.get(classType);
		if (classInfo != null) {
			firmNativeTypes.put(result, classInfo);
		}

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
			/* no superclass */
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
		for (final polyglot.types.Type t : interfaces) {
			final polyglot.types.Type iface = GenericTypeSystem.simplifyType(t);
			assert ((polyglot.types.ClassType)iface).flags().isInterface() : "Not an interface: " + iface;
			final Type firmIface = asClass(iface);
			result.addSuperType(firmIface);
		}

		final X10ClassType astAny = x10TypeSystem.Any();
		if (noSuperType(result) && classType != astAny) {
			/* Every X10 type implements Any */
			final Type firmAny = asClass(astAny);
			result.addSuperType(firmAny);
		}

		/* create fields */
		for (final FieldInstance field : classType.fields()) {
			addField(field, result);
		}

		/* creates fields for properties */
		for (final FieldInstance field : classType.properties()) {
			addField(field, result);
		}

		final Type global = Program.getGlobalType();
		final Type pointerType = Mode.getP().getType();

		if (!flags.isStruct())
			OO.setClassVPtrEntity(result, getVptrEntity());

		if (!flags.isInterface() && !flags.isStruct()) {
			final String vtableName = NameMangler.mangleVTable(classType);
			final Entity vtable = new Entity(global, vtableName, pointerType);
			vtable.setVisibility(ir_visibility.ir_visibility_default);
			vtable.setLinkage(ir_linkage.IR_LINKAGE_CONSTANT.val);
			OO.setClassVTableEntity(result, vtable);
		}

		final String rttiName = NameMangler.mangleTypeinfo(classType);
		final Entity classInfoEntity = new Entity(global, rttiName, pointerType);
		classInfoEntity.setVisibility(ir_visibility.ir_visibility_local);
		classInfoEntity.setLinkage(ir_linkage.IR_LINKAGE_CONSTANT.val);
		OO.setClassRTTIEntity(result, classInfoEntity);

		// Layouting of classes must be done explicitly by finishTypes

		return result;
	}

	private static boolean noSuperType(final ClassType result) {
		return result.getNSuperTypes() == 0;
	}

	/**
	 * returns firm entity created for a FieldInstance.
	 * Note: this will only work if createClassType was already called for
	 * the fields class.
	 */
	public Entity getEntityForField(final FieldInstance instance) {
		/* make sure enclosing class-type has been created */
		asType(instance.container());

		final GenericClassContext context = getDefiningContext(instance);
		final Entity ent = context.getFieldEntity(instance.def());
		return ent;
	}

	/**
	 * For primitive types (x10.lang.Int, etc) returns class (compound) Firm types (Is, etc).
	 * If you need native Firm types (Is, etc) use the {@code asType} method.
	 *
	 * @param origType  The given polyglot ast-type
	 * @return the firm type for a given ast-type.
	 */
	public firm.Type asClass(final polyglot.types.Type origType) {
		final polyglot.types.Type type = x10TypeSystem.getConcreteType(origType);

		Type result = firmCoreTypes.get(type);
		if (result != null)
			return result;

		if (type instanceof X10ClassType) {
			result = createClassType((X10ClassType) type);
		} else {
			throw new java.lang.RuntimeException("No implement to get firm type for: " + type);
		}
		return result;
	}

	/**
	 * Returns the mode for a given ast-type.
	 */
	public Mode getFirmMode(final polyglot.types.Type type) {
		final Type firmType = asType(type);
		Mode mode = firmType.getMode();
		if (mode == null) {
			assert x10TypeSystem.isStructType0(type);
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

		/* we "lower" some well-known types directly to firm modes */
		final Mode modePointer = Mode.getP();
		final Type typePointer = new PrimitiveType(modePointer);
		recordPrimitiveType(x10TypeSystem.pointer(), typePointer, "Pv");

		final Mode modeLong = Mode.createIntMode("Long", Arithmetic.TwosComplement, 64, true, 64);
		final Type typeLong = new PrimitiveType(modeLong);
		typeLong.setAlignmentBytes(4);
		recordPrimitiveType(x10TypeSystem.Long(), typeLong, "x");

		final Mode modeULong = Mode.createIntMode("ULong", Arithmetic.TwosComplement, 64, false, 64);
		final Type typeULong = new PrimitiveType(modeULong);
		typeULong.setAlignmentBytes(4);
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
		typeLong.setAlignmentBytes(4);
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
		final GenericClassContext context = getDefiningContext(instance);
		Entity entity = context.getConstructorEntity(instance.x10Def());

		if (entity == null) {
			final String name = NameMangler.mangleConstructor(instance);
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

			context.putConstructorEntity(instance.x10Def(), entity);
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

		overrides.addAll(instance.overrides(x10Context));
		final X10ClassType myClassType = (X10ClassType)instance.container();
		// Watch out for constructors of classes with super classes
		if (myClassType.superClass() != null && overrides.size() > 1) {
			// the overridden methods in overrides are sorted !!!
			return overrides.get(1);
		}
		return null;
	}

	private <T extends Def> GenericClassContext getDefiningContext(final MemberInstance<T> member) {
		final X10ClassType clazz = (X10ClassType) member.container();
		if (clazz == null)
			return rootContext;
		/* no type parameters, not a generic class */
		final List<ParameterType> typeParameters = clazz.def().typeParameters();
		if (typeParameters == null || typeParameters.isEmpty())
			return rootContext;

		final GenericClassInstance classInstance;
		// This should always be the case but unfortunately it is not.
		if (clazz.typeArguments() != null && typeParameters.size() == clazz.typeArguments().size()) {
			final ParameterTypeMapping map = new ParameterTypeMapping();
			for (final polyglot.types.Type type : clazz.typeArguments()) {
				if (type instanceof ParameterType) {
					final ParameterType tmp = (ParameterType)type;
					map.add(tmp, x10TypeSystem.getConcreteType(tmp));
				}
			}

			if (map.getKeySet().size() > 0) {
				classInstance = new GenericClassInstance(clazz.x10Def(), map);
			} else {
				classInstance = new GenericClassInstance(clazz);
			}
		} else {
			// FIXME:  This is a hack to workaround a problem in X10.
			final ParameterTypeMapping map = new ParameterTypeMapping();
			for (final ParameterType pt : typeParameters) {
				map.add(pt, x10TypeSystem.getConcreteType(pt));
			}
			classInstance = new GenericClassInstance(clazz.x10Def(), map);
		}
		assert classInstance != null;

		GenericClassContext context = genericContexts.get(classInstance);
		if (context == null) {
			context = new GenericClassContext();
			genericContexts.put(classInstance, context);
		}
		return context;
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
		final GenericClassContext context = getDefiningContext(instance);
		final GenericMethodInstance gMethodInstance = new GenericMethodInstance(instance, x10TypeSystem);
		final firm.Type type = asFirmType(instance);
		Entity entity = context.getMethodEntity(gMethodInstance);

		if (entity == null) {
			final X10ClassType owner = (X10ClassType) instance.container();
			final String mangledName = NameMangler.mangleMethod(instance);
			final String shortName = NameMangler.mangleMethodShort(instance);
			final Flags flags = instance.flags();
			final firm.Type owningClass = asClass(owner);

			if (flags.isNative()) { /* try to get it from stdlib */
				assert !flags.isInterface() : "We do not import interfaces.";
				assert !flags.isAbstract() : "We do not import abstract methods.";

				final Entity cEntity = this.cStdlibEntities.get(mangledName);
				if (cEntity != null) {
					final firm.Type entityType = cEntity.getType();
					if (!(entityType instanceof MethodType))
						throw new CodeGenError("native Entity without methodtype", instance.position());
					final firm.MethodType entityMType = (MethodType) entityType;
					final firm.MethodType mType = (MethodType) type;
					if (!methodsCompatible(entityMType, mType))
						throw new CodeGenError(
								String.format("native Entity '%s' does not match declared type", instance),
								instance.position());

					/* fix up stuff, which was impossible to do during the import */
					cEntity.setOwner(owningClass);
					if (flags.isStatic()) {
						OO.setEntityBinding(cEntity, ddispatch_binding.bind_static);
					} else {
						OO.setEntityBinding(cEntity, ddispatch_binding.bind_dynamic);
					}

					context.putMethodEntity(gMethodInstance, cEntity);
					return cEntity;
				}
			}

			final firm.Type ownerFirm = flags.isStatic() ? Program.getGlobalType() : owningClass;
			entity = new Entity(ownerFirm, shortName, type);
			entity.setLdIdent(mangledName);

			if (flags.isStatic()) {
				OO.setEntityBinding(entity, ddispatch_binding.bind_static);
			} else if (owner.flags().isInterface()) {
				OO.setEntityBinding(entity, ddispatch_binding.bind_interface);
			} else if (x10TypeSystem.isStructType0(owner)) {
				// struct methods needn`t be dynamic
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

			context.putMethodEntity(gMethodInstance, entity);
		}

		return entity;
	}

	/**
	 * Inserts parameter type mapping into global mappings.
	 * @param ptm a set of type mappings
	 */
	public void pushTypeMapping(final ParameterTypeMapping ptm) {
		for (final ParameterType param : ptm.getKeySet()) {
			final polyglot.types.Type mappedType = ptm.getMappedType(param);

			assert firmCoreTypes.containsKey(mappedType) || firmTypes.containsKey(mappedType);

			x10TypeSystem.addTypeMapping(param, mappedType);

			if (firmCoreTypes.containsKey(mappedType))
				firmCoreTypes.put(param, firmCoreTypes.get(mappedType));

			if (firmTypes.containsKey(mappedType))
				firmTypes.put(param, firmTypes.get(mappedType));
		}
	}

	/**
	 * Removes parameter type mapping from global mappings.
	 * @param ptm a set of type mappings
	 */
	public void popTypeMapping(final ParameterTypeMapping ptm) {
		for (final ParameterType param : ptm.getKeySet()) {
			x10TypeSystem.removeTypeMapping(param);

			firmCoreTypes.remove(param);
			firmTypes.remove(param);
		}
	}
}
