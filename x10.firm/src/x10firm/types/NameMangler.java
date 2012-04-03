package x10firm.types;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

import polyglot.types.FieldInstance;
import polyglot.types.Name;
import polyglot.types.Package;
import polyglot.types.Ref;
import polyglot.types.Type;
import polyglot.util.UniqueID;
import x10.types.MethodInstance;
import x10.types.ParameterType;
import x10.types.X10ClassType;
import x10.types.X10ConstructorInstance;
import x10firm.CompilerOptions;
import x10firm.MachineTriple;
import x10firm.visit.CodeGenError;

/**
 * Name mangler which mangles X10 type objects to unique names.
 *
 * The mangling attempts to be as close as possible to the C++ Itanium ABI
 * which is used by many c++ compilers:
 *   http://sourcery.mentor.com/public/cxx-abi/abi.html
 */
public final class NameMangler {

	/**
	 * Reference to the X10 type system.
	 */
	private static GenericTypeSystem typeSystem;

	/**
	 * Mapping of primitive types.
	 */
	private static Map<Type, String> primMangleTable = new HashMap<Type, String>();

	/**
	 * Substitution table for method names.
	 */
	private static Map<String, String> binOpSubst = new HashMap<String, String>();

	/**
	 * Substitution table for unary operators.
	 */
	private static Map<String, String> unOpSubst = new HashMap<String, String>();

	/**
	 * Mapping for anonymous class names.
	 */
	private static Map<X10ClassType, String> anonymousClassNames = new HashMap<X10ClassType, String>();

	private static String platformPrefix = "";
	private static final String MANGLE_PREFIX = "_Z";
	private static final char   QUAL_START = 'N';
	private static final char   QUAL_END = 'E';
	private static final char   TYPEARG_START = 'I';
	private static final char   TYPEARG_END = 'E';
	private static final char   MANGLE_QUALIFIER_POINTER = 'P';
	private static final String MANGLED_CONSTRUCTOR = "C1";
	private static final String MANGLED_VTABLE = "TV";
	private static final String MANGLED_TYPEINFO = "TI";

	private static final String MANGLED_ANONYMOUS_CLASS_PREFIX = "$ANONYMOUS";

	/** utility class no need to instantiate it. */
	private NameMangler() {
	}

	/**
	 * Initializes name substitutions.
	 */
	private static void setupNameSubstitutions() {
		unOpSubst.put("operator~", "co");
		unOpSubst.put("operator+", "ps");
		unOpSubst.put("operator-", "ng");

		/* the following substitutions should be the same as in the C++ (itanium) ABI */
		binOpSubst.put("operator+",   "pl");
		binOpSubst.put("operator-",   "mi");
		binOpSubst.put("operator*",   "ml");
		binOpSubst.put("operator/",   "dv");
		binOpSubst.put("operator%",   "rm");
		binOpSubst.put("operator&",   "an");
		binOpSubst.put("operator|",   "or");
		binOpSubst.put("operator^",   "eo");
		binOpSubst.put("operator=",   "aS");
		binOpSubst.put("operator+=",  "pL");
		binOpSubst.put("operator-=",  "mI");
		binOpSubst.put("operator*=",  "mL");
		binOpSubst.put("operator/=",  "dV");
		binOpSubst.put("operator%=",  "rM");
		binOpSubst.put("operator&=",  "aN");
		binOpSubst.put("operator|=",  "oR");
		binOpSubst.put("operator^=",  "eO");
		binOpSubst.put("operator<<",  "ls");
		binOpSubst.put("operator>>",  "rs");
		binOpSubst.put("operator<<=", "lS");
		binOpSubst.put("operator>>=", "rS");
		binOpSubst.put("operator==",  "eq");
		binOpSubst.put("operator!=",  "ne");
		binOpSubst.put("operator<",   "lt");
		binOpSubst.put("operator>",   "gt");
		binOpSubst.put("operator<=",  "le");
		binOpSubst.put("operator>=",  "ge");
		binOpSubst.put("operator!",   "nt");
		binOpSubst.put("operator&&",  "aa");
		binOpSubst.put("operator||",  "oo");
		binOpSubst.put("operator++",  "pp");
		binOpSubst.put("operator--",  "mm");
		binOpSubst.put("operator->",  "pt");
		binOpSubst.put("operator()",  "ix");
		/* this are our own additions */
		binOpSubst.put("operator>>>", "v3rbs");
		binOpSubst.put("operator()=", "v3aps");

		/* inverse operators -> same as the upper operators with a 'v' <digit> 'i' prefix
		 * our own additions
		 */
		final Map<String, String> invNameSubs = new HashMap<String, String>();
		for (final String key : binOpSubst.keySet()) {
			invNameSubs.put("inverse_" + key, "v" + (key.length() + 1) + "i" + binOpSubst.get(key));
		}
		binOpSubst.putAll(invNameSubs);

		/* note: "cv" and "vXcv" are not here because they need the destination
		 * type mangled as part of their name */
	}

