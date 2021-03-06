package x10firm.visit.builtins;

import java.util.Collections;
import java.util.List;

import polyglot.types.LocalInstance;
import polyglot.types.Type;
import x10.types.MethodInstance;
import x10.types.X10ClassType;
import x10firm.types.FirmTypeSystem;
import x10firm.visit.FirmGenerator;
import x10firm.visit.MethodConstruction;
import x10firm.visit.VarEntry;
import firm.Entity;
import firm.Mode;
import firm.nodes.Load;
import firm.nodes.Node;
import firm.nodes.Store;

/**
 * Firm Generator for {@code x10.lang.Pointer} class.
 */
abstract class X10LangPointer {
	/**
	 * Creates an instance of {@code x10.lang.Pointer.read[T](): T}.
	 */
	static class Read implements BuiltinMethodGenerator {
		@Override
		public void generate(final FirmGenerator codeGenerator, final MethodInstance meth,
		                     final List<LocalInstance> formals) {
			final FirmTypeSystem firmTypeSystem = codeGenerator.getFirmTypeSystem();
			final X10ClassType owner = (X10ClassType)meth.container();
			final Entity entity = firmTypeSystem.getMethodEntity(meth);

			assert meth.typeParameters().size() == 1;
			final Type typeParameter = meth.typeParameters().get(0);
			assert formals.size() == 0;

			final Type returnType = meth.returnType();
			final MethodConstruction savedConstruction
				= codeGenerator.initConstruction(entity, formals, Collections.<LocalInstance>emptyList(),
						returnType, owner);

			final MethodConstruction con = codeGenerator.getFirmConstruction();
			final Mode parMode = firmTypeSystem.getFirmMode(typeParameter);
			final Node result;
			final firm.Type firmType = firmTypeSystem.asType(typeParameter);
			final Node addr = con.getVariable(FirmGenerator.PARAM_VARNUM, parMode);
			if (firmTypeSystem.isFirmStructType(typeParameter)) {
				result = addr;
			} else {
				final Node mem = con.getCurrentMem();
				final Mode loadMode = firmType.getMode();
				final Node load = con.newLoad(mem, addr, loadMode);
				final Node newMem = con.newProj(load, Mode.getM(), Load.pnM);
				result = con.newProj(load, loadMode, Load.pnRes);
				con.setCurrentMem(newMem);
			}

			final Node mem2 = con.getCurrentMem();
			final Node retNode = con.newReturn(mem2, new Node[]{result});
			assert retNode != null;
			con.getGraph().getEndBlock().addPred(retNode);
			con.setUnreachable();

			codeGenerator.finishConstruction(savedConstruction);
		}
	}

	/**
	 * Creates an instance of {@code x10.lang.Pointer.write[T](val: T)}.
	 */
	static class Write implements BuiltinMethodGenerator {
		@Override
		public void generate(final FirmGenerator codeGenerator, final MethodInstance meth,
						final List<LocalInstance> formals) {
			final FirmTypeSystem firmTypeSystem = codeGenerator.getFirmTypeSystem();
			final X10ClassType owner = (X10ClassType)meth.container();
			final Entity entity = firmTypeSystem.getMethodEntity(meth);

			assert meth.typeParameters().size() == 1;
			final Type typeParameter = meth.typeParameters().get(0);

			assert formals.size() == 1;
			final LocalInstance val = formals.get(0);

			final Type returnType = meth.returnType();
			final MethodConstruction savedConstruction
				= codeGenerator.initConstruction(entity, formals, Collections.<LocalInstance>emptyList(),
					returnType, owner);

			final MethodConstruction con = codeGenerator.getFirmConstruction();
			final VarEntry varValue = con.getVarEntry(val);
			assert varValue != null;

			final Mode ptrMode = Mode.getP();
			final Node address = con.getVariable(FirmGenerator.PARAM_VARNUM, ptrMode);

			final Node newMem;
			if (firmTypeSystem.isFirmStructType(typeParameter)) {
				final Node value = con.getVariable(varValue.getIdx(), ptrMode);
				final Node mem = con.getCurrentMem();
				final firm.Type firmType = firmTypeSystem.asType(typeParameter);
				final Node copyB = con.newCopyB(mem, address, value, firmType,
						firm.bindings.binding_ircons.ir_cons_flags.cons_none);
				newMem = copyB;
			} else {
				final Mode mode = firmTypeSystem.getFirmMode(val.type());
				final Node asgn = con.getVariable(varValue.getIdx(), mode);
				final Node mem = con.getCurrentMem();
				final Node store = con.newStore(mem, address, asgn);
				newMem = con.newProj(store, Mode.getM(), Store.pnM);
			}
			con.setCurrentMem(newMem);

			final Node mem = con.getCurrentMem();
			final Node retNode = con.newReturn(mem, new Node[]{});
			assert retNode != null;

			con.getGraph().getEndBlock().addPred(retNode);
			con.setUnreachable();

			codeGenerator.finishConstruction(savedConstruction);
		}
	}

	/**
	 * Creates an instance of {@code x10.lang.Pointer.castTo[T](): T}.
	 */
	static class CastTo implements BuiltinMethodGenerator {
		@Override
		public void generate(final FirmGenerator codeGenerator, final MethodInstance meth,
		                     final List<LocalInstance> formals) {
			final FirmTypeSystem firmTypeSystem = codeGenerator.getFirmTypeSystem();
			final X10ClassType owner = (X10ClassType) meth.container();
			final Entity entity = firmTypeSystem.getMethodEntity(meth);

			assert meth.typeParameters().size() == 1;
			final Type typeParameter = meth.typeParameters().get(0);

			assert formals.size() == 0;

			final Type returnType = meth.returnType();
			final MethodConstruction savedConstruction
				= codeGenerator.initConstruction(entity, formals, Collections.<LocalInstance>emptyList(),
						returnType, owner);

			final MethodConstruction con = codeGenerator.getFirmConstruction();
			final Node ptr = con.getVariable(FirmGenerator.PARAM_VARNUM, Mode.getP());
			final Node result = con.newConv(ptr, firmTypeSystem.getFirmMode(typeParameter));
			final Node mem = con.getCurrentMem();
			final Node retNode = con.newReturn(mem, new Node[]{result});
			assert retNode != null;
			con.getGraph().getEndBlock().addPred(retNode);
			con.setUnreachable();

			codeGenerator.finishConstruction(savedConstruction);
		}
	}
}
