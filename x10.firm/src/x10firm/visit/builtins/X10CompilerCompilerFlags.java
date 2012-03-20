package x10firm.visit.builtins;

import java.util.Collections;
import java.util.List;

import polyglot.types.LocalInstance;
import polyglot.types.Type;
import x10.types.MethodInstance;
import x10firm.CompilerOptions;
import x10firm.types.FirmTypeSystem;
import x10firm.visit.FirmGenerator;
import x10firm.visit.MethodConstruction;
import firm.Entity;
import firm.Mode;
import firm.nodes.Node;

/**
 * x10.compiler.CompilerFlags builtins
 */
public abstract class X10CompilerCompilerFlags {
	private static void generateBoolMethod(FirmGenerator codeGenerator,
			MethodInstance methodInstance, List<LocalInstance> formals,
			boolean value) {
		final FirmTypeSystem firmTypeSystem = codeGenerator.getFirmTypeSystem();
		final Entity entity = firmTypeSystem.getMethodEntity(methodInstance);

		final Type returnType = methodInstance.returnType();
		final MethodConstruction savedConstruction
			= codeGenerator.initConstruction(entity, formals, Collections.<LocalInstance>emptyList(), returnType, null);

		final MethodConstruction con = codeGenerator.getFirmConstruction();
		final Mode mode = firmTypeSystem.getFirmMode(returnType);
		final Node cnst = con.newConst(value ? mode.getOne() : mode.getNull());
		final Node mem = con.getCurrentMem();
		final Node ret = con.newReturn(mem, new Node[] { cnst });
		con.getGraph().getEndBlock().addPred(ret);
		con.setCurrentBlockBad();

		codeGenerator.finishConstruction(entity, savedConstruction);
	}

	/** static x10.compiler.CompilerFlags.TRUE(): Boolean */
	static class TRUE implements BuiltinMethodGenerator {
		@Override
		public void generate(FirmGenerator codeGenerator,
				MethodInstance methodInstance, List<LocalInstance> formals) {
			generateBoolMethod(codeGenerator, methodInstance, formals, true);
		}
	}

	/** static x10.compiler.CompilerFlags.FALSE(): Boolean */
	static class FALSE implements BuiltinMethodGenerator {
		@Override
		public void generate(FirmGenerator codeGenerator,
				MethodInstance methodInstance, List<LocalInstance> formals) {
			generateBoolMethod(codeGenerator, methodInstance, formals, false);
		}
	}

	/** static x10.compiler.CompilerFlags.checkBounds(): Boolean */
	static class CheckBounds implements BuiltinMethodGenerator {
		@Override
		public void generate(FirmGenerator codeGenerator,
				MethodInstance methodInstance, List<LocalInstance> formals) {
			final CompilerOptions options = codeGenerator.getOptions();
			generateBoolMethod(codeGenerator, methodInstance, formals, !options.x10_config.NO_CHECKS);
		}
	}

	/** static x10.compiler.CompilerFlags.checkPlace(): Boolean */
	static class CheckPlace implements BuiltinMethodGenerator {
		@Override
		public void generate(FirmGenerator codeGenerator,
				MethodInstance methodInstance, List<LocalInstance> formals) {
			final CompilerOptions options = codeGenerator.getOptions();
			generateBoolMethod(codeGenerator, methodInstance, formals, !options.x10_config.NO_CHECKS);
		}
	}

	/** static x10.compiler.CompilerFlags.useUnsigned(): Boolean */
	static class UseUnsigned implements BuiltinMethodGenerator {
		@Override
		public void generate(FirmGenerator codeGenerator,
				MethodInstance methodInstance, List<LocalInstance> formals) {
			generateBoolMethod(codeGenerator, methodInstance, formals, true);
		}
	}
}
