package x10firm;

import polyglot.ast.Node;
import polyglot.frontend.Compiler;
import polyglot.frontend.Job;
import polyglot.frontend.SourceGoal_c;
import x10.ast.X10NodeFactory;
import x10.extension.X10Ext;
import x10firm.types.TypeSystem;
import x10firm.visit.X10FirmCodeGenerator;

public class FirmGenerationGoal extends SourceGoal_c {
	private final TypeSystem typeSystem;
	private final X10NodeFactory nodeFactory;

	public FirmGenerationGoal(Job job, TypeSystem typeSystem, X10NodeFactory nodeFactory) {
		super("FirmGeneration", job);
		this.typeSystem = typeSystem;
		this.nodeFactory = nodeFactory;
	}

	@Override
	public boolean runTask() {
		Node ast = job().ast();
		if (!((X10Ext) ast.ext()).subtreeValid()) {
			return false;
		}
		
		Compiler compiler = job().compiler();
		final X10FirmCodeGenerator v = new X10FirmCodeGenerator(compiler, typeSystem, nodeFactory);
		v.visitAppropriate(ast);
		return true;
	}
}
