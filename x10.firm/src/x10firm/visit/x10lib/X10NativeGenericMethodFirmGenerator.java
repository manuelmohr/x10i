package x10firm.visit.x10lib;

import java.util.List;

import polyglot.types.LocalInstance;
import x10.types.MethodInstance;
import x10firm.visit.X10FirmCodeGenerator;

/**
 * Generator for native generic methods
 */
public interface X10NativeGenericMethodFirmGenerator {
	/**
	 * Generates the firm code for a native generic method
	 * @param codeGenerator The firm code generator
	 * @param methodInstance The method instance of the native generic method
	 * @param formals The formals of the method
	 * @return True if the firm code could be generated for the given method
	 */
	public boolean gen(final X10FirmCodeGenerator codeGenerator, final MethodInstance methodInstance,
					   final List<LocalInstance> formals);

	/** Returns the name of the native generic method -> Used for dispatching
	 * @return The name of the native generic method
	 */
	public String getMethodName();
}
