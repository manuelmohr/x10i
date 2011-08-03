package x10firm.types;

import java.io.BufferedReader;
import java.io.FileReader;
import java.util.ArrayList;
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
import x10.types.FunctionType;
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
import x10firm.visit.X10ClosureRemover;
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
import firm.bindings.binding_typerep.ir_visibility;

/**
 * Includes everything to map X10 types to Firm types
 *
 * XXX While the mapping is static, the X10 type system is not,
 * because the runtime is loaded dynamically.
 */
public class FirmTypeSystem {
	/** Maps polyglot types to firm types. */
	private final Map<polyglot.types.Type, Type> firmCoreTypes = new HashMap<polyglot.types.Type, Type>();

	/** Maps some polyglot types to "native"/primitive firm types. */
	private final Map<polyglot.types.Type, Type> firmTypes = new HashMap<polyglot.types.Type, Type>();
	
	/** Mapping for function types (Function type name! -> function type) -> Only for function types that are interfaces!!! */
	private final Map<String, polyglot.types.Type> firmFunctionTypes = new HashMap<String, polyglot.types.Type>();
	
	/** Maps struct types to the appropriate boxing types */
	private final Map<X10ClassType, X10ClassType> structBoxingTypes = new HashMap<X10ClassType, X10ClassType>();

	private final GenericClassContext rootContext = new GenericClassContext();

	private final Map<GenericClassInstance, GenericClassContext> genericContexts = new HashMap<GenericClassInstance, GenericClassContext>();

	/** X10 Context */
	private Context x10Context = null;

	/** All class instances share the same location for the vptr (the pointer to the vtable) */
	private Entity vptrEntity;

	private static long boxingID = 1;
	
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
	private static final Map<firm.ClassType, NativeClassInfo> firmNativeTypes = new HashMap<firm.ClassType, NativeClassInfo>(); 

	/**
	 * Name of the boxed value.
	 */
	public static String BOXED_VALUE = "__value__";


	private final GenericTypeSystem x10TypeSystem;

	/**
	 * Construct a firm type system object.
	 * @param x10TypeSystem The X10 type system
	 */
	public FirmTypeSystem(final GenericTypeSystem x10TypeSystem) {
		this.x10TypeSystem = x10TypeSystem;
		this.x10Context    = new Context(this.x10TypeSystem);
	}

	private String getUniqueBoxingName(final String structName) {
		return structName + "__FirmBox__" + (boxingID++);
	}
	
	private boolean inited = false; 
	
