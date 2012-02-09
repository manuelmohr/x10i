package x10firm.types;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

import polyglot.types.FieldInstance;
import polyglot.types.Flags;
import polyglot.types.LocalInstance;
import polyglot.types.Package;
import polyglot.types.Type;
import polyglot.types.TypeObject;
import polyglot.util.UniqueID;
import x10.types.MethodInstance;
import x10.types.X10ClassType;
import x10.types.X10ConstructorInstance;

/**
 * Name mangler which mangles X10 type objects to unique names
 */
public class NameMangler {

	/**
	 * Reference to the X10 type system
	 */
	private static GenericTypeSystem x10TypeSystem;

	/**
	 * Mapping of primitive types
	 */
	private static Map<Type, String> primMangleTable = new HashMap<Type, String>();

	/**
	 * Substitution table for method names.
	 */
	private static Map<String, String> nameSubst = new HashMap<String, String>();

	/**
	 * Substitution table for unary operators.
	 */
	private static Map<String, String> unOpSubst = new HashMap<String, String>();

	/**
	 * Mapping for anonymous class names.
	 */
	private static Map<X10ClassType, String> anonymousClassNames = new HashMap<X10ClassType, String>();

	private static final String MANGLE_PREFIX = "_Z";
	private static final String MANGLE_SUFFIX = "";
	private static final String QUAL_START = "N";
	private static final String QUAL_END = "E";
	private static final String TYPEARG_START = "I";
	private static final String TYPEARG_END = "E";
	private static final String MANGLED_VOID_TYPE = "v";
	private static final String MANGLED_POINTER_REF = "P";
	private static final String MANGLED_CONSTRUCTOR = "C1";
	private static final String MANGLED_THIS = "C1";
	private static final String MANGLED_VTABLE = "TV";
	private static final String MANGLED_TYPEINFO = "TI";

	private static final String MANGLED_ANONYMOUS_CLASS_PREFIX = "$ANONYMOUS";

	/**
	 * Initializes name substitutions for unary operators
	 */
	private static void setupUnOpSubstitutions() {
		unOpSubst.put("operator+", "ps");
		unOpSubst.put("operator-", "ng");
		// There are no substitutions in the spec for the following unary! operators
		// -> our own additions
		unOpSubst.put("operator~", "v3uti");
	}

	/**
	 * Initializes name substitutions
	 */
	private static void setupNameSubstitutions() {
		/* the following substitutions should be the same as in the C++ (itanium) ABI */
		nameSubst.put("operator~",   "co");
		nameSubst.put("operator+",   "pl");
		nameSubst.put("operator-",   "mi");
		nameSubst.put("operator*",   "ml");
		nameSubst.put("operator/",   "dv");
		nameSubst.put("operator%",   "rm");
		nameSubst.put("operator&",   "an");
		nameSubst.put("operator|",   "or");
		nameSubst.put("operator^",   "eo");
		nameSubst.put("operator=",   "aS");
		nameSubst.put("operator+=",  "pL");
		nameSubst.put("operator-=",  "mI");
		nameSubst.put("operator*=",  "mL");
		nameSubst.put("operator/=",  "dV");
		nameSubst.put("operator%=",  "rM");
		nameSubst.put("operator&=",  "aN");
		nameSubst.put("operator|=",  "oR");
		nameSubst.put("operator^=",  "eO");
		nameSubst.put("operator<<",  "ls");
		nameSubst.put("operator>>",  "rs");
		nameSubst.put("operator<<=", "lS");
		nameSubst.put("operator>>=", "rS");
		nameSubst.put("operator==",  "eq");
		nameSubst.put("operator!=",  "ne");
		nameSubst.put("operator<",   "lt");
		nameSubst.put("operator>",   "gt");
		nameSubst.put("operator<=",  "le");
		nameSubst.put("operator>=",  "ge");
		nameSubst.put("operator!",   "nt");
		nameSubst.put("operator&&",  "aa");
		nameSubst.put("operator||",  "oo");
		nameSubst.put("operator++",  "pp");
		nameSubst.put("operator--",  "mm");
		nameSubst.put("operator->",  "pt");

		/* inverse operators -> same as the upper operators with a 'v' <digit> 'i' prefix
		 * our own additions
		 */
		Map<String, String> invNameSubs = new HashMap<String, String>();
		for(String key : nameSubst.keySet())
			invNameSubs.put("inverse_" + key, "v3i" + nameSubst.get(key));

		/* this are our own additions */
		nameSubst.put("operator>>>", "v3rbs");
		nameSubst.put("operator()=", "v3aps");
		nameSubst.put("operator()",  "apply");

		nameSubst.putAll(invNameSubs);

		nameSubst.put("operator_as", "cv");
		// operator_as and implicit_operator_as must be distinct because you can have
		// both operator definitions in a class
		nameSubst.put("implicit_operator_as", "v3icv");

		/* constructor */
		nameSubst.put("this", MANGLED_THIS);
	}