	/**
	 * Initializes mapping between primitive types and the appropriate name mangles.
	 */
	static void addPrimitiveMangling(final Type type, final String mangled) {
		assert !primMangleTable.containsKey(type);
		primMangleTable.put(type, mangled);
	}

	/**
	 * Initializes the name mangler.
	 */
	public static void setup(final GenericTypeSystem newTypeSystem, final CompilerOptions options) {
		NameMangler.typeSystem = newTypeSystem;
		setupNameSubstitutions();
		final MachineTriple target = options.getTargetTriple();
		if (target.isDarwin() || target.isWindowsOS()) {
			platformPrefix = "_";
		}
	}

	/**
	 * Mangles a given identifier.
	 */
	private static void mangleIdentifier(final StringBuilder buf,
			final String name) {
		buf.append(name.length());
		for (int i = 0; i < name.length(); ++i) {
			char c = name.charAt(i);
			if (c == '$') {
				c = '_';
			/**
			 * As of X10 2.2.0 and thanks to XTENLANG-1647, a space is inserted
			 * into the class name in x10.compiler/src/x10/util/ClosureSynthesizer.java
			 *
			 * As a quick fix, we translate this into a dollar sign.
			 */
			} else if (c == ' ') {
				c = '$';
			}
			buf.append(c);
		}
	}

	private static void mangleName(final StringBuilder buf,
			final Name name) {
		mangleIdentifier(buf, name.toString());
	}

	private static void mangleTypeParameterInstantiation(final StringBuilder buf,
			final List<ParameterType> typeParameters) {
		if (typeParameters == null || typeParameters.size() == 0)
			return;
		buf.append(TYPEARG_START);
		for (Type typeParameter : typeParameters) {
			final Type concrete = typeSystem.getConcreteType(typeParameter);
			mangleType(buf, concrete);
		}
		buf.append(TYPEARG_END);
	}

	private static void mangleTypeArguments(final StringBuilder buf,
			final List<Type> typeArguments) {
		if (typeArguments == null || typeArguments.size() == 0)
			return;
		buf.append(TYPEARG_START);
		for (Type typeArgument : typeArguments) {
			mangleType(buf, typeArgument);
		}
		buf.append(TYPEARG_END);
	}

	private static void mangleAnonymousClassName(final StringBuilder buf,
			final X10ClassType clazz) {
		String name = anonymousClassNames.get(clazz);
		if (name == null) {
			name = UniqueID.newID(MANGLED_ANONYMOUS_CLASS_PREFIX);
			anonymousClassNames.put(clazz, name);
		}
		buf.append(name);
	}

	private static void mangleClassName(final StringBuilder buf,
			final X10ClassType type) {
		if (type.isAnonymous()) {
			mangleAnonymousClassName(buf, type);
		} else {
			mangleName(buf, type.name());
		}
	}

	private static void manglePackage(final StringBuilder buf,
			final Package pkg) {
		if (pkg == null)
			return;
		final Ref<? extends Package> outer = pkg.prefix();
		if (outer != null)
			manglePackage(buf, outer.get());
		mangleName(buf, pkg.name());
	}