	/**
	 * Initializes the firm type system 
	 */
	public void init(final CompilerOptions options) {
		if(inited) return;
		inited = true;
		readFirmNativeTypesConfig(options.getFirmNativeTypesFilename()); 
		initFirmTypes();
		X10NameMangler.setup(x10TypeSystem);
		// Always generate the vtable for x10.lang.String.
		asFirmCoreType(x10TypeSystem.String());
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
	
	private polyglot.types.Type getTypeHelp(polyglot.types.Type type) {
		final polyglot.types.Type tmp = X10ClosureRemover.getClosureMappingType(simplifyType(type));
		if(tmp != null)
			return tmp;
		if(type instanceof FunctionType) {
			final FunctionType func = (FunctionType)type;
			if(func.flags().isInterface()) {
				final polyglot.types.Type tmp2 = firmFunctionTypes.get(func.toString());
				if(tmp2 != null)
					return tmp2;
				firmFunctionTypes.put(func.toString(), type);
			}
		}
		return type;
	}
	
	private void putFirmType(final polyglot.types.Type x10_type, Type firm_Type) {
		firmTypes.put(getTypeHelp(x10_type), firm_Type);
	}
	
	private Type getFirmType(final polyglot.types.Type x10_type) {
		return firmTypes.get(getTypeHelp(x10_type));
	}
	
	private boolean containsFirmType(final polyglot.types.Type x10_type) {
		return firmTypes.containsKey(getTypeHelp(x10_type));
	}
	
	private Type removeFirmType(final polyglot.types.Type x10_type) {
		return firmTypes.remove(getTypeHelp(x10_type));
	}
	
	private void putFirmCoreType(final polyglot.types.Type x10_type, Type firm_Type) {
		firmCoreTypes.put(getTypeHelp(x10_type), firm_Type);
	}
	
	private Type getFirmCoreType(final polyglot.types.Type x10_type) {
		return firmCoreTypes.get(getTypeHelp(x10_type));
	}
	
	private boolean containsFirmCoreType(final polyglot.types.Type x10_type) {
		return firmCoreTypes.containsKey(getTypeHelp(x10_type));
	}
	
	private Type removeFirmCoreType(final polyglot.types.Type x10_type) {
		return firmCoreTypes.remove(getTypeHelp(x10_type));
	}

	/**
	 * Returns the boxing type for a given struct type
	 * @param type The type for which the boxing type should be returned
	 * @return The boxing type for the given struct type
	 */
	public X10ClassType getBoxingType(final X10ClassType type) {
		assert x10TypeSystem.isStructType(type);

		final X10ClassType ret = structBoxingTypes.get(type);
		if(ret != null) return ret;

        final Position pos = Position.COMPILER_GENERATED;

        X10ClassDef cd = new X10ClassDef_c(x10TypeSystem, null);

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

        	final X10ParsedClassType intervace = (X10ParsedClassType)t;
        	final X10ClassDef  intervaceDef = intervace.x10Def();

        	cd.addInterface(Types.ref(intervace));
        	
        	// only init the substitution if we really need it
        	TypeParamSubst subst = null; 
        	ArrayList<ParameterType> paramTypes = null; 
        	ArrayList<polyglot.types.Type> argTypes = null; 

    		ThisDef thisDef = x10TypeSystem.thisDef(pos, Types.ref(ct));
        	for(final MethodDef mDef : intervaceDef.methods())  {
        		final X10MethodDef md = x10TypeSystem.methodDef(pos, Types.ref(ct), Flags.PUBLIC, mDef.returnType(), mDef.name(),
        										                mDef.formalTypes());
        		md.setTypeParameters(mDef.typeParameters());
        		md.setThisDef(thisDef);
        		md.setGuard(mDef.guard());
        		md.setTypeGuard(mDef.typeGuard());
        		
        		final List<Ref<? extends polyglot.types.Type>> formalTypes = new LinkedList<Ref<? extends polyglot.types.Type>>();
        		final List<LocalDef> formalNames = new LinkedList<LocalDef>();
        		
        		final List<Ref<? extends polyglot.types.Type>> fTypes = mDef.formalTypes();
        		final List<LocalDef> fNames = mDef.formalNames(); 
        		
        		assert(fTypes.size() == fNames.size()); 
        		for(int i = 0; i < fTypes.size(); i++) {
        			final polyglot.types.Type x = fTypes.get(i).get(); 
        			Ref<? extends polyglot.types.Type> fType = fTypes.get(i);
        			LocalDef fName = fNames.get(i); 
        			
        			// a subsitution
        			if(x instanceof ParameterType) {
        				// init the substitution
        				if(subst == null || paramTypes == null || argTypes == null) {
        		        	subst = intervace.subst(); 
        		        	paramTypes = subst.copyTypeParameters();
        		        	argTypes = subst.copyTypeArguments(); 
        		        	assert(paramTypes.size() == argTypes.size()); 
        				}
        				int j = 0;
        				for(; j < paramTypes.size(); j++) 
        					if(paramTypes.get(j) == x)
        						break;

        				assert(j < paramTypes.size());
        				fType = Types.ref(argTypes.get(j));
        				
        				fName = x10TypeSystem.localDef(Position.COMPILER_GENERATED, fName.flags(), fType, fName.name());
        			} 
        			
        			formalNames.add(fName); 
        			formalTypes.add(fType);
        		}

        		md.setFormalNames(formalNames);
        		md.setFormalTypes(formalTypes);
        		
                cd.addMethod(md);
        	}
        }

        // add the boxed value to the class.
        final FieldDef boxValue = x10TypeSystem.fieldDef(pos, Types.ref(ct), Flags.PUBLIC, Types.ref(type), Name.make(BOXED_VALUE));
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
		final int nResults = methodInstance.returnType() == x10TypeSystem.Void() ? 0 : 1;
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
		// set the appropriate native size of the firm type
		final NativeClassInfo classInfo = firmNativeTypes.get(klass);
		if(classInfo != null) {
			klass.setSizeBytes(classInfo.getSize()); 
		}
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
		final polyglot.types.Type baseType = simplifyType(type);
		return Types.isX10Struct(baseType) && !isFirmPrimitiveType(baseType);
	}

