package x10firm.types;

import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;

import x10.types.X10ClassType;
import x10.types.X10Flags;
import x10.types.X10MethodInstance;
import x10.types.X10TypeSystem_c;
import firm.ClassType;
import firm.Mode;
import firm.Mode.ir_mode_arithmetic;
import firm.Mode.ir_mode_sort;
import firm.NameMangling;
import firm.PointerType;
import firm.PrimitiveType;
import firm.Type;

/**
 * Includes everything to map X10 types to Firm types
 *
 * XXX While the mapping is static, the X10 type system is not,
 * because the runtime is loaded dynamically.
 */
public class TypeSystem extends X10TypeSystem_c {

	/// Maps polyglot types to firm types.
	private Map<polyglot.types.Type, Type> firmTypeCache = new HashMap<polyglot.types.Type, Type>();
	/// Maps some polyglot types to "native"/primitive firm types
	private Map<polyglot.types.Type, Type> firmNativeTypes = new HashMap<polyglot.types.Type, Type>();

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
			Type classType = asFirmType(owner);
			PointerType thisPtrType = new PointerType(classType);
			parameterTypes[p++] = thisPtrType;
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
	 * Returns the corresponding Firm type for the given polyglot type
	 * 
	 * @param type
	 *            The given polyglot type
	 * @return corresponding Firm method type
	 */
	public firm.Type asFirmType(polyglot.types.Type type) {
		firm.Type result = firmNativeTypes.get(type);
		if (result != null)
			return result;
		
		return asFirmTypeNonNative(type);
	}
	
	public firm.Type asFirmTypeNonNative(polyglot.types.Type type) {		
		firm.Type result = firmTypeCache.get(type);
		if (result == null) {
			if (type instanceof X10ClassType) {
				X10ClassType classType = (X10ClassType) type;
				result = new ClassType(classType.name().toString());
			} else if (type.toString().startsWith("x10.lang.Int")) {
				/* type may be longer, e.g. "x10.lang.Int{self==0}" */
				return new PrimitiveType(getFirmMode(Int()));
			} else {
				assert false : "No implement to get firm type for: " + type;
			}
			firmTypeCache.put(type, result);
		}
		firmTypeCache.put(type, result);
		return result;
	}

	public Mode getFirmMode(polyglot.types.Type type) {
		return asFirmType(type).getMode();
	}

	public void beforeGraphConstruction() {
		/* we "lower" some well-known types directly to firm modes */
		Mode modeInt = new Mode("Int", ir_mode_sort.irms_int_number, 32, 1,
				ir_mode_arithmetic.irma_twos_complement, 32);
		Type typeInt = new PrimitiveType(modeInt);
		firmNativeTypes.put(Int(), typeInt);
		
		Mode modeBoolean = Mode.getb();
		Type typeBoolean = new PrimitiveType(modeBoolean);
		firmNativeTypes.put(Boolean(), typeBoolean);
	}
	
	public void setupNameMangler(NameMangling mangler) {
		for(Entry<polyglot.types.Type, Type> entry : firmNativeTypes.entrySet()) {
			String mangledName = null;
			if (entry.getKey() == Int()) {
				mangledName = "i";
			} else if (entry.getKey() == Boolean()) {
				mangledName = "b";
			} else {
				/* all NativeTypes must have a direct encoding in the name mangling */
				throw new java.lang.RuntimeException("Unexpected Native Type");
			}
			mangler.setPrimitiveTypeName(entry.getValue(), mangledName);
		}
	}
}
