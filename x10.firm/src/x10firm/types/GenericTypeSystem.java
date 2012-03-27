package x10firm.types;

import polyglot.types.Context;
import polyglot.types.Type;
import polyglot.types.TypeSystem_c;
import polyglot.types.Types;
import x10.types.TypeParamSubst;
import x10.types.X10ClassType;

/**
 * Implements generic-aware versions of the methods provided by {@link TypeSystem_c}.
 * This means that passing ParameterTypes like T are handled correctly by all
 * methods by looking up the type that T is currently mapped to.
 *
 * Note that we remove all all constraint types while doing so, as they are
 * not relevant for code generation (and we want to avoid creating different
 * versions of a generic method just because of different constraints).
 */
public class GenericTypeSystem {
	/** underlying X10 type system. */
	private final TypeSystem_c typeSystem;
	/** An empty context, because some functions expect one. */
	private final Context emptyContext;
	/** current type parameter substitution. */
	private TypeParamSubst subst;

	/**
	 * Constructs a new GenericTypeSystem.
	 */
	public GenericTypeSystem(final TypeSystem_c typeSystem) {
		this.typeSystem = typeSystem;
		emptyContext = typeSystem.emptyContext();
		subst = TypeParamSubst.IDENTITY;
	}

	/**
	 * Returns reference to the base TypeSystem (dangerous! The base type
	 * system does not perform type parameter substitution based on the context
	 * only use this if you know what that means!)
	 */
	public TypeSystem_c getTypeSystem() {
		return typeSystem;
	}

	/** Set a new type mapping. */
	public void setSubst(final TypeParamSubst subst) {
		this.subst = subst;
	}

	/** Returns the current type mapping. */
	public TypeParamSubst getSubst() {
		return subst;
	}

	/**
	 * Returns True iff {@code param} is a struct type.
	 */
	public boolean isStructType(final Type type) {
		final Type ret = getConcreteType(type);
		return typeSystem.isStructType(ret);
	}

	/**
	 * Returns True iff {@code t1} is a subtype of {@code t2}.
	 */
	public boolean isSubtype(final Type t1, final Type t2) {
		final Type t1c = getConcreteType(t1);
		final Type t2c = getConcreteType(t2);

		return typeSystem.isSubtype(t1c, t2c, emptyContext);
	}

	/**
	 * Returns True iff {@code t1} is equal to {@code t2}.
	 */
	public boolean typeEquals(final Type t1, final Type t2) {
		final Type t1c = getConcreteType(t1);
		final Type t2c = getConcreteType(t2);

		return typeSystem.typeEquals(t1c, t2c, emptyContext);
	}

	/**
	 * Returns True iff {@code t1} is equal to {@code t2},
	 * ignoring their dep clauses and the dep clauses of their type arguments
	 * recursively.
	 */
	public boolean typeBaseEquals(final Type t1, final Type t2) {
		final Type t1c = getConcreteType(t1);
		final Type t2c = getConcreteType(t2);

		return typeSystem.typeBaseEquals(t1c, t2c, emptyContext);
	}

	/**
	 * Returns true iff {@code t1} is base equals to {@code t2}.
	 */
	public boolean typeDeepBaseEquals(final Type t1, final Type t2) {
		final Type t1c = getConcreteType(t1);
		final Type t2c = getConcreteType(t2);

		return typeSystem.typeDeepBaseEquals(t1c, t2c, emptyContext);
	}

	/**
	 * Returns the concrete type for a given type
	 * (after substitution of type parameters etc.).
	 * @param type The given type
	 * @return The concrete type
	 */
	public Type getConcreteType(final Type type) {
		/* first remove constraints and annotationes, we don't need and want
		 * them in the backend */
		final Type stripped = Types.stripConstraints(type);
		return subst.reinstantiate(stripped);
	}

	/**
	 * Tests whether {@code type} is a class type.
	 * @param type some type
	 * @return  is it a key mapped to a class type?
	 */
	public boolean isClass(final Type type) {
		final Type ret = getConcreteType(type);
		return ret.isClass();
	}

	/**
	 * @return The type {@code t} casted to a class type or null
	 */
	public X10ClassType toClass(final Type t) {
		final Type ret = getConcreteType(t);
		return ret.toClass();
	}

	/**
	 * @return True iff {@code type} is a reference type.
	 */
	public boolean isRefType(final Type type) {
		final Type ret = getConcreteType(type);
		return !isStructType(ret) && (ret == typeSystem.Null() || isClass(ret) || typeSystem.isInterfaceType(ret));
	}

	/** x10.lang.Pointer type. */
	private X10ClassType pointer;

	/**
	 * @return The FirmPointer class type.
	 */
	public X10ClassType pointer() {
		if (pointer == null)
			pointer = typeSystem.load("x10.lang.Pointer");
		return pointer;
	}

	/**
	 * @param type Type to check.
	 * @return True iff {@code type} is Pointer or a subtype of Pointer.
	 */
	public boolean isPointer(final Type type) {
		return isSubtype(type, pointer());
	}

	/**
	 * Returns true iff type is an Int type.
	 */
	public boolean isInt(final Type type) {
		return isSubtype(type, typeSystem.Int());
	}

	/**
	 * Returns true iff type is a parameter type.
	 */
	public boolean isParameterType(final Type type) {
		return typeSystem.isParameterType(type);
	}

	@Override
	public String toString() {
		return subst.toString();
	}

	/** returns true if 2 TypeParamSubst are the same.
	 * (until the class implements equals() itself) */
	public static boolean substEquals(final TypeParamSubst subst1, final TypeParamSubst subst2) {
		/* TODO: this depends on the arbitrary order of the args/parameters although
		 * if we only switch order of the arguments/parameters TypeParamSubst stay
		 * the same. */
		if (!subst1.copyTypeArguments().equals(subst2.copyTypeArguments()))
			return false;
		if (!subst1.copyTypeParameters().equals(subst2.copyTypeParameters()))
			return false;
		return true;
	}

	/** returns a hash key for a TypeParamSubst.
	 * (until the class implements hashKey itself) */
	public static int getSubstHashKey(final TypeParamSubst subst) {
		return subst.copyTypeArguments().hashCode()
		     ^ subst.copyTypeParameters().hashCode();
	}

	/** Returns an empty Context. */
	public Context emptyContext() {
		return emptyContext;
	}
}
