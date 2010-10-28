package x10firm.types;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

import firm.Firm;
import firm.Mode;

import polyglot.types.ClassType;
import polyglot.types.Context;
import polyglot.types.Ref;
import polyglot.types.Type;
import x10.types.FunctionType;
import x10.types.X10ClassType;
import x10.types.X10Context_c;
import x10.types.X10MethodDef;
import x10.types.X10NamedType;
import x10.types.X10NullType;
import x10.types.X10PrimitiveType;
import x10.types.X10Struct;
import x10.types.X10TypeSystem_c;

public class TypeSystem extends X10TypeSystem_c {

	private Map<polyglot.types.Type, firm.Mode> primModeMap = new HashMap<polyglot.types.Type, firm.Mode>();
	private Map<polyglot.types.Type, firm.Type> tcache      = new HashMap<polyglot.types.Type, firm.Type>();
	private firm.Mode pointerMode;
	private boolean inited = false;
	
	static {
		Firm.init();
	}
	
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

		primModeMap.put(Boolean(), Mode.getb());
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
		addType(Boolean(),new firm.PrimitiveType(getFirmMode(Boolean())));
		addType(Byte(),   new firm.PrimitiveType(getFirmMode(Byte())));
		addType(UInt(),   new firm.PrimitiveType(getFirmMode(UInt())));
		addType(Int(),    new firm.PrimitiveType(getFirmMode(Int())));
		addType(ULong(),  new firm.PrimitiveType(getFirmMode(ULong())));
		addType(Long(),   new firm.PrimitiveType(getFirmMode(Long())));
		addType(Float(),  new firm.PrimitiveType(getFirmMode(Float())));
		addType(Double(), new firm.PrimitiveType(getFirmMode(Double())));
		addType(Char(),   new firm.PrimitiveType(getFirmMode(Char())));
	}

	public final firm.Mode getFirmMode(final polyglot.types.Type type) {
		firm.Mode mode = primModeMap.get(type);
		if (mode != null)
			return mode;
		return pointerMode;
	}

	private void addType(polyglot.types.Type t, firm.Type type) {
		assert (!tcache.containsKey(t));
		tcache.put(t, type);
	}

	public firm.Type getFirmType(polyglot.types.Type t) {
		assert (tcache.containsKey(t));
		return tcache.get(t);
	}

	public void declFirmClass(polyglot.types.Type cType) {
		assert cType instanceof ClassType;
		// TODO: Implement me
//		firm.Type cType 		= new firm.ClassType(new firm.Ident(cname));
//		firm.Type cPointerType 	= new firm.PointerType(cType);

	//	addType(cDef, cPointerType);
	}

	public void declFirmStruct(polyglot.types.Type sType) {
		assert sType instanceof ClassType;
		// TODO: Implement me
	}

	/**Creates a new firm method type
	 * 
	 * @param def X10 Method Definition
	 * @return corresponding Firm method type
	 */
	public firm.MethodType declFirmMethod(X10MethodDef def) {
		// Watch out: typeParamters are the template parameters of the method and
		// not the formal parameters
		
		// TODO: "this" is not included in formalTypes -> include it in the firm MethodType
		List<Ref<? extends Type>> formalTypes = def.formalTypes();
		final int nParameters = formalTypes.size();
		final int nResults = def.returnType() == null ? 0 : 1;
		
		firm.MethodType type = new firm.MethodType(nParameters, nResults);
		
		/* set parameter types */
		for(int i = 0; i < formalTypes.size(); i++) {
			Ref<? extends Type> formalType = formalTypes.get(i);
			type.setParamType(i, asFirmType(formalType.get()));
		}

		if (nResults == 1) {
			type.setResType(0, asFirmType(def.returnType().get()));
		}
		return type;
	}
	
	/** 
	 * Returns the corresponding Firm type for the given polyglot type
	 * 
	 * @param type The given polyglot type
	 * @return corresponding Firm method type
	 */
	public firm.Type asFirmType(polyglot.types.Type type) {
		firm.Type t = getFirmType(type);
		if(t != null)
			return t;
		assert false : "Cannot convert to Firm type: " + type;
		return null;
		
//		if (type instanceof FunctionType) {
//			assert false : "Cannot convert FunctionType to Firm type: " + type;
//		} else if (type instanceof X10NamedType) {
//			/* this includes builtin types like x10.lang.Int */
//			final String typename = ((X10NamedType) type).name().toString();
//			
//			if (typename.equals("Int")) {
//				return new firm.PrimitiveType(firm.Mode.getIs());
//			}
//			assert false : "Cannot convert X10NamedType to Firm type: "
//					+ typename;
//		} else if (type instanceof X10PrimitiveType) {
//			assert false : "Cannot convert X10PrimitiveType to Firm type: " + type;
//		} else if (type instanceof X10Struct) {
//			assert false : "Cannot convert X10Struct to Firm type: " + type;
//		} else if (type instanceof X10NullType) {
//			assert false : "Cannot convert X10NullType to Firm type: " + type;
//		} else if (type instanceof X10ClassType) {
//			X10ClassType ct = (X10ClassType) type;
//			firm.Type cType = new firm.ClassType(new firm.Ident(ct.name()
//					.toString()));
//			return new firm.PointerType(cType);
//		}
//		assert false : "Cannot convert to Firm type: " + type;
//		return null;
	}

	@Override
	public Context emptyContext() {
		return new X10Context_c(this);
	}
}