	/**
	 * Mangles the name of a class and type arguments.
	 * You may still append method/field names after calling this.
	 */
	private static void mangleClass(final StringBuilder buf,
			final X10ClassType type) {
		if (type.isMember()) {
			final X10ClassType outer = (X10ClassType)type.outer();
			if (type.flags().isStatic()) {
				mangleClassWithoutTypeArguments(buf, outer);
			} else {
				mangleClass(buf, outer);
			}
		} else {
			final Package pkg = type.package_();
			manglePackage(buf, pkg);
		}
		mangleClassName(buf, type);
		/* currently the generic code handling is a strange hybrid, sometimes
		 * it uses reinstantiated MethodInstances, sometimes it does not do so
		 * and expects us to output the current mapping of type parameters.
		 */
		final List<Type> typeArguments = type.typeArguments();
		if (typeArguments != null) {
			mangleTypeArguments(buf, typeArguments);
		} else {
			final List<ParameterType> typeParameters = type.def().typeParameters();
			mangleTypeParameterInstantiation(buf, typeParameters);
		}
	}

	private static void mangleClassWithoutTypeArguments(
			final StringBuilder buf, final X10ClassType type) {
		if (type.isMember()) {
			final X10ClassType outer = (X10ClassType)type.outer();
			mangleClassWithoutTypeArguments(buf, outer);
		} else {
			final Package pkg = type.package_();
			manglePackage(buf, pkg);
		}
		mangleClassName(buf, type);
	}

	/** Mangles a complete class type. */
	private static void mangleClassType(final StringBuilder buf,
			final X10ClassType type) {
		/* for aesthetic reasons and because the gnu java compiler does it
		 * similar we encode the class references as C++ pointers. The problem
		 * with that is that we have to replicate the logic of what is a
		 * reference and what isn't here */
		if (!typeSystem.isStructType(type))
			buf.append(MANGLE_QUALIFIER_POINTER);
		buf.append(QUAL_START);
		mangleClass(buf, type);
		buf.append(QUAL_END);
	}

	/**
	 * Mangles a given type.
	 */
	private static void mangleType(final StringBuilder buf, final Type pType) {
		final Type type = typeSystem.getConcreteType(pType);
		final String prim = primMangleTable.get(type);
		if (prim != null) {
			buf.append(prim);
			return;
		}

		if (type instanceof X10ClassType) {
			mangleClassType(buf, (X10ClassType) type);
			return;
		}
		throw new CodeGenError("Unknown type in mangleType " + pType.getClass() + ": " + pType, pType.position());
	}

	private static void mangleFormals(final StringBuilder buf,
			final List<Type> formals) {
		if (formals.size() == 0) {
			buf.append("v");
			return;
		}
		for (Type type : formals) {
			mangleType(buf, type);
		}
	}

	/**
	 * Mangles a given method name.
	 */
	private static void mangleMethodName(final StringBuilder buf,
			final MethodInstance method) {
		final String name = method.name().toString();
		if (name.startsWith("operator")) {
			final String subst = unOpSubst.get(name);
			if (subst != null) {
				/* really an unary operator */
				final boolean isStatic = method.flags().isStatic();
				final List<Type> formals = method.formalTypes();
				if ((isStatic && formals.size() == 1)
				    || (!isStatic && formals.size() == 0)) {
					buf.append(subst);
					return;
				}
			} else if (name.equals("operator_as")) {
				final StringBuilder tbuf = new StringBuilder();
				final Type returnType = method.returnType();
				mangleType(tbuf, returnType);
				final String destType = tbuf.toString();
				buf.append('v');
				buf.append(destType.length() + 2);
				buf.append("as");
				buf.append(destType);
				return;
			}
		} else if (name.equals("implicit_operator_as")) {
			final Type returnType = method.returnType();
			buf.append("cv");
			mangleType(buf, returnType);
			return;
		}

		final String subst = binOpSubst.get(name);
		if (subst != null) {
			buf.append(subst);
			return;
		}

		mangleIdentifier(buf, name);
	}

