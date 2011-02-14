package x10firm.visit;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

import firm.nodes.Block;
import firm.nodes.Node;

import polyglot.ast.ClassMember;
import polyglot.ast.Stmt;
import polyglot.types.FieldInstance;
import polyglot.types.LocalInstance;
import polyglot.types.VarInstance;
import x10.types.X10ClassType;

/**
 * Class that holds attributes (scopes, mapping of local instance variables etc.) for a new method.
 * For every new method entry we will create a new firm context.
 */
public class X10FirmContext {
	/** Holds the topmost firmScope. -> Push a dummy frame in the current FirmContext */
	private X10FirmScope topFirmScope = new X10FirmScope();

	/** Maps VarInstances to the appropriate "VarEntry" entries */
	private Map<VarInstance<?>, X10VarEntry> varEntryMapper = new HashMap<VarInstance<?>, X10VarEntry>();
	
	/**
	 * Reference to the current class type
	 */
	private X10ClassType curClass;

	/**
	 * Will hold the corresponding statement if we have reached a labeled statement. Otherwise null.
	 */
	private Stmt stmt;

	/**
	 * Will hold the corresponding label if we have reached a labeled statement. Otherwise null.
	 */
	private String label;
	
	/**
	 * Reference to the upper firm context
	 */
	private X10FirmContext outer;
	
	/**
	 * True if we are currently in a closure
	 */
	private boolean inClosure = false;
	
	/**
	 * List with the class members which must be initialised explicitly in a constructor etc. 
	 */
	private List<ClassMember> initClassMembers = null;

	/**
	 * Create a new Firm context
	 */
	public X10FirmContext() {
		
	}
	
	/**
	 * Sets the current class
	 */
	public void setCurClass(X10ClassType curClass) {
		this.curClass = curClass;
	}
	
	/**
	 * Returns the current class
	 */
	public X10ClassType getCurClass() {
		return curClass;
	}
	
	/**
	 * Sets the class members which must be intialised explicitly
	 */
	public void setInitClassMembers(List<ClassMember> members) {
		assert(initClassMembers == null); // method should only be called once
		if(initClassMembers != null) {
			System.out.println("YES");
		}
		initClassMembers = members;
	}
	
	/**
	 * Returns all class members which must be manually initialized
	 * @return A list with all class members which must be manually intialized. 
	 */
	public List<ClassMember> getInitClassMembers() {
		assert(initClassMembers != null);
		return initClassMembers;
	}
	
	/**
	 * Pushes a new firm context
	 * @param newContext The new firm context which should be pushed
	 * @return The new firm context which was pushed.
	 */
	public X10FirmContext pushFirmContext(X10FirmContext newContext) {
		assert newContext != null;
		newContext.outer = this;
		return newContext;
	}
	
	/**
	 * Pops the topmost firm context
	 * @return The upper firm context
	 */
	public X10FirmContext popFirmContext() {
		assert outer != null;
		return outer;
	}
	
	/**
	 * Marking that we are currently in a closure
	 * @param in True if we are currently in a closure 
	 */
	public void setInClosure(boolean in) {
		inClosure = in;
	}
	
	/**
	 * Checks if we are currently in a closure
	 * @return True if we are currently in a closure
	 */
	public boolean isInClosure() {
		return inClosure;
	}
	
	/** Sets the "VarEntry" for a given variable (local variable or field instance)
	 * @param entry The "VarEntry" for the given variable
	 */
	public void setVarEntry(X10VarEntry entry) {
		assert !varEntryMapper.containsKey(entry.getVarInstance());
		varEntryMapper.put(entry.getVarInstance(), entry);
	}

	/** Returns the "VarEntry" for a given variable (local variable or field instance)
	 * @return The "VarEntry" of the given variable or null if the variable could not be found
	 */
	public X10VarEntry getVarEntry(VarInstance<?> var) {
		X10VarEntry ret = varEntryMapper.get(var);
		if(ret == null) {
			if(outer != null) 
				return outer.getVarEntry(var);
			assert(false);
			return null;
		}
		
		return ret;
	}
	
	/** Returns the "VarEntry" for a given instance variable in the current scope
	 * @return The "VarEntry" of the given instance variable in the current scope or 
	 * null if the instance variable could not be found.
	 */
	public X10VarEntry getVarEntryInThisScope(VarInstance<?> var) {
		return varEntryMapper.get(var);
	}

	/** Pushes a new firm scope
	 * @param scope The firm scope which should be pushed
	 * @return The new firm scope
	 */
	public X10FirmScope pushFirmScope(X10FirmScope scope) {
		scope.prev = topFirmScope;
		topFirmScope = scope;
		return scope;
	}

