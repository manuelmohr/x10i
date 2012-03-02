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
import polyglot.types.Named;
import polyglot.types.QName;
import polyglot.types.Ref;
import polyglot.types.TypeObject;
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
import x10firm.visit.CodeGenError;
import x10firm.CompilerOptions;
import firm.ClassType;
import firm.CompoundType;
import firm.Entity;
import firm.Ident;
import firm.MethodType;
import firm.Mode;
import firm.Mode.Arithmetic;
import firm.OO;
import firm.PointerType;
import firm.PrimitiveType;
import firm.Program;
import firm.Type;
import firm.bindings.binding_oo.ddispatch_binding;
import firm.bindings.binding_typerep.ir_type_state;
import firm.bindings.binding_typerep.ir_visibility;

/**
 * Includes everything to map X10 types to Firm types
 *
 * XXX While the mapping is static, the X10 type system is not,
 * because the runtime is loaded dynamically.
 */
public class FirmTypeSystem {
	/** Maps polyglot types to firm types.
	 * TODO: Use the polyglot.types.Type for hashing
	 * */
	private final Map<polyglot.types.Type, Type> firmCoreTypes = new HashMap<polyglot.types.Type, Type>();

	/** Maps some polyglot types to "native"/primitive firm types. */
	private final Map<polyglot.types.Type, Type> firmTypes = new HashMap<polyglot.types.Type, Type>();

	/** We import C functions at the beginning. When we encounter the corresponding X10 native methods,
	 * we have to get the C function entity by the mangled name.
	 */
	private final Map<String, Entity> cStdlibEntities = new HashMap<String, Entity>();

	/** Maps struct types to the appropriate boxing types */
	private final Map<X10ClassType, X10ClassType> structBoxingTypes = new HashMap<X10ClassType, X10ClassType>();

	private final GenericClassContext rootContext = new GenericClassContext();

	private final Map<GenericClassInstance, GenericClassContext> genericContexts = new HashMap<GenericClassInstance, GenericClassContext>();

	/** X10 Context */
	private Context x10Context = null;

	/** All class instances share the same location for the vptr (the pointer to the vtable) */
	private Entity vptrEntity;

	private static class NativeClassInfo {
		private final int size;

		private NativeClassInfo(final int size_) {
			size = size_;
		}

		public int getSize() { return size; }

		public static NativeClassInfo newNativeClassInfo(final int size) {
			return new NativeClassInfo(size);
		}
	}

	/** Mapping between X10ClassTypes and the appropriate native class info */
	private static final Map<X10ClassType, NativeClassInfo> x10NativeTypes = new HashMap<X10ClassType, NativeClassInfo>();

	/** Mapping between firm class types and the appropriate native object size */
	private static final Map<ClassType, NativeClassInfo> firmNativeTypes = new HashMap<ClassType, NativeClassInfo>();

	/**
	 * Name of the boxed value.
	 */
	public static String BOXED_VALUE = "__value__";

	/**
	 * Reference to the generic type system
	 */
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
		for (Entity ent : glob.getMembers()) {
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
		if(clazz.typeArguments() != null && !clazz.typeArguments().isEmpty()) {
			buf.append("_");
			for(final polyglot.types.Type type_arg : clazz.typeArguments())
				buf.append(type_arg.name().toString());
			buf.append("_");
		}
		buf.append("_FirmBox_");
		return buf.toString();
	}

	private boolean inited = false;

	/**
	 * Initializes the firm type system
	 */
	public void init(final CompilerOptions options) {
		if (inited)
			return;
		final String nativeTypesConfig = options.getFirmNativeTypesFilename();
		inited = true;
		findExistingEntities();
		readFirmNativeTypesConfig(nativeTypesConfig);
		initFirmTypes();
		NameMangler.setup(x10TypeSystem, options);
		// Always generate the vtable for x10.lang.String.
		asClass(x10TypeSystem.String());
	}