	/**
	 * Initializes mapping between primitive types and the appropriate name mangles.
	 */
	private static void setupPrimitiveTypesNameMangling() {
		primMangleTable.put(x10TypeSystem.Long(),    "x");
		primMangleTable.put(x10TypeSystem.ULong(),   "y");
		primMangleTable.put(x10TypeSystem.Int(),     "i");
		primMangleTable.put(x10TypeSystem.UInt(),    "j");
		primMangleTable.put(x10TypeSystem.Short(),   "s");
		primMangleTable.put(x10TypeSystem.UShort(),  "t");
		primMangleTable.put(x10TypeSystem.Byte(),    "a");
		primMangleTable.put(x10TypeSystem.UByte(),   "h");
		primMangleTable.put(x10TypeSystem.Char(),    "Di");
		primMangleTable.put(x10TypeSystem.Float(),   "f");
		primMangleTable.put(x10TypeSystem.Double(),  "d");
		primMangleTable.put(x10TypeSystem.Boolean(), "b");
		primMangleTable.put(x10TypeSystem.Void(),    MANGLED_VOID_TYPE);
	}

	/**
	 * Initializes the name mangler.
	 * @param x10TypeSystem_ Reference to the type system.
	 */
	public static void setup(final GenericTypeSystem x10TypeSystem_) {
		x10TypeSystem = x10TypeSystem_;
		setupUnOpSubstitutions();
		setupNameSubstitutions();
		setupPrimitiveTypesNameMangling();
	}

	/**
	 * Tries to mangle a given primitive type
	 * @param type The primitive type which should be mangled
	 * @return The mangled name of the given primitive type or null if no mangling was set for the given primitive type
	 */
	private static String tryPrimitiveType(final Type type) {
		return primMangleTable.get(type);
	}

	/**
	 * Tries to mangle a given string
	 * @param name The string which should be mangled
	 * @return The mangled name of the given string or null if no name substitution was set for the given string
	 */
	private static String tryNameSubsitution(final String name) {
		return nameSubst.get(name);
	}

	/**
	 * Tries to mangle a given string (unary)
	 * @param name The string which should be mangled
	 * @return The mangled name of the given string or null if no name substitution was set for the given string
	 */
	private static String tryUnOpSubsitution(final String name) {
		return unOpSubst.get(name);
	}

	/**
	 * Mangles a given string
	 * @param name The string which should be mangled
	 * @return The mangled name of the given string
	 */
	private static String mangleName(final String name) {
		StringBuilder buf = new StringBuilder();
		buf.append(name.length());
		for(char c : name.toCharArray()) {
			if(c == '$') buf.append("_");
			else buf.append(c);
		}
		return buf.toString();
	}

	/**
	 * Mangles a given method name
	 * @param name The method name which should be mangled
	 * @return The mangled method name
	 */
	private static String mangleMethodName(final MethodInstance meth) {
		final String name = meth.name().toString();
		if(name.startsWith("operator")) {
			final List<Type> formals = meth.formalTypes();
			final Flags flags = meth.flags();
			if((flags.isStatic() && formals.size() == 1) ||
			  (!flags.isStatic() && formals.size() == 0)) { // try unary
				String tmp = tryUnOpSubsitution(name);
				if(tmp != null) return tmp;
			}
		}

		final String tmp = tryNameSubsitution(name);
		if(tmp != null) return tmp;
		return mangleName(name);
	}

