package x10firm.goals;

import java.io.IOException;

import polyglot.ast.Node;
import polyglot.frontend.Compiler;
import polyglot.frontend.Job;
import polyglot.frontend.SourceGoal_c;
import polyglot.types.TypeSystem;
import polyglot.visit.Translator;
import x10.ast.X10NodeFactory_c;
import x10.extension.X10Ext;
import x10firm.CompilerOptions;
import x10firm.types.FirmTypeSystem;
import x10firm.types.GenericTypeSystem;
import x10firm.visit.X10FirmCodeGenerator;
import firm.Dump;
import firm.Graph;
import firm.Program;

/**
 * This defines the FirmGeneration goal (other people would say "phase")
 * for polyglot.
 * @author matze
 */
public class FirmGenerated extends SourceGoal_c {
	/**
	 * Remember the FIRM type system until the code generator is actually invoked.
	 */
	private final FirmTypeSystem firmTypeSystem;

	/**
	 * Remember the X10 type system until the code generator is actually invoked.
	 */
	private final GenericTypeSystem x10TypeSystem;

	/**
	 * Remember the node factory until the code generator is actually invoked
	 */
	private final X10NodeFactory_c nodeFactory;

	/** Constructor */
	public FirmGenerated(final Job job, final TypeSystem x10TypeSystem,
			final FirmTypeSystem firmTypeSystem,
			final X10NodeFactory_c nodeFactory) {
		super("FirmGenerated", job);
		this.firmTypeSystem = firmTypeSystem;
		this.x10TypeSystem = (GenericTypeSystem) x10TypeSystem;
		this.nodeFactory = nodeFactory;
	}

	@Override
	public boolean runTask() {
		Node ast = job().ast();
		System.out.println("FirmGenerated: " + ast);
		assert (ast != null);
		if (!((X10Ext) ast.ext()).subtreeValid())
			return false;

		firmTypeSystem.beforeGraphConstruction();

		final Translator tr = new Translator(job(), x10TypeSystem, null, null);
		final Compiler compiler = job().compiler();
		final CompilerOptions options =
			(CompilerOptions) scheduler.extensionInfo().getOptions();

		final X10FirmCodeGenerator v = new X10FirmCodeGenerator(compiler,
				firmTypeSystem, x10TypeSystem, nodeFactory, tr, options);

		v.visitAppropriate(ast);

		firmTypeSystem.finishTypeSystem();

		if (options.dump_firm_graphs) {
			try {
				Dump.dumpTypeGraph("typegraph_" + ast.toString() + ".vcg");
			} catch (IOException e1) {

			}
		}

		/* TODO: this is suboptimal here, since we have multiple FirmGenerated
		 * goals for each inputfile. We should only dump the graphs for the current
		 * input here and not all... */
		if (options.dump_firm_graphs) {
			for (Graph g : Program.getGraphs()) {
					Dump.dumpGraph(g, "--fresh");
			}
		}

		return true;
	}
}