	private void readFirmNativeTypesConfig(final String firmNativeTypesFilename) {
		try {
			BufferedReader in = new BufferedReader(new FileReader(firmNativeTypesFilename));

			String line = null;
			while((line = in.readLine()) != null) {
				StringTokenizer toker = new StringTokenizer(line);
				assert toker.countTokens() == 3 : "Illegal format in " + firmNativeTypesFilename;
				final String packName  = toker.nextToken();
				final String className = toker.nextToken();
				int size = 0;

				try {
					size = Integer.parseInt(toker.nextToken());
				} catch(NumberFormatException nfexc) {
					assert false: "Illegal size " + size  +" in " + firmNativeTypesFilename;
				}
				final X10ClassType klass = getNamedX10Type(packName, className);
				x10NativeTypes.put(klass, NativeClassInfo.newNativeClassInfo(size));
			}

			in.close();
		} catch(Exception exc) {
			System.err.println("Error in reading file" + firmNativeTypesFilename + " Exception: "+ exc);
			System.exit(-1);
		}
	}

	private void saveType(final polyglot.types.Type x10_type, Type firm_Type) {
		firmTypes.put(x10_type, firm_Type);
	}

	private Type getType(final polyglot.types.Type x10_type) {
		return firmTypes.get(x10_type);
	}

	private boolean hasFirmType(final polyglot.types.Type x10_type) {
		return firmTypes.containsKey(x10_type);
	}

	private Type removeFirmType(final polyglot.types.Type x10_type) {
		return firmTypes.remove(x10_type);
	}

	private void saveFirmCoreType(final polyglot.types.Type x10_type, Type firm_Type) {
		firmCoreTypes.put(x10_type, firm_Type);
	}

	private Type getFirmCoreType(final polyglot.types.Type x10_type) {
		return firmCoreTypes.get(x10_type);
	}

	private boolean hasFirmCoreType(final polyglot.types.Type x10_type) {
		return firmCoreTypes.containsKey(x10_type);
	}

	private Type removeFirmCoreType(final polyglot.types.Type x10_type) {
		return firmCoreTypes.remove(x10_type);
	}

	/**
	 * Returns the boxing type for a given struct type
	 * @param type_ The type for which the boxing type should be returned
	 * @return The boxing type for the given struct type
	 */
	public X10ClassType getBoxingType(X10ClassType type_) {
		final X10ClassType type = (X10ClassType)x10TypeSystem.getConcreteType(type_);

		assert x10TypeSystem.isStructType0(type);

		final X10ClassType ret = structBoxingTypes.get(type);
		if(ret != null) return ret;

        final Position pos = Position.COMPILER_GENERATED;

        X10ClassDef cd = new X10ClassDef_c(x10TypeSystem, null);

        // use a unique name for the boxing class
        final String name = getUniqueBoxingName(type);

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

        // "interfaces" method returns duplicates???
		for (final polyglot.types.Type t : type.interfaces()) {
			if (intSet.contains(t))
				continue;
			intSet.add(t);

			final X10ParsedClassType intervace = (X10ParsedClassType) t;
			final X10ClassDef intervaceDef = intervace.x10Def();

			cd.addInterface(Types.ref(intervace));

			// get the substitution mapping
			final TypeParamSubst subst = intervace.subst();
			final List<ParameterType> paramTypes = subst.copyTypeParameters();
			final List<polyglot.types.Type> argTypes = subst
					.copyTypeArguments();

			final ThisDef thisDef = x10TypeSystem.thisDef(pos, Types.ref(ct));
			for (final MethodDef mDef : intervaceDef.methods()) {
				final X10MethodDef md = x10TypeSystem.methodDef(pos,
						Types.ref(ct), Flags.PUBLIC, mDef.returnType(),
						mDef.name(), mDef.formalTypes());
				md.setTypeParameters(mDef.typeParameters());
				md.setThisDef(thisDef);
				md.setGuard(mDef.guard());
				md.setTypeGuard(mDef.typeGuard());

				final List<Ref<? extends polyglot.types.Type>> formalTypes = new LinkedList<Ref<? extends polyglot.types.Type>>();
				final List<LocalDef> formalNames = new LinkedList<LocalDef>();

				final List<Ref<? extends polyglot.types.Type>> fTypes = mDef
						.formalTypes();
				final List<LocalDef> fNames = mDef.formalNames();

				assert (fTypes.size() == fNames.size());
				for (int i = 0; i < fTypes.size(); i++) {
					final polyglot.types.Type x = fTypes.get(i).get();
					Ref<? extends polyglot.types.Type> fType = fTypes.get(i);
					LocalDef fName = fNames.get(i);

					// formal type generic substitution
					if (x instanceof ParameterType) {
						fType = Types.ref(getConcreteTypeFromSubst(x,
								paramTypes, argTypes));
						fName = x10TypeSystem.localDef(
								Position.COMPILER_GENERATED, fName.flags(),
								fType, fName.name());
					}

					formalNames.add(fName);
					formalTypes.add(fType);
				}

				// Watch out for generic return types -> Do a substitution
				Ref<? extends polyglot.types.Type> returnType = mDef
						.returnType();
				final polyglot.types.Type retType = returnType.get();
				if (retType instanceof ParameterType) {
					returnType = Types.ref(getConcreteTypeFromSubst(retType,
							paramTypes, argTypes));
				}

				md.setFormalNames(formalNames);
				md.setFormalTypes(formalTypes);
				md.setReturnType(returnType);

				cd.addMethod(md);
			}
		}

        // add the boxed value to the class.
        final FieldDef boxValue = x10TypeSystem.fieldDef(pos, Types.ref(ct), Flags.PUBLIC, Types.ref(type), Name.make(BOXED_VALUE));
        cd.addField(boxValue);

        // preinit the type
        asType(ct);
        final Type ft  = asClass(ct);

        final FieldInstance fieldInstance = boxValue.asInstance();
        addField(fieldInstance, ft);

        structBoxingTypes.put(type, ct);

		return ct;
	}

