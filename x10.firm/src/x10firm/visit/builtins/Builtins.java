package x10firm.visit.builtins;

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
public class Builtins {
	private Map<String, BuiltinMethodGenerator> map = new HashMap<String, BuiltinMethodGenerator>();

	/**
	 * Constructor.
	 */
	public Builtins() {
		map.put("x10.lang.Zero.get", new X10LangZeroGet());
		map.put("x10.lang.Pointer.read", new X10LangPointer.Read());
		map.put("x10.lang.Pointer.write", new X10LangPointer.Write());
		map.put("x10.lang.NativeSupport.getSize", new X10LangNativeSupportGetSize());
		map.put("x10.compiler.CompilerFlags.TRUE", new X10CompilerCompilerFlags.TRUE());
		map.put("x10.compiler.CompilerFlags.FALSE", new X10CompilerCompilerFlags.FALSE());
		map.put("x10.compiler.CompilerFlags.checkBounds", new X10CompilerCompilerFlags.CheckBounds());
		map.put("x10.compiler.CompilerFlags.checkPlace", new X10CompilerCompilerFlags.CheckPlace());
		map.put("x10.compiler.CompilerFlags.useUnsigned", new X10CompilerCompilerFlags.UseUnsigned());
	}

	/**
	 * Dispatch a given native generic method to the appropriate generics generator.
	 * @param codeGenerator The firm code generator
	 * @param meth The method instance for which the firm code should be generated
	 * @param formals The formals of the methods
	 * @return True if the given method could be dispatched.
	 */
	public boolean generate(final FirmGenerator codeGenerator, final MethodInstance meth,
	                        final List<LocalInstance> formals) {
		final X10ClassType owner = (X10ClassType)meth.container();
		final String ownerName = owner.fullName().toString();
		final String qualifiedName = ownerName + "." + meth.name().toString();
		final BuiltinMethodGenerator generator = map.get(qualifiedName);
		if (generator != null) {
			generator.generate(codeGenerator, meth, formals);
			return true;
		}
		return false;
	}
}