	/** Pops the topmost firm scope
	 * @return The upper firm scope of the topmost firm scope
	 */
	public X10FirmScope popFirmScope() {
		assert topFirmScope != null;
		topFirmScope = topFirmScope.prev;
		return topFirmScope;
	}

	/** Returns the topmost firm scope
	 * @return Topmost firm scope
	 */
	public X10FirmScope getTopScope() {
		assert topFirmScope != null;
		return topFirmScope;
	}

	/**
	 * Set the statement and label in a labeled statement
	 * @param label The label of the labeled statement
	 * @param stmt The statement of the labeled statement
	 */
	public void setLabeledStmt(String label, Stmt stmt) {
		this.label = label;
		this.stmt  = stmt;
	}

	/**
	 * Resets the saved statement and label in the last seen labeled statement
	 */
	public void resetLabeledStmt() {
		this.label = null;
		this.stmt  = null;
	}

	/**
	 * Returns the statement of the last seen labeled statement
	 * @return The statement
	 */
	public Stmt getLabeledStmt() {
		return stmt;
	}

	/**
	 * Returns the label of the last seen labeled statement
	 * @return The label
	 */
	public String getLabel() {
		assert label != null;
		return label;
	}
}

/** 
 * Class for saving variable instances (locals and fields) and the appropriate "firm" indices. 
 */
class X10VarEntry {
	private int idx;
	private VarInstance<?> var;
	
	private X10VarEntry(final VarInstance<?> var_, final int idx_) {
		assert(var_ != null);
		var = var_;
		idx = idx_;
	}
	
	/**
	 * Creates a new var entry for a local instance
	 * @param loc_ The local instance
	 * @param idx_ The "local" index (firm) for the local variable
	 * @return The created var entry. 
	 */
	public static X10VarEntry newVarEntryForLocalInstance(final LocalInstance loc_, final int idx_) {
		return new X10VarEntry(loc_, idx_);
	}
	
	/**
	 * Creates a new var entry for a field instance
	 * @param field_ The field instance
	 * @return The created var entry.
	 */
	public static X10VarEntry newVarEntryForFieldInstance(final FieldInstance field_) {
		return new X10VarEntry(field_, -1);
	}
	
	/**
	 * The index of the var entry -> -1 if the var entry is actually a field instance
	 * @return The index of the local instance.
	 */
	public int getIdx() {
		return idx;
	}
	
	/**
	 * Returns the var instance of the var key
	 * @return The var instance
	 */
	public VarInstance<?> getVarInstance() {
		return var;
	}
}


/**
 * Holds the corresponding target blocks for labeled continue and break statements.
 */
class X10FirmLabel {

	/**
	 * Holds the target block for a labeled continue statement
	 */
	private Block continueBlock;

	/**
	 * Holds the target block for a labeled break statement
	 */
	private Block breakBlock;

	/** Constructor */
	public X10FirmLabel() {
		
	}

	/**
	 * Sets the target block for a labeled continue statement
	 * @param block The target block
	 */
	public void setContinueBlock(Block block) {
		continueBlock = block;
	}

	/**
	 * Returns the target block for a labeled continue statement
	 * @return The target block
	 */
	public Block getContinueBlock() {
		assert continueBlock != null;
		return continueBlock;
	}

	/**
	 * Sets the target block for a labeled break statement
	 * @param block The target block
	 */
	public void setBreakBlock(Block block) {
		breakBlock = block;
	}

	/**
	 * Returns the target block for a labeled break statement
	 * @return The target block
	 */
	public Block getBreakBlock() {
		assert breakBlock != null;
		return breakBlock;
	}
}


/**
 * Class that holds attributes (true and false blocks, continue blocks, break blocks etc.) for a new scope.
 * For every new scope we will clone the current (top) scope and set the adequate attributes for the new scope.
 */
class X10FirmScope {

	/**
	 * Holds a reference to the upper FirmScope.
	 */
	X10FirmScope prev;

	/**
	 * Mapping between Labels (String) and the corresponding FirmLabels.
	 */
	private Map<String, X10FirmLabel> firmLabelMapper = new HashMap<String, X10FirmLabel>();

	/** Block we will jump into if an expression evaluates to true */
	private Block trueBlock;
	
	/** Block we will jump into if an expression evaluates to false */
	private Block falseBlock;
	
	/** Block we will jump into if we reach a continue statement */
	private Block continueBlock;
	
	/** Block we will jump into if we reach a break statement */
	private Block breakBlock;
	
	/** Reference to the current switch cond node -> null if we are not in a switch statement */
	private Node curSwitchCond;
	
	/** Proj number for the 'default' statement in a switch statement */
	private long curSwitchDefaultProjNr;

	/** constructor */
	public X10FirmScope() {
		
	}

	/** Sets the true block.
	 * @param block The block to set */
	public void setTrueBlock(Block block) {
		trueBlock = block;
	}

