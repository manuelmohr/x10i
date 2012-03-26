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
 * Creates instances of {@code x10.compiler.CompilerFlags} built-in methods.
 */
public abstract class X10CompilerCompilerFlags {
	private static void generateBoolMethod(final FirmGenerator codeGenerator,
			final MethodInstance methodInstance, final List<LocalInstance> formals,
			final boolean value) {
		final FirmTypeSystem firmTypeSystem = codeGenerator.getFirmTypeSystem();
		final Entity entity = firmTypeSystem.getMethodEntity(methodInstance);

		final Type returnType = methodInstance.returnType();
		final MethodConstruction savedConstruction
			= codeGenerator.initConstruction(entity, formals, Collections.<LocalInstance>emptyList(), returnType, null);

		final MethodConstruction con = codeGenerator.getFirmConstruction();
		final Mode mode = firmTypeSystem.getFirmMode(returnType);
		final Node cnst = con.newConst(value ? mode.getOne() : mode.getNull());
		final Node mem = con.getCurrentMem();
		final Node ret = con.newReturn(mem, new Node[] {cnst});
		con.getGraph().getEndBlock().addPred(ret);
		con.setCurrentBlockBad();

		codeGenerator.finishConstruction(entity, savedConstruction);
	}

	/** Creates instance of {@code static x10.compiler.CompilerFlags.TRUE(): Boolean} method. */
	static class TRUE implements BuiltinMethodGenerator {
		@Override
		public void generate(final FirmGenerator codeGenerator,
				final MethodInstance methodInstance, final List<LocalInstance> formals) {
			generateBoolMethod(codeGenerator, methodInstance, formals, true);
		}
	}

	/** Creates instance of {@code static x10.compiler.CompilerFlags.FALSE(): Boolean} method. */
	static class FALSE implements BuiltinMethodGenerator {
		@Override
		public void generate(final FirmGenerator codeGenerator,
				final MethodInstance methodInstance, final List<LocalInstance> formals) {
			generateBoolMethod(codeGenerator, methodInstance, formals, false);
		}
	}

	/** Creates instance of {@code static x10.compiler.CompilerFlags.checkBounds(): Boolean} method. */
	static class CheckBounds implements BuiltinMethodGenerator {
		@Override
		public void generate(final FirmGenerator codeGenerator,
				final MethodInstance methodInstance, final List<LocalInstance> formals) {
			final CompilerOptions options = codeGenerator.getOptions();
			generateBoolMethod(codeGenerator, methodInstance, formals, !options.x10_config.NO_CHECKS);
		}
	}

	/** Creates instance of {@code static x10.compiler.CompilerFlags.checkPlace(): Boolean} method. */
	static class CheckPlace implements BuiltinMethodGenerator {
		@Override
		public void generate(final FirmGenerator codeGenerator,
				final MethodInstance methodInstance, final List<LocalInstance> formals) {
			final CompilerOptions options = codeGenerator.getOptions();
			generateBoolMethod(codeGenerator, methodInstance, formals, !options.x10_config.NO_CHECKS);
		}
	}

	/** Creates instance of {@code static x10.compiler.CompilerFlags.useUnsigned(): Boolean} method. */
	static class UseUnsigned implements BuiltinMethodGenerator {
		@Override
		public void generate(final FirmGenerator codeGenerator,
				final MethodInstance methodInstance, final List<LocalInstance> formals) {
			generateBoolMethod(codeGenerator, methodInstance, formals, true);
		}
	}
}
