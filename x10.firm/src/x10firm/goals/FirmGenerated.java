package x10firm.goals;

import java.io.IOException;

import polyglot.ast.Node;
import polyglot.frontend.Compiler;
import polyglot.frontend.Job;
import polyglot.frontend.SourceGoal_c;
import polyglot.visit.Translator;
import x10.ast.X10NodeFactory_c;
import x10.extension.X10Ext;
import x10firm.types.TypeSystem;
import x10firm.visit.X10FirmCodeGenerator;
import firm.Dump;
import firm.Graph;
import firm.Program;
import firm.bindings.binding_iroptimize;

/**
 * This defines the FirmGeneration goal (other people would say "phase")
 * for polyglot.
 * @author matze
 */
public class FirmGenerated extends SourceGoal_c {
	/**
	 * Remember the typeSystem until the code generator is actually invoked.
	 */
	private final TypeSystem typeSystem;
	
	/**
	 * Remember the node factory until the code generator is actually invoked
	 */
	private final X10NodeFactory_c nodeFactory;

	/** Constructor */
	public FirmGenerated(final Job job, final TypeSystem typeSystem, final X10NodeFactory_c nodeFactory) {
		super("FirmGenerated", job);
		this.typeSystem = typeSystem;
		this.nodeFactory = nodeFactory;
	}
	
	private static boolean hasRun = false;

	@Override
	public boolean runTask() {
		// TODO: should not be necessary...
		if(hasRun) return true;
		hasRun = true;
		
		Node ast = job().ast();
		assert (ast != null);
		if (!((X10Ext) ast.ext()).subtreeValid()) {
			return false;
		}

		typeSystem.beforeGraphConstruction();
		
		final Translator tr = new Translator(job(), typeSystem, null, null);

		Compiler compiler = job().compiler();
		final X10FirmCodeGenerator v = new X10FirmCodeGenerator(compiler,
				typeSystem, nodeFactory, tr);
		v.visitAppropriate(ast);

		try {
			Dump.dumpTypeGraph("typegraph.vcg");
		} catch (IOException e1) {
		}

		for(Graph g : Program.getGraphs()) {
			binding_iroptimize.optimize_cf(g.ptr);
			Dump.dumpGraph(g, "--fresh");
		}

		return true;
	}
}