	/**
	 * Returns the appropriate concrete type for a given generic type and a type mapping
	 * @param genType The generic type for which the concrete type should be returned
	 * @param paramTypes A list which generic types
	 * @param argTypes A list with concrete types
	 * @return The concrete type for the given generic type
	 */
	private static polyglot.types.Type getConcreteTypeFromSubst(final polyglot.types.Type genType, final List<ParameterType> paramTypes,
			final List<polyglot.types.Type> argTypes) {
		int j = 0;
		for(; j < paramTypes.size(); j++)
			if(paramTypes.get(j) == genType)
				break;

		assert(j < paramTypes.size());
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
			final polyglot.types.Type simpType = x10TypeSystem.getConcreteType(type);
			parameterTypes[p++] = getFirmType(simpType);
		}
		assert (p == nParameters);

		if (nResults > 0) {
			assert nResults == 1;
			final polyglot.types.Type type = methodInstance.returnType();
			final polyglot.types.Type simpType = x10TypeSystem.getConcreteType(type);
			resultTypes[0] = getFirmType(simpType);
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
		// set the appropriate native size of the firm type
		final NativeClassInfo classInfo = firmNativeTypes.get(klass);
		if(classInfo != null)
			klass.setSizeBytes(classInfo.getSize());
		klass.finishLayout();
	}

	/**
	 * Finishes the type system.
	 */
	public void finishTypeSystem() {
		for(final Type type : firmCoreTypes.values())
			layoutType(type);
	}

	/**
	 * Checks if we need the core type for a given type (for example: Parameter passing)
	 * @param type The type which should be checked
	 * @return True if we need the core type for the given type
	 */
	public boolean isFirmStructType(final polyglot.types.Type type) {
		final polyglot.types.Type baseType = x10TypeSystem.getConcreteType(type);
		return Types.isX10Struct(baseType) && !isFirmPrimitiveType(baseType);
	}

	/**
	 * Checks if 2 types are equal
	 * @param type1 The first type
	 * @param type2 The second type
	 * @return True if both types are equal.
	 */
	private boolean equalTypes(final polyglot.types.Type type1, final polyglot.types.Type type2) {
		return x10TypeSystem.equals((TypeObject)type1, (TypeObject)type2);
	}

