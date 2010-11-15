package x10firm.types;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

import polyglot.types.Context;
import x10.types.X10ClassType;
import x10.types.X10Context_c;
import x10.types.X10Flags;
import x10.types.X10MethodInstance;
import x10.types.X10TypeSystem_c;
import firm.ClassType;
import firm.Mode;
import firm.PointerType;
import firm.PrimitiveType;
import firm.Type;

public class TypeSystem extends X10TypeSystem_c {

	// maps polyglot types to the appropriate firm modes. 
	private Map<polyglot.types.Type, firm.Mode> primModeMap   = new HashMap<polyglot.types.Type, firm.Mode>();
	// Maps polyglot types to firm types. 
	private Map<polyglot.types.Type, Type> firmTypeCache = new HashMap<polyglot.types.Type, Type>();
	
	private firm.Mode pointerMode;
	private boolean inited = false;
	
	// initialize the type system
	public void init() {
		if(!inited) {
			initModes();
			initPrimitiveType();
			inited = true;
		}
	}
	
	private void initModes() {
		pointerMode = Mode.getP();

		primModeMap.put(Boolean(), Mode.getBs());
		primModeMap.put(Byte(),    Mode.getBs());
		// unsigned short for x10_char -> Unicode
		primModeMap.put(Char(),    Mode.getHu());
		primModeMap.put(UInt(),    Mode.getIu());
		primModeMap.put(Int(), 	   Mode.getIs());
		primModeMap.put(ULong(),   Mode.getLLu());
		primModeMap.put(Long(),    Mode.getLLs());
		primModeMap.put(Float(),   Mode.getF());
		primModeMap.put(Double(),  Mode.getD());
	}
	
	private void initPrimitiveType() {
		firmTypeCache.put(Boolean(),new PrimitiveType(getFirmMode(Boolean())));
		firmTypeCache.put(Byte(),   new PrimitiveType(getFirmMode(Byte())));
		firmTypeCache.put(UInt(),   new PrimitiveType(getFirmMode(UInt())));
		firmTypeCache.put(Int(),    new PrimitiveType(getFirmMode(Int())));
		firmTypeCache.put(ULong(),  new PrimitiveType(getFirmMode(ULong())));
		firmTypeCache.put(Long(),   new PrimitiveType(getFirmMode(Long())));
		firmTypeCache.put(Float(),  new PrimitiveType(getFirmMode(Float())));
		firmTypeCache.put(Double(), new PrimitiveType(getFirmMode(Double())));
		firmTypeCache.put(Char(),   new PrimitiveType(getFirmMode(Char())));
		/* X10 has no primitive types per se */
	}

	public final firm.Mode getFirmMode(polyglot.types.Type type) {
		firm.Mode mode = primModeMap.get(type);
		if (mode != null)
			return mode;
		// PointerMode for all the others. 
		return pointerMode;
	}

	/**
	 * Creates a method type (= a member function). So we in addition to the
	 * type we need the flags to determine if it is static and the owner class
	 * to determine the type of the "this" parameter.
	 */
	public firm.MethodType asFirmType(X10MethodInstance methodInstance) {
		final List<polyglot.types.Type> formalTypes = methodInstance.formalTypes();
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
		assert(p == nParameters);
		
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
	 * @param type The given polyglot type
	 * @return corresponding Firm method type
	 */
	public firm.Type asFirmType(polyglot.types.Type type) {
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
		return result;
	}

	@Override
	public Context emptyContext() {
		return new X10Context_c(this);
	}
}