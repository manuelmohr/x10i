package x10firm;

import polyglot.ast.Node;
import polyglot.frontend.Compiler;
import polyglot.frontend.Job;
import polyglot.frontend.SourceGoal_c;
import x10.extension.X10Ext;
import x10firm.types.TypeSystem;
import x10firm.visit.X10FirmCodeGenerator;

public class FirmGenerationGoal extends SourceGoal_c {
	private final TypeSystem typeSystem;

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
		
		Compiler compiler = job().compiler();
		final X10FirmCodeGenerator v = new X10FirmCodeGenerator(compiler, typeSystem);
		v.visitAppropriate(ast);
		return true;
	}
}
