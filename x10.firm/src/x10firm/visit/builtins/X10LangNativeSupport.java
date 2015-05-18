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
 * compiler built-ins for x10.lang.NativeSupport.
 */
public abstract class X10LangNativeSupport {
	/**
	 * Create an instance of the built-in {@code static x10.lang.NativeSupport.unsafeCast[T](obj:Object): T} method.
	 */
	public static class UnsafeCast implements BuiltinMethodGenerator {

		@Override
		public void generate(final FirmGenerator codeGenerator, final MethodInstance methodInstance,
				final List<LocalInstance> formals) {
			final FirmTypeSystem firmTypeSystem = codeGenerator.getFirmTypeSystem();
			final Entity entity = firmTypeSystem.getMethodEntity(methodInstance);

			final Type returnType = methodInstance.returnType();
			final MethodConstruction savedConstruction
				= codeGenerator.initConstruction(entity, formals, Collections.<LocalInstance>emptyList(),
					returnType, null);
			final MethodConstruction con = codeGenerator.getFirmConstruction();

			final Node args = con.getGraph().getArgs();
			final Node arg = con.newProj(args, Mode.getP(), 0);
			final Node mem = con.getCurrentMem();
			final Node ret = con.newReturn(mem, new Node[] {arg});
			con.getGraph().getEndBlock().addPred(ret);
			con.setUnreachable();

			codeGenerator.finishConstruction(savedConstruction);
		}

	}

	/**
	 * Create an instance of the built-in {@code static x10.lang.NativeSupport.getSize[T](): Int} method.
	 */
	public static class GetSize implements BuiltinMethodGenerator {

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
			final Node cnst = con.newSize(mode, firmType);
			final Node mem = con.getCurrentMem();
			final Node ret = con.newReturn(mem, new Node[] {cnst});
			con.getGraph().getEndBlock().addPred(ret);
			con.setUnreachable();

			codeGenerator.finishConstruction(savedConstruction);
		}
	}

	/**
	 * Create an instance of the built-in {@code static x10.lang.NativeSupport.isPointerFree[T](): Boolean} method.
	 */
	public static class IsPointerFree implements BuiltinMethodGenerator {

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

			final Mode paramMode = firmTypeSystem.getFirmMode(typeParameter);
			final boolean isPointerFree = paramMode.isNum();
			final Mode retMode = firmTypeSystem.getFirmMode(returnType);
			final Node cnst = con.newConst(isPointerFree ? retMode.getOne() : retMode.getNull());
			final Node mem = con.getCurrentMem();
			final Node ret = con.newReturn(mem, new Node[] {cnst});
			con.getGraph().getEndBlock().addPred(ret);
			con.setUnreachable();

			codeGenerator.finishConstruction(savedConstruction);
		}
	}
}
