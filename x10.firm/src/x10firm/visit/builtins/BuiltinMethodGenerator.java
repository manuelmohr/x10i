package x10firm.visit.builtins;

import java.util.List;

import polyglot.types.LocalInstance;
import x10.types.MethodInstance;
import x10firm.visit.FirmGenerator;

/**
 * Generator for native generic methods
 */
interface BuiltinMethodGenerator {
	/**
	 * Generates the firm code for a native generic method
	 * @param codeGenerator The firm code generator
	 * @param methodInstance The method instance of the native generic method
	 * @param formals The formals of the method
	 */
	public void generate(final FirmGenerator codeGenerator, final MethodInstance methodInstance,
	                     final List<LocalInstance> formals);
}