	/** Returns the true block.
	 * @return The true block */
	public Block getTrueBlock() {
		return trueBlock;
	}

	/** Sets the false block.
	 * @param block The block to set */
	public void setFalseBlock(Block block) {
		falseBlock = block;
	}

	/** Returns the false block.
	 * @return The false block */
	public Block getFalseBlock() {
		return falseBlock;
	}

	/** Sets the continue block.
	 * @param block The block to set */
	public void setContinueBlock(Block block) {
		continueBlock = block;
	}

	/** Returns the continue block.
	 * @return The continue block */
	public Block getContinueBlock() {
		assert continueBlock != null;
		return continueBlock;
	}

	/** Sets the break block.
	 * @param block The block to set */
	public void setBreakBlock(Block block) {
		breakBlock = block;
	}

	/** Returns the break block. Creates a new block, if the break block was
	 * not previously set.
	 * @return The break block */
	public Block getBreakBlock() {
		return breakBlock;
	}

	/** Returns true if the break block is set.
	 *  @return True or false
	 */
	public boolean isBreakBlockSet() {
		return breakBlock != null;
	}

	/** Sets the current switch condition node.
	 * @param cond The condition to set
	 */
	public void setCurSwitchCond(Node cond) {
		curSwitchCond = cond;
	}

	/** Returns the current switch condition node
	 * @return The current switch condition node
	 */
	public Node getCurSwitchCond() {
		assert curSwitchCond != null;
		return curSwitchCond;
	}

	/** Sets the projection number for the 'default' statement in the current switch statement
	 * @param projNr The projection number for the 'default' statement.
	 */
	public void setCurSwitchDefaultProjNr(long projNr) {
		curSwitchDefaultProjNr = projNr;
	}

	/**
	 * Returns the projection number of the 'default' label in the current switch statement
	 * @return The projection number of the 'default' statement
	 */
	public long getCurSwitchDefaultProjNr() {
		return curSwitchDefaultProjNr;
	}

	/**
	 * Sets the target block for a labeled continue statement.
	 * @param label The label of the continue statement.
	 * @param block The target block for the continue statement
	 */
	public void setBlockForLabeledContinue(String label, Block block) {
		X10FirmLabel firmLabel = getFirmLabel(label);
		firmLabel.setContinueBlock(block);
	}

	/**
	 * Returns the corresponding target block for a labeled continue block
	 * @param label The label of the continue statement
	 * @return The target block for the continue statement
	 */
	public Block getBlockForLabeledContinue(String label) {
		X10FirmLabel firmLabel = getFirmLabel(label);
		return firmLabel.getContinueBlock();
	}

	/**
	 * Sets the target block for a labeled break statement.
	 * @param label The label of the break statement.
	 * @param block The target block for the break statement
	 */
	public void setBlockForLabeledBreak(String label, Block block) {
		X10FirmLabel firmLabel = getFirmLabel(label);
		firmLabel.setBreakBlock(block);
	}

	/**
	 * Returns the corresponding target block for a labeled break block
	 * @param label The label of the break statement
	 * @return The target block for the break statement
	 */
	public Block getBlockForLabeledBreak(String label) {
		X10FirmLabel firmLabel = getFirmLabel(label);
		return firmLabel.getBreakBlock();
	}

	/**
	 * Helper function. Traverse all FirmScopes upwards and try to find the
	 * corresponding FirmLabel for the given string label.
	 * @param label The label we are searching for
	 * @return The corresponding FirmLabel or null if the given string label could not be found
	 */
	private X10FirmLabel getFirmLabelHelp(String label) {
		if(!firmLabelMapper.containsKey(label)) {
			if(prev != null) {
				return prev.getFirmLabelHelp(label);
			}
			return null;

		}
		return firmLabelMapper.get(label);
	}

	/**
	 * Returns the corresponding FirmLabel for the given string label
	 * @param label The label we are searching for
	 * @return The corresponding FirmLabel for the given string label
	 */
	private X10FirmLabel getFirmLabel(String label) {
		X10FirmLabel firmLabel = getFirmLabelHelp(label);
		assert firmLabel != null;

		return firmLabel;
	}

	/**
	 * Declare (Create) a new FirmLabel for the given string label in the current firm scope.
	 * @param label The string label
	 */
	public void declFirmLabel(String label) {
		assert !firmLabelMapper.containsKey(label);
		firmLabelMapper.put(label, new X10FirmLabel());
	}

	@Override
	public Object clone() {
		X10FirmScope clonedScope  		= new X10FirmScope();
		clonedScope.trueBlock     	= this.trueBlock;
		clonedScope.falseBlock		= this.falseBlock;
		clonedScope.continueBlock   = this.continueBlock;
		clonedScope.breakBlock      = this.breakBlock;
		// The local mapper needn`t be cloned

		return clonedScope;
	}
}

