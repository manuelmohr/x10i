package x10firm.visit.builtins;

import java.util.Collections;
import java.util.List;

import polyglot.types.LocalInstance;
import polyglot.types.Type;
import x10.types.MethodInstance;
import x10firm.types.FirmTypeSystem;
import x10firm.visit.FirmGenerator;
import x10firm.visit.MethodConstruction;
import firm.Entity;
import firm.Mode;
import firm.nodes.Node;

/**
 * Create an instance of the built-in {@code static x10.lang.NativeSupport.getSize[T](): Int} method.
 */
class X10LangNativeSupportGetSize implements BuiltinMethodGenerator {

	@Override
	public void generate(final FirmGenerator codeGenerator, final MethodInstance meth,
					final List<LocalInstance> formals) {
		final FirmTypeSystem firmTypeSystem = codeGenerator.getFirmTypeSystem();
		final Entity entity = firmTypeSystem.getMethodEntity(meth);

		assert meth.typeParameters().size() == 1;
		final Type typeParameter = meth.typeParameters().get(0);

		final Type returnType = meth.returnType();
		final MethodConstruction savedConstruction
			= codeGenerator.initConstruction(entity, formals, Collections.<LocalInstance>emptyList(),
				returnType, null);
		final MethodConstruction con = codeGenerator.getFirmConstruction();

		final firm.Type firmType = firmTypeSystem.asType(typeParameter);
		final Mode mode = firmTypeSystem.getFirmMode(returnType);
		final Node cnst = con.newSymConstTypeSize(firmType, mode);
		final Node mem = con.getCurrentMem();
		final Node ret = con.newReturn(mem, new Node[] {cnst});
		con.getGraph().getEndBlock().addPred(ret);
		con.setUnreachable();

		codeGenerator.finishConstruction(entity, savedConstruction);
	}
}