	/** Mangles a complete method including container and formals. */
	public static String mangleMethod(final MethodInstance method) {
		final StringBuilder buf = new StringBuilder();

		buf.append(platformPrefix);
		buf.append(MANGLE_PREFIX);
		buf.append(QUAL_START);
		final X10ClassType container = (X10ClassType)method.container();
		if (method.flags().isStatic()) {
			mangleClassWithoutTypeArguments(buf, container);
		} else {
			mangleClass(buf, container);
		}
		mangleMethodName(buf, method);

		/* currently the generic code handling is a strange hybrid, sometimes
		 * it uses reinstantiated MethodInstances, sometimes it does not do so
		 * and expects us to output the current mapping of type parameters.
		 */
		final List<Type> typeArguments = method.typeParameters();
		final boolean hadTypeArguments;
		if (typeArguments != null) {
			mangleTypeArguments(buf, typeArguments);
			hadTypeArguments = typeArguments.size() > 0;
		} else {
			final List<ParameterType> typeParameters = method.def().typeParameters();
			mangleTypeParameterInstantiation(buf, typeParameters);
			hadTypeArguments = typeParameters.size() > 0;
		}
		buf.append(QUAL_END);
		if (hadTypeArguments) {
			/* C++ ABI requires that return type is mangled for
			 * generic methods */
			mangleType(buf, method.returnType());
		}
		mangleFormals(buf, method.formalTypes());
		return buf.toString();
	}

	/** Mangles a short form of a method without container type
	 * or other mangling prefixes. Intended to be used in interface lookup
	 * tables.
	 */
	public static String mangleMethodShort(final MethodInstance method) {
		final StringBuilder buf = new StringBuilder();
		mangleMethodName(buf, method);
		mangleFormals(buf, method.formalTypes());
		return buf.toString();
	}

	/** Mangles the name for a field. */
	public static String mangleField(final FieldInstance instance) {
		final StringBuilder buf = new StringBuilder();
		buf.append(platformPrefix);
		buf.append(MANGLE_PREFIX);
		buf.append(QUAL_START);
		final X10ClassType container = (X10ClassType)instance.container();
		if (instance.flags().isStatic()) {
			mangleClassWithoutTypeArguments(buf, container);
		} else {
			mangleClass(buf, container);
		}
		mangleIdentifier(buf, instance.name().toString());
		buf.append(QUAL_END);
		return buf.toString();
	}

	/**
	 * Mangles a given constructor instance.
	 */
	public static String mangleConstructor(final X10ConstructorInstance constructor) {
		final StringBuilder buf = new StringBuilder();
		buf.append(platformPrefix);
		buf.append(MANGLE_PREFIX);
		buf.append(QUAL_START);
		final X10ClassType container = (X10ClassType)constructor.container();
		mangleClass(buf, container);
		buf.append(MANGLED_CONSTRUCTOR);
		buf.append(QUAL_END);
		mangleFormals(buf, constructor.formalTypes());
		return buf.toString();
	}

	/**
	 * Returns the mangled vtable name for a given class type.
	 * @param clazz The class type for which the mangled vtable name should be returned
	 * @return The mangled vtable name
	 */
	public static String mangleVTable(final X10ClassType clazz) {
		final StringBuilder buf = new StringBuilder();
		buf.append(platformPrefix);
		buf.append(MANGLE_PREFIX);
		buf.append(MANGLED_VTABLE);
		buf.append(QUAL_START);
		mangleClass(buf, clazz);
		buf.append(QUAL_END);

		return buf.toString();
	}

	/**
	 * Returns the mangled typeinfo name for a given class type.
	 * @param clazz The class type for which the mangled typeinfo name should be returned
	 * @return The mangled typeinfo name
	 */
	public static String mangleTypeinfo(final X10ClassType clazz) {
		final StringBuilder buf = new StringBuilder();
		buf.append(platformPrefix);
		buf.append(MANGLE_PREFIX);
		buf.append(MANGLED_TYPEINFO);
		buf.append(QUAL_START);
		mangleClass(buf, clazz);
		buf.append(QUAL_END);

		return buf.toString();
	}

	/**
	 * Returns platform specific mangling for a given string.
	 * (i.e. adds an underscore prefix on mac/windows)
	 */
	public static String mangleKnownName(final String name) {
		final StringBuilder buf = new StringBuilder();
		buf.append(platformPrefix);
		buf.append(name);
		return buf.toString();
	}
}
