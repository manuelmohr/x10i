package x10firm.visit;

import java.util.HashMap;
import java.util.Map;

import firm.nodes.Block;
import firm.nodes.Node;

/**
 * Class that holds attributes (true and false blocks, continue blocks, break blocks etc.) for a new scope.
 * For every new scope we will clone the current (top) scope and set the adequate attributes for the new scope.
 */
class FirmScope {

	/**
	 * Holds the corresponding target blocks for labeled continue and break statements.
	 */
	class X10FirmLabel {

		/**
		 * Holds the target block for a labeled continue statement
		 */
		private Block cBlock;

		/**
		 * Holds the target block for a labeled break statement
		 */
		private Block bBlock;

		/** Constructor */
		public X10FirmLabel() {

		}

		/**
		 * Sets the target block for a labeled continue statement
		 * @param block The target block
		 */
		public void setContinueBlock(Block block) {
			cBlock = block;
		}

		/**
		 * Returns the target block for a labeled continue statement
		 * @return The target block
		 */
		public Block getContinueBlock() {
			assert cBlock != null;
			return cBlock;
		}

		/**
		 * Sets the target block for a labeled break statement
		 * @param block The target block
		 */
		public void setBreakBlock(Block block) {
			bBlock = block;
		}

		/**
		 * Returns the target block for a labeled break statement
		 * @return The target block
		 */
		public Block getBreakBlock() {
			assert bBlock != null;
			return bBlock;
		}
	}

	/**
	 * Holds a reference to the upper FirmScope.
	 */
	private FirmScope prev;

	/**
	 * Mapping between Labels (String) and the corresponding FirmLabels.
	 */
	private Map<String, X10FirmLabel> firmLabelMapper = new HashMap<String, X10FirmLabel>();

	/** Block we will jump into if we reach a continue statement */
	private Block continueBlock;

	/** Block we will jump into if we reach a break statement */
	private Block breakBlock;

	/** Reference to the current switch cond node -> null if we are not in a switch statement */
	private Node curSwitch;

	/** constructor */
	public FirmScope() {

	}

	/**
	 * Sets the upper scope
	 * @param scope the upper scope
	 */
	public void setPrev(FirmScope scope) {
		prev = scope;
	}

	/**
	 * Returns the upper scope
	 */
	public FirmScope getPrev() {
		return prev;
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
	 * @param swtch The condition to set
	 */
	public void setCurSwitch(Node swtch) {
		curSwitch = swtch;
	}

	/** Returns the current switch condition node
	 * @return The current switch condition node
	 */
	public Node getCurSwitch() {
		assert curSwitch != null;
		return curSwitch;
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
		FirmScope clonedScope  	= new FirmScope();
		clonedScope.continueBlock   = this.continueBlock;
		clonedScope.breakBlock      = this.breakBlock;
		// The local mapper needn`t be cloned

		return clonedScope;
	}
}