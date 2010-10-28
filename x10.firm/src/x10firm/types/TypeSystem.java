package x10firm.types;

import java.util.HashMap;
import java.util.Map;

import firm.Firm;
import firm.Mode;

import polyglot.types.Context;
import x10.types.X10ClassDef;
import x10.types.X10Context_c;
import x10.types.X10MethodDef;
import x10.types.X10TypeSystem_c;

public class TypeSystem extends X10TypeSystem_c {

	public static final String X10_BOOLEAN 	= "Boolean";
	public static final String X10_BYTE     = "Byte";
	public static final String X10_CHAR 	= "Char";
	public static final String X10_UINT 	= "UInt";
	public static final String X10_INT 		= "Int";
	public static final String X10_ULONG 	= "ULong";
	public static final String X10_LONG 	= "Long";
	public static final String X10_FLOAT 	= "Float";
	public static final String X10_DOUBLE 	= "Double";

	private static Map<String, firm.Mode> primModeMap;
	private static Map<String, firm.Type> tcache;
	private static firm.Mode pointerMode;

	static {
		primModeMap = new HashMap<String, firm.Mode>();
		tcache      = new HashMap<String, firm.Type>();
		
		Firm.init();

		initModes();
		initPrimitiveType();
	}
	
	private static void initModes() {
		pointerMode = Mode.getP();

		primModeMap.put(X10_BOOLEAN, Mode.getb());
		primModeMap.put(X10_BYTE, Mode.getBs());
		// unsigned short for x10_char -> Unicode
		primModeMap.put(X10_CHAR, Mode.getHu());
		primModeMap.put(X10_UINT, Mode.getIu());
		primModeMap.put(X10_INT, Mode.getIs());
		primModeMap.put(X10_ULONG, Mode.getLLu());
		primModeMap.put(X10_LONG, Mode.getLLs());
		primModeMap.put(X10_FLOAT, Mode.getF());
		primModeMap.put(X10_DOUBLE, Mode.getD());
	}
	

	private static void initPrimitiveType() {
		addType(X10_BOOLEAN, new firm.PrimitiveType(getFirmMode(X10_BOOLEAN)));
		addType(X10_BYTE,    new firm.PrimitiveType(getFirmMode(X10_BYTE)));
		addType(X10_UINT, 	 new firm.PrimitiveType(getFirmMode(X10_UINT)));
		addType(X10_INT, 	 new firm.PrimitiveType(getFirmMode(X10_INT)));
		addType(X10_ULONG,   new firm.PrimitiveType(getFirmMode(X10_ULONG)));
		addType(X10_LONG,    new firm.PrimitiveType(getFirmMode(X10_LONG)));
		addType(X10_FLOAT,   new firm.PrimitiveType(getFirmMode(X10_FLOAT)));
		addType(X10_DOUBLE,  new firm.PrimitiveType(getFirmMode(X10_DOUBLE)));
		addType(X10_CHAR,    new firm.PrimitiveType(getFirmMode(X10_CHAR)));
	}

	public static final firm.Mode getFirmMode(final String type) {
		firm.Mode mode = primModeMap.get(type);
		if (mode != null)
			return mode;
		return pointerMode;
	}

	private static void addType(String tname, firm.Type type) {
		assert (!tcache.containsKey(tname));
		tcache.put(tname, type);
	}

	public static firm.Type getFirmType(String tname) {
		assert (tcache.containsKey(tname));
		return tcache.get(tname);
	}

	public void declFirmClass(X10ClassDef cDef) {
		String cname = cDef.asType().fullName().toString();
		//X10FirmTranslator.getFullClassName(cDef.asType());

		firm.Type cType = new firm.ClassType(new firm.Ident(cname));
		firm.Type cPointerType = new firm.PointerType(cType);

		addType(cname, cPointerType);
	}

	public void declFirmStruct(X10ClassDef cDef) {
		// TODO: Implement me
	}

	public void declFirmMethod(X10MethodDef mDef) {
		// TODO: Implement me
	}

	public TypeSystem() {
		// TODO: Implement me
	}

	@Override
	public Context emptyContext() {
		return new X10Context_c(this);
	}
}
