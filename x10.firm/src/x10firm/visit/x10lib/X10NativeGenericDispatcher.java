package x10firm.visit.x10lib;

import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

import polyglot.types.LocalInstance;
import x10.types.MethodInstance;
import x10firm.visit.X10FirmCodeGenerator;

/**
 * Dispatcher for native generic methods. 
 */
public abstract class X10NativeGenericDispatcher {
	
	private Map<String, X10NativeGenericMethodFirmGenerator> map = new HashMap<String, X10NativeGenericMethodFirmGenerator>();
	
	/**
	 * Add a new method generator
	 * @param generator The method generator which should be added
	 */
	protected void addMethodGenerator(final X10NativeGenericMethodFirmGenerator generator) {
		assert(!map.containsKey(generator.getMethodName()));
		map.put(generator.getMethodName(), generator);
	}
	
	private Set<String> generated_method_cache = new HashSet<String>();
	
	private boolean wasMethodGenerated(final MethodInstance meth) {
		final String name = meth.toString();
		return generated_method_cache.contains(name);
	}
	
	private void setMethodGenerated(final MethodInstance meth) {
		assert(!generated_method_cache.contains(meth.toString()));
		generated_method_cache.add(meth.toString());
	}

	/**
	 * @param codeGenerator The firm code generator
	 * @param meth The method instance
	 * @param formals The formals of the method
	 * @return True if the method could be dispatched
	 */
	public boolean dispatch(final X10FirmCodeGenerator codeGenerator, final MethodInstance meth, 
							final List<LocalInstance> formals) {
		final X10NativeGenericMethodFirmGenerator meth_generator = map.get(meth.name().toString());
		if(meth_generator == null) return false;
		if(wasMethodGenerated(meth)) return true;
		
		final boolean ret = meth_generator.gen(codeGenerator, meth, formals);
		setMethodGenerated(meth);
		return ret;
	}
	
	/**
	 * Returns the dispatch name of the generator -> Class name
	 * @return The dispatch name
	 */
	public abstract String getDispatchName();
}