	/**
	 * Simplifies a given polyglot type -> Returns the base type of a given type. -> Removes constrained types, annotations etc.
	 * TODO  Put this into a separate Util (or similar) class.
	 * @param type The type which should be simplified
	 * @return The simplified version of the given type
	 */
	public static polyglot.types.Type simplifyType(final polyglot.types.Type type) {
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
		return x10TypeSystem.equals((TypeObject)type1, (TypeObject)type2);
	}

	/**
	 * True if the given type is handled as a primitive type in firm.
	 * @param type_ The type which should be checked
	 * @return True if the given type is handled as a primitive type.
	 */
	public boolean isFirmPrimitiveType(final polyglot.types.Type type_) {
		final polyglot.types.Type type = simplifyType(type_);
		return equalTypes(type, x10TypeSystem.Int())     || equalTypes(type, x10TypeSystem.UInt())   ||
		   	   equalTypes(type, x10TypeSystem.Long())    || equalTypes(type, x10TypeSystem.ULong())  ||
		   	   equalTypes(type, x10TypeSystem.Short())   || equalTypes(type, x10TypeSystem.UShort()) ||
		   	   equalTypes(type, x10TypeSystem.Byte())    || equalTypes(type, x10TypeSystem.UByte())  ||
		       equalTypes(type, x10TypeSystem.Float())   || equalTypes(type, x10TypeSystem.Double()) ||
		       equalTypes(type, x10TypeSystem.Boolean()) ||
		       equalTypes(type, x10TypeSystem.Char());
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
		final Type thisType = asFirmType(owner);
		resultTypes[0] = thisType;

		for (polyglot.types.Type type : formalTypes) {
			final polyglot.types.Type simpType = simplifyType(type);
			if (isFirmStructType(simpType)) {
				parameterTypes[p++] = asFirmCoreType(simpType);
			} else {
				parameterTypes[p++] = asFirmType(simpType);
			}
		}
		assert (p == nParameters);

		return new MethodType(parameterTypes, resultTypes);
	}

