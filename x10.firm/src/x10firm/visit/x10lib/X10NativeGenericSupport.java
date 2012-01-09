package x10firm.visit.x10lib;

import java.util.HashMap;
import java.util.List;
import java.util.Map;
import polyglot.types.LocalInstance;
import x10.types.MethodInstance;
import x10.types.X10ClassType;
import x10firm.visit.X10FirmCodeGenerator;

/**
 * Support class for generics. -> Manages a collection of generic code generators. 
 */
public class X10NativeGenericSupport {
	private Map<String, X10NativeGenericDispatcher> map = new HashMap<String, X10NativeGenericDispatcher>();
	
	private void addGenericGenerator(final X10NativeGenericDispatcher dispatcher) {
		assert(!map.containsKey(dispatcher.getDispatchName()));
		map.put(dispatcher.getDispatchName(), dispatcher);
	}
	
	/**
	 * Constructor
	 */
	public X10NativeGenericSupport() {
		addGenericGenerator(new X10FirmSupportGenerator());
		addGenericGenerator(new X10FirmPointerGenerator());
		addGenericGenerator(new X10FirmZeroGenerator());
	}
	
	/** 
	 * Dispatch a given native generic method to the appropriate generics generator
	 * @param codeGenerator The firm code generator
	 * @param meth The method instance for which the firm code should be generated
	 * @param formals The formals of the methods
	 * @return True if the given method could be dispatched. 
	 */
	public boolean dispatch(final X10FirmCodeGenerator codeGenerator, final MethodInstance meth,
								   final List<LocalInstance> formals) {
		final X10ClassType owner = (X10ClassType)meth.container();
		final X10NativeGenericDispatcher dispatcher = map.get(owner.name().toString());
		if(dispatcher == null) return false;
		return dispatcher.dispatch(codeGenerator, meth, formals);
	}
}