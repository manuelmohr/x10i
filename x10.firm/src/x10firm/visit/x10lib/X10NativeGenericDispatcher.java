package x10firm.visit.x10lib;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

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

		return meth_generator.gen(codeGenerator, meth, formals);
	}

	/**
	 * Returns the dispatch name of the generator -> Class name
	 * @return The dispatch name
	 */
	public abstract String getDispatchName();
}
