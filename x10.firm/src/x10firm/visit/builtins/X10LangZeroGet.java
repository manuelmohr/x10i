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
 * create method for static x10.lang.Zero.get[T](): T
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
		final MethodConstruction savedConstruction = codeGenerator.initConstruction(entity, formals, Collections.<LocalInstance>emptyList(),
				returnType, null);
		final MethodConstruction con = codeGenerator.getFirmConstruction();

		if (!x10TypeSystem.isStructType0(typeParameter)) {
			final Mode mode = firmTypeSystem.getFirmMode(typeParameter);
			final Node node = con.newConst(mode.getNull());
			final Node mem = con.getCurrentMem();
			final Node ret = con.newReturn(mem, new Node[] { node });
			con.getGraph().getEndBlock().addPred(ret);
		} else {
			final Node tmp = codeGenerator.genStackAlloc(typeParameter);
			// TODO: Add memset call
			final Node mem = con.getCurrentMem();
			final Node retNode = con.newReturn(mem, new Node[]{tmp});
			assert retNode != null;

			con.getGraph().getEndBlock().addPred(retNode);
			con.setCurrentBlockBad();
		}
		codeGenerator.finishConstruction(entity, savedConstruction);
	}
}
