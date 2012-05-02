package x10firm.visit;

import java.util.HashMap;
import java.util.Map;
import java.util.Map.Entry;

import polyglot.ast.Case;
import polyglot.ast.Id;
import polyglot.ast.Stmt;
import polyglot.types.LocalDef;
import polyglot.types.LocalInstance;
import polyglot.types.Type;
import firm.Graph;
import firm.nodes.Block;
import firm.nodes.Node;
import firm.nodes.OOConstruction;

/**
 * Class that holds state while a method graph is constructed.
 * (We need this as a class because it is possible to get nested method
 *  constructions - for boxing types or closures for example)
 */
public class MethodConstruction extends OOConstruction {
	/** Maps local var defs to the appropriate var entries. */
	private Map<LocalDef, VarEntry> varEntryMapper = new HashMap<LocalDef, VarEntry>();
	/** Reference to the current procedure return type. */
	Type returnType;
	/** holds current target for break statements. */
	Block breakBlock;
	/** holds current target for continue statements. */
	Block continueBlock;
	/** holds mapping of Id to labeled Statement.
	 * (This implies that labeled statement are not duplicated,
	 *  but for now this should be good enough as it is as bad as the
	 *  x10 c++ backend: XTENLANG-2434 */
	Map<String, Block> labeledBreaks = new HashMap<String, Block>();
	/** mapping of Id to labeled continue block. */
	Map<String, Block> labeledContinues = new HashMap<String, Block>();
	/** Id of last labeled statement seen. */
	Id lastLabel;
	/** last node in a labeled statement. */
	Stmt labeledStmt;
	/** SwitchJmp node of current switch. */
	Node switchNode;
	/** maps Cases to switch projection numbers. */
	Map<Case, Integer> casePNs;
	/** local instance for "this". */
	LocalInstance thisInstance;
	/** tells wether a struct constructor is created. So we know when a
	 * "return" has to be interpreted as "return this";
	 */
	boolean inStructConstructor;

	/**
	 * Creates a new Firm context.
	 */
	public MethodConstruction(final Graph graph) {
		super(graph);
	}

	/** Sets the "VarEntry" for a given variable (local variable or field instance).
	 * @param entry The "VarEntry" for the given variable
	 */
	public void setVarEntry(final VarEntry entry) {
		assert !varEntryMapper.containsKey(entry.getVarDef());
		varEntryMapper.put(entry.getVarDef(), entry);
	}

	/** Returns the "VarEntry" for a given instance variable in the current scope.
	 * @return The "VarEntry" of the given instance variable in the current scope or
	 * null if the instance variable could not be found.
	 */
	public VarEntry getVarEntry(final LocalInstance var) {
		/*
		 * The TypeAlphaRenamer and ClassRemover visitors create and use copies of X10LocalDefs.
		 * This copies will not work with our X10LocalDef hashing mechanism. To handle this copies with will not
		 * adjust the visitors instead we will search for the appropriate X10LocalDef copy in our varEntryMapper.
		 */
		final LocalDef def = var.def();
		VarEntry ret = varEntryMapper.get(var.def());
		if (ret != null)
			return ret; // The def is equal; return the appropriate var entry
		// Search for the copy.
		for (final Entry<LocalDef, VarEntry> entry : varEntryMapper.entrySet()) {
			final LocalDef d = entry.getKey();
			// Copy search: Name, position and flags must be equal.
			if (def.name().equals(d.name()) && def.position().equals(d.position())
			    && def.flags().equals(d.flags())) {
				ret = entry.getValue();
				break;
			}
		}
		return ret;
	}

	/**
	 * Returns current break block, creates a new one if necessary.
	 */
	public Block createBreakBlock() {
		if (breakBlock == null)
			breakBlock = newBlock();
		return breakBlock;
	}
}