	/**
	 * Mangles a given package
	 * @param pack The package which should be mangled
	 * @return The mangled name of the given package
	 */
	private static String manglePackage(final Package pack) {
		StringBuilder buf = new StringBuilder();
		final String []splits = pack.toString().split("\\.");
		for(String split : splits)
			buf.append(mangleName(split));
		return buf.toString();
	}

	/**
	 * Mangles a local instance as a argument
	 * @param type The type which should be mangled
	 * @return The mangled name of the given local instance as a argument
	 */
	private static String mangleArgument(final LocalInstance loc) {
		StringBuilder buf = new StringBuilder();
		buf.append(mangleParameter(loc.type()));
		return buf.toString();
	}

	/**
	 * Mangles a given type as an argument
	 * @param type The type which should be mangled
	 * @return The mangled name of the given type
	 */
	private static String mangleParameter(final Type type) {
		if (x10TypeSystem.isParameterType(type))
			return mangleParameter(x10TypeSystem.getConcreteType(type));

		final Type ret = GenericTypeSystem.simplifyType(type);

		String tmp = tryPrimitiveType(ret);
		if (tmp != null)
			return tmp;

		StringBuilder buf = new StringBuilder();

		boolean passAsRef = true; // only "real" classes not structs are passed as references.
		if(ret instanceof X10ClassType) {
			X10ClassType struct = (X10ClassType)ret;
			if(struct.isX10Struct())
				passAsRef = false;
		}

		if(passAsRef)
			buf.append(MANGLED_POINTER_REF);

		buf.append(mangleType(ret, false));

		return buf.toString();
	}

	/**
	 * Mangles a given type as a type parameter (Generics)
	 * @param type The type which should be mangled
	 * @return The mangled name of the given type
	 */
	private static String mangleTypeParameter(final Type type) {
		// same as mangle type without embedding
		return mangleType(type, false);
	}

	private static String getAnonymousClassName(final X10ClassType clazz) {
		String name = anonymousClassNames.get(clazz);
		if(name != null) return name;

		name = UniqueID.newID(MANGLED_ANONYMOUS_CLASS_PREFIX);
		anonymousClassNames.put(clazz, name);
		return name;
	}

	/**
	 * Mangles a given class type
	 * @param clazz The class type which name should be mangled
	 * @param embed True if the given class type is embedded.
	 * @return The mangled name of the given class type
	 */
	private static String mangleClassType(final X10ClassType clazz,
			final boolean embed) {
		StringBuilder buf = new StringBuilder();
		boolean needQualiEnd = false;
		if (clazz.isTopLevel()) {
			if (clazz.package_() != null) {
				if (!embed) {
					needQualiEnd = true;
					buf.append(QUAL_START);
				}
				buf.append(manglePackage(clazz.package_()));
			}
		} else if (clazz.isMember()) {
			if (!embed) {
				needQualiEnd = true;
				buf.append(QUAL_START);
			}
			buf.append(mangleType(clazz.outer(), true));
		} else if (clazz.isAnonymous()) {
			// DO NOTHING
		} else {
			assert (false) : "Unknown class type" + clazz;
		}

		final String clazzName = clazz.isAnonymous() ? getAnonymousClassName(clazz)
				: clazz.name().toString();
		buf.append(mangleName(fixClassName(clazzName)));

		final List<? extends Type> typeArgs = clazz.typeArguments() != null ? clazz
				.typeArguments() : clazz.x10Def().typeParameters();
		if (!typeArgs.isEmpty() && !mangleGenericStaticMethodInstance) {
			// don`t mangle type arguments if we are currently mangling a method
			// instance.
			buf.append(TYPEARG_START);
			for (Type type : typeArgs)
				buf.append(mangleTypeParameter(type));
			buf.append(TYPEARG_END);
		}

		if (needQualiEnd)
			buf.append(QUAL_END);

		return buf.toString();
	}

