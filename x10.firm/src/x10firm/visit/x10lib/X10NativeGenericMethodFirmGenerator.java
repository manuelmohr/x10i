package x10firm.visit.x10lib;

import java.util.List;

import polyglot.types.LocalInstance;
import x10.types.MethodInstance;
import x10firm.visit.X10FirmCodeGenerator;

public interface X10NativeGenericMethodFirmGenerator {
	public boolean gen(final X10FirmCodeGenerator codeGenerator, final MethodInstance methodInstance,
					   final List<LocalInstance> formals);
	public String getMethodName();
}