	/**
	 * True if the given type is handled as a primitive type in firm.
	 * @param type_ The type which should be checked
	 * @return True if the given type is handled as a primitive type.
	 */
	public boolean isFirmPrimitiveType(final polyglot.types.Type type_) {
		final polyglot.types.Type type = x10TypeSystem.getConcreteType(type_);
		return equalTypes(type, x10TypeSystem.Int())     || equalTypes(type, x10TypeSystem.UInt())   ||
		       equalTypes(type, x10TypeSystem.Long())    || equalTypes(type, x10TypeSystem.ULong())  ||
		       equalTypes(type, x10TypeSystem.Short())   || equalTypes(type, x10TypeSystem.UShort()) ||
		       equalTypes(type, x10TypeSystem.Byte())    || equalTypes(type, x10TypeSystem.UByte())  ||
		       equalTypes(type, x10TypeSystem.Float())   || equalTypes(type, x10TypeSystem.Double()) ||
		       equalTypes(type, x10TypeSystem.Boolean()) || equalTypes(type, x10TypeSystem.Char())   ||
		       equalTypes(type, x10TypeSystem.Pointer());
	}

	/**
	 * Returns the firm type for a given polygot type
	 * @param type The polyglot type
	 * @return The appropriate firm type for the given polyglot type
	 */
	public Type getFirmType(final polyglot.types.Type type) {
		final Type ret = isFirmStructType(type) ? asClass(type) : asType(type);

		assert(ret != null);
		return ret;
	}

	private MethodType getNativeConstructorType(X10ConstructorInstance instance) {
		assert (instance.flags().isNative());

		final List<polyglot.types.Type> formalTypes = instance.formalTypes();
		final int nParameters = formalTypes.size();
		final int nResults = 1;
		final X10ClassType owner = (X10ClassType) instance.container();
		final Type[] parameterTypes = new firm.Type[nParameters];
		final Type[] resultTypes = new firm.Type[nResults];

		int p = 0;
		final Type thisType = asType(owner);
		resultTypes[0] = thisType;

		for (final polyglot.types.Type type : formalTypes) {
			final polyglot.types.Type simpType = x10TypeSystem.getConcreteType(type);
			parameterTypes[p++] = getFirmType(simpType);
		}
		assert (p == nParameters);

		return new MethodType(parameterTypes, resultTypes);
	}

	/**
	 * create a method type for an X10 constructor
	 */
	public MethodType getConstructorType(X10ConstructorInstance instance) {
		if (instance.container() == x10TypeSystem.String())
			return getNativeConstructorType(instance);

		final List<polyglot.types.Type> formalTypes = instance.formalTypes();
		final int nParameters = formalTypes.size() + 1;
		final int nResults = 0;
		final X10ClassType owner = (X10ClassType) instance.container();
		final Type[] parameterTypes = new firm.Type[nParameters];
		final Type[] resultTypes = new firm.Type[nResults];

		int p = 0;
		final Type thisType = asType(owner);
		parameterTypes[p++] = thisType;

		for (final polyglot.types.Type type : formalTypes) {
			final polyglot.types.Type simpType = x10TypeSystem.getConcreteType(type);
			parameterTypes[p++] = getFirmType(simpType);
		}
		assert (p == nParameters);

		return new MethodType(parameterTypes, resultTypes);
	}

