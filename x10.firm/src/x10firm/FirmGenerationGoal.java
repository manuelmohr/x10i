package x10firm;

import java.io.IOException;

import firm.Backend;
import firm.Dump;
import polyglot.ast.Node;
import polyglot.frontend.Compiler;
import polyglot.frontend.Job;
import polyglot.frontend.SourceGoal_c;
import x10.extension.X10Ext;
import x10firm.types.TypeSystem;
import x10firm.visit.X10FirmCodeGenerator;

/**
 * This defines the FirmGeneration goal (other people would say "phase")
 * for polyglot.
 * @author matze
 */
public class FirmGenerationGoal extends SourceGoal_c {
	/**
	 * Remember the typeSystem until the code generator is actually invoked.
	 */
	private final TypeSystem typeSystem;

	/** Constructor */
	public FirmGenerationGoal(Job job, TypeSystem typeSystem) {
		super("FirmGeneration", job);
		this.typeSystem = typeSystem;
	}

	@Override
	public boolean runTask() {
		Node ast = job().ast();
		if (!((X10Ext) ast.ext()).subtreeValid()) {
			return false;
		}
		
		typeSystem.beforeGraphConstruction();

		Compiler compiler = job().compiler();
		final X10FirmCodeGenerator v = new X10FirmCodeGenerator(compiler,
				typeSystem);
		v.visitAppropriate(ast);
		
		try {
			Dump.dumpTypeGraph("typegraph.vcg");
		} catch (IOException e1) {
		}
		
		/* lower OO-constructs */
		OOSupport.lowerOO(typeSystem);

		/* try to generate some assembly */
		String compilationUnit = "x10program"; /* can we query the program name? */
		try {
			Backend.option("omitfp"); // makes the assembler a bit more readable 
			Backend.createAssembler("test.s", compilationUnit);
		} catch (IOException e) {
			e.printStackTrace();
		}

		return true;
	}
}
