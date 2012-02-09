package x10firm.visit.x10lib;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

import polyglot.types.LocalInstance;
import x10.types.MethodInstance;
import x10.types.X10ClassType;
import x10firm.visit.FirmGenerator;

/**
 * Support class for generics. -> Manages a collection of generic code generators.
 */
public class NativeGenericSupport {
	private Map<String, NativeGenericDispatcher> map = new HashMap<String, NativeGenericDispatcher>();

	private void addGenericGenerator(final NativeGenericDispatcher dispatcher) {
		assert(!map.containsKey(dispatcher.getDispatchName()));
		map.put(dispatcher.getDispatchName(), dispatcher);
	}

	/**
	 * Constructor
	 */
	public NativeGenericSupport() {
		addGenericGenerator(new SupportGenerator());
		addGenericGenerator(new PointerGenerator());
		addGenericGenerator(new ZeroGenerator());
	}

	/**
	 * Dispatch a given native generic method to the appropriate generics generator
	 * @param codeGenerator The firm code generator
	 * @param meth The method instance for which the firm code should be generated
	 * @param formals The formals of the methods
	 * @return True if the given method could be dispatched.
	 */
	public boolean dispatch(final FirmGenerator codeGenerator, final MethodInstance meth,
								   final List<LocalInstance> formals) {
		final X10ClassType owner = (X10ClassType)meth.container();
		final NativeGenericDispatcher dispatcher = map.get(owner.name().toString());
		if(dispatcher == null) return false;
		return dispatcher.dispatch(codeGenerator, meth, formals);
	}
}
