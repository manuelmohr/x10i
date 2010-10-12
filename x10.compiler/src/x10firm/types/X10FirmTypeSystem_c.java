package x10firm.types;

import java.util.HashMap;
import java.util.Map;

import firm.ClassType;
import firm.Firm;
import firm.Ident;
import firm.Mode;

import polyglot.types.Context;
import polyglot.types.Name;
import polyglot.types.PrimitiveType;
import polyglot.types.Type;
import x10.types.X10ClassDef;
import x10.types.X10MethodDef;
import x10.types.X10TypeSystem_c;
import x10.visit.StaticNestedClassRemover;
import x10firm.visit.X10FirmTranslator;

public class X10FirmTypeSystem_c extends X10TypeSystem_c {
	
	
	public static final String X10_BOOLEAN = "boolean";
	public static final String X10_CHAR    = "char";
	public static final String X10_UINT    = "uint";
	public static final String X10_INT     = "int"; 
	public static final String X10_ULONG   = "ulong"; 
	public static final String X10_LONG    = "long";
	public static final String X10_FLOAT   = "float";
	public static final String X10_DOUBLE  = "double";
	
	private static Map<String, firm.Mode> primModeMap = new HashMap<String, firm.Mode>();
	private static firm.Mode pointerMode = null;
	
	static {
		Firm.init();
		
		pointerMode = Mode.getP(); 
		
		primModeMap.put(X10_BOOLEAN, Mode.getb());
	   	 // unsigned short for x10_char -> Unicode
		primModeMap.put(X10_CHAR, 	Mode.getHu());
		primModeMap.put(X10_UINT, 	Mode.getIu());
		primModeMap.put(X10_INT, 	Mode.getIs());
		primModeMap.put(X10_ULONG, 	Mode.getLLu());
		primModeMap.put(X10_LONG, 	Mode.getLLs());
		primModeMap.put(X10_FLOAT, 	Mode.getF());
		primModeMap.put(X10_DOUBLE, Mode.getD());
	}
	
	public static final firm.Mode getFirmMode(final String type) {
		firm.Mode mode = primModeMap.get(type);
		if(mode != null) return mode;
		return pointerMode; 
	}
	
    private static Map<String, firm.Type> tcache = new HashMap<String, firm.Type>();
    
    private void addType(String tname, firm.Type type) {
    	assert(tcache.containsKey(tname));
    	tcache.put(tname, type); 
    }
    
    public static firm.Type getFirmType(String tname) {
    	assert(tcache.containsKey(tname)); 
    	return tcache.get(tname); 
    }
    
    private static firm.Type createPrimitiveType(firm.Mode mode) {
    	return new firm.PrimitiveType(mode); 
    }

    private void initPrimitiveType() {
    	
    	firm.Type x10_boolean = createPrimitiveType(getFirmMode(X10_BOOLEAN));
    	firm.Type x10_char    = createPrimitiveType(getFirmMode(X10_CHAR));
    	firm.Type x10_uint    = createPrimitiveType(getFirmMode(X10_UINT));
    	firm.Type x10_int     = createPrimitiveType(getFirmMode(X10_INT));
    	firm.Type x10_ulong   = createPrimitiveType(getFirmMode(X10_ULONG));
    	firm.Type x10_long    = createPrimitiveType(getFirmMode(X10_LONG));
    	firm.Type x10_float   = createPrimitiveType(getFirmMode(X10_FLOAT));
    	firm.Type x10_double  = createPrimitiveType(getFirmMode(X10_DOUBLE));
    	
    	addType(X10_BOOLEAN, x10_boolean);
    	addType(X10_UINT,    x10_uint);
    	addType(X10_INT,     x10_int);
    	addType(X10_ULONG,   x10_ulong);
    	addType(X10_LONG,    x10_long);
    	addType(X10_FLOAT,   x10_float);
    	addType(X10_DOUBLE,  x10_double);
    }
    
    public void declFirmClass(X10ClassDef cDef) {
    	String cname = X10FirmTranslator.getFullClassName(cDef.asType());
    	
    	firm.Type cType 		= new firm.ClassType(new firm.Ident(cname));
    	firm.Type cPointerType 	= new firm.PointerType(cType);
    	
    	addType(cname, cPointerType); 
    }
    
    public void declFirmStruct(X10ClassDef cDef) {
    	// TODO: Implement me
    }
    
    public void declFirmMethod(X10MethodDef mDef) {
    	
    }
    
    public X10FirmTypeSystem_c() {
    	
    }
	
	public Context emptyContext() {
		return new X10FirmContext_c(this);
	}
}