	/**
	 * As of X10 2.2.0 and thanks to XTENLANG-1647, a space is inserted
	 * into the class name in x10.compiler/src/x10/util/ClosureSynthesizer.java
	 *
	 * As a quick fix, we translate this into a dollar sign. However, there should be
	 * a better solution in x10.compiler! FIXME
	 *
	 * @param string  a class name, potentially with spaces
	 * @return        a class name without spaces
	 */
	private static String fixClassName(String string) {
		return string.replace(' ', '$');
	}

	// Flag to mark if we are currently mangling a static method instance
	private static boolean mangleGenericStaticMethodInstance = false;

	/**
	 * Mangles a given method instance
	 * @param method The method instance which should be mangled
	 * @param mangleDefiningClass True if the defining class of the method should also be mangled
	 * @return The mangled name of the given method instance
	 */
	private static String mangleMethodInstance(final MethodInstance method, final boolean mangleDefiningClass) {
		StringBuilder buf = new StringBuilder();
		buf.append(QUAL_START);

		final List<? extends Type> typeArgs = method.typeParameters() != null ? method.typeParameters() :
			method.x10Def().typeParameters();

		if (mangleDefiningClass) {
			if (method.container() != null) {
				if(method.flags().isStatic()) {
					mangleGenericStaticMethodInstance = true;
				}
				buf.append(mangleType(method.container(), true));
				if(mangleGenericStaticMethodInstance) {
					mangleGenericStaticMethodInstance = false;
				}
				buf.append(mangleMethodName(method));
			}
		} else {
			buf.append(mangleMethodName(method));
		}

		if (!typeArgs.isEmpty()) {
			buf.append(TYPEARG_START);
			for(Type type : method.typeParameters())
				buf.append(mangleTypeParameter(type));
			buf.append(TYPEARG_END);
		}

		buf.append(QUAL_END);

		if (!typeArgs.isEmpty()) {
			// Comply with C++ ABI and mangle return type.
			buf.append(mangleType(method.returnType(), false));
		}

		if (!method.formalNames().isEmpty()) {
			final List<LocalInstance> formalNames = method.formalNames();
			final List<Type> formalTypes = method.formalTypes();
			assert formalNames.size() == formalTypes.size();

			for (int i = 0; i < formalNames.size(); ++i) {
				final LocalInstance form = formalNames.get(i);
				buf.append(mangleArgument(form.type(formalTypes.get(i))));
			}
		} else {
			buf.append(MANGLED_VOID_TYPE);
		}

		return buf.toString();
	}

	/**
	 * Mangles a given field instance
	 * @param field The field instance which should be mangled
	 * @param defClass True if the defining class of the field should also be mangled.
	 * @return The mangled name of the given field instance
	 */
	private static String mangleFieldInstance(final FieldInstance field, final boolean defClass) {
		StringBuilder buf = new StringBuilder();
		assert(field.container() != null);

		if (defClass) {
			buf.append(QUAL_START);
			buf.append(mangleType(field.container(), true));
			buf.append(mangleName(field.name().toString()));
			buf.append(QUAL_END);
		} else {
			buf.append(mangleName(field.name().toString()));
		}

		return buf.toString();
	}

	/**
	 * Mangles a given constructor instance
	 * @param cons The constructor instance which should be mangled
	 * @return The mangled name of the given constructor instance
	 */
	private static String mangleConstructorInstance(final X10ConstructorInstance cons) {
		StringBuilder buf = new StringBuilder();
		assert(cons.container() != null);

		buf.append(QUAL_START);
		buf.append(mangleType(cons.container(), true));
		buf.append(MANGLED_CONSTRUCTOR);
		buf.append(QUAL_END);

		final List<LocalInstance> forms = cons.formalNames();
		if (!forms.isEmpty()) {
			for (LocalInstance form : forms)
				buf.append(mangleArgument(form));
		} else {
			buf.append(MANGLED_VOID_TYPE);
		}

		return buf.toString();
	}

