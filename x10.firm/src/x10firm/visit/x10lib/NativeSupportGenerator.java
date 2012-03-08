package x10firm.visit.x10lib;

import java.util.Collections;
import java.util.List;

import polyglot.ast.IntLit;
import polyglot.ast.Return;
import polyglot.types.LocalInstance;
import polyglot.types.Type;
import polyglot.util.Position;
import x10.ast.X10NodeFactory_c;
import x10.types.MethodInstance;
import x10.types.X10ClassType;
import x10firm.types.FirmTypeSystem;
import x10firm.types.GenericTypeSystem;
import x10firm.visit.FirmGenerator;
import x10firm.visit.MethodConstruction;
import firm.Entity;

/**
 *  FirmGenerator for x10.lang.NativeSupport.x10
 */
public class NativeSupportGenerator extends NativeGenericDispatcher {

	/**
	 *  Support code for the getSize method in NativeSupport.x10
	 */
	static class GenGetSize implements NativeGenericMethodGenerator {
		@Override
		public boolean gen(final FirmGenerator codeGenerator, final MethodInstance meth,
						   final List<LocalInstance> formals) {
			final FirmTypeSystem firmTypeSystem = codeGenerator.getFirmTypeSystem();
			final GenericTypeSystem x10TypeSystem = codeGenerator.getX10TypeSystem();
			final X10NodeFactory_c xnf = codeGenerator.getNodeFactory();
			final X10ClassType owner = (X10ClassType)meth.container();
			final Entity entity = firmTypeSystem.getMethodEntity(meth);

			assert meth.typeParameters().size() == 1;
			final Type typeParameter = meth.typeParameters().get(0);

			final Type returnType = meth.returnType();
			final Type thisType = meth.flags().isStatic() ? null : owner;
			final MethodConstruction savedConstruction = codeGenerator.initConstruction(entity, formals, Collections.<LocalInstance>emptyList(),
					returnType, thisType);

			final Position pos = Position.COMPILER_GENERATED;
			final firm.Type firmType = firmTypeSystem.getFirmType(typeParameter);

			final Return ret = xnf.Return(pos, xnf.IntLit(pos, IntLit.INT, firmType.getSizeBytes()).type(x10TypeSystem.Int()));
			codeGenerator.visitAppropriate(ret);

			codeGenerator.finishConstruction(entity, savedConstruction);

			return true;
		}

		/**
		 * Returns the name of the method
		 */
		@Override
		public String getMethodName() {
			return "getSize";
		}
	}

	/**
	 * Constructor
	 */
	public NativeSupportGenerator() {
		addMethodGenerator(new GenGetSize());
	}

	/**
	 * Returns the dispatch name
	 */
	@Override
	public String getDispatchName() {
		return "x10.lang.NativeSupport";
	}
}
