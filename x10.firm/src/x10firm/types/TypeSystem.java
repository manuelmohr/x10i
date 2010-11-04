package x10firm.types;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

import firm.Firm;
import firm.Mode;
import firm.Program;
import firm.bindings.binding_typerep;

import polyglot.types.Context;
import polyglot.types.Ref;
import polyglot.types.Type;
import x10.types.X10ClassType;
import x10.types.X10Context_c;
import x10.types.X10Flags;
import x10.types.X10MethodDef;
import x10.types.X10MethodInstance;
import x10.types.X10TypeSystem_c;

public class TypeSystem extends X10TypeSystem_c {

	// maps polyglot types to the appropriate firm modes. 
	private Map<polyglot.types.Type, firm.Mode> primModeMap   = new HashMap<polyglot.types.Type, firm.Mode>();
	// Maps polyglot types to firm types. 
	private Map<polyglot.types.Type, firm.Type> firmTypeCache = new HashMap<polyglot.types.Type, firm.Type>();
	// Maps firm types to the corresponding firm entities. 
	private Map<firm.Type, firm.Entity> firmEntityCache       = new HashMap<firm.Type, firm.Entity>();
	
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
		addFirmType(Boolean(),new firm.PrimitiveType(getFirmMode(Boolean())));
		addFirmType(Byte(),   new firm.PrimitiveType(getFirmMode(Byte())));
		addFirmType(UInt(),   new firm.PrimitiveType(getFirmMode(UInt())));
		addFirmType(Int(),    new firm.PrimitiveType(getFirmMode(Int())));
		addFirmType(ULong(),  new firm.PrimitiveType(getFirmMode(ULong())));
		addFirmType(Long(),   new firm.PrimitiveType(getFirmMode(Long())));
		addFirmType(Float(),  new firm.PrimitiveType(getFirmMode(Float())));
		addFirmType(Double(), new firm.PrimitiveType(getFirmMode(Double())));
		addFirmType(Char(),   new firm.PrimitiveType(getFirmMode(Char())));
	}

	public final firm.Mode getFirmMode(polyglot.types.Type type) {
		firm.Mode mode = primModeMap.get(type);
		if (mode != null)
			return mode;
		// PointerMode for all the others. 
		return pointerMode;
	}

	private void addFirmType(polyglot.types.Type t, firm.Type type) {
		assert (!firmTypeCache.containsKey(t));
		firmTypeCache.put(t, type);
	}

	private firm.Type getFirmType(polyglot.types.Type t) {
		assert (firmTypeCache.containsKey(t));
		return firmTypeCache.get(t);
	}
	
	private void addFirmEntity(firm.Type type, firm.Entity entity) {
		assert(!firmEntityCache.containsKey(type));
		firmEntityCache.put(type, entity);
	}
	
	public firm.Entity getFirmEntity(firm.Type type) {
		assert(firmEntityCache.containsKey(type));
		return firmEntityCache.get(type);
	}

	/**Creates a new firm class entity
	 * 
	 * @param def X10 Method Definition
	 * @return corresponding firm class entity
	 */
	public firm.Entity declFirmClass(polyglot.types.ClassType cType) {
		String cName = cType.toString();
		
		firm.ClassType classType = new firm.ClassType(new firm.Ident(cName));
		classType.setTypeState(binding_typerep.ir_type_state.layout_fixed);
		firm.PointerType classPointerType 	= new firm.PointerType(classType);
		addFirmType(cType, classPointerType);
		
		firm.Entity classEntity = new firm.Entity(Program.getGlobalType(), cName, classType);
		classEntity.setVisibility(binding_typerep.ir_visibility.ir_visibility_external);
		addFirmEntity(classPointerType, classEntity);
		
		return classEntity;
	}

	public void declFirmStruct(polyglot.types.StructType sType) {
		assert false;
		// TODO: Implement me
	}

	/**Creates a new firm method entity
	 * 
	 * @param def X10 method definition
	 * @param flags of the given method definition
	 * @param ownerClass owner class of the given method definition
	 * @return corresponding firm method entity
	 */
	public firm.Entity declFirmMethod(X10MethodDef def, final X10Flags flags, X10ClassType ownerClass) {
		
		boolean isStatic 		= flags.isStatic();
		X10MethodInstance mi 	= (X10MethodInstance) def.asInstance();
		
		List<Ref<? extends Type>> formalTypes = def.formalTypes();
		final int nParameters 	= formalTypes.size() + ((isStatic) ? 0 : 1);
		final int nResults 		= def.returnType() == null ? 0 : 1;
		
		firm.MethodType methType = new firm.MethodType(nParameters, nResults);
		
		// Set 'this'
		if(!isStatic) {
			firm.PointerType thisPtrType = new firm.PointerType(asFirmType(ownerClass));
			methType.setParamType(0, thisPtrType);
		}
		
		int i = isStatic ? 0 : 1;
		
		/* set parameter types */
		for(; i < formalTypes.size(); i++) {
			Ref<? extends Type> formalType = formalTypes.get(i);
			methType.setParamType(i, asFirmType(formalType.get()));
		}

		if (nResults == 1) {
			methType.setResType(0, asFirmType(def.returnType().get()));
		}
		
		String methodName 	= mi.name().toString();
		firm.Type methEntityOwnerType = null;
		
		if(isStatic) {
			methEntityOwnerType = firm.Program.getGlobalType();
		} else {
			// the returned firm type of the owner class must be a pointer type
			assert asFirmType(ownerClass) instanceof firm.PointerType;
			
			firm.PointerType ptrType = (firm.PointerType)asFirmType(ownerClass);
			methEntityOwnerType = ptrType.getPointsTo();
		}

		firm.Entity methEnt = new firm.Entity(methEntityOwnerType, methodName, methType);
		addFirmEntity(methType, methEnt);
		
		return methEnt;
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