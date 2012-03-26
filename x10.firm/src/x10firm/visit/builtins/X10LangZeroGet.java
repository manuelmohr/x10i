package x10firm.visit.builtins;

import java.util.Collections;
import java.util.List;

import polyglot.types.LocalInstance;
import polyglot.types.Type;
import x10.types.MethodInstance;
import x10firm.types.FirmTypeSystem;
import x10firm.types.GenericTypeSystem;
import x10firm.visit.FirmGenerator;
import x10firm.visit.MethodConstruction;
import firm.Entity;
import firm.Mode;
import firm.nodes.Node;

/**
 * Create instance of built-in {@code static x10.lang.Zero.get[T](): T} method.
 */
class X10LangZeroGet implements BuiltinMethodGenerator {
	@Override
	public void generate(final FirmGenerator codeGenerator, final MethodInstance meth,
		                 final List<LocalInstance> formals) {
		final FirmTypeSystem firmTypeSystem = codeGenerator.getFirmTypeSystem();
		final GenericTypeSystem x10TypeSystem = codeGenerator.getX10TypeSystem();
		final Entity entity = firmTypeSystem.getMethodEntity(meth);

		assert meth.typeParameters().size() == 1;
		final Type typeParameter = meth.typeParameters().get(0);

		final Type returnType = meth.returnType();
		final MethodConstruction savedConstruction
			= codeGenerator.initConstruction(entity, formals, Collections.<LocalInstance>emptyList(),
				returnType, null);
		final MethodConstruction con = codeGenerator.getFirmConstruction();

		final Node ret;
		if (!x10TypeSystem.isStructType0(typeParameter)) {
			final Mode mode = firmTypeSystem.getFirmMode(typeParameter);
			final Node node = con.newConst(mode.getNull());
			final Node mem = con.getCurrentMem();
			ret = con.newReturn(mem, new Node[] {node});
		} else {
			final Node tmp = codeGenerator.genStackAlloc(typeParameter);
			// TODO: Add memset call
			final Node mem = con.getCurrentMem();
			ret = con.newReturn(mem, new Node[]{tmp});
		}
		con.getGraph().getEndBlock().addPred(ret);
		con.setCurrentBlockBad();
		codeGenerator.finishConstruction(entity, savedConstruction);
	}
}