	/**
	 * Returns the corresponding Firm type for the given polyglot type
	 *
	 * For primitive types (x10.lang.Int, etc) returns "native" Firm types (Is, etc).
	 * If you need class Firm types use the {@code asClass} method.
	 *
	 * @param type The given polyglot type
	 * @return corresponding Firm method type
	 */
	public firm.Type asType(polyglot.types.Type type) {
		/* strip type-constraints */
		final polyglot.types.Type baseType = x10TypeSystem.getConcreteType(type);

		firm.Type result = getType(baseType);
		if (result != null)
			return result;

		result = asClass(baseType);
		if (result instanceof ClassType) {
			/* we really have references to classes */
			result = new PointerType(result);
		}
		saveType(baseType, result);

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
	 * @return The firm entity for the field
	 */
	private Entity addField(final FieldInstance field, final firm.Type klass) {
		final Flags fieldFlags = field.flags();
		final String name = NameMangler.mangleTypeObjectWithDefClass(field);

		final Type type = getFirmType(field.type());
		final firm.Type owner = fieldFlags.isStatic() ? Program.getGlobalType() : klass;
		final Entity entity = new Entity(owner, name, type);

		entity.setLdIdent(name);
		OO.setEntityBinding(entity, ddispatch_binding.bind_static);
		final GenericClassContext context = getDefiningContext(field);
		context.putFieldEntity(field.def(), entity);

		return entity;
	}

	/**
	 * Expands a given class type. -> Add extra methods etc.
	 * @param classType The class type which should be expanded.
	 */
	private void expandClassType(final X10ClassType classType) {
		// Currently only primitive types are expanded.
		if(!isFirmPrimitiveType(classType)) return;

		final X10ClassDef def = classType.x10Def();

		final X10ClassType x10Any = x10TypeSystem.Any();

		// Get the hashCode method from x10.Any
		final List<MethodInstance> methods = x10Any.methodsNamed(Name.make("hashCode"));
		assert(methods.size() == 1);
		final MethodInstance x10AnyhashCodeMethodInstance = methods.get(0);

		final List<MethodInstance> mm = classType.methods(Name.make("hashCode"), x10AnyhashCodeMethodInstance.formalTypes(), x10Context);
		if(mm.size() == 0) {
			// add the missing hashCode method to the class
			final MethodDef x10AnyhashCodeMethodDef = x10AnyhashCodeMethodInstance.def();

			final MethodDef hashCodeMethodDef = x10TypeSystem.methodDef(Position.COMPILER_GENERATED, Types.ref(classType),
					x10AnyhashCodeMethodDef.flags().clearAbstract().Native(), x10AnyhashCodeMethodDef.returnType(), x10AnyhashCodeMethodDef.name(),
					x10AnyhashCodeMethodDef.formalTypes());

			def.addMethod(hashCodeMethodDef);
		}
	}

	@SuppressWarnings("unused")
	private firm.Type createClassType(final X10ClassType classType) {
		expandClassType(classType);

		final String className = NameMangler.mangleTypeObjectWithDefClass(classType);
		final Flags flags = classType.flags();
		ClassType result = new ClassType(className);
		final NativeClassInfo classInfo = x10NativeTypes.get(classType);
		if(classInfo != null) {
			firmNativeTypes.put(result, classInfo);
		}

		/* put the class into the core types already, because we could
		 * have a field referencing ourself */
		saveFirmCoreType(classType, result);

		/* create supertypes */
		polyglot.types.Type superType = classType.superClass();
		if (superType != null) {
			final Type firmSuperType = asClass(superType);
			result.addSuperType(firmSuperType);
			new Entity(result, "$super", firmSuperType);
		} else if (flags.isStruct() || classType.isAnonymous()) {
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
		Set<polyglot.types.Type> interfaces = new LinkedHashSet<polyglot.types.Type>(classType.interfaces());
		for (final polyglot.types.Type t : interfaces) {
			final polyglot.types.Type iface = GenericTypeSystem.simplifyType(t);
			assert ((polyglot.types.ClassType)iface).flags().isInterface() : "Not an interface: "+iface;
			final Type firmIface = asClass(iface);
			result.addSuperType(firmIface);
		}

		final X10ClassType ast_any = x10TypeSystem.Any();
		if (noSuperType(result) && classType != ast_any) {
			/* Every X10 type implements Any */
			final Type firm_any = asClass(ast_any);
			result.addSuperType(firm_any);
		}

		/* create fields */
		for (final FieldInstance field : classType.fields())
			addField(field, result);

		/* creates fields for properties */
		for (final FieldInstance field : classType.properties()) {
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

		if (!(flags.isInterface() || flags.isStruct())) {
			Entity vtable = new Entity(Program.getGlobalType(), NameMangler.mangleVTable(classType), Mode.getP().getType());
			OO.setClassVTableEntity(result, vtable);
		}

		final Entity classInfoEntity = new Entity(Program.getGlobalType(), Ident.createUnique(className + "$"), Mode.getP().getType());

		OO.setClassRTTIEntity(result, classInfoEntity);

		// Layouting of classes must be done explicitly by finishTypes

		return result;
	}

	private static boolean noSuperType(ClassType result) {
		return result.getNSuperTypes() == 0;
	}

	/**
	 * returns firm entity created for a FieldInstance.
	 * Note: this will only work if createClassType was already called for
	 * the fields class.
	 */
	public Entity getEntityForField(FieldInstance instance) {
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

		Type result = getFirmCoreType(type);
		if (result != null)
			return result;

		if (type instanceof X10ClassType) {
			result = createClassType((X10ClassType) type);
		} else {
			/* remember to put new types into coreTypeCache */
			saveFirmCoreType(type, result);
			throw new java.lang.RuntimeException("No implement to get firm type for: " + type);
		}
		return result;
	}

	/**
	 * Returns the mode for a given ast-type.
	 */
	public Mode getFirmMode(polyglot.types.Type type) {
		return asType(type).getMode();
	}

	/**
	 * Should be called before the firm-graph is constructed. This extra step
	 * is necessary because at the time the type-system Object is created in
	 * the ExtensionInfo we must not use the Int(), Boolean(), ... functions
	 * yet.
	 */
	private void initFirmTypes() {

		/* we "lower" some well-known types directly to firm modes */
		Mode modePointer = Mode.getP();
		Type typePointer = new PrimitiveType(modePointer);
		saveType(x10TypeSystem.Pointer(), typePointer);

		Mode modeLong = Mode.createIntMode("Long", Arithmetic.TwosComplement, 64, true, 64);
		Type typeLong = new PrimitiveType(modeLong);
		typeLong.setAlignmentBytes(4);
		saveType(x10TypeSystem.Long(), typeLong);

		Mode modeULong = Mode.createIntMode("ULong", Arithmetic.TwosComplement, 64, false, 64);
		Type typeULong = new PrimitiveType(modeULong);
		typeULong.setAlignmentBytes(4);
		saveType(x10TypeSystem.ULong(), typeULong);

		Mode modeInt = Mode.createIntMode("Int", Arithmetic.TwosComplement, 32, true, 32);
		Type typeInt = new PrimitiveType(modeInt);
		saveType(x10TypeSystem.Int(), typeInt);

		Mode modeUInt = Mode.createIntMode("UInt", Arithmetic.TwosComplement, 32, false, 32);
		Type typeUInt = new PrimitiveType(modeUInt);
		saveType(x10TypeSystem.UInt(), typeUInt);

		Mode modeShort = Mode.createIntMode("Short", Arithmetic.TwosComplement, 16, true, 32);
		Type typeShort = new PrimitiveType(modeShort);
		saveType(x10TypeSystem.Short(), typeShort);

		Mode modeUShort = Mode.createIntMode("UShort", Arithmetic.TwosComplement, 16, false, 32);
		Type typeUShort = new PrimitiveType(modeUShort);
		saveType(x10TypeSystem.UShort(), typeUShort);

		Mode modeByte = Mode.createIntMode("Byte", Arithmetic.TwosComplement, 8, true, 32);
		Type typeByte = new PrimitiveType(modeByte);
		saveType(x10TypeSystem.Byte(), typeByte);

		Mode modeUByte = Mode.createIntMode("UByte", Arithmetic.TwosComplement, 8, false, 32);
		Type typeUByte = new PrimitiveType(modeUByte);
		saveType(x10TypeSystem.UByte(), typeUByte);

		/* since octopos has no real support for unicode yet, and we have a somewhat hardware-centric
		 * project we go for 8bit-chars for now. (You can still use UTF-8 strings after all) */
		Mode modeChar = modeByte;
		Type typeChar = new PrimitiveType(modeChar);
		saveType(x10TypeSystem.Char(), typeChar);

		Mode modeFloat = Mode.createFloatMode("Float", Arithmetic.IEE754, 8, 23);
		Type typeFloat = new PrimitiveType(modeFloat);
		saveType(x10TypeSystem.Float(), typeFloat);

		Mode modeDouble = Mode.createFloatMode("Double", Arithmetic.IEE754, 11, 52);
		Type typeDouble = new PrimitiveType(modeDouble);
		typeLong.setAlignmentBytes(4);
		saveType(x10TypeSystem.Double(), typeDouble);

		/* Note that the mode_b in firm can't be used here, since it is an
		 * internal mode which cannot be used for fields/call parameters/return
		 * values. We will use mode_b only internally when generating code for
		 * conditional jumps. */
		Mode modeBoolean = Mode.getBu();
		Type typeBoolean = new PrimitiveType(modeBoolean);
		saveType(x10TypeSystem.Boolean(), typeBoolean);

		Type unknown = Type.getUnknown();
		Type nullRefType = new PointerType(unknown);
		saveType(x10TypeSystem.Null(), nullRefType);
		/* Note: there is no sensible firmCoreType for Null() */
	}

	/**
	 * @return a class type for x10.lang.Object
	 */
	public X10ClassType getObjectType() {
		final QName fullName = QName.make("x10.lang", "Object");
	    final List<polyglot.types.Type> types = x10TypeSystem.systemResolver().check(fullName);
	    assert(types != null && types.size() == 1);
	    final Named n = types.get(0);
	    final X10ClassType objectType = (X10ClassType)n;
		return objectType;
	}

	/**
	 * Returns a x10 type
	 *
	 * @param packageName Package name of the x10 type
	 * @param className Class name of the x10 type
	 *
	 * @return a class type for the given full class name
	 */
	public X10ClassType getNamedX10Type(final String packageName, final String className) {
		final QName fullName = QName.make(packageName, className);
		final X10ClassType x10Type = x10TypeSystem.load(fullName.toString());
		return x10Type;
	}

	/**
	 * @param instance a constructor method instance
	 * @return a Firm entity corresponding to the constructor
	 */
	public Entity getConstructorEntity(X10ConstructorInstance instance) {
		final GenericClassContext context = getDefiningContext(instance);
		Entity entity = context.getConstructorEntity(instance.x10Def());

		if (entity == null) {
			final String name = NameMangler.mangleTypeObjectWithDefClass(instance);
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
	 * Returns the potentially overridden method of a given method
	 * @param instance The method instance which should be checked
	 * @return The overridden method instance or null
	 */
	private MethodInstance getOverriddenMethod(MethodInstance instance) {
		final Flags flags = instance.flags();
		// static or abstract methods can't override other methods.
		if (flags.isStatic() || flags.isAbstract())
			return null;

		final List<MethodInstance> overrides = new LinkedList<MethodInstance>();

		overrides.addAll(instance.overrides(x10Context));
		final X10ClassType myClassType = (X10ClassType)instance.container();
		// Watch out for constructors of classes with super classes
		if(myClassType.superClass() != null && overrides.size() > 1) {
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
			ParameterTypeMapping map = new ParameterTypeMapping();
			for(polyglot.types.Type type : clazz.typeArguments()) {
				if(type instanceof ParameterType) {
					final ParameterType tmp = (ParameterType)type;
					map.add(tmp, x10TypeSystem.getConcreteType(tmp));
				}
			}

			if(map.getKeySet().size() > 0) {
				classInstance = new GenericClassInstance(clazz.x10Def(), map);
			} else {
				classInstance = new GenericClassInstance(clazz);
			}
		} else {
			// FIXME:  This is a hack to workaround a problem in X10.
			ParameterTypeMapping map = new ParameterTypeMapping();
			for (ParameterType pt : typeParameters)
				map.add(pt, x10TypeSystem.getConcreteType(pt));
			classInstance = new GenericClassInstance(clazz.x10Def(), map);
		}
		assert(classInstance != null);

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
			firm.Type param1 = type1.getResType(i);
			firm.Type param2 = type2.getResType(i);
			if (param1 instanceof CompoundType != param2 instanceof CompoundType)
				return false;
			if (!(param1 instanceof CompoundType) && !param1.getMode().equals(param2.getMode()))
				return false;
		}
		for (int i = 0; i < type2.getNParams(); ++i) {
			firm.Type param1 = type1.getParamType(i);
			firm.Type param2 = type2.getParamType(i);
			if (!param1.getMode().equals(param2.getMode()))
				return false;
		}
		return true;
	}

	/**
	 * Return entity for an X10 method
	 */
	public Entity getMethodEntity(final MethodInstance instance) {

		final GenericClassContext context = getDefiningContext(instance);
		final GenericMethodInstance gMethodInstance = new GenericMethodInstance(instance, x10TypeSystem);
		final firm.Type type = asFirmType(instance);
		Entity entity = context.getMethodEntity(gMethodInstance);

		if (entity == null) {
			X10ClassType owner = (X10ClassType) instance.container();
			final String nameWithDefiningClass = NameMangler.mangleTypeObjectWithDefClass(instance);
			final String nameWithoutDefiningClass = NameMangler.mangleTypeObjectWithoutDefClass(instance);
			final Flags flags = instance.flags();
			final firm.Type owningClass = asClass(owner);

			if (flags.isNative()) { /* try to get it from stdlib */
				assert !flags.isInterface() : "We do not import interfaces.";
				assert !flags.isAbstract() : "We do not import abstract methods.";

				final Entity cEntity = this.cStdlibEntities.get(nameWithDefiningClass);
				if (cEntity != null) {
					firm.Type entityType = cEntity.getType();
					if (! (entityType instanceof MethodType))
						throw new CodeGenError("native Entity without methodtype", instance.position());
					firm.MethodType entityMType = (MethodType) entityType;
					firm.MethodType mType = (MethodType) type;
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
			entity = new Entity(ownerFirm, nameWithoutDefiningClass, type);
			entity.setLdIdent(nameWithDefiningClass);

			if (flags.isStatic()) {
				OO.setEntityBinding(entity, ddispatch_binding.bind_static);
			} else if (owner.flags().isInterface()) {
				OO.setEntityBinding(entity, ddispatch_binding.bind_interface);
			} else if(x10TypeSystem.isStructType0(owner)) {
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
			if(m != null) {
				final Entity ent = getMethodEntity(m);
				entity.addEntityOverwrites(ent);
			}

			context.putMethodEntity(gMethodInstance, entity);
		}

		return entity;
	}

	/**
	 * Inserts parameter type mapping into global mappings
	 * @param ptm a set of type mappings
	 */
	public void pushTypeMapping(ParameterTypeMapping ptm) {
		for (ParameterType param : ptm.getKeySet()) {
			final polyglot.types.Type mappedType = ptm.getMappedType(param);

			assert (hasFirmCoreType(mappedType) || hasFirmType(mappedType));

			x10TypeSystem.addTypeMapping(param, mappedType);

			if (hasFirmCoreType(mappedType))
				saveFirmCoreType(param, getFirmCoreType(mappedType));

			if (hasFirmType(mappedType))
				saveType(param, firmTypes.get(mappedType));
		}
	}

	/**
	 * Remove parameter type mapping from global mappings
	 * @param ptm a set of type mappings
	 */
	public void popTypeMapping(ParameterTypeMapping ptm) {
		for (ParameterType param : ptm.getKeySet()) {
			x10TypeSystem.removeTypeMapping(param);

			if (hasFirmCoreType(param))
				removeFirmCoreType(param);

			if (hasFirmType(param))
				removeFirmType(param);
		}
	}
}