	/**
	 * create a method type for an X10 constructor
	 */
	public MethodType asFirmType(X10ConstructorInstance instance) {
		if (instance.container() == x10TypeSystem.String())
			return getNativeConstructorType(instance);

		final List<polyglot.types.Type> formalTypes = instance.formalTypes();
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
			if (isFirmStructType(simpType)) {
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

		firm.Type result = getFirmType(baseType); 
		if (result != null)
			return result;
		
		polyglot.types.Type type2 = getTypeHelp(baseType);
		
		result = asFirmCoreType(type2);
		if (result instanceof ClassType) {
			/* we really have references to classes */
			result = new PointerType(result);
		}
		putFirmType(type2, result); 

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
		final GenericClassContext context = getDefiningContext(field);
		context.putFieldEntity(field.def(), entity);
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
		
		final String className = X10NameMangler.mangleTypeObjectWithDefClass(classType);
		final Flags flags = classType.flags();
		ClassType result = new ClassType(className);
		final NativeClassInfo classInfo = x10NativeTypes.get(classType);
		if(classInfo != null) {
			firmNativeTypes.put(result, classInfo); 
		}

		/* put the class into the core types already, because we could
		 * have a field referencing ourself */
		putFirmCoreType(classType, result); 

		/* create supertypes */
		polyglot.types.Type superType = classType.superClass();
		if (superType != null) {
			Type firmSuperType = asFirmCoreType(superType);
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
		for (polyglot.types.Type iface : interfaces) {
			assert ((polyglot.types.ClassType)iface).flags().isInterface() : "Not an interface: "+iface;
			Type firmIface = asFirmCoreType(iface);
			result.addSuperType(firmIface);
		}

		final X10ClassType ast_any = x10TypeSystem.Any();
		if (noSuperType(result) && classType != ast_any) {
			/* Every X10 type implements Any */
			final Type firm_any = asFirmCoreType(ast_any);
			result.addSuperType(firm_any);
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

	private boolean noSuperType(ClassType result) {
		return result.getNSuperTypes() == 0;
	}

	/**
	 * returns firm entity created for a FieldInstance.
	 * Note: this will only work if createClassType was already called for
	 * the fields class.
	 */
	public Entity getEntityForField(FieldInstance instance) {
		final GenericClassContext context = getDefiningContext(instance);
		return context.getFieldEntity(instance.def());
	}

	private X10ParsedClassType fixParsedClassType(X10ParsedClassType t) {
		if (t.isMissingTypeArguments()) {
			List<polyglot.types.Type> typeArguments = new ArrayList<polyglot.types.Type>();
			for (ParameterType pt : t.def().typeParameters())
				typeArguments.add(x10TypeSystem.getConcreteType(pt));

			return t.typeArguments(typeArguments);
		}
		else if (t.typeArguments() != null && !t.typeArguments().isEmpty()) {
			List<polyglot.types.Type> typeArguments = new ArrayList<polyglot.types.Type>();
			for (polyglot.types.Type typeArg : t.typeArguments())
				if (typeArg.getClass() == ParameterType.class)  // No constrained types here.
					typeArguments.add(x10TypeSystem.getConcreteType((ParameterType) typeArg));

			if (!typeArguments.isEmpty())
				return t.typeArguments(typeArguments);
		}

		return t;
	}

	/**
	 * return the firm type for a given ast-type.
	 * This variant does not return the "native"-type even if there is one.
	 */
	public firm.Type asFirmCoreType(polyglot.types.Type origType) {
		polyglot.types.Type type = origType;

		// FIXME:  Workaround.
		if (origType instanceof X10ParsedClassType)
			type = fixParsedClassType((X10ParsedClassType) origType);

		// isParsedClassType => !isMissingTypeArguments
		assert (!(type instanceof X10ParsedClassType) || !((X10ParsedClassType) type).isMissingTypeArguments());

		/* strip type-constraints */
		final polyglot.types.Type baseType = simplifyType(type);

		Type result = getFirmCoreType(baseType);
		if (result != null)
			return result;

		if (baseType instanceof X10ClassType) {
			result = createClassType((X10ClassType) baseType);
		} else {
			/* remember to put new types into coreTypeCache */
			putFirmCoreType(baseType, result);
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
	private void initFirmTypes() {
		
		/* we "lower" some well-known types directly to firm modes */
		Mode modeLong = new Mode("Long", ir_mode_sort.irms_int_number, 64, 1,
				ir_mode_arithmetic.irma_twos_complement, 64);
		Type typeLong = new PrimitiveType(modeLong);
		typeLong.setAlignmentBytes(4);
		putFirmType(x10TypeSystem.Long(), typeLong);

		Mode modeULong = new Mode("ULong", ir_mode_sort.irms_int_number, 64, 0,
				ir_mode_arithmetic.irma_twos_complement, 64);
		Type typeULong = new PrimitiveType(modeULong);
		typeULong.setAlignmentBytes(4);
		putFirmType(x10TypeSystem.ULong(), typeULong);

		Mode modeInt = new Mode("Int", ir_mode_sort.irms_int_number, 32, 1,
				ir_mode_arithmetic.irma_twos_complement, 32);
		Type typeInt = new PrimitiveType(modeInt);
		putFirmType(x10TypeSystem.Int(), typeInt);

		Mode modeUInt = new Mode("UInt", ir_mode_sort.irms_int_number, 32, 0,
				ir_mode_arithmetic.irma_twos_complement, 32);
		Type typeUInt = new PrimitiveType(modeUInt);
		putFirmType(x10TypeSystem.UInt(), typeUInt);

		Mode modeShort = new Mode("Short", ir_mode_sort.irms_int_number, 16, 1,
				ir_mode_arithmetic.irma_twos_complement, 32);
		Type typeShort = new PrimitiveType(modeShort);
		putFirmType(x10TypeSystem.Short(), typeShort);

		Mode modeUShort = new Mode("UShort", ir_mode_sort.irms_int_number, 16,
				0, ir_mode_arithmetic.irma_twos_complement, 32);
		Type typeUShort = new PrimitiveType(modeUShort);
		putFirmType(x10TypeSystem.UShort(), typeUShort);

		Mode modeByte = new Mode("Byte", ir_mode_sort.irms_int_number, 8, 1,
				ir_mode_arithmetic.irma_twos_complement, 32);
		Type typeByte = new PrimitiveType(modeByte);
		putFirmType(x10TypeSystem.Byte(), typeByte);

		Mode modeUByte = new Mode("UByte", ir_mode_sort.irms_int_number, 8, 0,
				ir_mode_arithmetic.irma_twos_complement, 32);
		Type typeUByte = new PrimitiveType(modeUByte);
		putFirmType(x10TypeSystem.UByte(), typeUByte);

		Mode modeChar = new Mode("Char", ir_mode_sort.irms_int_number, 32, 0,
				ir_mode_arithmetic.irma_twos_complement, 0);
		Type typeChar = new PrimitiveType(modeChar);
		putFirmType(x10TypeSystem.Char(), typeChar);

		Mode modeFloat = new Mode("Float", ir_mode_sort.irms_float_number, 32,
				1, ir_mode_arithmetic.irma_ieee754, 0);
		Type typeFloat = new PrimitiveType(modeFloat);
		putFirmType(x10TypeSystem.Float(), typeFloat);

		Mode modeDouble = new Mode("Double", ir_mode_sort.irms_float_number, 64,
				1, ir_mode_arithmetic.irma_ieee754, 0);
		Type typeDouble = new PrimitiveType(modeDouble);
		typeLong.setAlignmentBytes(4);
		putFirmType(x10TypeSystem.Double(), typeDouble);

		/* Note that the mode_b in firm can't be used here, since it is an
		 * internal mode which cannot be used for fields/call parameters/return
		 * values. We will use mode_b only internally when generating code for
		 * conditional jumps. */
		Mode modeBoolean = Mode.getBu();
		Type typeBoolean = new PrimitiveType(modeBoolean);
		putFirmType(x10TypeSystem.Boolean(), typeBoolean);

		Type unknown = Type.getUnknown();
		Type nullRefType = new PointerType(unknown);
		putFirmType(x10TypeSystem.Null(), nullRefType);
		/* Note: there is no sensible firmCoreType for Null() */
	}

	/**
	 * @return	a class type for x10.lang.Object
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
	 * @return	a class type for the given full class name 
	 */
	public X10ClassType getNamedX10Type(final String packageName, final String className) {
		final QName fullName = QName.make(packageName, className);
		final X10ClassType x10Type = x10TypeSystem.load(fullName.toString());
		return x10Type; 
	}

	/**
	 * @param instance	a constructor method instance
	 * @return	a Firm entity corresponding to the constructor
	 */
	public Entity getConstructorEntity(X10ConstructorInstance instance) {
		final GenericClassContext context = getDefiningContext(instance);
		Entity entity = context.getConstructorEntity(instance.x10Def());

		if (entity == null) {
			final String name = X10NameMangler.mangleTypeObjectWithDefClass(instance);
			final Flags flags = instance.flags();
			final firm.Type type = asFirmType(instance);

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

	private <T extends Def> GenericClassContext getDefiningContext(final MemberInstance<T> method) {
		final X10ClassType clazz = (X10ClassType) method.container();
		final boolean containedInGenericClass = clazz != null && clazz.def().typeParameters() != null && !clazz.def().typeParameters().isEmpty();

		if (containedInGenericClass) {
			GenericClassInstance classInstance;

			// This should always be the case but unfortunately it is not.
			if (clazz.typeArguments() != null && clazz.def().typeParameters().size() == clazz.typeArguments().size())
				classInstance = new GenericClassInstance(clazz);
			else {
				// FIXME:  This is a hack to workaround a problem in X10.
				ParameterTypeMapping map = new ParameterTypeMapping();
				for (ParameterType pt : clazz.def().typeParameters())
					map.add(pt, x10TypeSystem.getConcreteType(pt));
				classInstance = new GenericClassInstance(clazz.x10Def(), map);
			}

			GenericClassContext context = genericContexts.get(classInstance);
			if (context == null) {
				context = new GenericClassContext();
				genericContexts.put(classInstance, context);
			}

			return context;
		}

		return rootContext;
	}

	/**
	 * Return entity for an X10 method
	 */
	public Entity getMethodEntity(final MethodInstance instance) {
		final GenericClassContext context = getDefiningContext(instance);
		final GenericMethodInstance gMethodInstance = new GenericMethodInstance(instance);
		Entity entity = context.getMethodEntity(gMethodInstance);

		if (entity == null) {
			X10ClassType owner = (X10ClassType) instance.container();
			final String nameWithDefiningClass = X10NameMangler.mangleTypeObjectWithDefClass(instance);
			final String nameWithoutDefiningClass = X10NameMangler.mangleTypeObjectWithoutDefClass(instance);

			final Flags flags = instance.flags();
			final firm.Type owningClass = asFirmCoreType(owner);
			final firm.Type ownerFirm = flags.isStatic() ? Program.getGlobalType() : owningClass;
			final firm.Type type = asFirmType(instance);
			entity = new Entity(ownerFirm, nameWithoutDefiningClass, type);
			entity.setLdIdent(nameWithDefiningClass);

			if (flags.isStatic()) {
				OO.setEntityBinding(entity, ddispatch_binding.bind_static);
			} else if (owner.flags().isInterface()) {
				OO.setEntityBinding(entity, ddispatch_binding.bind_interface);
			} else if(x10TypeSystem.isStructType(owner)) {
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
	 * @param ptm	a set of type mappings
	 */
	public void pushTypeMapping(ParameterTypeMapping ptm) {
		for (ParameterType param : ptm.getKeySet()) {
			final polyglot.types.Type mappedType = ptm.getMappedType(param);

			assert (containsFirmCoreType(mappedType) || containsFirmType(mappedType));

			x10TypeSystem.addTypeMapping(param, mappedType);

			if (containsFirmCoreType(mappedType))
				putFirmCoreType(param, getFirmCoreType(mappedType));

			if (containsFirmType(mappedType))
				putFirmType(param, firmTypes.get(mappedType));
		}
	}

	/**
	 * Remove parameter type mapping from global mappings
	 * @param ptm	a set of type mappings
	 */
	public void popTypeMapping(ParameterTypeMapping ptm) {
		for (ParameterType param : ptm.getKeySet()) {
			x10TypeSystem.removeTypeMapping(param);

			if (containsFirmCoreType(param))
				removeFirmCoreType(param);

			if (containsFirmType(param))
				removeFirmType(param);
		}
	}
}
