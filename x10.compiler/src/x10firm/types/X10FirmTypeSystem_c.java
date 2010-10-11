package x10firm.types;

import java.util.HashMap;
import java.util.Map;

import firm.ClassType;
import firm.Ident;

import polyglot.types.Context;
import polyglot.types.Name;
import polyglot.types.PrimitiveType;
import polyglot.types.Type;
import x10.types.X10TypeSystem_c;

public class X10FirmTypeSystem_c extends X10TypeSystem_c {
	
    private Map<String, firm.Type> tcache = new HashMap<String, firm.Type>();
    
    private void addType(String tname, firm.Type type) {
    	assert(tcache.containsKey(tname));
    	tcache.put(tname, type); 
    }
    
    public firm.Type getFirmType(String tname) {
    	assert(tcache.containsKey(tname)); 
    	return tcache.get(tname); 
    }
    
    public void newClassType(String cname) {
    	firm.Type cType = new firm.ClassType(new firm.Ident(cname));
    	firm.Type cPointerType = new firm.PointerType(cType); 
    	addType(cname, cPointerType); 
    }
    
    private void initPrimitiveType() {

    	firm.Type x10_boolean = new firm.PrimitiveType(firm.Mode.getb());
    	 // unsigned short for x10_char -> Unicode
    	firm.Type x10_char    = new firm.PrimitiveType(firm.Mode.getHu());
    	firm.Type x10_byte    = new firm.PrimitiveType(firm.Mode.getBs());
    	firm.Type x10_short   = new firm.PrimitiveType(firm.Mode.getHs());
    	firm.Type x10_int     = new firm.PrimitiveType(firm.Mode.getIs());
    	firm.Type x10_long    = new firm.PrimitiveType(firm.Mode.getLs());
    	firm.Type x10_float   = new firm.PrimitiveType(firm.Mode.getF());
    	firm.Type x10_double  = new firm.PrimitiveType(firm.Mode.getD());
    	
    	addType("boolean", x10_boolean);
    	addType("char",    x10_byte);
    	addType("short",   x10_short);
    	addType("int",     x10_int);
    	addType("long",    x10_long);
    	addType("float",   x10_float);
    	addType("double",  x10_double);
    }
	
	public Context emptyContext() {
		return new X10FirmContext_c(this);
	}
}