	/**
	 * Mangle a given type
	 * @param type The type which should be mangled
	 * @param embed True if the given type is embedded in another type
	 * @return The mangled name of the given type
	 */
	private static String mangleType(final Type type, final boolean embed) {
		if (x10TypeSystem.isParameterType(type))
			return mangleType(x10TypeSystem.getConcreteType(type), embed);

		String tmp = null;

		final Type ret = GenericTypeSystem.simplifyType(type);
		if (!embed) {
			tmp = tryPrimitiveType(ret);
			if (tmp != null)
				return tmp;
		}

		if (ret instanceof X10ClassType) { // a class type
			tmp = mangleClassType((X10ClassType) ret, embed);
		} else {
			 assert(false): "Unknown type in mangleType " + ret.getClass() + ": " + ret;
		}

		return tmp;
	}

	/**
	 * Mangles a given type object
	 * @param typeObject The type object which should be mangled
	 * @param embed True if the given type object is embedded in another type object
	 * @return The mangled name of the given type object
	 */
	private static String mangleTypeObject(final TypeObject typeObject, final boolean embed, final boolean mangleDefiningClass) {
		if(typeObject instanceof Type)
			return mangleType((Type)typeObject, embed);

		String tmp = null;

		if(typeObject instanceof FieldInstance) { // a field instance
			tmp = mangleFieldInstance((FieldInstance)typeObject, mangleDefiningClass);
		} else if(typeObject instanceof MethodInstance) { // a method
			tmp = mangleMethodInstance((MethodInstance)typeObject, mangleDefiningClass);
		} else if(typeObject instanceof X10ConstructorInstance) { // a constructor
			tmp = mangleConstructorInstance((X10ConstructorInstance)typeObject);
		} else {
			assert(false) : "Unknown type in mangleType" + typeObject.getClass() + ": " + typeObject;
		}

		return tmp;
	}

	/**
	 * Mangles a given type object and returns the mangled name
	 * @param type The type object for which the name should be mangled
	 * @param mangleDefiningClass True if the defining class of the given type object should also be mangled
	 * @return The mangled name of the given type object
	 */
	private static String mangleTypeObject(final TypeObject type, final boolean mangleDefiningClass) {
		StringBuilder buf = new StringBuilder();

		buf.append(MANGLE_PREFIX);
		buf.append(mangleTypeObject(type, false, mangleDefiningClass));
		buf.append(MANGLE_SUFFIX);

		return buf.toString();
	}

	/**
	 * Mangles a given type object and returns the mangled name with the appropriate defining class
	 * @param type The type object for which the name should be mangled
	 * @return The mangled name of the given type object
	 */
	public static String mangleTypeObjectWithDefClass(final TypeObject type) {
		return mangleTypeObject(type, true);
	}

	/**
	 * Mangles a given type object and returns the mangled name withouth the appropriate defining class
	 * @param type The type object for which the name should be mangled
	 * @return The mangled name of the given type object
	 */
	public static String mangleTypeObjectWithoutDefClass(final TypeObject type) {
		return mangleTypeObject(type, false);
	}

	/**
	 * Returns the mangled vtable name for a given class type
	 * @param clazz The class type for which the mangled vtable name should be returned
	 * @return The mangled vtable name
	 */
	public static String mangleVTable(final X10ClassType clazz) {
		StringBuilder buf = new StringBuilder();

		buf.append(MANGLE_PREFIX);
		buf.append(MANGLED_VTABLE);
		buf.append(mangleClassType(clazz, false));
		buf.append(MANGLE_SUFFIX);

		return buf.toString();
	}

	/**
	 * Returns the mangled typeinfo name for a given class type
	 * @param clazz The class type for which the mangled typeinfo name should be returned
	 * @return The mangled typeinfo name
	 */
	public static String mangleTypeinfo(final X10ClassType clazz) {
		StringBuilder buf = new StringBuilder();

		buf.append(MANGLE_PREFIX);
		buf.append(MANGLED_TYPEINFO);
		buf.append(mangleClassType(clazz, false));
		buf.append(MANGLE_SUFFIX);

		return buf.toString();
	}
}
